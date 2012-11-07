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
#include "creris/credit_risk/test_data/entity_td.hpp"
#include "creris/credit_risk/test_data/metric_td.hpp"
#include "creris/credit_risk/test_data/model_configuration_td.hpp"
#include "creris/credit_risk/test_data/model_configuration_versioned_key_td.hpp"
#include "creris/credit_risk/test_data/time_series_configuration_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

creris::credit_risk::entity
create_creris_credit_risk_entity(const unsigned int position) {
    return creris::credit_risk::entity_generator::create(position);
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

creris::credit_risk::time_series_configuration*
create_creris_credit_risk_time_series_configuration_ptr(const unsigned int position) {
    return creris::credit_risk::time_series_configuration_generator::create_ptr(position);
}

boost::shared_ptr<creris::credit_risk::time_series_configuration>
create_boost_shared_ptr_creris_credit_risk_time_series_configuration(unsigned int position) {
    boost::shared_ptr<creris::credit_risk::time_series_configuration> r(
        create_creris_credit_risk_time_series_configuration_ptr(position));
    return r;
}

std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> > create_std_vector_boost_shared_ptr_creris_credit_risk_time_series_configuration_(unsigned int position) {
    std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> > r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_boost_shared_ptr_creris_credit_risk_time_series_configuration(position + i));
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

creris::credit_risk::model_configuration_versioned_key
create_creris_credit_risk_model_configuration_versioned_key(const unsigned int position) {
    return creris::credit_risk::model_configuration_versioned_key_generator::create(position);
}

}

namespace creris {
namespace credit_risk {

model_configuration_generator::model_configuration_generator() : position_(0) { }

void model_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_std_string(position + 0));
    v.description(create_std_string(position + 1));
    v.entity(create_creris_credit_risk_entity(position + 2));
    v.currency(create_std_string(position + 3));
    v.default_number_of_trials(create_unsigned_int(position + 4));
    v.metrics(create_std_vector_creris_credit_risk_metric(position + 5));
    v.time_series_configuration_set(create_std_vector_boost_shared_ptr_creris_credit_risk_time_series_configuration_(position + 6));
    v.adjustments(create_std_vector_creris_credit_risk_adjustment(position + 7));
    v.versioned_key(create_creris_credit_risk_model_configuration_versioned_key(position + 8));
}

model_configuration_generator::result_type
model_configuration_generator::create(const unsigned int position) {
    model_configuration r;
    model_configuration_generator::populate(position, r);
    return r;
}
model_configuration_generator::result_type*
model_configuration_generator::create_ptr(const unsigned int position) {
    model_configuration* p = new model_configuration();
    model_configuration_generator::populate(position, *p);
    return p;
}

model_configuration_generator::result_type
model_configuration_generator::operator()() {
    return create(position_++);
}

} }
