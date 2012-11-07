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
#include "creris/credit_risk/io/adjustment_constraint_io.hpp"
#include "creris/credit_risk/io/adjustment_io.hpp"
#include "creris/credit_risk/io/adjustment_predicate_io.hpp"
#include "creris/credit_risk/io/cauchy_generator_configuration_io.hpp"
#include "creris/credit_risk/io/entity_io.hpp"
#include "creris/credit_risk/io/fixed_time_series_configuration_io.hpp"
#include "creris/credit_risk/io/formula_generator_configuration_io.hpp"
#include "creris/credit_risk/io/generator_configuration_io.hpp"
#include "creris/credit_risk/io/identity_generator_configuration_io.hpp"
#include "creris/credit_risk/io/metric_io.hpp"
#include "creris/credit_risk/io/model_configuration_io.hpp"
#include "creris/credit_risk/io/model_configuration_unversioned_key_io.hpp"
#include "creris/credit_risk/io/model_configuration_versioned_key_io.hpp"
#include "creris/credit_risk/io/monte_carlo_generator_configuration_io.hpp"
#include "creris/credit_risk/io/normal_generator_configuration_io.hpp"
#include "creris/credit_risk/io/point_configuration_io.hpp"
#include "creris/credit_risk/io/rating_evaluation_io.hpp"
#include "creris/credit_risk/io/rating_evaluation_results_io.hpp"
#include "creris/credit_risk/io/ratings_map_io.hpp"
#include "creris/credit_risk/io/ratings_map_unversioned_key_io.hpp"
#include "creris/credit_risk/io/ratings_map_versioned_key_io.hpp"
#include "creris/credit_risk/io/relational_operator_types_io.hpp"
#include "creris/credit_risk/io/time_point_io.hpp"
#include "creris/credit_risk/io/time_series_configuration_io.hpp"
#include "creris/credit_risk/io/time_series_configuration_unversioned_key_io.hpp"
#include "creris/credit_risk/io/time_series_configuration_versioned_key_io.hpp"
#include "creris/credit_risk/io/time_series_io.hpp"
#include "creris/credit_risk/io/time_series_set_io.hpp"
#include "creris/credit_risk/io/time_series_unversioned_key_io.hpp"
#include "creris/credit_risk/io/time_series_versioned_key_io.hpp"
#include "creris/credit_risk/io/uniform_generator_configuration_io.hpp"
#include "creris/credit_risk/io/variable_time_series_configuration_io.hpp"
