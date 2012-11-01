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
#include "creris/credit_risk/hash/adjustment_hash.hpp"
#include "creris/credit_risk/hash/time_series_id_hash.hpp"
#include "creris/credit_risk/hash/versioned_key_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value)
{
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_std_vector_creris_credit_risk_time_series_id(const std::vector<creris::credit_risk::time_series_id>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

}

namespace creris {
namespace credit_risk {

std::size_t adjustment_hasher::hash(const adjustment& v) {
    std::size_t seed(0);

    combine(seed, v.name());
    combine(seed, v.expression());
    combine(seed, v.relation_to_threshold());
    combine(seed, v.threshold());
    combine(seed, v.series_to_adjust());
    combine(seed, hash_std_vector_creris_credit_risk_time_series_id(v.related_series()));
    combine(seed, v.constraint_operator());
    combine(seed, v.constrain_amount());
    combine(seed, hash_std_vector_creris_credit_risk_time_series_id(v.dependent_series()));
    combine(seed, v.versioned_key());

    return seed;
}

} }
