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
#include "creris/credit_risk/domain/generator_configuration.hpp"

namespace creris {
namespace credit_risk {

generator_configuration::generator_configuration(
    const std::string& name,
    const std::string& description)
    : name_(name),
      description_(description) { }

void generator_configuration::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"generator_configuration\"" << ", "
      << "\"name\": " << "\"" << name_ << "\"" << ", "
      << "\"description\": " << "\"" << description_ << "\""
      << " }";
}

void generator_configuration::swap(generator_configuration& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(description_, other.description_);
}

bool generator_configuration::compare(const generator_configuration& rhs) const {
    return name_ == rhs.name_ &&
        description_ == rhs.description_;
}

} }