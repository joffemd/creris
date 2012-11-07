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
#include "creris/credit_risk/serialization/adjustment_constraint_ser.hpp"
#include "creris/credit_risk/serialization/adjustment_predicate_ser.hpp"
#include "creris/credit_risk/serialization/adjustment_ser.hpp"
#include "creris/credit_risk/serialization/cauchy_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/entity_ser.hpp"
#include "creris/credit_risk/serialization/fixed_time_series_configuration_ser.hpp"
#include "creris/credit_risk/serialization/formula_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/identity_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/metric_ser.hpp"
#include "creris/credit_risk/serialization/model_configuration_ser.hpp"
#include "creris/credit_risk/serialization/model_configuration_unversioned_key_ser.hpp"
#include "creris/credit_risk/serialization/model_configuration_versioned_key_ser.hpp"
#include "creris/credit_risk/serialization/monte_carlo_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/normal_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/point_configuration_ser.hpp"
#include "creris/credit_risk/serialization/rating_evaluation_results_ser.hpp"
#include "creris/credit_risk/serialization/rating_evaluation_ser.hpp"
#include "creris/credit_risk/serialization/ratings_map_ser.hpp"
#include "creris/credit_risk/serialization/ratings_map_unversioned_key_ser.hpp"
#include "creris/credit_risk/serialization/ratings_map_versioned_key_ser.hpp"
#include "creris/credit_risk/serialization/relational_operator_types_ser.hpp"
#include "creris/credit_risk/serialization/time_point_ser.hpp"
#include "creris/credit_risk/serialization/time_series_configuration_ser.hpp"
#include "creris/credit_risk/serialization/time_series_configuration_unversioned_key_ser.hpp"
#include "creris/credit_risk/serialization/time_series_configuration_versioned_key_ser.hpp"
#include "creris/credit_risk/serialization/time_series_ser.hpp"
#include "creris/credit_risk/serialization/time_series_set_ser.hpp"
#include "creris/credit_risk/serialization/time_series_unversioned_key_ser.hpp"
#include "creris/credit_risk/serialization/time_series_versioned_key_ser.hpp"
#include "creris/credit_risk/serialization/uniform_generator_configuration_ser.hpp"
#include "creris/credit_risk/serialization/variable_time_series_configuration_ser.hpp"
