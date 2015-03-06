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


#ifndef GHO_INT_MPZ_T_H
#define GHO_INT_MPZ_T_H

#ifdef gho_with_gmp

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "gmp.h"

#include "../string.h"
#include "../any.h"
#include "lint.h"
#include "ulint.h"


/**
 * \brief gho_mpz_t encapsulates a GMP mpz_t
 */
typedef struct {
  
  /// \brief GMP mpz_t
  mpz_t i;
  
} gho_mpz_t;


// Create & destroy
static inline
gho_mpz_t gho_mpz_create();
static inline
gho_mpz_t gho_mpz_create_from_gmp(const mpz_t* const gmp_mpz);
static inline
void gho_mpz_destroy(gho_mpz_t* i);
static inline
void gho_mpz_reset(gho_mpz_t* i);

// Output
static inline
void gho_mpz_fprinti(FILE* file, const gho_mpz_t* const i,
                       const unsigned int indent);
static inline
void gho_mpz_fprint(FILE* file, const gho_mpz_t* const i);
static inline
void gho_mpz_print(const gho_mpz_t* const i);
static inline
void gho_mpz_sprinti(char** c_str, const gho_mpz_t* const i,
                       const unsigned int indent);
static inline
void gho_mpz_sprint(char** c_str, const gho_mpz_t* const i);

// Input
static inline
gho_mpz_t gho_mpz_fread(FILE* file);
static inline
gho_mpz_t gho_mpz_sread(const char** c_str);

// Copy & comparisons
static inline
gho_mpz_t gho_mpz_copy(const gho_mpz_t* const i);
static inline
void gho_mpz_copy_(const gho_mpz_t* const i, gho_mpz_t* copy);
static inline
bool gho_mpz_equal(const gho_mpz_t* const a, const gho_mpz_t* const b);
static inline
bool gho_mpz_equal_li(const gho_mpz_t* const a, const gho_lint b);
static inline
int gho_mpz_compare(const gho_mpz_t* const a, const gho_mpz_t* const b);
static inline
int gho_mpz_compare_li(const gho_mpz_t* const a, const gho_lint b);

// Conversion
static inline
gho_string_t gho_mpz_to_string(const gho_mpz_t* const i);
static inline
gho_any_t gho_mpz_to_any(const gho_mpz_t* const i);

// Set
static inline
void gho_mpz_set_li(gho_mpz_t* a, const gho_lint b);

// Swap
static inline
void gho_mpz_swap(gho_mpz_t* a, gho_mpz_t* b);

// Arithmetic
static inline
gho_mpz_t gho_mpz_add_li(const gho_mpz_t a, const gho_lint b);
static inline
gho_mpz_t gho_mpz_floor_div_li(const gho_mpz_t a, const gho_lint b);

#include "../implementation/int/mpz_t.h"

#endif

#endif
