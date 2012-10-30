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
#include "creris/credit_risk/test_data/adjustment_td.hpp"
#include "creris/credit_risk/test_data/time_series_id_td.hpp"
#include "creris/credit_risk/test_data/versioned_key_td.hpp"

namespace {

std::string create_std_string(const std::string& prefix, const unsigned int position) {
    std::ostringstream s;
    s << prefix << "_" << position;

    return s.str();
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

creris::credit_risk::time_series_id
create_creris_credit_risk_time_series_id(const unsigned int position) {
    return creris::credit_risk::time_series_id_generator::create(position);
}

creris::credit_risk::versioned_key
create_creris_credit_risk_versioned_key(const unsigned int position) {
    return creris::credit_risk::versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {

adjustment_generator::adjustment_generator() : position_(0) { }

void adjustment_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_std_string("name", position + 0));
    v.expression(create_std_string("expression", position + 0));
    v.relation_to_threshold(create_std_string("relation_to_threshold", position + 0));
    v.threshold(create_double(position + 0));
    v.series_to_adjust(create_creris_credit_risk_time_series_id(position + 1));
    v.related_series(create_std_string("related_series", position + 1));
    v.constraint_operator(create_std_string("constraint_operator", position + 1));
    v.constrain_amount(create_double(position + 1));
    v.dependent_series(create_std_string("dependent_series", position + 2));
    v.versioned_key(create_creris_credit_risk_versioned_key(position + 2));
}

adjustment_generator::result_type
adjustment_generator::create(const unsigned int position) {
    adjustment r;
    adjustment_generator::populate(position, r);
    return r;
}

adjustment_generator::result_type
adjustment_generator::operator()() {
    return create(position_++);
}

} }
