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
#include "creris/cache/serialization/model_configuration/result_ser.hpp"
#include "creris/cache/serialization/model_configuration/unversioned/get_ser.hpp"
#include "creris/cache/serialization/model_configuration/unversioned/put_ser.hpp"
#include "creris/cache/serialization/model_configuration_unversioned_key_ser.hpp"
#include "creris/cache/serialization/model_configuration_versioned_key_ser.hpp"
#include "creris/cache/serialization/ratings_map_unversioned_key_ser.hpp"
#include "creris/cache/serialization/ratings_map_versioned_key_ser.hpp"
#include "creris/cache/serialization/time_series/results_ser.hpp"
#include "creris/cache/serialization/time_series/versioned/get_ser.hpp"
#include "creris/cache/serialization/time_series/versioned/put_ser.hpp"
#include "creris/cache/serialization/time_series_configuration_unversioned_key_ser.hpp"
#include "creris/cache/serialization/time_series_configuration_versioned_key_ser.hpp"
#include "creris/cache/serialization/time_series_unversioned_key_ser.hpp"
#include "creris/cache/serialization/time_series_versioned_key_ser.hpp"
