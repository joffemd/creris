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
#include <stdexcept>
#include "creris/credit_risk/io/relational_operator_types_io.hpp"

namespace creris {
namespace credit_risk {

std::ostream& operator<<(std::ostream& s, const relational_operator_types& v) {
    s << "{ " << "\"__type__\": " << "\"relational_operator_types\", " << "\"value\": ";

    std::string attr;
    switch (v) {
    case relational_operator_types::invalid:
        attr = "\"invalid\"";
        break;
    case relational_operator_types::less_than:
        attr = "\"less_than\"";
        break;
    case relational_operator_types::less_than_or_equal:
        attr = "\"less_than_or_equal\"";
        break;
    case relational_operator_types::equal:
        attr = "\"equal\"";
        break;
    case relational_operator_types::greater_than:
        attr = "\"greater_than\"";
        break;
    case relational_operator_types::greater_than_or_equal:
        attr = "\"greater_than_or_equal\"";
        break;
    case relational_operator_types::not_equals:
        attr = "\"not_equals\"";
        break;
    default:
        throw std::invalid_argument("Invalid value for relational_operator_types");
    }
    s << attr << " }";
    return s;
}

} }