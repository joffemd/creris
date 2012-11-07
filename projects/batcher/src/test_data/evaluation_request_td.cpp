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
#include "creris/batcher/test_data/evaluation_request_td.hpp"
#include "creris/credit_risk/test_data/rating_evaluation_td.hpp"

namespace {

creris::credit_risk::rating_evaluation
create_creris_credit_risk_rating_evaluation(const unsigned int position) {
    return creris::credit_risk::rating_evaluation_generator::create(position);
}

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

}

namespace creris {
namespace batcher {

evaluation_request_generator::evaluation_request_generator() : position_(0) { }

void evaluation_request_generator::
populate(const unsigned int position, result_type& v) {
    v.rating_evaluation(create_creris_credit_risk_rating_evaluation(position + 0));
    v.request_id(create_unsigned_int(position + 1));
}

evaluation_request_generator::result_type
evaluation_request_generator::create(const unsigned int position) {
    evaluation_request r;
    evaluation_request_generator::populate(position, r);
    return r;
}
evaluation_request_generator::result_type*
evaluation_request_generator::create_ptr(const unsigned int position) {
    evaluation_request* p = new evaluation_request();
    evaluation_request_generator::populate(position, *p);
    return p;
}

evaluation_request_generator::result_type
evaluation_request_generator::operator()() {
    return create(position_++);
}

} }
