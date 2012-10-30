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
#include "creris/credit_risk/hash/configuration_hash.hpp"
#include "creris/credit_risk/hash/configuration_id_hash.hpp"
#include "creris/credit_risk/hash/versioned_key_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value)
{
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}

namespace creris {
namespace credit_risk {

std::size_t configuration_hasher::hash(const configuration& v) {
    std::size_t seed(0);

    combine(seed, v.name());
    combine(seed, v.configuration_id());
    combine(seed, v.entity_name());
    combine(seed, v.entity_description());
    combine(seed, v.currency());
    combine(seed, v.default_number_of_trials());
    combine(seed, v.metrics());
    combine(seed, v.time_series_configurations());
    combine(seed, v.adjustments());
    combine(seed, v.versioned_key());

    return seed;
}

} }
