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
#include "creris/credit_risk/domain/adjustment.hpp"
#include "creris/credit_risk/domain/adjustment_constraint.hpp"
#include "creris/credit_risk/domain/adjustment_predicate.hpp"
#include "creris/credit_risk/domain/cauchy_generator_configuration.hpp"
#include "creris/credit_risk/domain/entity.hpp"
#include "creris/credit_risk/domain/fixed_time_series_configuration.hpp"
#include "creris/credit_risk/domain/formula_generator_configuration.hpp"
#include "creris/credit_risk/domain/generator_configuration.hpp"
#include "creris/credit_risk/domain/identity_generator_configuration.hpp"
#include "creris/credit_risk/domain/metric.hpp"
#include "creris/credit_risk/domain/model_configuration.hpp"
#include "creris/credit_risk/domain/model_configuration_unversioned_key.hpp"
#include "creris/credit_risk/domain/model_configuration_versioned_key.hpp"
#include "creris/credit_risk/domain/monte_carlo_generator_configuration.hpp"
#include "creris/credit_risk/domain/normal_generator_configuration.hpp"
#include "creris/credit_risk/domain/point_configuration.hpp"
#include "creris/credit_risk/domain/rating_evaluation.hpp"
#include "creris/credit_risk/domain/rating_evaluation_results.hpp"
#include "creris/credit_risk/domain/ratings_map.hpp"
#include "creris/credit_risk/domain/ratings_map_unversioned_key.hpp"
#include "creris/credit_risk/domain/ratings_map_versioned_key.hpp"
#include "creris/credit_risk/domain/relational_operator_types.hpp"
#include "creris/credit_risk/domain/time_point.hpp"
#include "creris/credit_risk/domain/time_series.hpp"
#include "creris/credit_risk/domain/time_series_configuration.hpp"
#include "creris/credit_risk/domain/time_series_configuration_unversioned_key.hpp"
#include "creris/credit_risk/domain/time_series_configuration_versioned_key.hpp"
#include "creris/credit_risk/domain/time_series_set.hpp"
#include "creris/credit_risk/domain/time_series_unversioned_key.hpp"
#include "creris/credit_risk/domain/time_series_versioned_key.hpp"
#include "creris/credit_risk/domain/uniform_generator_configuration.hpp"
#include "creris/credit_risk/domain/variable_time_series_configuration.hpp"
