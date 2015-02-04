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


// Comparison operators: == != < <= > >=


/**
 * \brief a == b
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a == b
 */
bool gho_equal(const gho_operand_t a, const gho_operand_t b) {
  
  // int & int
  if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_INT) {
    return *(int*)(a.p) == *(int*)(b.p);
  }
  // int & gho_lint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LINT) {
    return *(int*)(a.p) == *(gho_lint*)(b.p);
  }
  // int & gho_llint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LLINT) {
    return *(int*)(a.p) == *(gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(gho_mpz_t*)(b.p)).i, *(int*)(a.p)) == 0;
  }
  #endif
  
  // gho_lint & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return *(gho_lint*)(a.p) == *(int*)(b.p);
  }
  // gho_lint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return *(gho_lint*)(a.p) == *(gho_lint*)(b.p);
  }
  // gho_lint & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    return *(gho_lint*)(a.p) == *(gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(gho_mpz_t*)(b.p)).i, *(gho_lint*)(a.p)) == 0;
  }
  #endif
  
  // gho_llint & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return *(gho_llint*)(a.p) == *(int*)(b.p);
  }
  // gho_llint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return *(gho_llint*)(a.p) == *(gho_lint*)(b.p);
  }
  // gho_llint & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    return *(gho_llint*)(a.p) == *(gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    const gho_lint tmp = gho_operand_to_lli(a);
    return mpz_cmp_si((*(gho_mpz_t*)(b.p)).i, tmp) == 0;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return mpz_cmp_si((*(gho_mpz_t*)(a.p)).i, *(int*)(b.p)) == 0;
  }
  // gho_mpz_t & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return mpz_cmp_si((*(gho_mpz_t*)(a.p)).i, *(gho_lint*)(b.p)) == 0;
  }
  // gho_mpz_t & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    const gho_lint tmp = gho_operand_to_lli(b);
    return mpz_cmp_si((*(gho_mpz_t*)(a.p)).i, tmp) == 0;
  }
  // gho_mpz_t & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp((*(gho_mpz_t*)(a.p)).i, (*(gho_mpz_t*)(b.p)).i) == 0;
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_equal", a, b);
  }
}

/**
 * \brief a != b
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a != b
 */
bool gho_not_equal(const gho_operand_t a, const gho_operand_t b) {
  return (gho_equal(a, b) == false);
}

/**
 * \brief a < b
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a < b
 */
bool gho_lesser(const gho_operand_t a, const gho_operand_t b) {
  
  // int & int
  if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_INT) {
    return *(int*)(a.p) < *(int*)(b.p);
  }
  // int & gho_lint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LINT) {
    return *(int*)(a.p) < *(gho_lint*)(b.p);
  }
  // int & gho_llint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LLINT) {
    return *(int*)(a.p) < *(gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(gho_mpz_t*)(b.p)).i, *(int*)(a.p)) > 0;
  }
  #endif
  
  // gho_lint & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return *(gho_lint*)(a.p) < *(int*)(b.p);
  }
  // gho_lint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return *(gho_lint*)(a.p) < *(gho_lint*)(b.p);
  }
  // gho_lint & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    return *(gho_lint*)(a.p) < *(gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(gho_mpz_t*)(b.p)).i, *(gho_lint*)(a.p)) > 0;
  }
  #endif
  
  // gho_llint & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return *(gho_llint*)(a.p) < *(int*)(b.p);
  }
  // gho_llint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return *(gho_llint*)(a.p) < *(gho_lint*)(b.p);
  }
  // gho_llint & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    return *(gho_llint*)(a.p) < *(gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    const gho_lint tmp = gho_operand_to_lli(a);
    return mpz_cmp_si((*(gho_mpz_t*)(b.p)).i, tmp) > 0;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return mpz_cmp_si((*(gho_mpz_t*)(a.p)).i, *(int*)(b.p)) < 0;
  }
  // gho_mpz_t & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return mpz_cmp_si((*(gho_mpz_t*)(a.p)).i, *(gho_lint*)(b.p)) < 0;
  }
  // gho_mpz_t & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    const gho_lint tmp = gho_operand_to_lli(b);
    return mpz_cmp_si((*(gho_mpz_t*)(a.p)).i, tmp) < 0;
  }
  // gho_mpz_t & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp((*(gho_mpz_t*)(a.p)).i, (*(gho_mpz_t*)(b.p)).i) < 0;
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_lesser", a, b);
  }
}

/**
 * \brief a <= b
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a <= b
 */
bool gho_lesser_or_equal(const gho_operand_t a, const gho_operand_t b) {
  return gho_lesser(a, b) || gho_equal(a, b);
}

/**
 * \brief a > b
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a > b
 */
bool gho_greater(const gho_operand_t a, const gho_operand_t b) {
  return (gho_lesser_or_equal(a, b) == false);
}

/**
 * \brief a <= b
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a <= b
 */
bool gho_greater_or_equal(const gho_operand_t a, const gho_operand_t b) {
  return (gho_lesser(a, b) == false);
}
