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
#ifndef CRERIS_CACHE_DOMAIN_TIME_SERIES_VERSIONED_PUT_HPP
#define CRERIS_CACHE_DOMAIN_TIME_SERIES_VERSIONED_PUT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <vector>
#include "creris/cache/serialization/time_series/versioned/put_fwd_ser.hpp"
#include "creris/credit_risk/domain/model_configuration_unversioned_key.hpp"
#include "creris/credit_risk/domain/time_series.hpp"

namespace creris {
namespace cache {
namespace time_series {
namespace versioned {

class put final {
public:
    put(const put&) = default;
    put(put&&) = default;
    ~put() = default;

public:
    put();

public:
    put(
        const creris::credit_risk::model_configuration_unversioned_key& key,
        const std::vector<creris::credit_risk::time_series>& values,
        const unsigned int time_to_live);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const put& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, put& v, unsigned int version);

public:
    creris::credit_risk::model_configuration_unversioned_key key() const {
        return key_;
    }

    void key(const creris::credit_risk::model_configuration_unversioned_key& v) {
        key_ = v;
    }

    std::vector<creris::credit_risk::time_series> values() const {
        return values_;
    }

    void values(const std::vector<creris::credit_risk::time_series>& v) {
        values_ = v;
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
    creris::credit_risk::model_configuration_unversioned_key key_;
    std::vector<creris::credit_risk::time_series> values_;
    unsigned int time_to_live_;
};

} } } }

namespace std {

template<>
inline void swap(
    creris::cache::time_series::versioned::put& lhs,
    creris::cache::time_series::versioned::put& rhs) {
    lhs.swap(rhs);
}

}

#endif
