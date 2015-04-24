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


#ifndef GHO_VECTOR_INT_H
#define GHO_VECTOR_INT_H

#include "../int/int.h"


#define gho_vector_T gho_vector_int
#define gho_vector_T_t gho_vector_int_t

#define T_t int

#define gho_type_vector_T GHO_TYPE_VECTOR_INT

// T gho_T_create();
#define gho_T_create gho_int_create

/// void gho_T_destroy(T* t);
#define gho_T_destroy gho_int_destroy

// void gho_T_fprint(FILE* file, const T* const t);
#define gho_T_fprint gho_int_fprint

// void gho_T_sprint(char** c_str, const T* const t);
#define gho_T_sprint gho_int_sprint

// T gho_T_fread(FILE* file);
#define gho_T_fread gho_int_fread

// T gho_T_sread(char**);
#define gho_T_sread gho_int_sread

// T gho_T_copy(const T* const t);
#define gho_T_copy gho_int_copy

// bool gho_T_equal(const T* const a, const T* const b);
#define gho_T_equal gho_int_equal

// int gho_T_compare(const T* const a, const T* const b);
#define gho_T_compare gho_int_compare

#include "../vector_T.h"


#ifdef DOXYGEN
/**
 * @brief Vector of int
 * 
 * @see gho_vector_T_t for documentation
 */
struct gho_vector_int_t { };
#endif

#endif
