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
#ifndef CRERIS_CACHE_DOMAIN_MODEL_CONFIGURATION_RESULT_HPP
#define CRERIS_CACHE_DOMAIN_MODEL_CONFIGURATION_RESULT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <vector>
#include "creris/cache/serialization/model_configuration/result_fwd_ser.hpp"
#include "creris/credit_risk/domain/model_configuration.hpp"

namespace creris {
namespace cache {
namespace model_configuration {

class result final {
public:
    result() = default;
    result(const result&) = default;
    result(result&&) = default;
    ~result() = default;

public:
    explicit result(const std::vector<creris::credit_risk::model_configuration>& model_configurations);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const result& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, result& v, unsigned int version);

public:
    std::vector<creris::credit_risk::model_configuration> model_configurations() const {
        return model_configurations_;
    }

    void model_configurations(const std::vector<creris::credit_risk::model_configuration>& v) {
        model_configurations_ = v;
    }

public:
    bool operator==(const result& rhs) const;
    bool operator!=(const result& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(result& other) noexcept;
    result& operator=(result other);

private:
    std::vector<creris::credit_risk::model_configuration> model_configurations_;
};

} } }

namespace std {

template<>
inline void swap(
    creris::cache::model_configuration::result& lhs,
    creris::cache::model_configuration::result& rhs) {
    lhs.swap(rhs);
}

}

#endif
