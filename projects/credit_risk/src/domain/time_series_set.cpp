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
#include "creris/credit_risk/domain/time_series_set.hpp"

namespace creris {
namespace credit_risk {

time_series_set::time_series_set(
    const std::unordered_map<std::string, creris::credit_risk::time_series_id>& series,
    const creris::credit_risk::versioned_key& versioned_key)
    : series_(series),
      versioned_key_(versioned_key) { }

void time_series_set::swap(time_series_set& other) noexcept {
    using std::swap;
    swap(series_, other.series_);
    swap(versioned_key_, other.versioned_key_);
}

bool time_series_set::operator==(const time_series_set& rhs) const {
    return series_ == rhs.series_ &&
        versioned_key_ == rhs.versioned_key_;
}

time_series_set& time_series_set::operator=(time_series_set other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }