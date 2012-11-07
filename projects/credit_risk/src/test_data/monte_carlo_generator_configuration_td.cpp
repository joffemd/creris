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
#include "creris/credit_risk/test_data/cauchy_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/monte_carlo_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/normal_generator_configuration_td.hpp"
#include "creris/credit_risk/test_data/uniform_generator_configuration_td.hpp"



namespace creris {
namespace credit_risk {


void monte_carlo_generator_configuration_generator::
populate(const unsigned int /*position*/, result_type& /*v*/) {
}

monte_carlo_generator_configuration_generator::result_type*
monte_carlo_generator_configuration_generator::create_ptr(const unsigned int position) {
    if ((position % 2) == 0)
        return creris::credit_risk::normal_generator_configuration_generator::create_ptr(position);
    if ((position % 2) == 1)
        return creris::credit_risk::uniform_generator_configuration_generator::create_ptr(position);
    return creris::credit_risk::cauchy_generator_configuration_generator::create_ptr(position);
}


} }
