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
#include "creris/credit_risk/test_data/adjustment_constraint_td.hpp"
#include "creris/credit_risk/test_data/adjustment_predicate_td.hpp"
#include "creris/credit_risk/test_data/adjustment_td.hpp"
#include "creris/credit_risk/test_data/time_series_unversioned_key_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

creris::credit_risk::adjustment_predicate
create_creris_credit_risk_adjustment_predicate(const unsigned int position) {
    return creris::credit_risk::adjustment_predicate_generator::create(position);
}

creris::credit_risk::time_series_unversioned_key
create_creris_credit_risk_time_series_unversioned_key(const unsigned int position) {
    return creris::credit_risk::time_series_unversioned_key_generator::create(position);
}

creris::credit_risk::adjustment_constraint
create_creris_credit_risk_adjustment_constraint(const unsigned int position) {
    return creris::credit_risk::adjustment_constraint_generator::create(position);
}

std::vector<creris::credit_risk::adjustment_constraint> create_std_vector_creris_credit_risk_adjustment_constraint(unsigned int position) {
    std::vector<creris::credit_risk::adjustment_constraint> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_adjustment_constraint(position + i));
    }
    return r;
}

std::vector<creris::credit_risk::time_series_unversioned_key> create_std_vector_creris_credit_risk_time_series_unversioned_key(unsigned int position) {
    std::vector<creris::credit_risk::time_series_unversioned_key> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_time_series_unversioned_key(position + i));
    }
    return r;
}

}

namespace creris {
namespace credit_risk {

adjustment_generator::adjustment_generator() : position_(0) { }

void adjustment_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_std_string(position + 0));
    v.predicate(create_creris_credit_risk_adjustment_predicate(position + 1));
    v.series_to_adjust(create_creris_credit_risk_time_series_unversioned_key(position + 2));
    v.adjustment_constraints(create_std_vector_creris_credit_risk_adjustment_constraint(position + 3));
    v.dependent_series(create_std_vector_creris_credit_risk_time_series_unversioned_key(position + 4));
}

adjustment_generator::result_type
adjustment_generator::create(const unsigned int position) {
    adjustment r;
    adjustment_generator::populate(position, r);
    return r;
}
adjustment_generator::result_type*
adjustment_generator::create_ptr(const unsigned int position) {
    adjustment* p = new adjustment();
    adjustment_generator::populate(position, *p);
    return p;
}

adjustment_generator::result_type
adjustment_generator::operator()() {
    return create(position_++);
}

} }
