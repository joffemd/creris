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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_CONFIGURATION_ID_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_CONFIGURATION_ID_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/configuration_id_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class configuration_id final {
public:
    configuration_id() = default;
    configuration_id(const configuration_id&) = default;
    configuration_id(configuration_id&&) = default;
    ~configuration_id() = default;

public:
    configuration_id(
        const std::string& code,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const configuration_id& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, configuration_id& v, unsigned int version);

public:
    std::string code() const {
        return code_;
    }

    void code(const std::string& v) {
        code_ = v;
    }

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const configuration_id& rhs) const;
    bool operator!=(const configuration_id& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(configuration_id& other) noexcept;
    configuration_id& operator=(configuration_id other);

private:
    std::string code_;
    creris::credit_risk::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::configuration_id& lhs,
    creris::credit_risk::configuration_id& rhs) {
    lhs.swap(rhs);
}

}

#endif
