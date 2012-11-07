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
#include "creris/credit_risk/domain/rating_evaluation_results.hpp"

namespace creris {
namespace credit_risk {

rating_evaluation_results::rating_evaluation_results(const std::vector<creris::credit_risk::time_series>& time_series)
    : time_series_(time_series) { }

void rating_evaluation_results::swap(rating_evaluation_results& other) noexcept {
    using std::swap;
    swap(time_series_, other.time_series_);
}

bool rating_evaluation_results::operator==(const rating_evaluation_results& rhs) const {
    return time_series_ == rhs.time_series_;
}

rating_evaluation_results& rating_evaluation_results::operator=(rating_evaluation_results other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }