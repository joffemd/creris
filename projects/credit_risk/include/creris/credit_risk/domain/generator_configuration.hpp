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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_GENERATOR_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_GENERATOR_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <string>
#include "creris/credit_risk/serialization/generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

/*
 * @brief Configuration for an individual generator.
 *
 * A generator is used to produce time series data. This class models all the
 * parameters required to instatiate the generator.
 */
class generator_configuration {
public:
    generator_configuration() = default;
    generator_configuration(const generator_configuration&) = default;
    generator_configuration(generator_configuration&&) = default;

    virtual ~generator_configuration() noexcept = 0;

public:
    generator_configuration(
        const std::string& name,
        const std::string& description);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, generator_configuration& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

public:
    /*
     * @brief Name of the generator we are configuring.
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
     * @brief Explanation of the purpose of the generator.
     */
    /**@{*/
    std::string description() const {
        return description_;
    }

    void description(const std::string& v) {
        description_ = v;
    }
    /**@}*/

protected:
    bool compare(const generator_configuration& rhs) const;
public:
    virtual bool equals(const generator_configuration& other) const = 0;

protected:
    void swap(generator_configuration& other) noexcept;

private:
    std::string name_;
    std::string description_;
};

inline generator_configuration::~generator_configuration() noexcept { }

inline bool operator==(const generator_configuration& lhs, const generator_configuration& rhs) {
    return lhs.equals(rhs);
}

} }



#endif
