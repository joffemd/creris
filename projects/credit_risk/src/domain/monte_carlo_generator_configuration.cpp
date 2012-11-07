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
#include "creris/credit_risk/io/generator_configuration_io.hpp"

namespace creris {
namespace credit_risk {

monte_carlo_generator_configuration::monte_carlo_generator_configuration(
    const std::string& name,
    const std::string& description)
    : creris::credit_risk::generator_configuration(name,
      description) { }

void monte_carlo_generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"monte_carlo_generator_configuration\"" << ", "
      << "\"__parent_0__\": ";
    generator_configuration::to_stream(s);
    s << " }";
}

void monte_carlo_generator_configuration::swap(monte_carlo_generator_configuration& other) noexcept {
    generator_configuration::swap(other);

}

bool monte_carlo_generator_configuration::compare(const monte_carlo_generator_configuration& rhs) const {
    return generator_configuration::compare(rhs);
}

} }