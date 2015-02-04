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


#ifndef GHO_MATH_H
#define GHO_MATH_H

#include <math.h>

#include "int/lint.h"
#include "int/llint.h"
#include "int/mpz_t.h"


// min & max

/**
 * \brief Return the smallest of a and b
 * \param[in] a A value
 * \param[in] b A value
 * \return the smallest value
 */
#define gho_T_min(a, b) \
  (((a) < (b)) ? (a) : (b))

/**
 * \brief Return the largest of a and b
 * \param[in] a A value
 * \param[in] b A value
 * \return the largest value
 */
#define gho_T_max(a, b) \
  (((a) > (b)) ? (a) : (b))

// ceil div & floor div

/**
 * \brief Return ceil((double)n / (double)d)
 * \param[in] n Numerator
 * \param[in] d Denominator
 * \return ceil((double)n / (double)d)
 */
#define gho_T_ceil_div(n, d) \
  ceil(((double)(n)) / ((double)(d)))

/**
 * \brief Return floor((double)n / (double)d)
 * \param[in] n Numerator
 * \param[in] d Denominator
 * \return floor((double)n / (double)d)
 */
#define gho_T_floor_div(n, d) \
  floor(((double)(n)) / ((double)(d)))

// abs

/**
 * \brief Return the absolute value of a T
 * \param[in] i A value
 * \return the absolute value of i
 */
#define gho_T_abs(i) \
  (((i) < 0) ? (-i) : (i))

#ifdef gho_with_gmp
static inline
gho_mpz_t gho_mpz_abs(const gho_mpz_t i);
#endif

// gcd

static inline
int gho_int_gcd(const int a, const int b);

static inline
gho_lint gho_lint_gcd(const gho_lint a, const gho_lint b);

static inline
gho_llint gho_llint_gcd(const gho_llint a, const gho_llint b);

#ifdef gho_with_gmp
static inline
gho_mpz_t gho_mpz_gcd(const gho_mpz_t a, const gho_mpz_t b);
#endif

#ifdef gho_with_gmp
static inline
gho_ulint gho_mpz_gcd_uli(const gho_mpz_t a, const gho_ulint b);
#endif

// log

static inline
int gho_int_log2(const int i);

static inline
int gho_int_log10(const int i);

static inline
gho_lint gho_lint_log2(const gho_lint i);

static inline
gho_lint gho_lint_log10(const gho_lint i);

static inline
gho_llint gho_llint_log2(const gho_llint i);

static inline
gho_llint gho_llint_log10(const gho_llint i);

#ifdef gho_with_gmp
static inline
gho_mpz_t gho_mpz_log2(const gho_mpz_t i);
#endif

#ifdef gho_with_gmp
static inline
gho_mpz_t gho_mpz_log10(const gho_mpz_t i);
#endif

#include "implementation/math.h"

#endif
