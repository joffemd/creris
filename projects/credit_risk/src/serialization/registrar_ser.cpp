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
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include "creris/credit_risk/serialization/cauchy_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/fixed_time_series_configuration_ser.hpp"
#include "creris/credit_risk/serialization/formula_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/identity_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/normal_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/uniform_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/variable_time_series_configuration_ser.hpp"
#ifdef __linux__
#include "eos/portable_iarchive.hpp"
#include "eos/portable_oarchive.hpp"
#endif

namespace creris {
namespace credit_risk {

template<typename Archive>
void register_types(Archive& ar) {
    ar.template register_type<creris::credit_risk::cauchy_generator_configuration>();
    ar.template register_type<creris::credit_risk::fixed_time_series_configuration>();
    ar.template register_type<creris::credit_risk::formula_generator_configuration>();
    ar.template register_type<creris::credit_risk::identity_generator_configuration>();
    ar.template register_type<creris::credit_risk::normal_generator_configuration>();
    ar.template register_type<creris::credit_risk::uniform_generator_configuration>();
    ar.template register_type<creris::credit_risk::variable_time_series_configuration>();
}

template void register_types(boost::archive::polymorphic_oarchive& ar);
template void register_types(boost::archive::polymorphic_iarchive& ar);

template void register_types(boost::archive::text_oarchive& ar);
template void register_types(boost::archive::text_iarchive& ar);

template void register_types(boost::archive::binary_oarchive& ar);
template void register_types(boost::archive::binary_iarchive& ar);

template void register_types(boost::archive::xml_oarchive& ar);
template void register_types(boost::archive::xml_iarchive& ar);

#ifdef __linux__
template void register_types(eos::portable_oarchive& ar);
template void register_types(eos::portable_iarchive& ar);
#endif

} }