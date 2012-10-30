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
#

# set the site to the hostname. this shows up in the dashboard.
site_name(CRERIS_SITE)
set(SITE "${CRERIS_SITE}")
set(CTEST_SITE "${CRERIS_SITE}")

# project name
set(CTEST_PROJECT_NAME "creris")

# kitware dashboard settings
set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "kitanda.linkpc.net/cdash")
set(CTEST_DROP_LOCATION "/submit.php?project=creris")
set(CTEST_DROP_SITE_CDASH TRUE)
