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
#include "creris/credit_risk/domain/time_series_id.hpp"

namespace creris {
namespace credit_risk {

time_series_id::time_series_id(
    const std::string& code,
    const std::string& time_series_configuration_id,
    const creris::credit_risk::versioned_key& versioned_key)
    : code_(code),
      time_series_configuration_id_(time_series_configuration_id),
      versioned_key_(versioned_key) { }

void time_series_id::swap(time_series_id& other) noexcept {
    using std::swap;
    swap(code_, other.code_);
    swap(time_series_configuration_id_, other.time_series_configuration_id_);
    swap(versioned_key_, other.versioned_key_);
}

bool time_series_id::operator==(const time_series_id& rhs) const {
    return code_ == rhs.code_ &&
        time_series_configuration_id_ == rhs.time_series_configuration_id_ &&
        versioned_key_ == rhs.versioned_key_;
}

time_series_id& time_series_id::operator=(time_series_id other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }