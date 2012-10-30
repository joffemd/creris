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
#include "creris/credit_risk/io/credit_rating_evaluation_io.hpp"
#include "creris/protocol/domain/evaluation_request.hpp"
#include "creris/protocol/io/versioned_key_io.hpp"

namespace creris {
namespace protocol {

evaluation_request::evaluation_request(
    const creris::credit_risk::credit_rating_evaluation& credit_rating_evaluation,
    const creris::protocol::versioned_key& versioned_key)
    : credit_rating_evaluation_(credit_rating_evaluation),
      versioned_key_(versioned_key) { }

void evaluation_request::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"evaluation_request\"" << ", "
      << "\"credit_rating_evaluation\": " << credit_rating_evaluation_ << ", "
      << "\"versioned_key\": " << versioned_key_
      << " }";
}

void evaluation_request::swap(evaluation_request& other) noexcept {
    using std::swap;
    swap(credit_rating_evaluation_, other.credit_rating_evaluation_);
    swap(versioned_key_, other.versioned_key_);
}

bool evaluation_request::operator==(const evaluation_request& rhs) const {
    return credit_rating_evaluation_ == rhs.credit_rating_evaluation_ &&
        versioned_key_ == rhs.versioned_key_;
}

} }