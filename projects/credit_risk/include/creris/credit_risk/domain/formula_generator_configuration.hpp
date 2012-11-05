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
#ifndef CRERIS_CREDIT_RISK_DOMAIN_FORMULA_GENERATOR_CONFIGURATION_HPP
#define CRERIS_CREDIT_RISK_DOMAIN_FORMULA_GENERATOR_CONFIGURATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <string>
#include "creris/credit_risk/domain/generator_configuration.hpp"
#include "creris/credit_risk/serialization/formula_generator_configuration_fwd_ser.hpp"

namespace creris {
namespace credit_risk {

class formula_generator_configuration final : public creris::credit_risk::generator_configuration {
public:
    formula_generator_configuration(const formula_generator_configuration&) = default;
    formula_generator_configuration(formula_generator_configuration&&) = default;

public:
    formula_generator_configuration();

public:
    formula_generator_configuration(
        const std::string& generator_type,
        const creris::credit_risk::versioned_key& versioned_key,
        const std::string& formula,
        const double initial_value);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const formula_generator_configuration& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, formula_generator_configuration& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    std::string formula() const {
        return formula_;
    }

    void formula(const std::string& v) {
        formula_ = v;
    }

    double initial_value() const {
        return initial_value_;
    }

    void initial_value(const double v) {
        initial_value_ = v;
    }

public:
    bool operator==(const formula_generator_configuration& rhs) const;
    bool operator!=(const formula_generator_configuration& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const creris::credit_risk::generator_configuration& other) const override;

public:
    void swap(formula_generator_configuration& other) noexcept;
    formula_generator_configuration& operator=(formula_generator_configuration other);

private:
    std::string formula_;
    double initial_value_;
};

} }

namespace std {

template<>
inline void swap(
    creris::credit_risk::formula_generator_configuration& lhs,
    creris::credit_risk::formula_generator_configuration& rhs) {
    lhs.swap(rhs);
}

}

#endif
