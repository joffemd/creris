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
#include "creris/credit_risk/test_data/time_series_configuration_unversioned_key_td.hpp"
#include "creris/credit_risk/test_data/time_series_set_td.hpp"
#include "creris/credit_risk/test_data/time_series_td.hpp"

namespace {

creris::credit_risk::time_series_configuration_unversioned_key
create_creris_credit_risk_time_series_configuration_unversioned_key(const unsigned int position) {
    return creris::credit_risk::time_series_configuration_unversioned_key_generator::create(position);
}

creris::credit_risk::time_series
create_creris_credit_risk_time_series(const unsigned int position) {
    return creris::credit_risk::time_series_generator::create(position);
}

std::unordered_map<creris::credit_risk::time_series_configuration_unversioned_key, creris::credit_risk::time_series> create_std_unordered_map_creris_credit_risk_time_series_configuration_unversioned_key_creris_credit_risk_time_series(unsigned int position) {
    std::unordered_map<creris::credit_risk::time_series_configuration_unversioned_key, creris::credit_risk::time_series> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.insert(std::make_pair(create_creris_credit_risk_time_series_configuration_unversioned_key(position + i), create_creris_credit_risk_time_series(position + i)));
    }
    return r;
}

}

namespace creris {
namespace credit_risk {

time_series_set_generator::time_series_set_generator() : position_(0) { }

void time_series_set_generator::
populate(const unsigned int position, result_type& v) {
    v.series(create_std_unordered_map_creris_credit_risk_time_series_configuration_unversioned_key_creris_credit_risk_time_series(position + 0));
}

time_series_set_generator::result_type
time_series_set_generator::create(const unsigned int position) {
    time_series_set r;
    time_series_set_generator::populate(position, r);
    return r;
}
time_series_set_generator::result_type*
time_series_set_generator::create_ptr(const unsigned int position) {
    time_series_set* p = new time_series_set();
    time_series_set_generator::populate(position, *p);
    return p;
}

time_series_set_generator::result_type
time_series_set_generator::operator()() {
    return create(position_++);
}

} }
