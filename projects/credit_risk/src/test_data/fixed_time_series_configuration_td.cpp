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
#include "creris/credit_risk/test_data/fixed_time_series_configuration_td.hpp"
#include "creris/credit_risk/test_data/point_configuration_td.hpp"
#include "creris/credit_risk/test_data/time_series_configuration_td.hpp"

namespace {

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

creris::credit_risk::point_configuration
create_creris_credit_risk_point_configuration(const unsigned int position) {
    return creris::credit_risk::point_configuration_generator::create(position);
}

std::vector<creris::credit_risk::point_configuration> create_std_vector_creris_credit_risk_point_configuration(unsigned int position) {
    std::vector<creris::credit_risk::point_configuration> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_point_configuration(position + i));
    }
    return r;
}

}

namespace creris {
namespace credit_risk {

fixed_time_series_configuration_generator::fixed_time_series_configuration_generator() : position_(0) { }

void fixed_time_series_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.length(create_unsigned_int(position + 0));
    v.points_configuration(create_std_vector_creris_credit_risk_point_configuration(position + 1));
}

fixed_time_series_configuration_generator::result_type
fixed_time_series_configuration_generator::create(const unsigned int position) {
    fixed_time_series_configuration r;
    creris::credit_risk::time_series_configuration_generator::populate(position, r);
    fixed_time_series_configuration_generator::populate(position, r);
    return r;
}
fixed_time_series_configuration_generator::result_type*
fixed_time_series_configuration_generator::create_ptr(const unsigned int position) {
    fixed_time_series_configuration* p = new fixed_time_series_configuration();
    fixed_time_series_configuration_generator::populate(position, *p);
    return p;
}

fixed_time_series_configuration_generator::result_type
fixed_time_series_configuration_generator::operator()() {
    return create(position_++);
}

} }
