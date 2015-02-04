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


// abs

#ifdef gho_with_gmp
/**
 * \brief Return the absolute value of a gho_mpz_t
 * \param[in] i A gho_mpz_t
 * \return the absolute value of i
 */
gho_mpz_t gho_mpz_abs(const gho_mpz_t i) {
  gho_mpz_t r = gho_mpz_create();
  mpz_neg(r.i, i.i);
  return r;
}
#endif

// gcd

// http://en.wikipedia.org/wiki/Greatest_common_divisor
// https://proofwiki.org/wiki/GCD_for_Negative_Integers

static inline
int gho_int_gcd_without_abs(const int a, const int b);

/**
 * @brief Almost greatest common divisor of int (result can be negative)
 * @param[in] a A int
 * @param[in] b A int
 * @return almost the greatest common divisor of int (result can be negative)
 */
int gho_int_gcd_without_abs(const int a, const int b) {
  return (b != 0) ? gho_int_gcd_without_abs(b, a % b) : a;
}

/**
 * @brief Greatest common divisor of int
 * @param[in] a A int
 * @param[in] b A int
 * @return Greatest common divisor of int
 */
int gho_int_gcd(const int a, const int b) {
  return (b != 0) ? gho_int_gcd_without_abs(b, a % b) : a;
}

static inline
gho_lint gho_lint_gcd_without_abs(const gho_lint a, const gho_lint b);

/**
 * @brief Almost greatest common divisor of gho_lint (result can be negative)
 * @param[in] a A gho_lint
 * @param[in] b A gho_lint
 * @return almost the greatest common divisor of gho_lint (result can be negative)
 */
gho_lint gho_lint_gcd_without_abs(const gho_lint a, const gho_lint b) {
  return (b != 0) ? gho_lint_gcd_without_abs(b, a % b) : a;
}

/**
 * @brief Greatest common divisor of gho_lint
 * @param[in] a A gho_lint
 * @param[in] b A gho_lint
 * @return Greatest common divisor of gho_lint
 */
gho_lint gho_lint_gcd(const gho_lint a, const gho_lint b) {
  return (b != 0) ? gho_lint_gcd_without_abs(b, a % b) : a;
}

static inline
gho_llint gho_llint_gcd_without_abs(const gho_llint a, const gho_llint b);

/**
 * @brief Almost greatest common divisor of gho_llint (result can be negative)
 * @param[in] a A gho_llint
 * @param[in] b A gho_llint
 * @return almost the greatest common divisor of gho_llint (result can be negative)
 */
gho_llint gho_llint_gcd_without_abs(const gho_llint a, const gho_llint b) {
  return (b != 0) ? gho_llint_gcd_without_abs(b, a % b) : a;
}

/**
 * @brief Greatest common divisor of gho_llint
 * @param[in] a A gho_llint
 * @param[in] b A gho_llint
 * @return Greatest common divisor of gho_llint
 */
gho_llint gho_llint_gcd(const gho_llint a, const gho_llint b) {
  return (b != 0) ? gho_llint_gcd_without_abs(b, a % b) : a;
}

#ifdef gho_with_gmp
/**
 * @brief Greatest common divisor of gho_mpz_t
 * @param[in] a A gho_mpz_t
 * @param[in] b A gho_mpz_t
 * @return Greatest common divisor of gho_mpz_t
 */
gho_mpz_t gho_mpz_gcd(const gho_mpz_t a, const gho_mpz_t b) {
  gho_mpz_t r = gho_mpz_create();
  mpz_mod(r.i, a.i, b.i);
  return r;
}
#endif

#ifdef gho_with_gmp
/**
 * @brief Greatest common divisor of gho_mpz_t and gho_ulint
 * @param[in] a A gho_mpz_t
 * @param[in] b A gho_ulint
 * @return Greatest common divisor of gho_mpz_t and gho_ulint in a gho_ulint
 */
gho_ulint gho_mpz_gcd_uli(const gho_mpz_t a, const gho_ulint b) {
  gho_mpz_t tmp = gho_mpz_create();
  gho_ulint r = mpz_mod_ui(tmp.i, a.i, b);
  gho_mpz_destroy(&tmp);
  return r;
}
#endif

// log

/**
 * @brief Return log2(i)
 * @param[in] i A int
 * @return log2(i)
 */
int gho_int_log2(const int i) {
  int n = 0;
  int v = gho_T_abs(i);
  while (v) { v >>= 1; ++n; }
  n = ((n == 0) ? 1 : n);
  return n;
}

/**
 * @brief Return log10(i)
 * @param[in] i A int
 * @return log10(i)
 */
int gho_int_log10(const int i) {
  int n = 0;
  int v = gho_T_abs(i);
  while (v) { v /= 10; ++n; }
  n = ((n == 0) ? 1 : n);
  return n;
}

/**
 * @brief Return log2(i)
 * @param[in] i A gho_lint
 * @return log2(i)
 */
gho_lint gho_lint_log2(const gho_lint i) {
  gho_lint n = 0;
  gho_lint v = gho_T_abs(i);
  while (v) { v >>= 1; ++n; }
  n = ((n == 0) ? 1 : n);
  return n;
}

/**
 * @brief Return log10(i)
 * @param[in] i A gho_lint
 * @return log10(i)
 */
gho_lint gho_lint_log10(const gho_lint i) {
  gho_lint n = 0;
  gho_lint v = gho_T_abs(i);
  while (v) { v /= 10; ++n; }
  n = ((n == 0) ? 1 : n);
  return n;
}

/**
 * @brief Return log2(i)
 * @param[in] i A gho_llint
 * @return log2(i)
 */
gho_llint gho_llint_log2(const gho_llint i) {
  gho_llint n = 0;
  gho_llint v = gho_T_abs(i);
  while (v) { v >>= 1; ++n; }
  n = ((n == 0) ? 1 : n);
  return n;
}

/**
 * @brief Return log10(i)
 * @param[in] i A gho_llint
 * @return log10(i)
 */
gho_llint gho_llint_log10(const gho_llint i) {
  gho_llint n = 0;
  gho_llint v = gho_T_abs(i);
  while (v) { v /= 10; ++n; }
  n = ((n == 0) ? 1 : n);
  return n;
}

#ifdef gho_with_gmp
/**
 * @brief Return log2(i)
 * @param[in] i A gho_mpz_t
 * @return log2(i)
 */
gho_mpz_t gho_mpz_log2(const gho_mpz_t i) {
  gho_mpz_t n = gho_mpz_create();
  gho_mpz_t v = gho_mpz_abs(i);
  while (gho_mpz_equal_li(&v, 0) == false) {
    // v /= 2;
    {
      gho_mpz_t tmp = gho_mpz_floor_div_li(v, 2);
      gho_swap(gho_mpz_t, v, tmp)
      gho_mpz_destroy(&tmp);
    }
    // ++n;
    gho_mpz_add_li(n, 1);
  }
  // n = ((n == 0) ? 1 : n);
  if (gho_mpz_equal_li(&n, 1)) { gho_mpz_set_li(n, 1); }
  // Destroy and return
  gho_mpz_destroy(&v);
  return n;
}
#endif

#ifdef gho_with_gmp
/**
 * @brief Return log10(i)
 * @param[in] i A gho_mpz_t
 * @return log10(i)
 */
gho_mpz_t gho_mpz_log10(const gho_mpz_t i) {
  gho_mpz_t n = gho_mpz_create();
  gho_mpz_t v = gho_mpz_abs(i);
  while (gho_mpz_equal_li(&v, 0) == false) {
    // v /= 10;
    {
      gho_mpz_t tmp = gho_mpz_floor_div_li(v, 10);
      gho_swap(gho_mpz_t, v, tmp);
      gho_mpz_destroy(&tmp);
    }
    // ++n;
    gho_mpz_add_li(n, 1);
  }
  // n = ((n == 0) ? 1 : n);
  if (gho_mpz_equal_li(&n, 1)) { gho_mpz_set_li(n, 1); }
  // Destroy and return
  gho_mpz_destroy(&v);
  return n;
}
#endif
