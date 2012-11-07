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
#include "creris/credit_risk/test_data/adjustment_predicate_td.hpp"
#include "creris/credit_risk/test_data/relational_operator_types_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
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

adjustment_predicate_generator::adjustment_predicate_generator() : position_(0) { }

void adjustment_predicate_generator::
populate(const unsigned int position, result_type& v) {
    v.expression(create_std_string(position + 0));
    v.relation_to_threshold(create_creris_credit_risk_relational_operator_types(position + 1));
    v.threshold_value(create_double(position + 2));
}

adjustment_predicate_generator::result_type
adjustment_predicate_generator::create(const unsigned int position) {
    adjustment_predicate r;
    adjustment_predicate_generator::populate(position, r);
    return r;
}
adjustment_predicate_generator::result_type*
adjustment_predicate_generator::create_ptr(const unsigned int position) {
    adjustment_predicate* p = new adjustment_predicate();
    adjustment_predicate_generator::populate(position, *p);
    return p;
}

adjustment_predicate_generator::result_type
adjustment_predicate_generator::operator()() {
    return create(position_++);
}

} }
