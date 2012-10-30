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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_TIME_SERIES_ID_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_TIME_SERIES_ID_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/time_series_id_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class time_series_id final {
public:
    time_series_id() = default;
    time_series_id(const time_series_id&) = default;
    time_series_id(time_series_id&&) = default;
    ~time_series_id() = default;

public:
    time_series_id(
        const std::string& code,
        const std::string& time_series_configuration_id,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const time_series_id& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, time_series_id& v, unsigned int version);

public:
    std::string code() const {
        return code_;
    }

    void code(const std::string& v) {
        code_ = v;
    }

    std::string time_series_configuration_id() const {
        return time_series_configuration_id_;
    }

    void time_series_configuration_id(const std::string& v) {
        time_series_configuration_id_ = v;
    }

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const time_series_id& rhs) const;
    bool operator!=(const time_series_id& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(time_series_id& other) noexcept;
    time_series_id& operator=(time_series_id other);

private:
    std::string code_;
    std::string time_series_configuration_id_;
    creris::credit_risk::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::time_series_id& lhs,
    creris::credit_risk::time_series_id& rhs) {
    lhs.swap(rhs);
}

}

#endif
