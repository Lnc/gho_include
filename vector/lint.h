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


#ifndef GHO_VECTOR_LINT_H
#define GHO_VECTOR_LINT_H

#include "../int/lint.h"


#define gho_vector_T gho_vector_lint
#define gho_vector_T_t gho_vector_lint_t

#define T_t gho_lint

#define gho_type_vector_T GHO_TYPE_VECTOR_LINT

// T gho_T_create();
#define gho_T_create gho_lint_create

/// void gho_T_destroy(T* t);
#define gho_T_destroy gho_lint_destroy

// void gho_T_fprint(FILE* file, const T* const t);
#define gho_T_fprint gho_lint_fprint

// void gho_T_sprint(char** c_str, const T* const t);
#define gho_T_sprint gho_lint_sprint

// T gho_T_fread(FILE* file);
#define gho_T_fread gho_lint_fread

// T gho_T_sread(char**);
#define gho_T_sread gho_lint_sread

// T gho_T_copy(const T* const t);
#define gho_T_copy gho_lint_copy

// bool gho_T_equal(const T* const a, const T* const b);
#define gho_T_equal gho_lint_equal

// int gho_T_compare(const T* const a, const T* const b);
#define gho_T_compare gho_lint_compare

#include "../vector_T.h"


#ifdef DOXYGEN
/**
 * @brief Vector of gho_lint (long int)
 * 
 * @see gho_vector_T_t for documentation
 */
struct gho_vector_lint_t { };
#endif

#endif
