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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_TIME_POINT_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_TIME_POINT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "creris/credit_risk/serialization/time_point_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Point in a time series.
 */
class time_point final {
public:
    time_point(const time_point&) = default;
    time_point(time_point&&) = default;
    ~time_point() = default;

public:
    time_point();

public:
    time_point(
        const double time,
        const double value);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const time_point& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, time_point& v, unsigned int version);

public:
    /*
     * @brief Time at which the observation was recorded.
     *
     * FIXME: boost::date_time
     */
    /**@{*/
    double time() const {
        return time_;
    }

    void time(const double v) {
        time_ = v;
    }
    /**@}*/

    /*
     * @brief Value of the observation.
     */
    /**@{*/
    double value() const {
        return value_;
    }

    void value(const double v) {
        value_ = v;
    }
    /**@}*/

public:
    bool operator==(const time_point& rhs) const;
    bool operator!=(const time_point& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(time_point& other) noexcept;
    time_point& operator=(time_point other);

private:
    double time_;
    double value_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::time_point& lhs,
    creris::credit_risk::time_point& rhs) {
    lhs.swap(rhs);
}

}

#endif
