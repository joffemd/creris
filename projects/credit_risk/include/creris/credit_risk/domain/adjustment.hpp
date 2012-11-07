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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_ADJUSTMENT_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_ADJUSTMENT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include <vector>
#include "creris/credit_risk/domain/adjustment_constraint.hpp"
#include "creris/credit_risk/domain/adjustment_predicate.hpp"
#include "creris/credit_risk/domain/time_series_unversioned_key.hpp"
#include "creris/credit_risk/serialization/adjustment_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Formulas and conditions to be applied to time series values after calculations.
 *
 * For example, this could be used to adjust fiscal series, allowing the
 * limiting of annual surpluses or deficits.
 */
class adjustment final {
public:
    adjustment() = default;
    adjustment(const adjustment&) = default;
    adjustment(adjustment&&) = default;
    ~adjustment() = default;

public:
    adjustment(
        const std::string& name,
        const creris::credit_risk::adjustment_predicate& predicate,
        const creris::credit_risk::time_series_unversioned_key& series_to_adjust,
        const std::vector<creris::credit_risk::adjustment_constraint>& adjustment_constraints,
        const std::vector<creris::credit_risk::time_series_unversioned_key>& dependent_series);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const adjustment& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, adjustment& v, unsigned int version);

public:
    /*
     * @brief A text description of the adjustment.
     */
    /**@{*/
    std::string name() const {
        return name_;
    }

    void name(const std::string& v) {
        name_ = v;
    }
    /**@}*/

    /*
     * @brief Condition to evaluate that determines whether the adjustment is applied.
     */
    /**@{*/
    creris::credit_risk::adjustment_predicate predicate() const {
        return predicate_;
    }

    void predicate(const creris::credit_risk::adjustment_predicate& v) {
        predicate_ = v;
    }
    /**@}*/

    /*
     * @brief Series to adjust so that the predicate matches the threshold.
     */
    /**@{*/
    creris::credit_risk::time_series_unversioned_key series_to_adjust() const {
        return series_to_adjust_;
    }

    void series_to_adjust(const creris::credit_risk::time_series_unversioned_key& v) {
        series_to_adjust_ = v;
    }
    /**@}*/

    /*
     * @brief An additional list of series to change in order to be consistent with the adjusted value.
     *
     * All series in the list will be adjusted pro rata without constraint.
     */
    /**@{*/
    std::vector<creris::credit_risk::adjustment_constraint> adjustment_constraints() const {
        return adjustment_constraints_;
    }

    void adjustment_constraints(const std::vector<creris::credit_risk::adjustment_constraint>& v) {
        adjustment_constraints_ = v;
    }
    /**@}*/

    /*
     * @brief Other series whose values are dependent on series being adjusted.
     *
     * Series listed in this column will be recalculated after the adjustments have been applied.
     */
    /**@{*/
    std::vector<creris::credit_risk::time_series_unversioned_key> dependent_series() const {
        return dependent_series_;
    }

    void dependent_series(const std::vector<creris::credit_risk::time_series_unversioned_key>& v) {
        dependent_series_ = v;
    }
    /**@}*/

public:
    bool operator==(const adjustment& rhs) const;
    bool operator!=(const adjustment& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(adjustment& other) noexcept;
    adjustment& operator=(adjustment other);

private:
    std::string name_;
    creris::credit_risk::adjustment_predicate predicate_;
    creris::credit_risk::time_series_unversioned_key series_to_adjust_;
    std::vector<creris::credit_risk::adjustment_constraint> adjustment_constraints_;
    std::vector<creris::credit_risk::time_series_unversioned_key> dependent_series_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::adjustment& lhs,
    creris::credit_risk::adjustment& rhs) {
    lhs.swap(rhs);
}

}

#endif
