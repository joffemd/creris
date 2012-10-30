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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_METRIC_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_METRIC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/domain/time_series_id.hpp"
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/metric_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class metric final {
public:
    metric(const metric&) = default;
    metric(metric&&) = default;
    ~metric() = default;

public:
    metric();

public:
    metric(
        const std::string& name,
        const creris::credit_risk::time_series_id& time_series_id,
        const double threshold_level,
        const std::string& relation_to_threshold,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const metric& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, metric& v, unsigned int version);

public:
    std::string name() const {
        return name_;
    }

    void name(const std::string& v) {
        name_ = v;
    }

    creris::credit_risk::time_series_id time_series_id() const {
        return time_series_id_;
    }

    void time_series_id(const creris::credit_risk::time_series_id& v) {
        time_series_id_ = v;
    }

    double threshold_level() const {
        return threshold_level_;
    }

    void threshold_level(const double v) {
        threshold_level_ = v;
    }

    std::string relation_to_threshold() const {
        return relation_to_threshold_;
    }

    void relation_to_threshold(const std::string& v) {
        relation_to_threshold_ = v;
    }

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const metric& rhs) const;
    bool operator!=(const metric& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(metric& other) noexcept;
    metric& operator=(metric other);

private:
    std::string name_;
    creris::credit_risk::time_series_id time_series_id_;
    double threshold_level_;
    std::string relation_to_threshold_;
    creris::credit_risk::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::metric& lhs,
    creris::credit_risk::metric& rhs) {
    lhs.swap(rhs);
}

}

#endif
