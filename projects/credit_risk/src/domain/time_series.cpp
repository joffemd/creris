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
    const creris::credit_risk::time_series_id& id,
    const std::string& name,
    const std::string& data,
    const creris::credit_risk::versioned_key& versioned_key)
    : id_(id),
      name_(name),
      data_(data),
      versioned_key_(versioned_key) { }

void time_series::swap(time_series& other) noexcept {
    using std::swap;
    swap(id_, other.id_);
    swap(name_, other.name_);
    swap(data_, other.data_);
    swap(versioned_key_, other.versioned_key_);
}

bool time_series::operator==(const time_series& rhs) const {
    return id_ == rhs.id_ &&
        name_ == rhs.name_ &&
        data_ == rhs.data_ &&
        versioned_key_ == rhs.versioned_key_;
}

time_series& time_series::operator=(time_series other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }