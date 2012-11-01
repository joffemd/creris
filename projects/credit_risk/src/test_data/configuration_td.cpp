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
#include <sstream>
#include "creris/credit_risk/test_data/adjustment_td.hpp"
#include "creris/credit_risk/test_data/configuration_id_td.hpp"
#include "creris/credit_risk/test_data/configuration_td.hpp"
#include "creris/credit_risk/test_data/metric_td.hpp"
#include "creris/credit_risk/test_data/versioned_key_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

creris::credit_risk::configuration_id
create_creris_credit_risk_configuration_id(const unsigned int position) {
    return creris::credit_risk::configuration_id_generator::create(position);
}

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

creris::credit_risk::metric
create_creris_credit_risk_metric(const unsigned int position) {
    return creris::credit_risk::metric_generator::create(position);
}

std::vector<creris::credit_risk::metric> create_std_vector_creris_credit_risk_metric(unsigned int position) {
    std::vector<creris::credit_risk::metric> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_metric(position + i));
    }
    return r;
}

creris::credit_risk::adjustment
create_creris_credit_risk_adjustment(const unsigned int position) {
    return creris::credit_risk::adjustment_generator::create(position);
}

std::vector<creris::credit_risk::adjustment> create_std_vector_creris_credit_risk_adjustment(unsigned int position) {
    std::vector<creris::credit_risk::adjustment> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_creris_credit_risk_adjustment(position + i));
    }
    return r;
}

creris::credit_risk::versioned_key
create_creris_credit_risk_versioned_key(const unsigned int position) {
    return creris::credit_risk::versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {

configuration_generator::configuration_generator() : position_(0) { }

void configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_std_string(position + 0));
    v.configuration_id(create_creris_credit_risk_configuration_id(position + 1));
    v.entity_name(create_std_string(position + 2));
    v.entity_description(create_std_string(position + 3));
    v.currency(create_std_string(position + 4));
    v.default_number_of_trials(create_unsigned_int(position + 5));
    v.metrics(create_std_vector_creris_credit_risk_metric(position + 6));
    v.time_series_configurations(create_std_string(position + 7));
    v.adjustments(create_std_vector_creris_credit_risk_adjustment(position + 8));
    v.versioned_key(create_creris_credit_risk_versioned_key(position + 9));
}

configuration_generator::result_type
configuration_generator::create(const unsigned int position) {
    configuration r;
    configuration_generator::populate(position, r);
    return r;
}

configuration_generator::result_type
configuration_generator::operator()() {
    return create(position_++);
}

} }
