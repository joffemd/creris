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
#include "creris/cache/domain/model_configuration/result.hpp"

namespace creris {
namespace cache {
namespace model_configuration {

result::result(const std::vector<creris::credit_risk::model_configuration>& model_configurations)
    : model_configurations_(model_configurations) { }

void result::swap(result& other) noexcept {
    using std::swap;
    swap(model_configurations_, other.model_configurations_);
}

bool result::operator==(const result& rhs) const {
    return model_configurations_ == rhs.model_configurations_;
}

result& result::operator=(result other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} } }