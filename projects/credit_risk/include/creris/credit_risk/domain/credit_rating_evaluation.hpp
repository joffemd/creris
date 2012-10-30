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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_CREDIT_RATING_EVALUATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_CREDIT_RATING_EVALUATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "creris/credit_risk/domain/configuration_id.hpp"
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/credit_rating_evaluation_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class credit_rating_evaluation final {
public:
    credit_rating_evaluation(const credit_rating_evaluation&) = default;
    credit_rating_evaluation(credit_rating_evaluation&&) = default;
    ~credit_rating_evaluation() = default;

public:
    credit_rating_evaluation();

public:
    credit_rating_evaluation(
        const unsigned int initial_year,
        const unsigned int projection_years,
        const unsigned int number_of_trials,
        const creris::credit_risk::configuration_id& configuration_id,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const credit_rating_evaluation& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, credit_rating_evaluation& v, unsigned int version);

public:
    unsigned int initial_year() const {
        return initial_year_;
    }

    void initial_year(const unsigned int v) {
        initial_year_ = v;
    }

    unsigned int projection_years() const {
        return projection_years_;
    }

    void projection_years(const unsigned int v) {
        projection_years_ = v;
    }

    unsigned int number_of_trials() const {
        return number_of_trials_;
    }

    void number_of_trials(const unsigned int v) {
        number_of_trials_ = v;
    }

    creris::credit_risk::configuration_id configuration_id() const {
        return configuration_id_;
    }

    void configuration_id(const creris::credit_risk::configuration_id& v) {
        configuration_id_ = v;
    }

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const credit_rating_evaluation& rhs) const;
    bool operator!=(const credit_rating_evaluation& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(credit_rating_evaluation& other) noexcept;
    credit_rating_evaluation& operator=(credit_rating_evaluation other);

private:
    unsigned int initial_year_;
    unsigned int projection_years_;
    unsigned int number_of_trials_;
    creris::credit_risk::configuration_id configuration_id_;
    creris::credit_risk::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::credit_rating_evaluation& lhs,
    creris::credit_risk::credit_rating_evaluation& rhs) {
    lhs.swap(rhs);
}

}

#endif
