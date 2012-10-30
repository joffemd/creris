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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/domain/configuration_id.hpp"
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class configuration final {
public:
    configuration(const configuration&) = default;
    configuration(configuration&&) = default;
    ~configuration() = default;

public:
    configuration();

public:
    configuration(
        const std::string& name,
        const creris::credit_risk::configuration_id& configuration_id,
        const std::string& entity_name,
        const std::string& entity_description,
        const std::string& currency,
        const unsigned int default_number_of_trials,
        const std::string& metrics,
        const std::string& time_series_configurations,
        const std::string& adjustments,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, configuration& v, unsigned int version);

public:
    std::string name() const {
        return name_;
    }

    void name(const std::string& v) {
        name_ = v;
    }

    creris::credit_risk::configuration_id configuration_id() const {
        return configuration_id_;
    }

    void configuration_id(const creris::credit_risk::configuration_id& v) {
        configuration_id_ = v;
    }

    std::string entity_name() const {
        return entity_name_;
    }

    void entity_name(const std::string& v) {
        entity_name_ = v;
    }

    std::string entity_description() const {
        return entity_description_;
    }

    void entity_description(const std::string& v) {
        entity_description_ = v;
    }

    std::string currency() const {
        return currency_;
    }

    void currency(const std::string& v) {
        currency_ = v;
    }

    unsigned int default_number_of_trials() const {
        return default_number_of_trials_;
    }

    void default_number_of_trials(const unsigned int v) {
        default_number_of_trials_ = v;
    }

    /*
     * @brief FIXME: should be of type std::vector<metric>, should get fixed when dogen supports it
     */
    /**@{*/
    std::string metrics() const {
        return metrics_;
    }

    void metrics(const std::string& v) {
        metrics_ = v;
    }
    /**@}*/

    /*
     * @brief FIXME: should be of type std::vector<time_series_configuration>, should be fixed when dogen supports it
     */
    /**@{*/
    std::string time_series_configurations() const {
        return time_series_configurations_;
    }

    void time_series_configurations(const std::string& v) {
        time_series_configurations_ = v;
    }
    /**@}*/

    /*
     * @brief FIXME: should be of type std::vector<adjustment>, should be fixed when dogen supports it
     */
    /**@{*/
    std::string adjustments() const {
        return adjustments_;
    }

    void adjustments(const std::string& v) {
        adjustments_ = v;
    }
    /**@}*/

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const configuration& rhs) const;
    bool operator!=(const configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(configuration& other) noexcept;
    configuration& operator=(configuration other);

private:
    std::string name_;
    creris::credit_risk::configuration_id configuration_id_;
    std::string entity_name_;
    std::string entity_description_;
    std::string currency_;
    unsigned int default_number_of_trials_;
    std::string metrics_;
    std::string time_series_configurations_;
    std::string adjustments_;
    creris::credit_risk::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::configuration& lhs,
    creris::credit_risk::configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
