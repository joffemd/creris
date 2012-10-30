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
#include <ostream>
#include "creris/credit_risk/io/time_series_set_io.hpp"
#include "creris/credit_risk/io/versioned_key_io.hpp"

namespace creris {
namespace credit_risk {

std::ostream& operator<<(std::ostream& s, const time_series_set& v) {
    s << " { "
      << "\"__type__\": " << "\"time_series_set\"" << ", "
      << "\"series\": " << "\"" << v.series() << "\"" << ", "
      << "\"versioned_key\": " << v.versioned_key()
      << " }";
    return(s);
}

} }