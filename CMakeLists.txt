# -*- mode: cmake; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#
# avoid nonsense warning on cygwin
set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# enable ctest support
enable_testing()

# prohibit in-source builds: i.e. users are not allowed to perform
# builds either in the source root directory or in any of its
# sub-directories.
string(REGEX MATCH "^${CMAKE_SOURCE_DIR}" source_build ${CMAKE_BINARY_DIR})
if (source_build)
    message(FATAL_ERROR "Attempting to build in the source directory."
        "Please create a separate build directory and invoke cmake from there.")
endif()

project(creris)

# add our own modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build/cmake)

# options
option(WITH_DEBUG "Build the project with debug symbols" on)
option(WITH_PROFILING "Build the project with profiling support" off)

#
# check for dependencies
#

# threads
find_package(Threads REQUIRED)

# boost
set(BOOST_ROOT "$ENV{PFH_LOCATION}")
set(Boost_NO_SYSTEM_PATHS "ON")

find_package(Boost 1.40 REQUIRED COMPONENTS
    system
    serialization
    date_time
    thread
    filesystem
    program_options
    )

find_package(LibXml2)

# profiling
if(WITH_PROFILING)
    if(WITH_DEBUG)
        message(STATUS "Profiling enabled...")
    else()
        message(STATUS "Ignoring attempt to enable profiling without debug...")
        set(WITH_PROFILING off)
    endif()
else()
    message(STATUS "Profiling NOT enabled...")
endif()

# WinSock (for PQXX)
if (WIN32)
    find_library(WSOCK_LIB NAMES wsock32 DOC "The winsock library")
    if(WSOCK_LIB)
        list(APPEND CMAKE_REQUIRED_LIBRARIES wsock32)
    else()
        message(FATAL_ERROR "winsock not found.")
    endif()

    find_library(WSOCK2_LIB NAMES ws2_32 DOC "The winsock 2 library")
    if(WSOCK2_LIB)
        list(APPEND CMAKE_REQUIRED_LIBRARIES ws2_32)
    else()
        message(FATAL_ERROR "winsock2 not found.")
    endif()

    find_library(MSWSOCK_LIB NAMES mswsock DOC "The winsock 2 library")
    if(MSWSOCK_LIB)
        list(APPEND CMAKE_REQUIRED_LIBRARIES mswsock)
    else()
        message(FATAL_ERROR "mswsock not found.")
    endif()
endif()

# database
find_package(PQXX)
if(PQXX_FOUND)
    message(STATUS "Found libpqxx...")
else()
    message(FATAL_ERROR "libpqxx not found.")
endif()

#
# setup git
#
find_program(CTEST_GIT_COMMAND NAMES git)
if(NOT DEFINED CTEST_GIT_COMMAND)
    message(FATAL_ERROR "git not found.")
endif()
message(STATUS "Found git (${CTEST_GIT_COMMAND})...")

# hash of the top commit
execute_process(COMMAND ${CTEST_GIT_COMMAND} rev-list -n 1 HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    ERROR_VARIABLE git_error
    OUTPUT_VARIABLE CURRENT_GIT_COMMIT
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# ssh
find_program(ssh_executable ssh)
if(ssh_executable)
    message(STATUS "Found ssh (${ssh_executable})...")
else()
    message(FATAL_ERROR "Could not find a valid ssh installation.")
endif()

find_program(scp_executable scp)
if(scp_executable)
    message(STATUS "Found scp (${scp_executable})...")
else()
    message(FATAL_ERROR "Could not find a valid ssh installation.")
endif()

#
# useful vars
#

# site (for ctest)
site_name(CRERIS_SITE)

# staging directory
set(stage_dir ${CMAKE_BINARY_DIR}/stage)
set(stage_bin_dir ${CMAKE_BINARY_DIR}/stage/bin)
set(stage_pkg_dir ${CMAKE_BINARY_DIR}/stage/pkg)
set(stage_test_data_dir ${stage_dir}/test_data)
set(stage_doxygen_dir ${stage_dir}/doxygen)

# ensure cmake dumps binaries in the right places
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${stage_bin_dir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${stage_bin_dir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${stage_bin_dir})

# version info
set(CRERIS_MAJOR_VERSION 0)
set(CRERIS_MINOR_VERSION 0)
set(CRERIS_PATCH_VERSION 18)
set(CRERIS_VERSION "${CRERIS_MAJOR_VERSION}")
set(CRERIS_VERSION "${CRERIS_VERSION}.${CRERIS_MINOR_VERSION}")
set(CRERIS_VERSION "${CRERIS_VERSION}.${CRERIS_PATCH_VERSION}")

if(WITH_DEBUG)
    set(CRERIS_VERSION "${CRERIS_VERSION}-debug")
endif()

# system includes
include_directories(SYSTEM
    ${LIBXML2_INCLUDE_DIR}
    # for sigc++config.h multiarch
    /usr/lib/i386-linux-gnu/sigc++-2.0/include
    /usr/lib/x86_64-linux-gnu/sigc++-2.0/include
    )

#
# doxygen
#

# input directories (used in doxygen template)
set(CRERIS_CPP_CODE_DIR ${CMAKE_SOURCE_DIR}/projects)
set(CRERIS_DOX_DIR ${stage_doxygen_dir}/dox)

# output directory (used in doxygen template)
set(CRERIS_DOXYGEN_DIR ${stage_doxygen_dir})

# input file
set(doxy_file ${stage_doxygen_dir}/creris.doxy)
add_custom_target(doxy doxygen ${doxy_file})

set(server "kitanda.linkpc.net")
set(remote_site "/Users/git/Repositories/website/org/doxygen/creris")
set(remote_file "git@${server}:${remote_site}")

add_custom_target(deploy_doxy
    COMMAND ${ssh_executable} git@${server} 'rm -rf ${remote_site}.new
    /tmp/creris_doxygen.tgz && mkdir ${remote_site}.new'
    COMMAND tar -C ${stage_doxygen_dir} -zcf ${stage_dir}/creris_doxygen.tgz .
    COMMAND ${scp_executable} ${stage_dir}/creris_doxygen.tgz
    git@${server}:/tmp/creris_doxygen.tgz
    COMMAND ${ssh_executable} git@${server} 'tar -C ${remote_site}.new/
    -zxf /tmp/creris_doxygen.tgz'
    COMMAND ${ssh_executable} git@${server} 'mv ${remote_site} ${remote_site}.old'
    COMMAND ${ssh_executable} git@${server} 'mv ${remote_site}.new ${remote_site}'
    COMMAND ${ssh_executable} git@${server} 'rm -rf ${remote_site}.old'
    )
add_dependencies(deploy_doxy doxy)

#
# aggregate targets
#
add_custom_target(run_all_specs)

#
# include all sub directories
#
add_subdirectory(${CMAKE_SOURCE_DIR}/build/templates)
add_subdirectory(${CMAKE_SOURCE_DIR}/build/cpack)
add_subdirectory(${CMAKE_SOURCE_DIR}/projects)
add_subdirectory(${CMAKE_SOURCE_DIR}/diagrams)