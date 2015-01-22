// Copyright © 2015 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef GHO_H
#define GHO_H

#include <string>


/*! @mainpage gho: Generic Header-Only C Library
 * 
 * https://github.com/Lnc/gho @n
 * https://github.com/Lnc/gho_include
 *
 * @section section_introduction Introduction
 *
 * Generic Header-Only C Library
 * 
 * License: Apache License, Version 2.0
 * 
 * @section section_system_requirement System requirement for gho
 * 
 * gho uses CMake build system.
 * 
 * The required packages are: @n
 * build-essential cmake git doxygen
 * 
 * @section section_installation Installation of gho
 * 
 * @subsection subsection_installation_with_cmake With CMake
 * 
 * Your C compiler must support common features of C99
 * 
 * Use CMake to build gho:
 * @code
   mkdir build
   cd build
   cmake .. #-DCMAKE_INSTALL_PREFIX=/path/to/install/gho
   make
   make doc
   make test
   make install # su -c "make install" # sudo make install
   @endcode
 * 
 * @subsection subsection_installation_without_cmake Without CMake
 * 
 * gho is an header-only library, you can copy the include directory
 * in /usr/local or in your project.
 *
 * To use gho directly in your project, consider the use of git submodule:
 * https://github.com/Lnc/gho_include
 * 
 * @section section_use Use gho
 * 
 * If you use CMake, add these lines in your CMakeLists.txt:
 * @code
   # gho
   message(STATUS "---")
   find_package(gho REQUIRED)
   # See /gho/installation/path/lib/gho/gho-config.cmake for CMake variables
   @endcode
 * 
 * If you have make the documentation, the doxygen is in: @n
 * /gho/installation/path/share/gho/doxygen/
 * 
 */


/**
 * @brief Version of gho
 * 
 * @code
   #include <gho/gho.h>
   @endcode
 */
#define gho_version "0.0.0"

/**
 * @brief Codename of gho
 * 
 * @code
   #include <gho/gho.h>
   @endcode
 */
#define gho_codename "hope ;)"

#endif
