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
#ifndef CRERIS_PROCESSOR_DOMAIN_EVALUATION_REQUEST_HPP
#define CRERIS_PROCESSOR_DOMAIN_EVALUATION_REQUEST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "creris/credit_risk/domain/rating_evaluation.hpp"
#include "creris/processor/serialization/evaluation_request_fwd_ser.hpp"

namespace creris {
namespace processor {

/*
 * @brief Describes a credit rating evaluation request.
 */
class evaluation_request final {
public:
    evaluation_request(const evaluation_request&) = default;
    evaluation_request(evaluation_request&&) = default;
    ~evaluation_request() = default;

public:
    evaluation_request();

public:
    evaluation_request(
        const creris::credit_risk::rating_evaluation& rating_evaluation,
        const unsigned int request_id);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const evaluation_request& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, evaluation_request& v, unsigned int version);

public:
    /*
     * @brief All the details for the rating evaluation.
     */
    /**@{*/
    creris::credit_risk::rating_evaluation rating_evaluation() const {
        return rating_evaluation_;
    }

    void rating_evaluation(const creris::credit_risk::rating_evaluation& v) {
        rating_evaluation_ = v;
    }
    /**@}*/

    /*
     * @brief Request number for correlation purposes.
     */
    /**@{*/
    unsigned int request_id() const {
        return request_id_;
    }

    void request_id(const unsigned int v) {
        request_id_ = v;
    }
    /**@}*/

public:
    bool operator==(const evaluation_request& rhs) const;
    bool operator!=(const evaluation_request& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(evaluation_request& other) noexcept;
    evaluation_request& operator=(evaluation_request other);

private:
    creris::credit_risk::rating_evaluation rating_evaluation_;
    unsigned int request_id_;
};

} }

namespace std {

template<>
inline void swap(
    creris::processor::evaluation_request& lhs,
    creris::processor::evaluation_request& rhs) {
    lhs.swap(rhs);
}

}

#endif
