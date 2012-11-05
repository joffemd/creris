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
#include "creris/credit_risk/domain/monte_carlo_generator_configuration.hpp"
#include "creris/credit_risk/io/distribution_types_io.hpp"
#include "creris/credit_risk/io/generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

monte_carlo_generator_configuration::monte_carlo_generator_configuration()
    : mean_(static_cast<double>(0)),
      standard_deviation_(static_cast<double>(0)) { }

monte_carlo_generator_configuration::monte_carlo_generator_configuration(
    const creris::credit_risk::generator_types& generator_type,
    const creris::credit_risk::versioned_key& versioned_key,
    const double mean,
    const double standard_deviation,
    const creris::credit_risk::distribution_types& distribution_type)
    : creris::credit_risk::generator_configuration(generator_type,
      versioned_key),
      mean_(mean),
      standard_deviation_(standard_deviation),
      distribution_type_(distribution_type) { }

void monte_carlo_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"monte_carlo_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    generator_configuration::to_stream(s);
    s << ", "
      << "\"mean\": " << mean_ << ", "
      << "\"standard_deviation\": " << standard_deviation_ << ", "
      << "\"distribution_type\": " << distribution_type_
      << " }";
}

void monte_carlo_generator_configuration::swap(monte_carlo_generator_configuration& other) noexcept {
    generator_configuration::swap(other);

    using std::swap;
    swap(mean_, other.mean_);
    swap(standard_deviation_, other.standard_deviation_);
    swap(distribution_type_, other.distribution_type_);
}

bool monte_carlo_generator_configuration::equals(const creris::credit_risk::generator_configuration& other) const {
    const monte_carlo_generator_configuration* const p(dynamic_cast<const monte_carlo_generator_configuration* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool monte_carlo_generator_configuration::operator==(const monte_carlo_generator_configuration& rhs) const {
    return generator_configuration::compare(rhs) &&
        mean_ == rhs.mean_ &&
        standard_deviation_ == rhs.standard_deviation_ &&
        distribution_type_ == rhs.distribution_type_;
}

monte_carlo_generator_configuration& monte_carlo_generator_configuration::operator=(monte_carlo_generator_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }