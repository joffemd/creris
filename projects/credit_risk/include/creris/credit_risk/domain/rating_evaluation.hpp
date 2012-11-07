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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_RATING_EVALUATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_RATING_EVALUATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "creris/credit_risk/domain/model_configuration_unversioned_key.hpp"
#include "creris/credit_risk/serialization/rating_evaluation_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Details for an evaluation to perform.
 */
class rating_evaluation final {
public:
    rating_evaluation(const rating_evaluation&) = default;
    rating_evaluation(rating_evaluation&&) = default;
    ~rating_evaluation() = default;

public:
    rating_evaluation();

public:
    rating_evaluation(
        const unsigned int initial_year,
        const unsigned int projection_years,
        const unsigned int number_of_trials,
        const creris::credit_risk::model_configuration_unversioned_key& model_configuration_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const rating_evaluation& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, rating_evaluation& v, unsigned int version);

public:
    /*
     * @brief Fiscal year associated with the base year of the analysis.
     *
     * This is referred to as "Year 0" in the models tab. In the projection output, years are numbered sequentially beginning with this initial year.  This field must be a four digit numeric.  If a government entity uses the form FY 2012-2013, that should be entered as 2013 in this field.
     */
    /**@{*/
    unsigned int initial_year() const {
        return initial_year_;
    }

    void initial_year(const unsigned int v) {
        initial_year_ = v;
    }
    /**@}*/

    /*
     * @brief Number of years beyond the initial year that will be analyzed
     *
     * For example, if the Initial Year is 2011 and a value of 30 is entered for "Projection Years", the period analyzed will be 2012-2041.  Values for 2011 will also be displayed in the Projection output.
     */
    /**@{*/
    unsigned int projection_years() const {
        return projection_years_;
    }

    void projection_years(const unsigned int v) {
        projection_years_ = v;
    }
    /**@}*/

    /*
     * @brief Number of simulation trials to run.
     *
     * Please note that there is no limit, but there is a correlation
     * between number of simulations and run time.
     */
    /**@{*/
    unsigned int number_of_trials() const {
        return number_of_trials_;
    }

    void number_of_trials(const unsigned int v) {
        number_of_trials_ = v;
    }
    /**@}*/

    /*
     * @brief Which model configuration to use for this run.
     */
    /**@{*/
    creris::credit_risk::model_configuration_unversioned_key model_configuration_key() const {
        return model_configuration_key_;
    }

    void model_configuration_key(const creris::credit_risk::model_configuration_unversioned_key& v) {
        model_configuration_key_ = v;
    }
    /**@}*/

public:
    bool operator==(const rating_evaluation& rhs) const;
    bool operator!=(const rating_evaluation& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(rating_evaluation& other) noexcept;
    rating_evaluation& operator=(rating_evaluation other);

private:
    unsigned int initial_year_;
    unsigned int projection_years_;
    unsigned int number_of_trials_;
    creris::credit_risk::model_configuration_unversioned_key model_configuration_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::rating_evaluation& lhs,
    creris::credit_risk::rating_evaluation& rhs) {
    lhs.swap(rhs);
}

}

#endif
