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
#include "creris/credit_risk/domain/normal_generator_configuration.hpp"
#include "creris/credit_risk/io/monte_carlo_generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

normal_generator_configuration::normal_generator_configuration()
    : mean_(static_cast<double>(0)),
      standard_deviation_(static_cast<double>(0)) { }

normal_generator_configuration::normal_generator_configuration(
    const std::string& name,
    const std::string& description,
    const double mean,
    const double standard_deviation)
    : creris::credit_risk::monte_carlo_generator_configuration(name,
      description),
      mean_(mean),
      standard_deviation_(standard_deviation) { }

void normal_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"normal_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    monte_carlo_generator_configuration::to_stream(s);
    s << ", "
      << "\"mean\": " << mean_ << ", "
      << "\"standard_deviation\": " << standard_deviation_
      << " }";
}

void normal_generator_configuration::swap(normal_generator_configuration& other) noexcept {
    monte_carlo_generator_configuration::swap(other);

    using std::swap;
    swap(mean_, other.mean_);
    swap(standard_deviation_, other.standard_deviation_);
}

bool normal_generator_configuration::equals(const creris::credit_risk::generator_configuration& other) const {
    const normal_generator_configuration* const p(dynamic_cast<const normal_generator_configuration* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool normal_generator_configuration::operator==(const normal_generator_configuration& rhs) const {
    return monte_carlo_generator_configuration::compare(rhs) &&
        mean_ == rhs.mean_ &&
        standard_deviation_ == rhs.standard_deviation_;
}

normal_generator_configuration& normal_generator_configuration::operator=(normal_generator_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }