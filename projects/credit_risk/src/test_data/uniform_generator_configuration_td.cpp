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
#include "creris/credit_risk/test_data/monte_carlo_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/uniform_generator_configuration_td.hpp"

namespace {

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace creris {
namespace credit_risk {

uniform_generator_configuration_generator::uniform_generator_configuration_generator() : position_(0) { }

void uniform_generator_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.lower(create_double(position + 0));
    v.upper(create_double(position + 1));
}

uniform_generator_configuration_generator::result_type
uniform_generator_configuration_generator::create(const unsigned int position) {
    uniform_generator_configuration r;
    creris::credit_risk::monte_carlo_generator_configuration_generator::populate(position, r);
    uniform_generator_configuration_generator::populate(position, r);
    return r;
}
uniform_generator_configuration_generator::result_type*
uniform_generator_configuration_generator::create_ptr(const unsigned int position) {
    uniform_generator_configuration* p = new uniform_generator_configuration();
    uniform_generator_configuration_generator::populate(position, *p);
    return p;
}

uniform_generator_configuration_generator::result_type
uniform_generator_configuration_generator::operator()() {
    return create(position_++);
}

} }
