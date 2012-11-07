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
#include "creris/credit_risk/test_data/adjustment_constraint_td.hpp"
#include "creris/credit_risk/test_data/relational_operator_types_td.hpp"
#include "creris/credit_risk/test_data/time_series_unversioned_key_td.hpp"

namespace {

creris::credit_risk::time_series_unversioned_key
create_creris_credit_risk_time_series_unversioned_key(const unsigned int position) {
    return creris::credit_risk::time_series_unversioned_key_generator::create(position);
}

std::vector<creris::credit_risk::time_series_unversioned_key> create_std_vector_creris_credit_risk_time_series_unversioned_key(unsigned int position) {
    std::vector<creris::credit_risk::time_series_unversioned_key> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_time_series_unversioned_key(position + i));
    }
    return r;
}

creris::credit_risk::relational_operator_types
create_creris_credit_risk_relational_operator_types(const unsigned int position) {
    return creris::credit_risk::relational_operator_types_generator::create(position);
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace creris {
namespace credit_risk {

adjustment_constraint_generator::adjustment_constraint_generator() : position_(0) { }

void adjustment_constraint_generator::
populate(const unsigned int position, result_type& v) {
    v.related_series(create_std_vector_creris_credit_risk_time_series_unversioned_key(position + 0));
    v.constraint_operator(create_creris_credit_risk_relational_operator_types(position + 1));
    v.constraint_amount(create_double(position + 2));
}

adjustment_constraint_generator::result_type
adjustment_constraint_generator::create(const unsigned int position) {
    adjustment_constraint r;
    adjustment_constraint_generator::populate(position, r);
    return r;
}
adjustment_constraint_generator::result_type*
adjustment_constraint_generator::create_ptr(const unsigned int position) {
    adjustment_constraint* p = new adjustment_constraint();
    adjustment_constraint_generator::populate(position, *p);
    return p;
}

adjustment_constraint_generator::result_type
adjustment_constraint_generator::operator()() {
    return create(position_++);
}

} }
