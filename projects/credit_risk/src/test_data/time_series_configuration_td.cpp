/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <sstream>
#include "creris/credit_risk/test_data/fixed_time_series_configuration_td.hpp"
#include "creris/credit_risk/test_data/generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/time_series_configuration_td.hpp"
#include "creris/credit_risk/test_data/time_series_configuration_versioned_key_td.hpp"
#include "creris/credit_risk/test_data/variable_time_series_configuration_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

creris::credit_risk::generator_configuration*
create_creris_credit_risk_generator_configuration_ptr(const unsigned int position) {
    return creris::credit_risk::generator_configuration_generator::create_ptr(position);
}

boost::shared_ptr<creris::credit_risk::generator_configuration>
create_boost_shared_ptr_creris_credit_risk_generator_configuration(unsigned int position) {
    boost::shared_ptr<creris::credit_risk::generator_configuration> r(
        create_creris_credit_risk_generator_configuration_ptr(position));
    return r;
}

creris::credit_risk::time_series_configuration_versioned_key
create_creris_credit_risk_time_series_configuration_versioned_key(const unsigned int position) {
    return creris::credit_risk::time_series_configuration_versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {


void time_series_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_std_string(position + 0));
    v.description(create_std_string(position + 1));
    v.time_axis_label(create_std_string(position + 2));
    v.value_axis_label(create_std_string(position + 3));
    v.generator_configuration(create_boost_shared_ptr_creris_credit_risk_generator_configuration(position + 4));
    v.versioned_key(create_creris_credit_risk_time_series_configuration_versioned_key(position + 5));
}

time_series_configuration_generator::result_type*
time_series_configuration_generator::create_ptr(const unsigned int position) {
    if ((position % 1) == 0)
        return creris::credit_risk::variable_time_series_configuration_generator::create_ptr(position);
    return creris::credit_risk::fixed_time_series_configuration_generator::create_ptr(position);
}


} }
