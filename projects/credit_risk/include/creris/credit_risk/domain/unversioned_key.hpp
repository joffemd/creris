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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_UNVERSIONED_KEY_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_UNVERSIONED_KEY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "creris/credit_risk/serialization/unversioned_key_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class unversioned_key final {
public:
    unversioned_key(const unversioned_key&) = default;
    unversioned_key(unversioned_key&&) = default;
    ~unversioned_key() = default;

public:
    unversioned_key();

public:
    explicit unversioned_key(const unsigned int id);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const unversioned_key& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, unversioned_key& v, unsigned int version);

public:
    unsigned int id() const {
        return id_;
    }

    void id(const unsigned int v) {
        id_ = v;
    }

public:
    bool operator==(const unversioned_key& rhs) const;
    bool operator!=(const unversioned_key& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(unversioned_key& other) noexcept;
    unversioned_key& operator=(unversioned_key other);

private:
    unsigned int id_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::unversioned_key& lhs,
    creris::credit_risk::unversioned_key& rhs) {
    lhs.swap(rhs);
}

}

#endif
