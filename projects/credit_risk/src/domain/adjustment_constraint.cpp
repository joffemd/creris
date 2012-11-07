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
#include "creris/credit_risk/domain/adjustment_constraint.hpp"

namespace creris {
namespace credit_risk {

adjustment_constraint::adjustment_constraint()
    : constraint_amount_(static_cast<double>(0)) { }

adjustment_constraint::adjustment_constraint(
    const std::vector<creris::credit_risk::time_series_unversioned_key>& related_series,
    const creris::credit_risk::relational_operator_types& constraint_operator,
    const double constraint_amount)
    : related_series_(related_series),
      constraint_operator_(constraint_operator),
      constraint_amount_(constraint_amount) { }

void adjustment_constraint::swap(adjustment_constraint& other) noexcept {
    using std::swap;
    swap(related_series_, other.related_series_);
    swap(constraint_operator_, other.constraint_operator_);
    swap(constraint_amount_, other.constraint_amount_);
}

bool adjustment_constraint::operator==(const adjustment_constraint& rhs) const {
    return related_series_ == rhs.related_series_ &&
        constraint_operator_ == rhs.constraint_operator_ &&
        constraint_amount_ == rhs.constraint_amount_;
}

adjustment_constraint& adjustment_constraint::operator=(adjustment_constraint other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }