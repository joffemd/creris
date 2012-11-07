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
#include "creris/credit_risk/domain/metric.hpp"

namespace creris {
namespace credit_risk {

metric::metric()
    : threshold_level_(static_cast<double>(0)) { }

metric::metric(
    const std::string& name,
    const creris::credit_risk::time_series_configuration_unversioned_key& time_series_key,
    const double threshold_level,
    const std::string& relation_to_threshold)
    : name_(name),
      time_series_key_(time_series_key),
      threshold_level_(threshold_level),
      relation_to_threshold_(relation_to_threshold) { }

void metric::swap(metric& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(time_series_key_, other.time_series_key_);
    swap(threshold_level_, other.threshold_level_);
    swap(relation_to_threshold_, other.relation_to_threshold_);
}

bool metric::operator==(const metric& rhs) const {
    return name_ == rhs.name_ &&
        time_series_key_ == rhs.time_series_key_ &&
        threshold_level_ == rhs.threshold_level_ &&
        relation_to_threshold_ == rhs.relation_to_threshold_;
}

metric& metric::operator=(metric other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }