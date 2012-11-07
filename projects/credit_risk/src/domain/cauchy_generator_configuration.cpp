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
#include "creris/credit_risk/domain/cauchy_generator_configuration.hpp"
#include "creris/credit_risk/io/monte_carlo_generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

cauchy_generator_configuration::cauchy_generator_configuration()
    : location_(static_cast<double>(0)),
      scale_(static_cast<double>(0)) { }

cauchy_generator_configuration::cauchy_generator_configuration(
    const std::string& name,
    const std::string& description,
    const double location,
    const double scale)
    : creris::credit_risk::monte_carlo_generator_configuration(name,
      description),
      location_(location),
      scale_(scale) { }

void cauchy_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"cauchy_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    monte_carlo_generator_configuration::to_stream(s);
    s << ", "
      << "\"location\": " << location_ << ", "
      << "\"scale\": " << scale_
      << " }";
}

void cauchy_generator_configuration::swap(cauchy_generator_configuration& other) noexcept {
    monte_carlo_generator_configuration::swap(other);

    using std::swap;
    swap(location_, other.location_);
    swap(scale_, other.scale_);
}

bool cauchy_generator_configuration::equals(const creris::credit_risk::generator_configuration& other) const {
    const cauchy_generator_configuration* const p(dynamic_cast<const cauchy_generator_configuration* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool cauchy_generator_configuration::operator==(const cauchy_generator_configuration& rhs) const {
    return monte_carlo_generator_configuration::compare(rhs) &&
        location_ == rhs.location_ &&
        scale_ == rhs.scale_;
}

cauchy_generator_configuration& cauchy_generator_configuration::operator=(cauchy_generator_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }