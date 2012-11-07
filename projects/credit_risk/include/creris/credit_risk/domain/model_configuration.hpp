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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_MODEL_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_MODEL_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include "creris/credit_risk/domain/adjustment.hpp"
#include "creris/credit_risk/domain/entity.hpp"
#include "creris/credit_risk/domain/metric.hpp"
#include "creris/credit_risk/domain/model_configuration_versioned_key.hpp"
#include "creris/credit_risk/domain/time_series_configuration.hpp"
#include "creris/credit_risk/serialization/model_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief User defined model configuration.
 *
 * A model configuration provides a template to execute credit
 * rating evaluations for a given entity. It contains all the model parameters
 * required to perform an evaluation.
 */
class model_configuration final {
public:
    model_configuration(const model_configuration&) = default;
    model_configuration(model_configuration&&) = default;
    ~model_configuration() = default;

public:
    model_configuration();

public:
    model_configuration(
        const std::string& name,
        const std::string& description,
        const creris::credit_risk::entity& entity,
        const std::string& currency,
        const unsigned int default_number_of_trials,
        const std::vector<creris::credit_risk::metric>& metrics,
        const std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> >& time_series_configuration_set,
        const std::vector<creris::credit_risk::adjustment>& adjustments,
        const creris::credit_risk::model_configuration_versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const model_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, model_configuration& v, unsigned int version);

public:
    /*
     * @brief User friendly name for the model configuration.
     *
     * It is displayed in the user interface to allow users to choose
     * which configuration to use.
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
     * @brief Short description of the model.
     */
    /**@{*/
    std::string description() const {
        return description_;
    }

    void description(const std::string& v) {
        description_ = v;
    }
    /**@}*/

    /*
     * @brief Entity being analysed.
     */
    /**@{*/
    creris::credit_risk::entity entity() const {
        return entity_;
    }

    void entity(const creris::credit_risk::entity& v) {
        entity_ = v;
    }
    /**@}*/

    /*
     * @brief Currency in which values are denominated.
     *
     * All models are assumed to use a single currency.
     */
    /**@{*/
    std::string currency() const {
        return currency_;
    }

    void currency(const std::string& v) {
        currency_ = v;
    }
    /**@}*/

    /*
     * @brief Number of simulation trials to run if the user does not supply it.
     *
     * Please note that there is no limit, but there is a correlation
     * between number of simulations and run time.
     */
    /**@{*/
    unsigned int default_number_of_trials() const {
        return default_number_of_trials_;
    }

    void default_number_of_trials(const unsigned int v) {
        default_number_of_trials_ = v;
    }
    /**@}*/

    /*
     * @brief Set of predicates used to determine when a default occurs.
     */
    /**@{*/
    std::vector<creris::credit_risk::metric> metrics() const {
        return metrics_;
    }

    void metrics(const std::vector<creris::credit_risk::metric>& v) {
        metrics_ = v;
    }
    /**@}*/

    /*
     * @brief Configuration for all time series required by this model.
     */
    /**@{*/
    std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> > time_series_configuration_set() const {
        return time_series_configuration_set_;
    }

    void time_series_configuration_set(const std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> >& v) {
        time_series_configuration_set_ = v;
    }
    /**@}*/

    /*
     * @brief All adjustments to be applied to this model configuration.
     */
    /**@{*/
    std::vector<creris::credit_risk::adjustment> adjustments() const {
        return adjustments_;
    }

    void adjustments(const std::vector<creris::credit_risk::adjustment>& v) {
        adjustments_ = v;
    }
    /**@}*/

    creris::credit_risk::model_configuration_versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::model_configuration_versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const model_configuration& rhs) const;
    bool operator!=(const model_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(model_configuration& other) noexcept;
    model_configuration& operator=(model_configuration other);

private:
    std::string name_;
    std::string description_;
    creris::credit_risk::entity entity_;
    std::string currency_;
    unsigned int default_number_of_trials_;
    std::vector<creris::credit_risk::metric> metrics_;
    std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> > time_series_configuration_set_;
    std::vector<creris::credit_risk::adjustment> adjustments_;
    creris::credit_risk::model_configuration_versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::model_configuration& lhs,
    creris::credit_risk::model_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
