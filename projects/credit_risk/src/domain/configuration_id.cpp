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
#include "creris/credit_risk/domain/configuration_id.hpp"

namespace creris {
namespace credit_risk {

configuration_id::configuration_id(
    const std::string& code,
    const creris::credit_risk::versioned_key& versioned_key)
    : code_(code),
      versioned_key_(versioned_key) { }

void configuration_id::swap(configuration_id& other) noexcept {
    using std::swap;
    swap(code_, other.code_);
    swap(versioned_key_, other.versioned_key_);
}

bool configuration_id::operator==(const configuration_id& rhs) const {
    return code_ == rhs.code_ &&
        versioned_key_ == rhs.versioned_key_;
}

configuration_id& configuration_id::operator=(configuration_id other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }