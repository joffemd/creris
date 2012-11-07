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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_NORMAL_GENERATOR_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_NORMAL_GENERATOR_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "creris/credit_risk/domain/monte_carlo_generator_configuration.hpp"
#include "creris/credit_risk/serialization/normal_generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Configuration for the monte-carlo generator with a normal distribution.
 */
class normal_generator_configuration final : public creris::credit_risk::monte_carlo_generator_configuration {
public:
    normal_generator_configuration(const normal_generator_configuration&) = default;
    normal_generator_configuration(normal_generator_configuration&&) = default;

public:
    normal_generator_configuration();

public:
    normal_generator_configuration(
        const std::string& name,
        const std::string& description,
        const double mean,
        const double standard_deviation);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const normal_generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, normal_generator_configuration& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    /*
     * @brief Mean value for the distribution.
     */
    /**@{*/
    double mean() const {
        return mean_;
    }

    void mean(const double v) {
        mean_ = v;
    }
    /**@}*/

    /*
     * @brief Standard deviation for the distribution.
     */
    /**@{*/
    double standard_deviation() const {
        return standard_deviation_;
    }

    void standard_deviation(const double v) {
        standard_deviation_ = v;
    }
    /**@}*/

public:
    bool operator==(const normal_generator_configuration& rhs) const;
    bool operator!=(const normal_generator_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const creris::credit_risk::generator_configuration& other) const override;

public:
    void swap(normal_generator_configuration& other) noexcept;
    normal_generator_configuration& operator=(normal_generator_configuration other);

private:
    double mean_;
    double standard_deviation_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::normal_generator_configuration& lhs,
    creris::credit_risk::normal_generator_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
