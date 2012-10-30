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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_RATINGS_MAP_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_RATINGS_MAP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/domain/versioned_key.hpp"
#include "creris/credit_risk/serialization/ratings_map_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class ratings_map final {
public:
    ratings_map() = default;
    ratings_map(const ratings_map&) = default;
    ratings_map(ratings_map&&) = default;
    ~ratings_map() = default;

public:
    ratings_map(
        const std::string& series,
        const creris::credit_risk::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const ratings_map& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, ratings_map& v, unsigned int version);

public:
    /*
     * @brief FIXME: type should be std::vector<time_series_id>, should be fixed when dogen supports it
     */
    /**@{*/
    std::string series() const {
        return series_;
    }

    void series(const std::string& v) {
        series_ = v;
    }
    /**@}*/

    creris::credit_risk::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::credit_risk::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const ratings_map& rhs) const;
    bool operator!=(const ratings_map& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(ratings_map& other) noexcept;
    ratings_map& operator=(ratings_map other);

private:
    std::string series_;
    creris::credit_risk::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::ratings_map& lhs,
    creris::credit_risk::ratings_map& rhs) {
    lhs.swap(rhs);
}

}

#endif
