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
#ifndef CRERIS_PROTOCOL_DOMAIN_EVALUATION_REQUEST_HPP
#define CRERIS_PROTOCOL_DOMAIN_EVALUATION_REQUEST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <string>
#include "creris/protocol/domain/versioned_key.hpp"
#include "creris/protocol/serialization/evaluation_request_fwd_ser.hpp"

namespace creris {
namespace protocol {

class evaluation_request {
public:
    evaluation_request() = default;
    evaluation_request(const evaluation_request&) = default;
    evaluation_request(evaluation_request&&) = default;

    virtual ~evaluation_request() noexcept = 0;

public:
    evaluation_request(
        const std::string& credit_rating_evaluation,
        const creris::protocol::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const evaluation_request& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, evaluation_request& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

public:
    /*
     * @brief credit_risk::credit_rating_evaluation
     */
    /**@{*/
    std::string credit_rating_evaluation() const {
        return credit_rating_evaluation_;
    }

    void credit_rating_evaluation(const std::string& v) {
        credit_rating_evaluation_ = v;
    }
    /**@}*/

    creris::protocol::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const creris::protocol::versioned_key& v) {
        versioned_key_ = v;
    }

protected:
    bool operator==(const evaluation_request& rhs) const;
    bool operator!=(const evaluation_request& rhs) const {
        return !this->operator==(rhs);
    }

protected:
    void swap(evaluation_request& other) noexcept;

private:
    std::string credit_rating_evaluation_;
    creris::protocol::versioned_key versioned_key_;
};


inline evaluation_request::~evaluation_request() noexcept { }

} }



#endif
