# -*- mode: cmake; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.

add_custom_target(generate_credit_risk
    COMMAND ${CMAKE_BINARY_DIR}/../dogen/stage/bin/dogen_driver
     -t ${CMAKE_SOURCE_DIR}/diagrams/credit_risk.dia
     -x ${CMAKE_SOURCE_DIR}/projects/
     --cpp-enable-facet domain
     --cpp-enable-facet io
     --cpp-enable-facet hash
     --cpp-enable-facet serialization
     --cpp-enable-facet test_data
     -v -d -p creris
    )

add_custom_target(generate_protocol
    COMMAND ${CMAKE_BINARY_DIR}/../dogen/stage/bin/dogen_driver
     -t ${CMAKE_SOURCE_DIR}/diagrams/protocol.dia
     -x ${CMAKE_SOURCE_DIR}/projects/
     --cpp-enable-facet domain
     --cpp-enable-facet io
     --cpp-enable-facet hash
     --cpp-enable-facet serialization
     --cpp-enable-facet test_data
     -v -d -p creris
    )

add_dependencies(protocol generate_credit_risk)

add_custom_target(codegen)

add_dependencies(codegen generate_credit_risk protocol)
