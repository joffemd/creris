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
#ifndef CRERIS_PROTOCOL_DOMAIN_AUGMENTED_EVALUATION_REQUEST_HPP
#define CRERIS_PROTOCOL_DOMAIN_AUGMENTED_EVALUATION_REQUEST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <string>
#include "creris/protocol/domain/evaluation_request.hpp"
#include "creris/protocol/serialization/augmented_evaluation_request_fwd_ser.hpp"

namespace creris {
namespace protocol {

class augmented_evaluation_request final : public creris::protocol::evaluation_request {
public:
    augmented_evaluation_request() = default;
    augmented_evaluation_request(const augmented_evaluation_request&) = default;
    augmented_evaluation_request(augmented_evaluation_request&&) = default;

public:
    augmented_evaluation_request(
        const creris::credit_risk::credit_rating_evaluation& credit_rating_evaluation,
        const creris::protocol::versioned_key& versioned_key,
        const std::string& augmenting_attribute);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const augmented_evaluation_request& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, augmented_evaluation_request& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    std::string augmenting_attribute() const {
        return augmenting_attribute_;
    }

    void augmenting_attribute(const std::string& v) {
        augmenting_attribute_ = v;
    }

public:
    bool operator==(const augmented_evaluation_request& rhs) const;
    bool operator!=(const augmented_evaluation_request& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(augmented_evaluation_request& other) noexcept;
    augmented_evaluation_request& operator=(augmented_evaluation_request other);

private:
    std::string augmenting_attribute_;
};

} }

namespace std {

template<>
inline void swap(
    creris::protocol::augmented_evaluation_request& lhs,
    creris::protocol::augmented_evaluation_request& rhs) {
    lhs.swap(rhs);
}

}

#endif
