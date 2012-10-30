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
#include "creris/credit_risk/test_data/time_series_configuration_td.hpp"
#include "creris/credit_risk/test_data/versioned_key_td.hpp"

namespace {

std::string create_std_string(const std::string& prefix, const unsigned int position) {
    std::ostringstream s;
    s << prefix << "_" << position;

    return s.str();
}

creris::credit_risk::versioned_key
create_creris_credit_risk_versioned_key(const unsigned int position) {
    return creris::credit_risk::versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {


void time_series_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.time_series_configuration_id(create_std_string("time_series_configuration_id", position + 0));
    v.name(create_std_string("name", position + 0));
    v.description(create_std_string("description", position + 0));
    v.time_axis_label(create_std_string("time_axis_label", position + 0));
    v.value_axis_label(create_std_string("value_axis_label", position + 0));
    v.generator_configuration(create_std_string("generator_configuration", position + 0));
    v.versioned_key(create_creris_credit_risk_versioned_key(position + 0));
}



} }
