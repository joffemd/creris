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
#include "creris/credit_risk/test_data/time_point_td.hpp"
#include "creris/credit_risk/test_data/time_series_configuration_versioned_key_td.hpp"
#include "creris/credit_risk/test_data/time_series_td.hpp"
#include "creris/credit_risk/test_data/time_series_versioned_key_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

creris::credit_risk::time_series_configuration_versioned_key
create_creris_credit_risk_time_series_configuration_versioned_key(const unsigned int position) {
    return creris::credit_risk::time_series_configuration_versioned_key_generator::create(position);
}

creris::credit_risk::time_point
create_creris_credit_risk_time_point(const unsigned int position) {
    return creris::credit_risk::time_point_generator::create(position);
}

std::vector<creris::credit_risk::time_point> create_std_vector_creris_credit_risk_time_point(unsigned int position) {
    std::vector<creris::credit_risk::time_point> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_time_point(position + i));
    }
    return r;
}

creris::credit_risk::time_series_versioned_key
create_creris_credit_risk_time_series_versioned_key(const unsigned int position) {
    return creris::credit_risk::time_series_versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {

time_series_generator::time_series_generator() : position_(0) { }

void time_series_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_std_string(position + 0));
    v.time_series_configuration(create_creris_credit_risk_time_series_configuration_versioned_key(position + 1));
    v.points(create_std_vector_creris_credit_risk_time_point(position + 2));
    v.versioned_key(create_creris_credit_risk_time_series_versioned_key(position + 3));
}

time_series_generator::result_type
time_series_generator::create(const unsigned int position) {
    time_series r;
    time_series_generator::populate(position, r);
    return r;
}
time_series_generator::result_type*
time_series_generator::create_ptr(const unsigned int position) {
    time_series* p = new time_series();
    time_series_generator::populate(position, *p);
    return p;
}

time_series_generator::result_type
time_series_generator::operator()() {
    return create(position_++);
}

} }
