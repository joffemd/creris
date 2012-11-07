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

time_series_set::time_series_set(const std::unordered_map<creris::credit_risk::time_series_configuration_unversioned_key, creris::credit_risk::time_series>& series)
    : series_(series) { }

void time_series_set::swap(time_series_set& other) noexcept {
    using std::swap;
    swap(series_, other.series_);
}

bool time_series_set::operator==(const time_series_set& rhs) const {
    return series_ == rhs.series_;
}

time_series_set& time_series_set::operator=(time_series_set other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }