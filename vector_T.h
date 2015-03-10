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


#ifndef gho_vector_T
  #error "Please define gho_vector_T before include <gho/vector_T.h>"
#endif

#ifndef gho_vector_T_t
  #error "Please define gho_vector_T_t before include <gho/vector_T.h>"
#endif

#ifndef T_t
  #error "Please define T_t before include <gho/vector_T.h>"
#endif

#ifndef gho_type_vector_T
  #error "Please define gho_type_vector_T before include <gho/matrix_T.h>"
#endif

#ifndef gho_T_create
  #error "Please define gho_T_create before include <gho/vector_T.h>"
#endif

#ifndef gho_T_destroy
  #error "Please define gho_T_destroy before include <gho/vector_T.h>"
#endif

#ifndef gho_T_fprint
  #error "Please define gho_T_fprint before include <gho/vector_T.h>"
#endif

#ifndef gho_T_sprint
  #error "Please define gho_T_sprint before include <gho/vector_T.h>"
#endif

#ifndef gho_T_copy
  #error "Please define gho_T_copy before include <gho/vector_T.h>"
#endif

#ifndef gho_T_equal
  #error "Please define gho_T_equal before include <gho/vector_T.h>"
#endif


#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "type.h"
#include "any.h"


// http://stackoverflow.com/questions/13842468/comma-in-c-c-macro
#define COMMA ,

// http://stackoverflow.com/questions/8587965/c-pre-processor-macro-expansion
#define concat_name_helper(a, b) a##_##b
#define concat_name(a_COMMA_b) concat_name_helper(a_COMMA_b)


/**
 * \brief gho_vector_T encapsulates an vector of T
 */
typedef struct {
  
  /// \brief Type
  gho_type_t type;
  
  /// \brief Size of the array
  size_t size;
  
  /// \brief capacity of the array
  size_t capacity;
  
  /// \brief Array of T
  T_t* array;
  
} gho_vector_T_t;

// Create & destroy
#define gho_vector_T_create concat_name(gho_vector_T COMMA create)
#define gho_vector_T_create_n concat_name(gho_vector_T COMMA create_n)
#define gho_vector_T_create_n_copy concat_name(gho_vector_T COMMA create_n_copy)
#define gho_vector_T_destroy concat_name(gho_vector_T COMMA destroy)
#define gho_vector_T_reset concat_name(gho_vector_T COMMA reset)
static inline
gho_vector_T_t gho_vector_T_create();
static inline
gho_vector_T_t gho_vector_T_create_n(const size_t n);
static inline
gho_vector_T_t gho_vector_T_create_n_copy(const size_t n,
                                          const T_t* const default_value);
static inline
void gho_vector_T_destroy(gho_vector_T_t* vector);
static inline
void gho_vector_T_reset(gho_vector_T_t* vector);

// Output
#define gho_vector_T_fprinti concat_name(gho_vector_T COMMA fprinti)
#define gho_vector_T_fprint concat_name(gho_vector_T COMMA fprint)
#define gho_vector_T_print concat_name(gho_vector_T COMMA print)
#define gho_vector_T_sprinti concat_name(gho_vector_T COMMA sprinti)
#define gho_vector_T_sprint concat_name(gho_vector_T COMMA sprint)
static inline
void gho_vector_T_fprinti(FILE* file, const gho_vector_T_t* const vector,
                          const unsigned int indent);
static inline
void gho_vector_T_fprint(FILE* file, const gho_vector_T_t* const vector);
static inline
void gho_vector_T_print(const gho_vector_T_t* const vector);
static inline
void gho_vector_T_sprinti(char** c_str, const gho_vector_T_t* const vector,
                          const unsigned int indent);
static inline
void gho_vector_T_sprint(char** c_str,
                         const gho_vector_T_t* const vector);

// Input
#define gho_vector_T_fread concat_name(gho_vector_T COMMA fread)
#define gho_vector_T_sread concat_name(gho_vector_T COMMA sread)
#ifdef gho_T_fread
static inline
gho_vector_T_t gho_vector_T_fread(FILE* file);
#endif
#ifdef gho_T_sread
static inline
gho_vector_T_t gho_vector_T_sread(const char** c_str);
#endif

// Copy & comparisons
#define gho_vector_T_copy concat_name(gho_vector_T COMMA copy)
#define gho_vector_T_copy_ concat_name(gho_vector_T COMMA copy_)
#define gho_vector_T_equal concat_name(gho_vector_T COMMA equal)
#define gho_vector_T_equal_n concat_name(gho_vector_T COMMA equal_n)
#define gho_vector_T_compare concat_name(gho_vector_T COMMA compare)
static inline
gho_vector_T_t gho_vector_T_copy(const gho_vector_T_t* const vector);
static inline
void gho_vector_T_copy_(const gho_vector_T_t* const vector,
                        gho_vector_T_t* copy);
static inline
bool gho_vector_T_equal(const gho_vector_T_t* const a,
                        const gho_vector_T_t* const b);
static inline
bool gho_vector_T_equal_n(const gho_vector_T_t* const a,
                          const gho_vector_T_t* const b,
                          const size_t n);
#ifdef gho_T_compare
static inline
int gho_vector_T_compare(const gho_vector_T_t* const a,
                         const gho_vector_T_t* const b);
#endif

// Conversion
#define gho_vector_T_to_string concat_name(gho_vector_T COMMA to_string)
#define gho_vector_T_to_any concat_name(gho_vector_T COMMA to_any)
static inline
gho_string_t gho_vector_T_to_string(const gho_vector_T_t* const vector);
static inline
gho_any_t gho_vector_T_to_any(const gho_vector_T_t* const vector);

// Size
#define gho_vector_T_size concat_name(gho_vector_T COMMA size)
#define gho_vector_T_capacity concat_name(gho_vector_T COMMA capacity)
#define gho_vector_T_empty concat_name(gho_vector_T COMMA empty)
#define gho_vector_T_reserve concat_name(gho_vector_T COMMA reserve)
#define gho_vector_T_resize concat_name(gho_vector_T COMMA resize)
static inline
size_t gho_vector_T_size(const gho_vector_T_t* const vector);
static inline
size_t gho_vector_T_capacity(const gho_vector_T_t* const vector);
static inline
bool gho_vector_T_empty(const gho_vector_T_t* const vector);
static inline
void gho_vector_T_reserve(gho_vector_T_t* vector, const size_t n);
static inline
void gho_vector_T_resize(gho_vector_T_t* vector, const size_t n);

// Get & Set
#define gho_vector_T_at concat_name(gho_vector_T COMMA at)
#define gho_vector_T_set concat_name(gho_vector_T COMMA set)
static inline
const T_t* gho_vector_T_at(const gho_vector_T_t* const vector, const size_t i);
static inline
void gho_vector_T_set(gho_vector_T_t* vector, const size_t i,
                      const T_t* const value);

// Add, Insert & Remove
#define gho_vector_T_add concat_name(gho_vector_T COMMA add)
#define gho_vector_T_add_ concat_name(gho_vector_T COMMA add_)
#define gho_vector_T_add_vector concat_name(gho_vector_T COMMA add_vector)
#define gho_vector_T_insert concat_name(gho_vector_T COMMA insert)
#define gho_vector_T_remove concat_name(gho_vector_T COMMA remove)
#define gho_vector_T_remove_last concat_name(gho_vector_T COMMA remove_last)
static inline
void gho_vector_T_add(gho_vector_T_t* vector, const T_t* const to_be_added);
static inline
void gho_vector_T_add_(gho_vector_T_t* vector, const T_t to_be_added);
static inline
void gho_vector_T_add_vector(gho_vector_T_t* vector,
                             const gho_vector_T_t* const to_be_added);
static inline
void gho_vector_T_insert(gho_vector_T_t* vector,
                         const T_t* const to_be_added, const size_t i);
static inline
void gho_vector_T_remove(gho_vector_T_t* vector, const size_t i);
static inline
void gho_vector_T_remove_last(gho_vector_T_t* vector);

// Algorithm
#define gho_vector_T_find concat_name(gho_vector_T COMMA find)
#define gho_vector_T_sort concat_name(gho_vector_T COMMA sort)
static inline
size_t gho_vector_T_find(gho_vector_T_t* vector, const T_t* const v);
#ifdef gho_T_compare
static inline
void gho_vector_T_sort(gho_vector_T_t* vector);
#endif

#include "implementation/vector_T.h"


#undef gho_vector_T
#undef gho_vector_T_t
#undef T_t
#undef gho_type_vector_T

#undef gho_T_create
#undef gho_T_destroy
#undef gho_T_fprint
#undef gho_T_sprint
#ifdef gho_T_fread
  #undef gho_T_fread
#endif
#ifdef gho_T_sread
  #undef gho_T_sread
#endif
#undef gho_T_copy
#undef gho_T_equal
#ifdef gho_T_compare
  #undef gho_T_compare
#endif

#undef concat_name_helper
#undef concat_name
#undef COMMA
