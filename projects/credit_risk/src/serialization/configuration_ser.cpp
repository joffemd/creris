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
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include "creris/credit_risk/serialization/adjustment_ser.hpp"
#include "creris/credit_risk/serialization/configuration_id_ser.hpp"
#include "creris/credit_risk/serialization/configuration_ser.hpp"
#include "creris/credit_risk/serialization/metric_ser.hpp"
#include "creris/credit_risk/serialization/versioned_key_ser.hpp"

#ifdef __linux__
#include "eos/portable_iarchive.hpp"
#include "eos/portable_oarchive.hpp"
#endif

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const creris::credit_risk::configuration& v,
    const unsigned int /*version*/) {
    ar << make_nvp("name", v.name_);
    ar << make_nvp("configuration_id", v.configuration_id_);
    ar << make_nvp("entity_name", v.entity_name_);
    ar << make_nvp("entity_description", v.entity_description_);
    ar << make_nvp("currency", v.currency_);
    ar << make_nvp("default_number_of_trials", v.default_number_of_trials_);
    ar << make_nvp("metrics", v.metrics_);
    ar << make_nvp("time_series_configurations", v.time_series_configurations_);
    ar << make_nvp("adjustments", v.adjustments_);
    ar << make_nvp("versioned_key", v.versioned_key_);
}

template<typename Archive>
void load(Archive& ar,
    creris::credit_risk::configuration& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("name", v.name_);
    ar >> make_nvp("configuration_id", v.configuration_id_);
    ar >> make_nvp("entity_name", v.entity_name_);
    ar >> make_nvp("entity_description", v.entity_description_);
    ar >> make_nvp("currency", v.currency_);
    ar >> make_nvp("default_number_of_trials", v.default_number_of_trials_);
    ar >> make_nvp("metrics", v.metrics_);
    ar >> make_nvp("time_series_configurations", v.time_series_configurations_);
    ar >> make_nvp("adjustments", v.adjustments_);
    ar >> make_nvp("versioned_key", v.versioned_key_);
}

} }

BOOST_CLASS_EXPORT_IMPLEMENT(creris::credit_risk::configuration)

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const creris::credit_risk::configuration& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, creris::credit_risk::configuration& v, unsigned int version);

template void save(archive::text_oarchive& ar, const creris::credit_risk::configuration& v, unsigned int version);
template void load(archive::text_iarchive& ar, creris::credit_risk::configuration& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const creris::credit_risk::configuration& v, unsigned int version);
template void load(archive::binary_iarchive& ar, creris::credit_risk::configuration& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const creris::credit_risk::configuration& v, unsigned int version);
template void load(archive::xml_iarchive& ar, creris::credit_risk::configuration& v, unsigned int version);

#ifdef __linux__
template void save(eos::portable_oarchive& ar, const creris::credit_risk::configuration& v, unsigned int version);
template void load(eos::portable_iarchive& ar, creris::credit_risk::configuration& v, unsigned int version);
#endif

} }