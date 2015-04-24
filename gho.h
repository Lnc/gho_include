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


/*! @mainpage gho: Generic Header-Only C Library
 * 
 * https://github.com/Lnc/gho/tree/master @n
 * http://hnc.toile-libre.org/index.php?section=dev&page=gho @n
 * https://www.lri.fr/~bagneres/index.php?section=dev&page=gho
 *
 * @section section_introduction Introduction
 *
 * Generic Header-Only C Library
 * 
 * License: Apache License, Version 2.0
 * 
 * @section section_system_requirement System Requirement
 * 
 * Required:
 * - C99 compiler
 * 
 * Optional:
 * - CMake build system
 * 
 * @section section_installation Installation
 * 
 * With CMake:
 * - @code
     mkdir build
     cd build
     cmake .. # -DCMAKE_INSTALL_PREFIX=/path/to/install # -DDEBUG=TRUE
     make
     # make doc
     # make test
     make install # su -c "make install" # sudo make install
     @endcode
 * 
 * Without CMake:
 * - This project is a header-only library, you can copy the include directory in /usr/local (for example) or in your project. (But you have to define some macros to enable optional parts.)
 * 
 * @section section_utilization Utilization
 * 
 * If you use CMake, add these lines in your CMakeLists.txt:
 * @code
   # gho
   message(STATUS "---")
   find_package(gho REQUIRED)
   # See /installation/path/lib/gho/gho-config.cmake for CMake variables
   @endcode
 */


/**
 * \defgroup gho gho
 * \brief Some informations about gho (version, codename)
 */


/**
 * @brief Version of gho
 * @ingroup gho
 */
#define gho_version "0.0.0"

/**
 * @brief Codename of gho (gho_codename macro)
 * @ingroup gho
 */
#define gho_codename "hope ;)"

#endif
