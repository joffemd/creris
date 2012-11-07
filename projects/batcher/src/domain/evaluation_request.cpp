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
#include "creris/batcher/domain/evaluation_request.hpp"

namespace creris {
namespace batcher {

evaluation_request::evaluation_request()
    : request_id_(static_cast<unsigned int>(0)) { }

evaluation_request::evaluation_request(
    const creris::credit_risk::rating_evaluation& rating_evaluation,
    const unsigned int request_id)
    : rating_evaluation_(rating_evaluation),
      request_id_(request_id) { }

void evaluation_request::swap(evaluation_request& other) noexcept {
    using std::swap;
    swap(rating_evaluation_, other.rating_evaluation_);
    swap(request_id_, other.request_id_);
}

bool evaluation_request::operator==(const evaluation_request& rhs) const {
    return rating_evaluation_ == rhs.rating_evaluation_ &&
        request_id_ == rhs.request_id_;
}

evaluation_request& evaluation_request::operator=(evaluation_request other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }