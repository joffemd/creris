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
add_custom_target(codegen)

# get latest dogen
set(dogen_dir "${CMAKE_BINARY_DIR}/../dogen/stage/bin/")
execute_process(
    COMMAND ls -t ${dogen_dir}
    COMMAND grep dogen_driver-
    COMMAND sort -r
    COMMAND head -n1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    OUTPUT_VARIABLE dogen_binary
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)

message(STATUS "Using dogen: ${dogen_binary}")

set(target credit_risk)
add_custom_target(generate_${target}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${dogen_dir}/${dogen_binary}
    --target ${CMAKE_SOURCE_DIR}/diagrams/${target}.dia
    --cpp-project-dir ${CMAKE_SOURCE_DIR}/projects/
    --cpp-enable-facet domain
    --cpp-enable-facet io
    --cpp-enable-facet hash
    --cpp-enable-facet serialization
    --cpp-enable-facet test_data
    -v -d -p creris)
add_dependencies(codegen generate_${target})

set(target batcher)
add_custom_target(generate_${target}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${dogen_dir}/${dogen_binary}
    --target ${CMAKE_SOURCE_DIR}/diagrams/${target}.dia
    --cpp-project-dir ${CMAKE_SOURCE_DIR}/projects/
    --reference ${CMAKE_SOURCE_DIR}/diagrams/credit_risk.dia
    --cpp-enable-facet domain
    --cpp-enable-facet io
    --cpp-enable-facet hash
    --cpp-enable-facet serialization
    --cpp-enable-facet test_data
    -v -d -p creris)
add_dependencies(codegen generate_${target})
