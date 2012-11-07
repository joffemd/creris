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
#include "creris/credit_risk/domain/time_point.hpp"

namespace creris {
namespace credit_risk {

time_point::time_point()
    : time_(static_cast<double>(0)),
      value_(static_cast<double>(0)) { }

time_point::time_point(
    const double time,
    const double value)
    : time_(time),
      value_(value) { }

void time_point::swap(time_point& other) noexcept {
    using std::swap;
    swap(time_, other.time_);
    swap(value_, other.value_);
}

bool time_point::operator==(const time_point& rhs) const {
    return time_ == rhs.time_ &&
        value_ == rhs.value_;
}

time_point& time_point::operator=(time_point other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }