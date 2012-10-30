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
#include <sstream>
#include "creris/credit_risk/test_data/formula_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/generator_configuration_td.hpp"

namespace {

std::string create_std_string(const std::string& prefix, const unsigned int position) {
    std::ostringstream s;
    s << prefix << "_" << position;

    return s.str();
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace creris {
namespace credit_risk {

formula_generator_configuration_generator::formula_generator_configuration_generator() : position_(0) { }

void formula_generator_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.formula(create_std_string("formula", position + 0));
    v.initial_value(create_double(position + 0));
}

formula_generator_configuration_generator::result_type
formula_generator_configuration_generator::create(const unsigned int position) {
    formula_generator_configuration r;
    creris::credit_risk::generator_configuration_generator::populate(position, r);
    formula_generator_configuration_generator::populate(position, r);
    return r;
}

formula_generator_configuration_generator::result_type
formula_generator_configuration_generator::operator()() {
    return create(position_++);
}

} }
