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
#include "creris/cache/test_data/time_series/versioned/get_td.hpp"
#include "creris/credit_risk/test_data/model_configuration_unversioned_key_td.hpp"

namespace {

creris::credit_risk::model_configuration_unversioned_key
create_creris_credit_risk_model_configuration_unversioned_key(const unsigned int position) {
    return creris::credit_risk::model_configuration_unversioned_key_generator::create(position);
}

}

namespace creris {
namespace cache {
namespace time_series {
namespace versioned {

get_generator::get_generator() : position_(0) { }

void get_generator::
populate(const unsigned int position, result_type& v) {
    v.key(create_creris_credit_risk_model_configuration_unversioned_key(position + 0));
}

get_generator::result_type
get_generator::create(const unsigned int position) {
    get r;
    get_generator::populate(position, r);
    return r;
}
get_generator::result_type*
get_generator::create_ptr(const unsigned int position) {
    get* p = new get();
    get_generator::populate(position, *p);
    return p;
}

get_generator::result_type
get_generator::operator()() {
    return create(position_++);
}

} } } }
