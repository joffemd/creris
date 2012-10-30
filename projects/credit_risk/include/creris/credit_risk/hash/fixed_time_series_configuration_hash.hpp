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
#ifndef CRERIS_CREDIT_RISK_HASH_FIXED_TIME_SERIES_CONFIGURATION_HASH_HPP
#define CRERIS_CREDIT_RISK_HASH_FIXED_TIME_SERIES_CONFIGURATION_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "creris/credit_risk/domain/fixed_time_series_configuration.hpp"

namespace creris {
namespace credit_risk {

class fixed_time_series_configuration_hasher {
public:
    static std::size_t hash(const fixed_time_series_configuration& v);
};

} }

namespace std {

template<>
class hash<creris::credit_risk::fixed_time_series_configuration> {
public:
    size_t operator()(const creris::credit_risk::fixed_time_series_configuration& v) const {
        return creris::credit_risk::fixed_time_series_configuration_hasher::hash(v);
    }
};

}
#endif
