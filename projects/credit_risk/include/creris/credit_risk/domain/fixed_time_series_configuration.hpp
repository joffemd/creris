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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_FIXED_TIME_SERIES_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_FIXED_TIME_SERIES_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <vector>
#include "creris/credit_risk/domain/point_configuration.hpp"
#include "creris/credit_risk/domain/time_series_configuration.hpp"
#include "creris/credit_risk/serialization/fixed_time_series_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Configuration for a time series with a defined number of points.
 */
class fixed_time_series_configuration final : public creris::credit_risk::time_series_configuration {
public:
    fixed_time_series_configuration(const fixed_time_series_configuration&) = default;
    fixed_time_series_configuration(fixed_time_series_configuration&&) = default;

public:
    fixed_time_series_configuration();

public:
    fixed_time_series_configuration(
        const std::string& name,
        const std::string& description,
        const std::string& time_axis_label,
        const std::string& value_axis_label,
        const boost::shared_ptr<creris::credit_risk::generator_configuration>& generator_configuration,
        const creris::credit_risk::time_series_configuration_versioned_key& versioned_key,
        const unsigned int length,
        const std::vector<creris::credit_risk::point_configuration>& points_configuration);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const fixed_time_series_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, fixed_time_series_configuration& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    /*
     * @brief Number of points in time series.
     */
    /**@{*/
    unsigned int length() const {
        return length_;
    }

    void length(const unsigned int v) {
        length_ = v;
    }
    /**@}*/

    /*
     * @brief Configuration for all points in the series.
     */
    /**@{*/
    std::vector<creris::credit_risk::point_configuration> points_configuration() const {
        return points_configuration_;
    }

    void points_configuration(const std::vector<creris::credit_risk::point_configuration>& v) {
        points_configuration_ = v;
    }
    /**@}*/

public:
    bool operator==(const fixed_time_series_configuration& rhs) const;
    bool operator!=(const fixed_time_series_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const creris::credit_risk::time_series_configuration& other) const override;

public:
    void swap(fixed_time_series_configuration& other) noexcept;
    fixed_time_series_configuration& operator=(fixed_time_series_configuration other);

private:
    unsigned int length_;
    std::vector<creris::credit_risk::point_configuration> points_configuration_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::fixed_time_series_configuration& lhs,
    creris::credit_risk::fixed_time_series_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
