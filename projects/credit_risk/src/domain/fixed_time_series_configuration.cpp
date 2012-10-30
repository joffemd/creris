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
#include "creris/credit_risk/domain/fixed_time_series_configuration.hpp"
#include "creris/credit_risk/io/time_series_configuration_io.hpp"

namespace creris {
namespace credit_risk {

fixed_time_series_configuration::fixed_time_series_configuration()
    : length_(static_cast<unsigned int>(0)) { }

fixed_time_series_configuration::fixed_time_series_configuration(
    const std::string& time_series_configuration_id,
    const std::string& name,
    const std::string& description,
    const std::string& time_axis_label,
    const std::string& value_axis_label,
    const std::string& generator_configuration,
    const creris::credit_risk::versioned_key& versioned_key,
    const unsigned int length,
    const std::string& points_configuration)
    : creris::credit_risk::time_series_configuration(time_series_configuration_id,
      name,
      description,
      time_axis_label,
      value_axis_label,
      generator_configuration,
      versioned_key),
      length_(length),
      points_configuration_(points_configuration) { }

void fixed_time_series_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"fixed_time_series_configuration\"" << ", "
      << "\"__parent_0__\": ";
    time_series_configuration::to_stream(s);
    s << ", "
      << "\"length\": " << length_ << ", "
      << "\"points_configuration\": " << "\"" << points_configuration_ << "\""
      << " }";
}

void fixed_time_series_configuration::swap(fixed_time_series_configuration& other) noexcept {
    time_series_configuration::swap(other);

    using std::swap;
    swap(length_, other.length_);
    swap(points_configuration_, other.points_configuration_);
}

bool fixed_time_series_configuration::operator==(const fixed_time_series_configuration& rhs) const {
    return time_series_configuration::operator==(rhs) &&
        length_ == rhs.length_ &&
        points_configuration_ == rhs.points_configuration_;
}

fixed_time_series_configuration& fixed_time_series_configuration::operator=(fixed_time_series_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }