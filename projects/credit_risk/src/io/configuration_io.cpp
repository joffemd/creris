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
#include <ostream>
#include "creris/credit_risk/io/adjustment_io.hpp"
#include "creris/credit_risk/io/configuration_id_io.hpp"
#include "creris/credit_risk/io/configuration_io.hpp"
#include "creris/credit_risk/io/metric_io.hpp"
#include "creris/credit_risk/io/versioned_key_io.hpp"

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::vector<creris::credit_risk::metric>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::vector<creris::credit_risk::adjustment>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace creris {
namespace credit_risk {

std::ostream& operator<<(std::ostream& s, const configuration& v) {
    s << " { "
      << "\"__type__\": " << "\"configuration\"" << ", "
      << "\"name\": " << "\"" << v.name() << "\"" << ", "
      << "\"configuration_id\": " << v.configuration_id() << ", "
      << "\"entity_name\": " << "\"" << v.entity_name() << "\"" << ", "
      << "\"entity_description\": " << "\"" << v.entity_description() << "\"" << ", "
      << "\"currency\": " << "\"" << v.currency() << "\"" << ", "
      << "\"default_number_of_trials\": " << v.default_number_of_trials() << ", "
      << "\"metrics\": " << v.metrics() << ", "
      << "\"time_series_configurations\": " << "\"" << v.time_series_configurations() << "\"" << ", "
      << "\"adjustments\": " << v.adjustments() << ", "
      << "\"versioned_key\": " << v.versioned_key()
      << " }";
    return(s);
}

} }