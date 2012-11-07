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
#include "creris/credit_risk/domain/generator_configuration.hpp"
#include "creris/credit_risk/serialization/monte_carlo_generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Configuration for the monte-carlo based generator.
 */
class monte_carlo_generator_configuration : public creris::credit_risk::generator_configuration {
public:
    monte_carlo_generator_configuration() = default;
    monte_carlo_generator_configuration(const monte_carlo_generator_configuration&) = default;
    monte_carlo_generator_configuration(monte_carlo_generator_configuration&&) = default;

    virtual ~monte_carlo_generator_configuration() noexcept = 0;

public:
    monte_carlo_generator_configuration(
        const std::string& name,
        const std::string& description);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const monte_carlo_generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, monte_carlo_generator_configuration& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

protected:
    bool compare(const monte_carlo_generator_configuration& rhs) const;
public:
    virtual bool equals(const creris::credit_risk::generator_configuration& other) const = 0;

protected:
    void swap(monte_carlo_generator_configuration& other) noexcept;

};

inline monte_carlo_generator_configuration::~monte_carlo_generator_configuration() noexcept { }

inline bool operator==(const monte_carlo_generator_configuration& lhs, const monte_carlo_generator_configuration& rhs) {
    return lhs.equals(rhs);
}

} }



#endif
