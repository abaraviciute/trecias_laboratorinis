﻿/**
 * @file
 * @brief Bibliotekų header failas.
 *
 * Header failas apima įvairias standartines bibliotekas ir pagerina kodo skaitomumą, naudojant dažnai reikalingus elementus.
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <chrono>
#include <random>
#include <limits>
#include <list>
#include <functional>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::setprecision;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istringstream;
using std::invalid_argument;
using std::out_of_range;
using std::runtime_error;
using std::cerr;
using std::exception;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::ostringstream;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::exit;
using std::list;
using std::conditional_t;
using std::partition;
using std::function;
using std::copy_if;
using std::remove_if;
using std::back_inserter;
using std::is_same_v;
using std::remove_copy_if;
using std::find_if;
using std::back_inserter;
using std::is_same;
using std::istream;
using std::ostream;