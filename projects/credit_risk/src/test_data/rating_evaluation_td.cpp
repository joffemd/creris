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
#include "creris/credit_risk/test_data/model_configuration_unversioned_key_td.hpp"
#include "creris/credit_risk/test_data/rating_evaluation_td.hpp"

namespace {

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

creris::credit_risk::model_configuration_unversioned_key
create_creris_credit_risk_model_configuration_unversioned_key(const unsigned int position) {
    return creris::credit_risk::model_configuration_unversioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {

rating_evaluation_generator::rating_evaluation_generator() : position_(0) { }

void rating_evaluation_generator::
populate(const unsigned int position, result_type& v) {
    v.initial_year(create_unsigned_int(position + 0));
    v.projection_years(create_unsigned_int(position + 1));
    v.number_of_trials(create_unsigned_int(position + 2));
    v.model_configuration_key(create_creris_credit_risk_model_configuration_unversioned_key(position + 3));
}

rating_evaluation_generator::result_type
rating_evaluation_generator::create(const unsigned int position) {
    rating_evaluation r;
    rating_evaluation_generator::populate(position, r);
    return r;
}
rating_evaluation_generator::result_type*
rating_evaluation_generator::create_ptr(const unsigned int position) {
    rating_evaluation* p = new rating_evaluation();
    rating_evaluation_generator::populate(position, *p);
    return p;
}

rating_evaluation_generator::result_type
rating_evaluation_generator::operator()() {
    return create(position_++);
}

} }
