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
#ifndef CRERIS_CACHE_HASH_TIME_SERIES_RESULTS_HASH_HPP
#define CRERIS_CACHE_HASH_TIME_SERIES_RESULTS_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "creris/cache/domain/time_series/results.hpp"

namespace creris {
namespace cache {
namespace time_series {

class results_hasher {
public:
    static std::size_t hash(const results& v);
};

} } }

namespace std {

template<>
class hash<creris::cache::time_series::results> {
public:
    size_t operator()(const creris::cache::time_series::results& v) const {
        return creris::cache::time_series::results_hasher::hash(v);
    }
};

}
#endif
