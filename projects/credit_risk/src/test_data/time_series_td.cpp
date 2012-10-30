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
#include "creris/credit_risk/test_data/time_series_id_td.hpp"
#include "creris/credit_risk/test_data/time_series_td.hpp"
#include "creris/credit_risk/test_data/versioned_key_td.hpp"

namespace {

creris::credit_risk::time_series_id
create_creris_credit_risk_time_series_id(const unsigned int position) {
    return creris::credit_risk::time_series_id_generator::create(position);
}

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

time_series_generator::time_series_generator() : position_(0) { }

void time_series_generator::
populate(const unsigned int position, result_type& v) {
    v.id(create_creris_credit_risk_time_series_id(position + 0));
    v.name(create_std_string("name", position + 0));
    v.data(create_std_string("data", position + 0));
    v.versioned_key(create_creris_credit_risk_versioned_key(position + 0));
}

time_series_generator::result_type
time_series_generator::create(const unsigned int position) {
    time_series r;
    time_series_generator::populate(position, r);
    return r;
}

time_series_generator::result_type
time_series_generator::operator()() {
    return create(position_++);
}

} }
