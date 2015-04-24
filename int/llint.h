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


#ifndef GHO_INT_LLINT_H
#define GHO_INT_LLINT_H

#include <stdio.h>
#include <stdbool.h>

#include "../string.h"
#include "../any.h"


// Consider long long int as a class in Doxygen
#ifdef DOXYGEN

  /// @brief Typedef for long long int
  struct gho_llint { };

#else

  // Typedef for long long int
  typedef long long int gho_llint;

#endif


// Create & destroy
static inline
gho_llint gho_llint_create();
static inline
void gho_llint_destroy(gho_llint* i);
static inline
void gho_llint_reset(gho_llint* i);

// Output
static inline
void gho_llint_fprinti(FILE* file, const gho_llint* const i,
                     const unsigned int indent);
static inline
void gho_llint_fprint(FILE* file, const gho_llint* const i);
static inline
void gho_llint_print(const gho_llint* const i);
static inline
void gho_llint_sprinti(char** c_str, const gho_llint* const i,
                     const unsigned int indent);
static inline
void gho_llint_sprint(char** c_str, const gho_llint* const i);

// Input
static inline
gho_llint gho_llint_fread(FILE* file);
static inline
gho_llint gho_llint_sread(const char** c_str);

// Copy & comparisons
static inline
gho_llint gho_llint_copy(const gho_llint* const i);
static inline
void gho_llint_copy_(const gho_llint* const i, gho_llint* copy);
static inline
bool gho_llint_equal(const gho_llint* const a, const gho_llint* const b);
static inline
int gho_llint_compare(const gho_llint* const a, const gho_llint* const b);

// Conversion
static inline
gho_string_t gho_llint_to_string(const gho_llint* const i);
static inline
gho_any_t gho_llint_to_any(const gho_llint* const i);

#include "../implementation/int/llint.h"

#endif
