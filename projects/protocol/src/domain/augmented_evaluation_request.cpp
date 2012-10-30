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
#include "creris/protocol/domain/augmented_evaluation_request.hpp"
#include "creris/protocol/io/evaluation_request_io.hpp"

namespace creris {
namespace protocol {

augmented_evaluation_request::augmented_evaluation_request(
    const creris::credit_risk::credit_rating_evaluation& credit_rating_evaluation,
    const creris::protocol::versioned_key& versioned_key,
    const std::string& augmenting_attribute)
    : creris::protocol::evaluation_request(credit_rating_evaluation,
      versioned_key),
      augmenting_attribute_(augmenting_attribute) { }

void augmented_evaluation_request::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"augmented_evaluation_request\"" << ", "
      << "\"__parent_0__\": ";
    evaluation_request::to_stream(s);
    s << ", "
      << "\"augmenting_attribute\": " << "\"" << augmenting_attribute_ << "\""
      << " }";
}

void augmented_evaluation_request::swap(augmented_evaluation_request& other) noexcept {
    evaluation_request::swap(other);

    using std::swap;
    swap(augmenting_attribute_, other.augmenting_attribute_);
}

bool augmented_evaluation_request::operator==(const augmented_evaluation_request& rhs) const {
    return evaluation_request::operator==(rhs) &&
        augmenting_attribute_ == rhs.augmenting_attribute_;
}

augmented_evaluation_request& augmented_evaluation_request::operator=(augmented_evaluation_request other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }