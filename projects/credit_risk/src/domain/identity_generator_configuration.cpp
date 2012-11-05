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
#include "creris/credit_risk/domain/identity_generator_configuration.hpp"
#include "creris/credit_risk/io/generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

identity_generator_configuration::identity_generator_configuration(
    const std::string& generator_type,
    const creris::credit_risk::versioned_key& versioned_key)
    : creris::credit_risk::generator_configuration(generator_type,
      versioned_key) { }

void identity_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"identity_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    generator_configuration::to_stream(s);
    s << " }";
}

void identity_generator_configuration::swap(identity_generator_configuration& other) noexcept {
    generator_configuration::swap(other);

}

bool identity_generator_configuration::equals(const creris::credit_risk::generator_configuration& other) const {
    const identity_generator_configuration* const p(dynamic_cast<const identity_generator_configuration* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool identity_generator_configuration::operator==(const identity_generator_configuration& rhs) const {
    return generator_configuration::compare(rhs);
}

identity_generator_configuration& identity_generator_configuration::operator=(identity_generator_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }