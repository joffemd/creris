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
#include "creris/cache/domain/time_series/versioned/put.hpp"

namespace creris {
namespace cache {
namespace time_series {
namespace versioned {

put::put()
    : time_to_live_(static_cast<unsigned int>(0)) { }

put::put(
    const creris::credit_risk::model_configuration_unversioned_key& key,
    const std::vector<creris::credit_risk::time_series>& values,
    const unsigned int time_to_live)
    : key_(key),
      values_(values),
      time_to_live_(time_to_live) { }

void put::swap(put& other) noexcept {
    using std::swap;
    swap(key_, other.key_);
    swap(values_, other.values_);
    swap(time_to_live_, other.time_to_live_);
}

bool put::operator==(const put& rhs) const {
    return key_ == rhs.key_ &&
        values_ == rhs.values_ &&
        time_to_live_ == rhs.time_to_live_;
}

put& put::operator=(put other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} } } }