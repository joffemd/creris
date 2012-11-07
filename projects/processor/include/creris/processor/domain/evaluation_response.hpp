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
#ifndef CRERIS_PROCESSOR_DOMAIN_EVALUATION_RESPONSE_HPP
#define CRERIS_PROCESSOR_DOMAIN_EVALUATION_RESPONSE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "creris/credit_risk/domain/rating_evaluation_results.hpp"
#include "creris/processor/serialization/evaluation_response_fwd_ser.hpp"

namespace creris {
namespace processor {

/*
 * @brief Describes a credit rating evaluation response.
 */
class evaluation_response final {
public:
    evaluation_response(const evaluation_response&) = default;
    evaluation_response(evaluation_response&&) = default;
    ~evaluation_response() = default;

public:
    evaluation_response();

public:
    evaluation_response(
        const creris::credit_risk::rating_evaluation_results& rating_evaluation_results,
        const unsigned int request_id);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const evaluation_response& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, evaluation_response& v, unsigned int version);

public:
    /*
     * @brief All results pertaining to this evaluation.
     */
    /**@{*/
    creris::credit_risk::rating_evaluation_results rating_evaluation_results() const {
        return rating_evaluation_results_;
    }

    void rating_evaluation_results(const creris::credit_risk::rating_evaluation_results& v) {
        rating_evaluation_results_ = v;
    }
    /**@}*/

    /*
     * @brief Request that originated the response, for correlation.
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
    bool operator==(const evaluation_response& rhs) const;
    bool operator!=(const evaluation_response& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(evaluation_response& other) noexcept;
    evaluation_response& operator=(evaluation_response other);

private:
    creris::credit_risk::rating_evaluation_results rating_evaluation_results_;
    unsigned int request_id_;
};

} }

namespace std {

template<>
inline void swap(
    creris::processor::evaluation_response& lhs,
    creris::processor::evaluation_response& rhs) {
    lhs.swap(rhs);
}

}

#endif
