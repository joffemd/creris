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
#include "creris/credit_risk/domain/uniform_generator_configuration.hpp"
#include "creris/credit_risk/io/monte_carlo_generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

uniform_generator_configuration::uniform_generator_configuration()
    : lower_(static_cast<double>(0)),
      upper_(static_cast<double>(0)) { }

uniform_generator_configuration::uniform_generator_configuration(
    const std::string& name,
    const std::string& description,
    const double lower,
    const double upper)
    : creris::credit_risk::monte_carlo_generator_configuration(name,
      description),
      lower_(lower),
      upper_(upper) { }

void uniform_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"uniform_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    monte_carlo_generator_configuration::to_stream(s);
    s << ", "
      << "\"lower\": " << lower_ << ", "
      << "\"upper\": " << upper_
      << " }";
}

void uniform_generator_configuration::swap(uniform_generator_configuration& other) noexcept {
    monte_carlo_generator_configuration::swap(other);

    using std::swap;
    swap(lower_, other.lower_);
    swap(upper_, other.upper_);
}

bool uniform_generator_configuration::equals(const creris::credit_risk::generator_configuration& other) const {
    const uniform_generator_configuration* const p(dynamic_cast<const uniform_generator_configuration* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool uniform_generator_configuration::operator==(const uniform_generator_configuration& rhs) const {
    return monte_carlo_generator_configuration::compare(rhs) &&
        lower_ == rhs.lower_ &&
        upper_ == rhs.upper_;
}

uniform_generator_configuration& uniform_generator_configuration::operator=(uniform_generator_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }