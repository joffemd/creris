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
#ifndef CRERIS_CACHE_SERIALIZATION_RATINGS_MAP_UNVERSIONED_KEY_SER_HPP
#define CRERIS_CACHE_SERIALIZATION_RATINGS_MAP_UNVERSIONED_KEY_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "creris/credit_risk/domain/ratings_map_unversioned_key.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(creris::credit_risk::ratings_map_unversioned_key)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const creris::credit_risk::ratings_map_unversioned_key& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, creris::credit_risk::ratings_map_unversioned_key& v, unsigned int version);

} }

#endif
