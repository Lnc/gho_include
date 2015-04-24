// Copyright © 2014-2015 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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


#ifndef GHO_MEMORY_H
#define GHO_MEMORY_H

#include <stdio.h>
#include <stdlib.h>


/**
 * \defgroup gho_memory gho_memory
 * \brief Memory macros (allocation, swap)
 */


// Alloc & array alloc

/**
 * \brief Allocate a type
 * \param[in] type Type
 * \return a allocated type*
 * @ingroup gho_memory
 */
#define gho_alloc(type) \
  (type*)malloc(sizeof(type))

/**
 * \brief Allocate a array
 * \param[in] type Type
 * \param[in] n    Array size
 * \return a allocated type [n]
 * @ingroup gho_memory
 */
#define gho_array_alloc(type, n) \
  (type*)malloc(sizeof(type) * n)

/**
 * \brief Reallocate a array
 * \param[in] pointer Previous array allocation
 * \param[in] type    Type
 * \param[in] n       Array new size
 * \return a allocated type [n]
 * @ingroup gho_memory
 */
#define gho_array_realloc(pointer, type, n) \
  pointer = (type*)realloc(pointer, sizeof(type) * n)

// Swap

/**
 * \brief Swap
 * \param[in] T Type of a and b
 * \param[in] a A T
 * \param[in] b A T
 * @ingroup gho_memory
 */
#define gho_T_swap(T, a, b) \
  { \
    T tmp; \
    tmp = a; \
    a = b; \
    b = tmp; \
  }

#endif
