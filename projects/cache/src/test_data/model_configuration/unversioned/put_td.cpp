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
#include "creris/cache/test_data/model_configuration/unversioned/put_td.hpp"
#include "creris/credit_risk/test_data/model_configuration_unversioned_key_td.hpp"

namespace {

creris::credit_risk::model_configuration_unversioned_key
create_creris_credit_risk_model_configuration_unversioned_key(const unsigned int position) {
    return creris::credit_risk::model_configuration_unversioned_key_generator::create(position);
}

std::vector<creris::credit_risk::model_configuration_unversioned_key> create_std_vector_creris_credit_risk_model_configuration_unversioned_key(unsigned int position) {
    std::vector<creris::credit_risk::model_configuration_unversioned_key> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_model_configuration_unversioned_key(position + i));
    }
    return r;
}

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

}

namespace creris {
namespace cache {
namespace model_configuration {
namespace unversioned {

put_generator::put_generator() : position_(0) { }

void put_generator::
populate(const unsigned int position, result_type& v) {
    v.value(create_std_vector_creris_credit_risk_model_configuration_unversioned_key(position + 0));
    v.time_to_live(create_unsigned_int(position + 1));
}

put_generator::result_type
put_generator::create(const unsigned int position) {
    put r;
    put_generator::populate(position, r);
    return r;
}
put_generator::result_type*
put_generator::create_ptr(const unsigned int position) {
    put* p = new put();
    put_generator::populate(position, *p);
    return p;
}

put_generator::result_type
put_generator::operator()() {
    return create(position_++);
}

} } } }
