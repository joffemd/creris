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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_ADJUSTMENT_PREDICATE_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_ADJUSTMENT_PREDICATE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/domain/relational_operator_types.hpp"
#include "creris/credit_risk/serialization/adjustment_predicate_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Condition that determines if an adjustment should be made or not.
 */
class adjustment_predicate final {
public:
    adjustment_predicate(const adjustment_predicate&) = default;
    adjustment_predicate(adjustment_predicate&&) = default;
    ~adjustment_predicate() = default;

public:
    adjustment_predicate();

public:
    adjustment_predicate(
        const std::string& expression,
        const creris::credit_risk::relational_operator_types& relation_to_threshold,
        const double threshold_value);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const adjustment_predicate& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, adjustment_predicate& v, unsigned int version);

public:
    /*
     * @brief Underlying value used for comparison to treshold.
     *
     * A syntactically valid expression in terms of series that computes an expression to test once all series have been calculated for a given year in a given trial.
     */
    /**@{*/
    std::string expression() const {
        return expression_;
    }

    void expression(const std::string& v) {
        expression_ = v;
    }
    /**@}*/

    /*
     * @brief What comparison to perform between the expression value and the threshold.
     */
    /**@{*/
    creris::credit_risk::relational_operator_types relation_to_threshold() const {
        return relation_to_threshold_;
    }

    void relation_to_threshold(const creris::credit_risk::relational_operator_types& v) {
        relation_to_threshold_ = v;
    }
    /**@}*/

    /*
     * @brief Level beyond which the adjustment will be made.
     */
    /**@{*/
    double threshold_value() const {
        return threshold_value_;
    }

    void threshold_value(const double v) {
        threshold_value_ = v;
    }
    /**@}*/

public:
    bool operator==(const adjustment_predicate& rhs) const;
    bool operator!=(const adjustment_predicate& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(adjustment_predicate& other) noexcept;
    adjustment_predicate& operator=(adjustment_predicate other);

private:
    std::string expression_;
    creris::credit_risk::relational_operator_types relation_to_threshold_;
    double threshold_value_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::adjustment_predicate& lhs,
    creris::credit_risk::adjustment_predicate& rhs) {
    lhs.swap(rhs);
}

}

#endif
