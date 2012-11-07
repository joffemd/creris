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
#include "creris/credit_risk/domain/model_configuration_unversioned_key.hpp"

namespace creris {
namespace credit_risk {

model_configuration_unversioned_key::model_configuration_unversioned_key()
    : id_(static_cast<unsigned int>(0)) { }

model_configuration_unversioned_key::model_configuration_unversioned_key(const unsigned int id)
    : id_(id) { }

void model_configuration_unversioned_key::swap(model_configuration_unversioned_key& other) noexcept {
    using std::swap;
    swap(id_, other.id_);
}

bool model_configuration_unversioned_key::operator==(const model_configuration_unversioned_key& rhs) const {
    return id_ == rhs.id_;
}

model_configuration_unversioned_key& model_configuration_unversioned_key::operator=(model_configuration_unversioned_key other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

} }