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


#ifndef GHO_INT_ULLINT_H
#define GHO_INT_ULLINT_H

#include <stdio.h>
#include <stdbool.h>

#include "../string.h"
#include "../any.h"


// Consider unsigned long long int as a class in Doxygen
#ifdef DOXYGEN

  /// @brief Typedef for unsigned long long int
  struct gho_ullint { };

#else

  // Typedef for unsigned long long int
  typedef unsigned long long int gho_ullint;

#endif


// Create & destroy
static inline
gho_ullint gho_ullint_create();
static inline
void gho_ullint_destroy(gho_ullint* i);
static inline
void gho_ullint_reset(gho_ullint* i);

// Output
static inline
void gho_ullint_fprinti(FILE* file, const gho_ullint* const i,
                      const unsigned int indent);
static inline
void gho_ullint_fprint(FILE* file, const gho_ullint* const i);
static inline
void gho_ullint_print(const gho_ullint* const i);
static inline
void gho_ullint_sprinti(char** c_str, const gho_ullint* const i,
                      const unsigned int indent);
static inline
void gho_ullint_sprint(char** c_str, const gho_ullint* const i);

// Input
static inline
gho_ullint gho_ullint_fread(FILE* file);
static inline
gho_ullint gho_ullint_sread(const char** c_str);

// Copy & comparisons
static inline
gho_ullint gho_ullint_copy(const gho_ullint* const i);
static inline
void gho_ullint_copy_(const gho_ullint* const i, gho_ullint* copy);
static inline
bool gho_ullint_equal(const gho_ullint* const a, const gho_ullint* const b);
static inline
int gho_ullint_compare(const gho_ullint* const a, const gho_ullint* const b);

// Conversion
static inline
gho_string_t gho_ullint_to_string(const gho_ullint* const i);
static inline
gho_any_t gho_ullint_to_any(const gho_ullint* const i);

#include "../implementation/int/ullint.h"

#endif
