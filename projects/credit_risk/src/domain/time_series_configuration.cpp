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
#include "creris/credit_risk/domain/time_series_configuration.hpp"
#include "creris/credit_risk/io/versioned_key_io.hpp"

namespace creris {
namespace credit_risk {

time_series_configuration::time_series_configuration(
    const std::string& time_series_configuration_id,
    const std::string& name,
    const std::string& description,
    const std::string& time_axis_label,
    const std::string& value_axis_label,
    const std::string& generator_configuration,
    const creris::credit_risk::versioned_key& versioned_key)
    : time_series_configuration_id_(time_series_configuration_id),
      name_(name),
      description_(description),
      time_axis_label_(time_axis_label),
      value_axis_label_(value_axis_label),
      generator_configuration_(generator_configuration),
      versioned_key_(versioned_key) { }

void time_series_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"time_series_configuration\"" << ", "
      << "\"time_series_configuration_id\": " << "\"" << time_series_configuration_id_ << "\"" << ", "
      << "\"name\": " << "\"" << name_ << "\"" << ", "
      << "\"description\": " << "\"" << description_ << "\"" << ", "
      << "\"time_axis_label\": " << "\"" << time_axis_label_ << "\"" << ", "
      << "\"value_axis_label\": " << "\"" << value_axis_label_ << "\"" << ", "
      << "\"generator_configuration\": " << "\"" << generator_configuration_ << "\"" << ", "
      << "\"versioned_key\": " << versioned_key_
      << " }";
}

void time_series_configuration::swap(time_series_configuration& other) noexcept {
    using std::swap;
    swap(time_series_configuration_id_, other.time_series_configuration_id_);
    swap(name_, other.name_);
    swap(description_, other.description_);
    swap(time_axis_label_, other.time_axis_label_);
    swap(value_axis_label_, other.value_axis_label_);
    swap(generator_configuration_, other.generator_configuration_);
    swap(versioned_key_, other.versioned_key_);
}

bool time_series_configuration::compare(const time_series_configuration& rhs) const {
    return time_series_configuration_id_ == rhs.time_series_configuration_id_ &&
        name_ == rhs.name_ &&
        description_ == rhs.description_ &&
        time_axis_label_ == rhs.time_axis_label_ &&
        value_axis_label_ == rhs.value_axis_label_ &&
        generator_configuration_ == rhs.generator_configuration_ &&
        versioned_key_ == rhs.versioned_key_;
}

} }