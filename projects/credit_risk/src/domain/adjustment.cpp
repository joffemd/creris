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
#include "creris/credit_risk/domain/adjustment.hpp"

namespace creris {
namespace credit_risk {

adjustment::adjustment()
    : threshold_(static_cast<double>(0)),
      constrain_amount_(static_cast<double>(0)) { }

adjustment::adjustment(
    const std::string& name,
    const std::string& expression,
    const std::string& relation_to_threshold,
    const double threshold,
    const creris::credit_risk::time_series_id& series_to_adjust,
    const std::string& related_series,
    const std::string& constraint_operator,
    const double constrain_amount,
    const std::string& dependent_series,
    const creris::credit_risk::versioned_key& versioned_key)
    : name_(name),
      expression_(expression),
      relation_to_threshold_(relation_to_threshold),
      threshold_(threshold),
      series_to_adjust_(series_to_adjust),
      related_series_(related_series),
      constraint_operator_(constraint_operator),
      constrain_amount_(constrain_amount),
      dependent_series_(dependent_series),
      versioned_key_(versioned_key) { }

void adjustment::swap(adjustment& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(expression_, other.expression_);
    swap(relation_to_threshold_, other.relation_to_threshold_);
    swap(threshold_, other.threshold_);
    swap(series_to_adjust_, other.series_to_adjust_);
    swap(related_series_, other.related_series_);
    swap(constraint_operator_, other.constraint_operator_);
    swap(constrain_amount_, other.constrain_amount_);
    swap(dependent_series_, other.dependent_series_);
    swap(versioned_key_, other.versioned_key_);
}

bool adjustment::operator==(const adjustment& rhs) const {
    return name_ == rhs.name_ &&
        expression_ == rhs.expression_ &&
        relation_to_threshold_ == rhs.relation_to_threshold_ &&
        threshold_ == rhs.threshold_ &&
        series_to_adjust_ == rhs.series_to_adjust_ &&
        related_series_ == rhs.related_series_ &&
        constraint_operator_ == rhs.constraint_operator_ &&
        constrain_amount_ == rhs.constrain_amount_ &&
        dependent_series_ == rhs.dependent_series_ &&
        versioned_key_ == rhs.versioned_key_;
}

adjustment& adjustment::operator=(adjustment other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }