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


#ifndef GHO_MATRIX_LLINT_H
#define GHO_MATRIX_LLINT_H

#include "../int/llint.h"


#define gho_matrix_T gho_matrix_llint
#define gho_matrix_T_t gho_matrix_llint_t

#define T_t gho_llint

#define gho_type_matrix_T GHO_TYPE_MATRIX_LINT

// T gho_T_create();
#define gho_T_create gho_llint_create

/// void gho_T_destroy(T* t);
#define gho_T_destroy gho_llint_destroy

// void gho_T_fprint(FILE* file, const T* const t);
#define gho_T_fprint gho_llint_fprint

// void gho_T_sprint(char** c_str, const T* const t);
#define gho_T_sprint gho_llint_sprint

// T gho_T_copy(const T* const t);
#define gho_T_copy gho_llint_copy

// bool gho_T_equal(const T* const a, const T* const b);
#define gho_T_equal gho_llint_equal

#include "../matrix_T.h"


#ifdef DOXYGEN
/**
 * @brief Matrix of gho_llint (long long int)
 * 
 * @see gho_matrix_T_t for documentation
 */
struct gho_matrix_llint_t { };
#endif

#endif
