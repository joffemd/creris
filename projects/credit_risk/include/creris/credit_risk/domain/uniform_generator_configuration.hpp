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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_UNIFORM_GENERATOR_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_UNIFORM_GENERATOR_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "creris/credit_risk/domain/monte_carlo_generator_configuration.hpp"
#include "creris/credit_risk/serialization/uniform_generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Configuration for the monte-carlo generator with a uniform distribution.
 */
class uniform_generator_configuration final : public creris::credit_risk::monte_carlo_generator_configuration {
public:
    uniform_generator_configuration(const uniform_generator_configuration&) = default;
    uniform_generator_configuration(uniform_generator_configuration&&) = default;

public:
    uniform_generator_configuration();

public:
    uniform_generator_configuration(
        const std::string& name,
        const std::string& description,
        const double lower,
        const double upper);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const uniform_generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, uniform_generator_configuration& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    /*
     * @brief Lower value for the distribution.
     */
    /**@{*/
    double lower() const {
        return lower_;
    }

    void lower(const double v) {
        lower_ = v;
    }
    /**@}*/

    /*
     * @brief Upper value for the distribution.
     */
    /**@{*/
    double upper() const {
        return upper_;
    }

    void upper(const double v) {
        upper_ = v;
    }
    /**@}*/

public:
    bool operator==(const uniform_generator_configuration& rhs) const;
    bool operator!=(const uniform_generator_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const creris::credit_risk::generator_configuration& other) const override;

public:
    void swap(uniform_generator_configuration& other) noexcept;
    uniform_generator_configuration& operator=(uniform_generator_configuration other);

private:
    double lower_;
    double upper_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::uniform_generator_configuration& lhs,
    creris::credit_risk::uniform_generator_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
