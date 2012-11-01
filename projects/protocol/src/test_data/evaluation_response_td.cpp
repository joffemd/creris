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
#include "creris/protocol/test_data/evaluation_response_td.hpp"
#include "creris/protocol/test_data/versioned_key_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

creris::protocol::versioned_key
create_creris_protocol_versioned_key(const unsigned int position) {
    return creris::protocol::versioned_key_generator::create(position);
}

}

namespace creris {
namespace protocol {

evaluation_response_generator::evaluation_response_generator() : position_(0) { }

void evaluation_response_generator::
populate(const unsigned int position, result_type& v) {
    v.time_series_set(create_std_string(position + 0));
    v.versioned_key(create_creris_protocol_versioned_key(position + 1));
}

evaluation_response_generator::result_type
evaluation_response_generator::create(const unsigned int position) {
    evaluation_response r;
    evaluation_response_generator::populate(position, r);
    return r;
}

evaluation_response_generator::result_type
evaluation_response_generator::operator()() {
    return create(position_++);
}

} }
