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
#include "creris/credit_risk/domain/adjustment_predicate.hpp"

namespace creris {
namespace credit_risk {

adjustment_predicate::adjustment_predicate()
    : threshold_value_(static_cast<double>(0)) { }

adjustment_predicate::adjustment_predicate(
    const std::string& expression,
    const creris::credit_risk::relational_operator_types& relation_to_threshold,
    const double threshold_value)
    : expression_(expression),
      relation_to_threshold_(relation_to_threshold),
      threshold_value_(threshold_value) { }

void adjustment_predicate::swap(adjustment_predicate& other) noexcept {
    using std::swap;
    swap(expression_, other.expression_);
    swap(relation_to_threshold_, other.relation_to_threshold_);
    swap(threshold_value_, other.threshold_value_);
}

bool adjustment_predicate::operator==(const adjustment_predicate& rhs) const {
    return expression_ == rhs.expression_ &&
        relation_to_threshold_ == rhs.relation_to_threshold_ &&
        threshold_value_ == rhs.threshold_value_;
}

adjustment_predicate& adjustment_predicate::operator=(adjustment_predicate other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }