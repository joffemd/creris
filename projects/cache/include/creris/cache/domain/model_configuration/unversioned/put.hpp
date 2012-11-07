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
#ifndef CRERIS_CACHE_DOMAIN_MODEL_CONFIGURATION_UNVERSIONED_PUT_HPP
#define CRERIS_CACHE_DOMAIN_MODEL_CONFIGURATION_UNVERSIONED_PUT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <vector>
#include "creris/cache/serialization/model_configuration/unversioned/put_fwd_ser.hpp"
#include "creris/credit_risk/domain/model_configuration_unversioned_key.hpp"

namespace creris {
namespace cache {
namespace model_configuration {
namespace unversioned {

class put final {
public:
    put(const put&) = default;
    put(put&&) = default;
    ~put() = default;

public:
    put();

public:
    put(
        const std::vector<creris::credit_risk::model_configuration_unversioned_key>& value,
        const unsigned int time_to_live);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const put& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, put& v, unsigned int version);

public:
    std::vector<creris::credit_risk::model_configuration_unversioned_key> value() const {
        return value_;
    }

    void value(const std::vector<creris::credit_risk::model_configuration_unversioned_key>& v) {
        value_ = v;
    }

    unsigned int time_to_live() const {
        return time_to_live_;
    }

    void time_to_live(const unsigned int v) {
        time_to_live_ = v;
    }

public:
    bool operator==(const put& rhs) const;
    bool operator!=(const put& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(put& other) noexcept;
    put& operator=(put other);

private:
    std::vector<creris::credit_risk::model_configuration_unversioned_key> value_;
    unsigned int time_to_live_;
};

} } } }

namespace std {

template<>
inline void swap(
    creris::cache::model_configuration::unversioned::put& lhs,
    creris::cache::model_configuration::unversioned::put& rhs) {
    lhs.swap(rhs);
}

}

#endif
