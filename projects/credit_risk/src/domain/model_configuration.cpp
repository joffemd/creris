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
#include "creris/credit_risk/domain/model_configuration.hpp"

namespace boost {

inline bool operator==(const boost::shared_ptr<creris::credit_risk::time_series_configuration>& lhs,
const boost::shared_ptr<creris::credit_risk::time_series_configuration>& rhs) {
    return lhs && rhs && (*lhs == *rhs);
}

}

namespace creris {
namespace credit_risk {

model_configuration::model_configuration()
    : default_number_of_trials_(static_cast<unsigned int>(0)) { }

model_configuration::model_configuration(
    const std::string& name,
    const std::string& description,
    const creris::credit_risk::entity& entity,
    const std::string& currency,
    const unsigned int default_number_of_trials,
    const std::vector<creris::credit_risk::metric>& metrics,
    const std::vector<boost::shared_ptr<creris::credit_risk::time_series_configuration> >& time_series_configuration_set,
    const std::vector<creris::credit_risk::adjustment>& adjustments,
    const creris::credit_risk::model_configuration_versioned_key& versioned_key)
    : name_(name),
      description_(description),
      entity_(entity),
      currency_(currency),
      default_number_of_trials_(default_number_of_trials),
      metrics_(metrics),
      time_series_configuration_set_(time_series_configuration_set),
      adjustments_(adjustments),
      versioned_key_(versioned_key) { }

void model_configuration::swap(model_configuration& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(description_, other.description_);
    swap(entity_, other.entity_);
    swap(currency_, other.currency_);
    swap(default_number_of_trials_, other.default_number_of_trials_);
    swap(metrics_, other.metrics_);
    swap(time_series_configuration_set_, other.time_series_configuration_set_);
    swap(adjustments_, other.adjustments_);
    swap(versioned_key_, other.versioned_key_);
}

bool model_configuration::operator==(const model_configuration& rhs) const {
    return name_ == rhs.name_ &&
        description_ == rhs.description_ &&
        entity_ == rhs.entity_ &&
        currency_ == rhs.currency_ &&
        default_number_of_trials_ == rhs.default_number_of_trials_ &&
        metrics_ == rhs.metrics_ &&
        time_series_configuration_set_ == rhs.time_series_configuration_set_ &&
        adjustments_ == rhs.adjustments_ &&
        versioned_key_ == rhs.versioned_key_;
}

model_configuration& model_configuration::operator=(model_configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }