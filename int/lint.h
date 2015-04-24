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


#ifndef GHO_INT_LINT_H
#define GHO_INT_LINT_H

#include <stdio.h>
#include <stdbool.h>

#include "../string.h"
#include "../any.h"


// Consider long int as a class in Doxygen
#ifdef DOXYGEN

  /// @brief Typedef for long int
  struct gho_lint { };

#else

  // Typedef for long int
  typedef long int gho_lint;

#endif


// Create & destroy
static inline
gho_lint gho_lint_create();
static inline
void gho_lint_destroy(gho_lint* i);
static inline
void gho_lint_reset(gho_lint* i);

// Output
static inline
void gho_lint_fprinti(FILE* file, const gho_lint* const i,
                     const unsigned int indent);
static inline
void gho_lint_fprint(FILE* file, const gho_lint* const i);
static inline
void gho_lint_print(const gho_lint* const i);
static inline
void gho_lint_sprinti(char** c_str, const gho_lint* const i,
                     const unsigned int indent);
static inline
void gho_lint_sprint(char** c_str, const gho_lint* const i);

// Input
static inline
gho_lint gho_lint_fread(FILE* file);
static inline
gho_lint gho_lint_sread(const char** c_str);

// Copy & comparisons
static inline
gho_lint gho_lint_copy(const gho_lint* const i);
static inline
void gho_lint_copy_(const gho_lint* const i, gho_lint* copy);
static inline
bool gho_lint_equal(const gho_lint* const a, const gho_lint* const b);
static inline
int gho_lint_compare(const gho_lint* const a, const gho_lint* const b);

// Conversion
static inline
gho_string_t gho_lint_to_string(const gho_lint* const i);
static inline
gho_any_t gho_lint_to_any(const gho_lint* const i);

#include "../implementation/int/lint.h"

#endif
