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


#ifndef GHO_INT_INT_H
#define GHO_INT_INT_H

#include <stdio.h>
#include <stdbool.h>

#include "../string.h"
#include "../any.h"


// Consider int as a class in Doxygen
#ifdef DOXYGEN

  /// @brief Typedef for int
  struct gho_int { };

#else

  // Typedef for int
  typedef int gho_int;

#endif


// Create & destroy
static inline
int gho_int_create();
static inline
void gho_int_destroy(int* i);
static inline
void gho_int_reset(int* i);

// Output
static inline
void gho_int_fprinti(FILE* file, const int* const i,
                     const unsigned int indent);
static inline
void gho_int_fprint(FILE* file, const int* const i);
static inline
void gho_int_print(const int* const i);
static inline
void gho_int_sprinti(char** c_str, const int* const i,
                     const unsigned int indent);
static inline
void gho_int_sprint(char** c_str, const int* const i);

// Input
static inline
int gho_int_fread(FILE* file);
static inline
int gho_int_sread(const char** c_str);

// Copy & comparisons
static inline
int gho_int_copy(const int* const i);
static inline
void gho_int_copy_(const int* const i, int* copy);
static inline
bool gho_int_equal(const int* const a, const int* const b);
static inline
int gho_int_compare(const int* const a, const int* const b);

// Conversion
static inline
gho_string_t gho_int_to_string(const int* const i);
static inline
gho_any_t gho_int_to_any(const int* const i);

#include "../implementation/int/int.h"

#endif
