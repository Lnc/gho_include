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


#ifndef gho_matrix_T
  #error "Please define gho_matrix_T before include <gho/matrix_T.h>"
#endif

#ifndef gho_matrix_T_t
  #error "Please define gho_matrix_T_t before include <gho/matrix_T.h>"
#endif

#ifndef T_t
  #error "Please define T_t before include <gho/matrix_T.h>"
#endif

#ifndef gho_type_matrix_T
  #error "Please define gho_type_matrix_T before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_create
  #error "Please define gho_T_create before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_destroy
  #error "Please define gho_T_destroy before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_fprint
  #error "Please define gho_T_fprint before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_sprint
  #error "Please define gho_T_sprint before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_copy
  #error "Please define gho_T_copy before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_equal
  #error "Please define gho_T_equal before include <gho/matrix_T.h>"
#endif


#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#include "any.h"

// http://stackoverflow.com/questions/13842468/comma-in-c-c-macro
#define COMMA ,

// http://stackoverflow.com/questions/8587965/c-pre-processor-macro-expansion
#define concat_name_helper(a, b) a##_##b
#define concat_name(a_COMMA_b) concat_name_helper(a_COMMA_b)


/**
 * \brief gho_matrix_T encapsulates an array of array of T
 */
typedef struct {
  
  /// \brief Type
  gho_type_t type;
  
  /// \brief Number of rows
  size_t nb_row;
  
  /// \brief Number of columns
  size_t nb_col;
  
  /// \brief Array of array of T
  T_t** array;
  
} gho_matrix_T_t;

// Create & destroy
#define gho_matrix_T_create concat_name(gho_matrix_T COMMA create)
#define gho_matrix_T_create_n_m concat_name(gho_matrix_T COMMA create_n_m)
#define gho_matrix_T_create_n_m_copy \
  concat_name(gho_matrix_T COMMA create_n_m_copy)
#define gho_matrix_T_destroy concat_name(gho_matrix_T COMMA destroy)
#define gho_matrix_T_reset concat_name(gho_matrix_T COMMA reset)
static inline
gho_matrix_T_t gho_matrix_T_create();
static inline
gho_matrix_T_t gho_matrix_T_create_n_m(const size_t nb_row,
                                       const size_t nb_col);
static inline
gho_matrix_T_t gho_matrix_T_create_n_m_copy(
                                       const size_t nb_row, const size_t nb_col,
                                       const T_t* const default_value);
static inline
void gho_matrix_T_destroy(gho_matrix_T_t* matrix);
static inline
void gho_matrix_T_reset(gho_matrix_T_t* matrix);

// Output
#define gho_matrix_T_fprinti concat_name(gho_matrix_T COMMA fprinti)
#define gho_matrix_T_fprint concat_name(gho_matrix_T COMMA fprint)
#define gho_matrix_T_print concat_name(gho_matrix_T COMMA print)
#define gho_matrix_T_sprinti concat_name(gho_matrix_T COMMA sprinti)
#define gho_matrix_T_sprint concat_name(gho_matrix_T COMMA sprint)
static inline
void gho_matrix_T_fprinti(FILE* file, const gho_matrix_T_t* const matrix,
                          const unsigned int indent);
static inline
void gho_matrix_T_fprint(FILE* file, const gho_matrix_T_t* const matrix);
static inline
void gho_matrix_T_print(const gho_matrix_T_t* const matrix);
static inline
void gho_matrix_T_sprinti(char** c_str, const gho_matrix_T_t* const matrix,
                          const unsigned int indent);
static inline
void gho_matrix_T_sprint(char** c_str, const gho_matrix_T_t* const matrix);

// Copy & comparisons
#define gho_matrix_T_copy concat_name(gho_matrix_T COMMA copy)
#define gho_matrix_T_copy_ concat_name(gho_matrix_T COMMA copy_)
#define gho_matrix_T_equal concat_name(gho_matrix_T COMMA equal)
static inline
gho_matrix_T_t gho_matrix_T_copy(const gho_matrix_T_t* const matrix);
static inline
void gho_matrix_T_copy_(const gho_matrix_T_t* const matrix,
                        gho_matrix_T_t* copy);
static inline
bool gho_matrix_T_equal(const gho_matrix_T_t* const a,
                        const gho_matrix_T_t* const b);

// Conversion
#define gho_matrix_T_to_string concat_name(gho_matrix_T COMMA to_string)
#define gho_matrix_T_to_any concat_name(gho_matrix_T COMMA to_any)
static inline
gho_string_t gho_matrix_T_to_string(const gho_matrix_T_t* const matrix);
static inline
gho_any_t gho_matrix_T_to_any(const gho_matrix_T_t* const matrix);

// Size
#define gho_matrix_T_nb_row concat_name(gho_matrix_T COMMA nb_row)
#define gho_matrix_T_nb_col concat_name(gho_matrix_T COMMA nb_col)
#define gho_matrix_T_empty concat_name(gho_matrix_T COMMA empty)
static inline
size_t gho_matrix_T_nb_row(const gho_matrix_T_t* const matrix);
static inline
size_t gho_matrix_T_nb_col(const gho_matrix_T_t* const matrix);
static inline
bool gho_matrix_T_empty(const gho_matrix_T_t* const matrix);

// Get & Set
#define gho_matrix_T_at concat_name(gho_matrix_T COMMA at)
#define gho_matrix_T_set concat_name(gho_matrix_T COMMA set)
static inline
const T_t* gho_matrix_T_at(const gho_matrix_T_t* const matrix,
                           const size_t i, const size_t j);
static inline
void gho_matrix_T_set(gho_matrix_T_t* matrix, const size_t i, const size_t j,
                      const T_t* const value);

// Add & remove
#define gho_matrix_T_add_row \
  concat_name(gho_matrix_T COMMA add_row)
#define gho_matrix_T_add_row_before \
  concat_name(gho_matrix_T COMMA add_row_before)
#define gho_matrix_T_add_row_after \
  concat_name(gho_matrix_T COMMA add_row_after)
#define gho_matrix_T_add_col \
  concat_name(gho_matrix_T COMMA add_col)
#define gho_matrix_T_add_col_before \
  concat_name(gho_matrix_T COMMA add_col_before)
#define gho_matrix_T_add_col_after \
  concat_name(gho_matrix_T COMMA add_col_after)
#define gho_matrix_T_remove_row \
  concat_name(gho_matrix_T COMMA remove_row)
#define gho_matrix_T_remove_col \
  concat_name(gho_matrix_T COMMA remove_col)
static inline
void gho_matrix_T_add_row(gho_matrix_T_t* matrix);
static inline
void gho_matrix_T_add_row_before(gho_matrix_T_t* matrix, const size_t i);
static inline
void gho_matrix_T_add_row_after(gho_matrix_T_t* matrix, const size_t i);
static inline
void gho_matrix_T_add_col(gho_matrix_T_t* matrix);
static inline
void gho_matrix_T_add_col_before(gho_matrix_T_t* matrix, const size_t j);
static inline
void gho_matrix_T_add_col_after(gho_matrix_T_t* matrix, const size_t j);
static inline
void gho_matrix_T_remove_row(gho_matrix_T_t* matrix, const size_t i);
static inline
void gho_matrix_T_remove_col(gho_matrix_T_t* matrix, const size_t j);

#include "implementation/matrix_T.h"


#undef gho_matrix_T
#undef gho_matrix_T_t
#undef T_t
#undef gho_type_matrix_T

#undef gho_T_create
#undef gho_T_destroy
#undef gho_T_fprint
#undef gho_T_sprint
#undef gho_T_copy
#undef gho_T_equal

#undef concat_name_helper
#undef concat_name
#undef COMMA
