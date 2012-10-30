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
#include "creris/credit_risk/domain/time_series_id.hpp"
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/adjustment_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class adjustment final {
public:
    adjustment(const adjustment&) = default;
    adjustment(adjustment&&) = default;
    ~adjustment() = default;

public:
    adjustment();

public:
    adjustment(
        const std::string& name,
        const std::string& expression,
        const std::string& relation_to_threshold,
        const double threshold,
        const creris::credit_risk::time_series_id& series_to_adjust,
        const std::string& related_series,
        const std::string& constraint_operator,
        const double constrain_amount,
        const std::string& dependent_series,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const adjustment& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, adjustment& v, unsigned int version);

public:
    std::string name() const {
        return name_;
    }

    void name(const std::string& v) {
        name_ = v;
    }

    std::string expression() const {
        return expression_;
    }

    void expression(const std::string& v) {
        expression_ = v;
    }

    std::string relation_to_threshold() const {
        return relation_to_threshold_;
    }

    void relation_to_threshold(const std::string& v) {
        relation_to_threshold_ = v;
    }

    double threshold() const {
        return threshold_;
    }

    void threshold(const double v) {
        threshold_ = v;
    }

    creris::credit_risk::time_series_id series_to_adjust() const {
        return series_to_adjust_;
    }

    void series_to_adjust(const creris::credit_risk::time_series_id& v) {
        series_to_adjust_ = v;
    }

    /*
     * @brief FIXME: should be of type std::vector<time_series_id>, should be fixed when dogen supports it
     */
    /**@{*/
    std::string related_series() const {
        return related_series_;
    }

    void related_series(const std::string& v) {
        related_series_ = v;
    }
    /**@}*/

    std::string constraint_operator() const {
        return constraint_operator_;
    }

    void constraint_operator(const std::string& v) {
        constraint_operator_ = v;
    }

    double constrain_amount() const {
        return constrain_amount_;
    }

    void constrain_amount(const double v) {
        constrain_amount_ = v;
    }

    /*
     * @brief FIXME: should be of type std::vector<time_series_id>, should be fixed when dogen supports it
     */
    /**@{*/
    std::string dependent_series() const {
        return dependent_series_;
    }

    void dependent_series(const std::string& v) {
        dependent_series_ = v;
    }
    /**@}*/

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

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
    std::string expression_;
    std::string relation_to_threshold_;
    double threshold_;
    creris::credit_risk::time_series_id series_to_adjust_;
    std::string related_series_;
    std::string constraint_operator_;
    double constrain_amount_;
    std::string dependent_series_;
    creris::credit_risk::versioned_key versioned_key_;
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
