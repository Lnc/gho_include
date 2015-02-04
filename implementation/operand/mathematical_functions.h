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


// Mathematical functions: abs floor ceil log pow_10_floor pow_10_round
// TODO
static inline
void gho_abs(gho_operand_t i);
static inline
void gho_floor(gho_operand_t i);
static inline
void gho_ceil(gho_operand_t i);
static inline
void gho_log2(gho_operand_t i);
static inline
void gho_log10(gho_operand_t i);
static inline
void gho_pow_10_floor(gho_operand_t i);
static inline
void gho_pow_10_round(gho_operand_t i);

/**
 * \brief i = |i|
 * \param[in] i A gho_operand
 */
void gho_abs(gho_operand_t i) {
  
  if (gho_is_negatif(i)) { gho_oppose(i); }

  // Other
  /*else*/ {
    gho_operand_type_error_1("gho_abs", i);
  }
}

/**
 * \brief i = floor(i)
 * \param[in] i A gho_operand
 */
void gho_floor(gho_operand_t i) {
  
  // Integer
  if (GHO_TYPE_INT || GHO_TYPE_LINT || GHO_TYPE_LLINT || GHO_TYPE_GHO_MPZ_T) {
    // Do nothing
  }
  
  // Other
  else {
    gho_operand_type_error_1("gho_floor", i);
  }
}

/**
 * \brief i = ceil(i)
 * \param[in] i A gho_operand
 */
void gho_ceil(gho_operand_t i) {
  
  // Integer
  if (GHO_TYPE_INT || GHO_TYPE_LINT || GHO_TYPE_LLINT || GHO_TYPE_GHO_MPZ_T) {
    // Do nothing
  }
  
  // Other
  else {
    gho_operand_type_error_1("gho_ceil", i);
  }
}

/**
 * \brief i = log2(i)
 * \param[in] i A gho_operand
 */
void gho_log2(gho_operand_t i) {
  
  // int
  if (i.type == GHO_TYPE_INT) {
    *(int*)(i.p) = gho_int_log2(*(int*)(i.p));
  }
  
  // gho_lint
  else if (i.type == GHO_TYPE_LINT) {
    *(gho_lint*)(i.p) = gho_lint_log2(*(gho_lint*)(i.p));
  }
  
  // gho_llint
  else if (i.type == GHO_TYPE_LLINT) {
    *(gho_llint*)(i.p) = gho_llint_log2(*(gho_llint*)(i.p));
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t tmp = gho_mpz_log2(*(gho_mpz_t*)(i.p));
    gho_swap(gho_mpz_t, tmp, *(gho_mpz_t*)(i.p));
    gho_mpz_destroy(&tmp);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_log2", i);
  }
}

/**
 * \brief i = log10(i)
 * \param[in] i A gho_operand
 */
void gho_log10(gho_operand_t i) {
  
  // int
  if (i.type == GHO_TYPE_INT) {
    *(int*)(i.p) = gho_int_log10(*(int*)(i.p));
  }
  
  // gho_lint
  else if (i.type == GHO_TYPE_LINT) {
    *(gho_lint*)(i.p) = gho_lint_log10(*(gho_lint*)(i.p));
  }
  
  // gho_llint
  else if (i.type == GHO_TYPE_LLINT) {
    *(gho_llint*)(i.p) = gho_llint_log10(*(gho_llint*)(i.p));
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t tmp = gho_mpz_log10(*(gho_mpz_t*)(i.p));
    gho_swap(gho_mpz_t, tmp, *(gho_mpz_t*)(i.p));
    gho_mpz_destroy(&tmp);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_log2", i);
  }
}

/**
 * \brief i = pow_10_floor(i)
 * \param[in] i A gho_operand
 */
void gho_pow_10_floor(gho_operand_t i) {
  // http://ubuntuforums.org/showthread.php?t=816175&s=2917e9d0741387015eda91408727af19&p=5099702#post5099702
  gho_operand_type_error_1("gho_pow_10_floor", i);
}

/**
 * \brief i = pow_10_round(i)
 * \param[in] i A gho_operand
 */
void gho_pow_10_round(gho_operand_t i) {
  // http://ubuntuforums.org/showthread.php?t=816175&s=2917e9d0741387015eda91408727af19&p=5099702#post5099702
  gho_operand_type_error_1("gho_pow_10_round", i);
//   gho_log10(i);
//   gho_floor(i);
//   gho_set_lli(i, pow(10, gho_operand_to_size_t(i)));
}
