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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_RATING_EVALUATION_RESULTS_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_RATING_EVALUATION_RESULTS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <vector>
#include "creris/credit_risk/domain/time_series.hpp"
#include "creris/credit_risk/serialization/rating_evaluation_results_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class rating_evaluation_results final {
public:
    rating_evaluation_results() = default;
    rating_evaluation_results(const rating_evaluation_results&) = default;
    rating_evaluation_results(rating_evaluation_results&&) = default;
    ~rating_evaluation_results() = default;

public:
    explicit rating_evaluation_results(const std::vector<creris::credit_risk::time_series>& time_series);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const rating_evaluation_results& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, rating_evaluation_results& v, unsigned int version);

public:
    std::vector<creris::credit_risk::time_series> time_series() const {
        return time_series_;
    }

    void time_series(const std::vector<creris::credit_risk::time_series>& v) {
        time_series_ = v;
    }

public:
    bool operator==(const rating_evaluation_results& rhs) const;
    bool operator!=(const rating_evaluation_results& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(rating_evaluation_results& other) noexcept;
    rating_evaluation_results& operator=(rating_evaluation_results other);

private:
    std::vector<creris::credit_risk::time_series> time_series_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::rating_evaluation_results& lhs,
    creris::credit_risk::rating_evaluation_results& rhs) {
    lhs.swap(rhs);
}

}

#endif
