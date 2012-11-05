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
#include "creris/credit_risk/domain/formula_generator_configuration.hpp"
#include "creris/credit_risk/io/generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

formula_generator_configuration::formula_generator_configuration()
    : initial_value_(static_cast<double>(0)) { }

formula_generator_configuration::formula_generator_configuration(
    const creris::credit_risk::generator_types& generator_type,
    const creris::credit_risk::versioned_key& versioned_key,
    const std::string& formula,
    const double initial_value)
    : creris::credit_risk::generator_configuration(generator_type,
      versioned_key),
      formula_(formula),
      initial_value_(initial_value) { }

void formula_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"formula_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    generator_configuration::to_stream(s);
    s << ", "
      << "\"formula\": " << "\"" << formula_ << "\"" << ", "
      << "\"initial_value\": " << initial_value_
      << " }";
}

void formula_generator_configuration::swap(formula_generator_configuration& other) noexcept {
    generator_configuration::swap(other);

    using std::swap;
    swap(formula_, other.formula_);
    swap(initial_value_, other.initial_value_);
}

bool formula_generator_configuration::equals(const creris::credit_risk::generator_configuration& other) const {
    const formula_generator_configuration* const p(dynamic_cast<const formula_generator_configuration* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool formula_generator_configuration::operator==(const formula_generator_configuration& rhs) const {
    return generator_configuration::compare(rhs) &&
        formula_ == rhs.formula_ &&
        initial_value_ == rhs.initial_value_;
}

formula_generator_configuration& formula_generator_configuration::operator=(formula_generator_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }