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

adjustment::adjustment(
    const std::string& name,
    const creris::credit_risk::adjustment_predicate& predicate,
    const creris::credit_risk::time_series_unversioned_key& series_to_adjust,
    const std::vector<creris::credit_risk::adjustment_constraint>& adjustment_constraints,
    const std::vector<creris::credit_risk::time_series_unversioned_key>& dependent_series)
    : name_(name),
      predicate_(predicate),
      series_to_adjust_(series_to_adjust),
      adjustment_constraints_(adjustment_constraints),
      dependent_series_(dependent_series) { }

void adjustment::swap(adjustment& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(predicate_, other.predicate_);
    swap(series_to_adjust_, other.series_to_adjust_);
    swap(adjustment_constraints_, other.adjustment_constraints_);
    swap(dependent_series_, other.dependent_series_);
}

bool adjustment::operator==(const adjustment& rhs) const {
    return name_ == rhs.name_ &&
        predicate_ == rhs.predicate_ &&
        series_to_adjust_ == rhs.series_to_adjust_ &&
        adjustment_constraints_ == rhs.adjustment_constraints_ &&
        dependent_series_ == rhs.dependent_series_;
}

adjustment& adjustment::operator=(adjustment other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }