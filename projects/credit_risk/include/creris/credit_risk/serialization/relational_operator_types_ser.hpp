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
#ifndef CRERIS_CREDIT_RISK_SERIALIZATION_RELATIONAL_OPERATOR_TYPES_SER_HPP
#define CRERIS_CREDIT_RISK_SERIALIZATION_RELATIONAL_OPERATOR_TYPES_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/nvp.hpp>
#include "creris/credit_risk/domain/relational_operator_types.hpp"

template<class Archive>
void serialize(Archive& ar, creris::credit_risk::relational_operator_types& v, unsigned int /*version*/){
    using boost::serialization::make_nvp;
    ar & make_nvp("relational_operator_types", v);
}

#endif
