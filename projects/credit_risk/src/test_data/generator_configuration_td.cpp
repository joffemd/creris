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
#include "creris/credit_risk/test_data/formula_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/generator_types_td.hpp"
#include "creris/credit_risk/test_data/identity_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/monte_carlo_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/versioned_key_td.hpp"

namespace {

creris::credit_risk::generator_types
create_creris_credit_risk_generator_types(const unsigned int position) {
    return creris::credit_risk::generator_types_generator::create(position);
}

creris::credit_risk::versioned_key
create_creris_credit_risk_versioned_key(const unsigned int position) {
    return creris::credit_risk::versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {


void generator_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.generator_type(create_creris_credit_risk_generator_types(position + 0));
    v.versioned_key(create_creris_credit_risk_versioned_key(position + 1));
}

generator_configuration_generator::result_type*
generator_configuration_generator::create_ptr(const unsigned int position) {
    if ((position % 2) == 0)
        return creris::credit_risk::formula_generator_configuration_generator::create_ptr(position);
    if ((position % 2) == 1)
        return creris::credit_risk::monte_carlo_generator_configuration_generator::create_ptr(position);
    return creris::credit_risk::identity_generator_configuration_generator::create_ptr(position);
}


} }
