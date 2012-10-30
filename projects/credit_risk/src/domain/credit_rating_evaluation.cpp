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
#include "creris/credit_risk/domain/credit_rating_evaluation.hpp"

namespace creris {
namespace credit_risk {

credit_rating_evaluation::credit_rating_evaluation()
    : initial_year_(static_cast<unsigned int>(0)),
      projection_years_(static_cast<unsigned int>(0)),
      number_of_trials_(static_cast<unsigned int>(0)) { }

credit_rating_evaluation::credit_rating_evaluation(
    const unsigned int initial_year,
    const unsigned int projection_years,
    const unsigned int number_of_trials,
    const creris::credit_risk::configuration_id& configuration_id,
    const creris::credit_risk::versioned_key& versioned_key)
    : initial_year_(initial_year),
      projection_years_(projection_years),
      number_of_trials_(number_of_trials),
      configuration_id_(configuration_id),
      versioned_key_(versioned_key) { }

void credit_rating_evaluation::swap(credit_rating_evaluation& other) noexcept {
    using std::swap;
    swap(initial_year_, other.initial_year_);
    swap(projection_years_, other.projection_years_);
    swap(number_of_trials_, other.number_of_trials_);
    swap(configuration_id_, other.configuration_id_);
    swap(versioned_key_, other.versioned_key_);
}

bool credit_rating_evaluation::operator==(const credit_rating_evaluation& rhs) const {
    return initial_year_ == rhs.initial_year_ &&
        projection_years_ == rhs.projection_years_ &&
        number_of_trials_ == rhs.number_of_trials_ &&
        configuration_id_ == rhs.configuration_id_ &&
        versioned_key_ == rhs.versioned_key_;
}

credit_rating_evaluation& credit_rating_evaluation::operator=(credit_rating_evaluation other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }