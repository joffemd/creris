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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_CAUCHY_GENERATOR_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_CAUCHY_GENERATOR_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "creris/credit_risk/domain/monte_carlo_generator_configuration.hpp"
#include "creris/credit_risk/serialization/cauchy_generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Configuration for the monte-carlo generator with a cauchy-lorenz distribution.
 */
class cauchy_generator_configuration final : public creris::credit_risk::monte_carlo_generator_configuration {
public:
    cauchy_generator_configuration(const cauchy_generator_configuration&) = default;
    cauchy_generator_configuration(cauchy_generator_configuration&&) = default;

public:
    cauchy_generator_configuration();

public:
    cauchy_generator_configuration(
        const std::string& name,
        const std::string& description,
        const double location,
        const double scale);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cauchy_generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cauchy_generator_configuration& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    /*
     * @brief Location of the peak of the distribution (the mode of the distribution).
     */
    /**@{*/
    double location() const {
        return location_;
    }

    void location(const double v) {
        location_ = v;
    }
    /**@}*/

    /*
     * @brief Specifies half the width of the PDF at half the maximum height.
     */
    /**@{*/
    double scale() const {
        return scale_;
    }

    void scale(const double v) {
        scale_ = v;
    }
    /**@}*/

public:
    bool operator==(const cauchy_generator_configuration& rhs) const;
    bool operator!=(const cauchy_generator_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const creris::credit_risk::generator_configuration& other) const override;

public:
    void swap(cauchy_generator_configuration& other) noexcept;
    cauchy_generator_configuration& operator=(cauchy_generator_configuration other);

private:
    double location_;
    double scale_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::cauchy_generator_configuration& lhs,
    creris::credit_risk::cauchy_generator_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
