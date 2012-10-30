# -*- mode: cmake; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2011 Kitanda
#
# This file is distributed under the Kitanda Proprietary Software
# Licence. See doc/LICENCE.TXT for details.
#
set(quant_spec_files "")
file(GLOB_RECURSE quant_spec_files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(quant_spec ${quant_spec_files})

target_link_libraries(quant_spec
    QuantLib
    ${LIBXML2_LIBRARIES}
    ${Boost_LIBRARIES})

set(quant_spec_cmd
    ${stage_bin_dir}/quant_spec ${boost_test_parameters})

add_custom_target(run_quant_spec
    COMMAND ${quant_spec_cmd}
    WORKING_DIRECTORY ${stage_bin_dir}
    DEPENDS quant_spec)

add_boost_tests(quant ${quant_spec_files})
