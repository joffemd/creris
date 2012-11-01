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
#include "creris/credit_risk/domain/configuration.hpp"

namespace creris {
namespace credit_risk {

configuration::configuration()
    : default_number_of_trials_(static_cast<unsigned int>(0)) { }

configuration::configuration(
    const std::string& name,
    const creris::credit_risk::configuration_id& configuration_id,
    const std::string& entity_name,
    const std::string& entity_description,
    const std::string& currency,
    const unsigned int default_number_of_trials,
    const std::vector<creris::credit_risk::metric>& metrics,
    const std::string& time_series_configurations,
    const std::vector<creris::credit_risk::adjustment>& adjustments,
    const creris::credit_risk::versioned_key& versioned_key)
    : name_(name),
      configuration_id_(configuration_id),
      entity_name_(entity_name),
      entity_description_(entity_description),
      currency_(currency),
      default_number_of_trials_(default_number_of_trials),
      metrics_(metrics),
      time_series_configurations_(time_series_configurations),
      adjustments_(adjustments),
      versioned_key_(versioned_key) { }

void configuration::swap(configuration& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(configuration_id_, other.configuration_id_);
    swap(entity_name_, other.entity_name_);
    swap(entity_description_, other.entity_description_);
    swap(currency_, other.currency_);
    swap(default_number_of_trials_, other.default_number_of_trials_);
    swap(metrics_, other.metrics_);
    swap(time_series_configurations_, other.time_series_configurations_);
    swap(adjustments_, other.adjustments_);
    swap(versioned_key_, other.versioned_key_);
}

bool configuration::operator==(const configuration& rhs) const {
    return name_ == rhs.name_ &&
        configuration_id_ == rhs.configuration_id_ &&
        entity_name_ == rhs.entity_name_ &&
        entity_description_ == rhs.entity_description_ &&
        currency_ == rhs.currency_ &&
        default_number_of_trials_ == rhs.default_number_of_trials_ &&
        metrics_ == rhs.metrics_ &&
        time_series_configurations_ == rhs.time_series_configurations_ &&
        adjustments_ == rhs.adjustments_ &&
        versioned_key_ == rhs.versioned_key_;
}

configuration& configuration::operator=(configuration other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }