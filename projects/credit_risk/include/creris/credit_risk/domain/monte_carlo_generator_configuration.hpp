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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_MONTE_CARLO_GENERATOR_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_MONTE_CARLO_GENERATOR_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "creris/credit_risk/domain/distribution_types.hpp"
#include "creris/credit_risk/domain/generator_configuration.hpp"
#include "creris/credit_risk/serialization/monte_carlo_generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class monte_carlo_generator_configuration final : public creris::credit_risk::generator_configuration {
public:
    monte_carlo_generator_configuration(const monte_carlo_generator_configuration&) = default;
    monte_carlo_generator_configuration(monte_carlo_generator_configuration&&) = default;

public:
    monte_carlo_generator_configuration();

public:
    monte_carlo_generator_configuration(
        const creris::credit_risk::generator_types& generator_type,
        const creris::credit_risk::versioned_key& versioned_key,
        const double mean,
        const double standard_deviation,
        const creris::credit_risk::distribution_types& distribution_type);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const monte_carlo_generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, monte_carlo_generator_configuration& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    double mean() const {
        return mean_;
    }

    void mean(const double v) {
        mean_ = v;
    }

    double standard_deviation() const {
        return standard_deviation_;
    }

    void standard_deviation(const double v) {
        standard_deviation_ = v;
    }

    creris::credit_risk::distribution_types distribution_type() const {
        return distribution_type_;
    }

    void distribution_type(const creris::credit_risk::distribution_types& v) {
        distribution_type_ = v;
    }

public:
    bool operator==(const monte_carlo_generator_configuration& rhs) const;
    bool operator!=(const monte_carlo_generator_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const creris::credit_risk::generator_configuration& other) const override;

public:
    void swap(monte_carlo_generator_configuration& other) noexcept;
    monte_carlo_generator_configuration& operator=(monte_carlo_generator_configuration other);

private:
    double mean_;
    double standard_deviation_;
    creris::credit_risk::distribution_types distribution_type_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::monte_carlo_generator_configuration& lhs,
    creris::credit_risk::monte_carlo_generator_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
