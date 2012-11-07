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
#include "creris/batcher/domain/evaluation_response.hpp"

namespace creris {
namespace batcher {

evaluation_response::evaluation_response()
    : request_id_(static_cast<unsigned int>(0)) { }

evaluation_response::evaluation_response(
    const creris::credit_risk::rating_evaluation_results& rating_evaluation_results,
    const unsigned int request_id)
    : rating_evaluation_results_(rating_evaluation_results),
      request_id_(request_id) { }

void evaluation_response::swap(evaluation_response& other) noexcept {
    using std::swap;
    swap(rating_evaluation_results_, other.rating_evaluation_results_);
    swap(request_id_, other.request_id_);
}

bool evaluation_response::operator==(const evaluation_response& rhs) const {
    return rating_evaluation_results_ == rhs.rating_evaluation_results_ &&
        request_id_ == rhs.request_id_;
}

evaluation_response& evaluation_response::operator=(evaluation_response other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }