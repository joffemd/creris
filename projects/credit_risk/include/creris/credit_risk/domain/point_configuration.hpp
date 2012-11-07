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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_POINT_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_POINT_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/serialization/point_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Definition of an individual time point.
 *
 * This includes the label to use for this point.
 */
class point_configuration final {
public:
    point_configuration() = default;
    point_configuration(const point_configuration&) = default;
    point_configuration(point_configuration&&) = default;
    ~point_configuration() = default;

public:
    explicit point_configuration(const std::string& name);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const point_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, point_configuration& v, unsigned int version);

public:
    /*
     * @brief Name of the point.
     *
     * Will be used as a label.
     */
    /**@{*/
    std::string name() const {
        return name_;
    }

    void name(const std::string& v) {
        name_ = v;
    }
    /**@}*/

public:
    bool operator==(const point_configuration& rhs) const;
    bool operator!=(const point_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(point_configuration& other) noexcept;
    point_configuration& operator=(point_configuration other);

private:
    std::string name_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::point_configuration& lhs,
    creris::credit_risk::point_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
