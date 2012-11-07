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
#include "creris/credit_risk/domain/time_series.hpp"

namespace creris {
namespace credit_risk {

time_series::time_series(
    const std::string& name,
    const creris::credit_risk::time_series_configuration_versioned_key& time_series_configuration,
    const std::vector<creris::credit_risk::time_point>& points,
    const creris::credit_risk::time_series_versioned_key& versioned_key)
    : name_(name),
      time_series_configuration_(time_series_configuration),
      points_(points),
      versioned_key_(versioned_key) { }

void time_series::swap(time_series& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(time_series_configuration_, other.time_series_configuration_);
    swap(points_, other.points_);
    swap(versioned_key_, other.versioned_key_);
}

bool time_series::operator==(const time_series& rhs) const {
    return name_ == rhs.name_ &&
        time_series_configuration_ == rhs.time_series_configuration_ &&
        points_ == rhs.points_ &&
        versioned_key_ == rhs.versioned_key_;
}

time_series& time_series::operator=(time_series other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }