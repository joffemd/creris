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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_ENTITY_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_ENTITY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "creris/credit_risk/serialization/entity_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class entity final {
public:
    entity() = default;
    entity(const entity&) = default;
    entity(entity&&) = default;
    ~entity() = default;

public:
    entity(
        const std::string& name,
        const std::string& description);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const entity& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, entity& v, unsigned int version);

public:
    /*
     * @brief Name of the entity being analysed.
     */
    /**@{*/
    std::string name() const {
        return name_;
    }

    void name(const std::string& v) {
        name_ = v;
    }
    /**@}*/

    /*
     * @brief Short description of the entity.
     */
    /**@{*/
    std::string description() const {
        return description_;
    }

    void description(const std::string& v) {
        description_ = v;
    }
    /**@}*/

public:
    bool operator==(const entity& rhs) const;
    bool operator!=(const entity& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(entity& other) noexcept;
    entity& operator=(entity other);

private:
    std::string name_;
    std::string description_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::entity& lhs,
    creris::credit_risk::entity& rhs) {
    lhs.swap(rhs);
}

}

#endif
