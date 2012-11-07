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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_ADJUSTMENT_CONSTRAINT_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_ADJUSTMENT_CONSTRAINT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <vector>
#include "creris/credit_risk/domain/relational_operator_types.hpp"
#include "creris/credit_risk/domain/time_series_unversioned_key.hpp"
#include "creris/credit_risk/serialization/adjustment_constraint_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Constraints to updating related series.
 */
class adjustment_constraint final {
public:
    adjustment_constraint(const adjustment_constraint&) = default;
    adjustment_constraint(adjustment_constraint&&) = default;
    ~adjustment_constraint() = default;

public:
    adjustment_constraint();

public:
    adjustment_constraint(
        const std::vector<creris::credit_risk::time_series_unversioned_key>& related_series,
        const creris::credit_risk::relational_operator_types& constraint_operator,
        const double constraint_amount);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const adjustment_constraint& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, adjustment_constraint& v, unsigned int version);

public:
    /*
     * @brief An additional list of series to change in order to be consistent with the adjusted value.
     *
     * All series in the list will be adjusted pro rata without constraint.
     */
    /**@{*/
    std::vector<creris::credit_risk::time_series_unversioned_key> related_series() const {
        return related_series_;
    }

    void related_series(const std::vector<creris::credit_risk::time_series_unversioned_key>& v) {
        related_series_ = v;
    }
    /**@}*/

    /*
     * @brief Relational operator that should be used in conjunction with the Constraint Amount to set a limit to the amount of the series is adjusted.
     *
     * Acceptable values are < , <= , > and >=. Only applicable to the first metric.
     */
    /**@{*/
    creris::credit_risk::relational_operator_types constraint_operator() const {
        return constraint_operator_;
    }

    void constraint_operator(const creris::credit_risk::relational_operator_types& v) {
        constraint_operator_ = v;
    }
    /**@}*/

    /*
     * @brief Number, series member or compound term specifying the upper or lower bound for the adjusted value.
     *
     * A typical use of this field (and the operator field above) is to prevent a series from swiching signs.
     */
    /**@{*/
    double constraint_amount() const {
        return constraint_amount_;
    }

    void constraint_amount(const double v) {
        constraint_amount_ = v;
    }
    /**@}*/

public:
    bool operator==(const adjustment_constraint& rhs) const;
    bool operator!=(const adjustment_constraint& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(adjustment_constraint& other) noexcept;
    adjustment_constraint& operator=(adjustment_constraint other);

private:
    std::vector<creris::credit_risk::time_series_unversioned_key> related_series_;
    creris::credit_risk::relational_operator_types constraint_operator_;
    double constraint_amount_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::adjustment_constraint& lhs,
    creris::credit_risk::adjustment_constraint& rhs) {
    lhs.swap(rhs);
}

}

#endif
