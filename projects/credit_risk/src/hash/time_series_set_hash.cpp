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
#include "creris/credit_risk/hash/time_series_configuration_unversioned_key_hash.hpp"
#include "creris/credit_risk/hash/time_series_hash.hpp"
#include "creris/credit_risk/hash/time_series_set_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value)
{
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_std_unordered_map_creris_credit_risk_time_series_configuration_unversioned_key_creris_credit_risk_time_series(const std::unordered_map<creris::credit_risk::time_series_configuration_unversioned_key, creris::credit_risk::time_series>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

}

namespace creris {
namespace credit_risk {

std::size_t time_series_set_hasher::hash(const time_series_set&v) {
    std::size_t seed(0);

    combine(seed, hash_std_unordered_map_creris_credit_risk_time_series_configuration_unversioned_key_creris_credit_risk_time_series(v.series()));
    return seed;
}

} }
