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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE utility_spec
#include <string>
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/throw_exception.hpp>
#include "creris/utility/io/hex_dumper_io.hpp"


BOOST_AUTO_TEST_SUITE(utility)


BOOST_AUTO_TEST_CASE(exericise_hex_dumper_with_a_non_multiple_of_16) {
    //SETUP_TEST_LOG_SOURCE("exericise_hex_dumper_with_a_non_multiple_of_16");
    std::cout << "exericise_hex_dumper_with_a_non_multiple_of_16" << std::endl;
    const unsigned int size(1000);
    char str[size];
    for (unsigned int i(0); i < size; ++i) {
        str[i] = char(i % 256);
    }
    std::ostringstream stream;
    creris::utility::io::hex_dumper(stream, str, size);
    std::cout << stream.str() << std::endl;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(exericise_hex_dumper_with_a_multiple_of_16) {
    std::cout << "exericise_hex_dumper_with_a_multiple_of_16" << std::endl;
    const unsigned int size(64);
    char str[size];
    for (unsigned int i(0); i < size; ++i) {
        str[i] = char(i % 256);
    }
    std::ostringstream stream;
    creris::utility::io::hex_dumper(stream, str, size);
    std::cout << stream.str() << std::endl;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(exericise_hex_dumper_with_less_than_16) {
    std::cout << "exericise_hex_dumper_with_less_than_16" << std::endl;
    const unsigned int size(10);
    char str[size];
    for (unsigned int i(0); i < size; ++i) {
        str[i] = char(i % 256);
    }
    std::ostringstream stream;
    creris::utility::io::hex_dumper(stream, str, size);
    std::cout << stream.str() << std::endl;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(exericise_hex_dumper_with_an_empty_buffer) {
    std::cout << "exericise_hex_dumper_with_an_empty_buffer" << std::endl;
    const unsigned int size(0);
    char str[1];
    std::ostringstream stream;
    creris::utility::io::hex_dumper(stream, str, size);
    std::cout << stream.str() << std::endl;
    BOOST_CHECK(true);
}


BOOST_AUTO_TEST_SUITE_END()
