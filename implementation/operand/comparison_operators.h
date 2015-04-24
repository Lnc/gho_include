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

// gho_operand_t

/**
 * \brief a == b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a == b
 * @relates gho_operand_t
 */
bool gho_op_equal(const gho_operand_t a, const gho_operand_t b) {
  const gho_coperand_t a_cop = gho_coperand_type(a.p, a.type);
  const gho_coperand_t b_cop = gho_coperand_type(b.p, b.type);
  return gho_cop_equal(a_cop, b_cop);
}

/**
 * \brief a != b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a != b
 * @relates gho_operand_t
 */
bool gho_op_not_equal(const gho_operand_t a, const gho_operand_t b) {
  return (gho_op_equal(a, b) == false);
}

/**
 * \brief a < b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a < b
 * @relates gho_operand_t
 */
bool gho_op_lesser(const gho_operand_t a, const gho_operand_t b) {
  const gho_coperand_t a_cop = gho_coperand_type(a.p, a.type);
  const gho_coperand_t b_cop = gho_coperand_type(b.p, b.type);
  return gho_cop_lesser(a_cop, b_cop);
}

/**
 * \brief a <= b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a <= b
 * @relates gho_operand_t
 */
bool gho_op_lesser_or_equal(const gho_operand_t a, const gho_operand_t b) {
  return gho_op_lesser(a, b) || gho_op_equal(a, b);
}

/**
 * \brief a > b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a > b
 * @relates gho_operand_t
 */
bool gho_op_greater(const gho_operand_t a, const gho_operand_t b) {
  return (gho_op_lesser_or_equal(a, b) == false);
}

/**
 * \brief a <= b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a <= b
 * @relates gho_operand_t
 */
bool gho_op_greater_or_equal(const gho_operand_t a, const gho_operand_t b) {
  return (gho_op_lesser(a, b) == false);
}

// gho_coperand_t

/**
 * \brief a == b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a == b
 * @relates gho_coperand_t
 */
bool gho_cop_equal(const gho_coperand_t a, const gho_coperand_t b) {
  
  // int & int
  if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_INT) {
    return *(const int*)(a.p) == *(const int*)(b.p);
  }
  // int & gho_lint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LINT) {
    return *(const int*)(a.p) == *(const gho_lint*)(b.p);
  }
  // int & gho_llint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LLINT) {
    return *(const int*)(a.p) == *(const gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(const gho_mpz_t*)(b.p)).i, *(const int*)(a.p)) == 0;
  }
  #endif
  
  // gho_lint & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return *(const gho_lint*)(a.p) == *(const int*)(b.p);
  }
  // gho_lint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return *(const gho_lint*)(a.p) == *(const gho_lint*)(b.p);
  }
  // gho_lint & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    return *(const gho_lint*)(a.p) == *(const gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(const gho_mpz_t*)(b.p)).i, *(const gho_lint*)(a.p)) == 0;
  }
  #endif
  
  // gho_llint & int
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_INT) {
    return *(const gho_llint*)(a.p) == *(const int*)(b.p);
  }
  // gho_llint & gho_lint
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_LINT) {
    return *(const gho_llint*)(a.p) == *(const gho_lint*)(b.p);
  }
  // gho_llint & gho_llint
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_LLINT) {
    return *(const gho_llint*)(a.p) == *(const gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    const gho_lint tmp = gho_coperand_to_lli(a);
    return mpz_cmp_si((*(const gho_mpz_t*)(b.p)).i, tmp) == 0;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_INT) {
    return mpz_cmp_si((*(const gho_mpz_t*)(a.p)).i, *(const int*)(b.p)) == 0;
  }
  // gho_mpz_t & gho_lint
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_LINT) {
    return mpz_cmp_si((*(const gho_mpz_t*)(a.p)).i, *(const gho_lint*)(b.p)) == 0;
  }
  // gho_mpz_t & gho_llint
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_LLINT) {
    const gho_lint tmp = gho_coperand_to_lli(b);
    return mpz_cmp_si((*(const gho_mpz_t*)(a.p)).i, tmp) == 0;
  }
  // gho_mpz_t & gho_mpz_t
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp((*(const gho_mpz_t*)(a.p)).i, (*(const gho_mpz_t*)(b.p)).i) == 0;
  }
  #endif
  
  // Other
  else {
    gho_coperand_type_error_2("gho_cop_equal", a, b);
  }
  return false;
}

/**
 * \brief a != b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a != b
 * @relates gho_coperand_t
 */
bool gho_cop_not_equal(const gho_coperand_t a, const gho_coperand_t b) {
  return (gho_cop_equal(a, b) == false);
}

/**
 * \brief a < b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a < b
 * @relates gho_coperand_t
 */
bool gho_cop_lesser(const gho_coperand_t a, const gho_coperand_t b) {
  
  // int & int
  if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_INT) {
    return *(const int*)(a.p) < *(const int*)(b.p);
  }
  // int & gho_lint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LINT) {
    return *(const int*)(a.p) < *(const gho_lint*)(b.p);
  }
  // int & gho_llint
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_LLINT) {
    return *(const int*)(a.p) < *(const gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(const gho_mpz_t*)(b.p)).i, *(const int*)(a.p)) > 0;
  }
  #endif
  
  // gho_lint & int
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_INT) {
    return *(const gho_lint*)(a.p) < *(const int*)(b.p);
  }
  // gho_lint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    return *(const gho_lint*)(a.p) < *(const gho_lint*)(b.p);
  }
  // gho_lint & gho_llint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LLINT) {
    return *(const gho_lint*)(a.p) < *(const gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp_si((*(const gho_mpz_t*)(b.p)).i, *(const gho_lint*)(a.p)) > 0;
  }
  #endif
  
  // gho_llint & int
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_INT) {
    return *(const gho_llint*)(a.p) < *(const int*)(b.p);
  }
  // gho_llint & gho_lint
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_LINT) {
    return *(const gho_llint*)(a.p) < *(const gho_lint*)(b.p);
  }
  // gho_llint & gho_llint
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_LLINT) {
    return *(const gho_llint*)(a.p) < *(const gho_llint*)(b.p);
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_GHO_MPZ_T) {
    const gho_lint tmp = gho_coperand_to_lli(a);
    return mpz_cmp_si((*(const gho_mpz_t*)(b.p)).i, tmp) > 0;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_INT) {
    return mpz_cmp_si((*(const gho_mpz_t*)(a.p)).i, *(const int*)(b.p)) < 0;
  }
  // gho_mpz_t & gho_lint
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_LINT) {
    return mpz_cmp_si((*(const gho_mpz_t*)(a.p)).i, *(const gho_lint*)(b.p)) < 0;
  }
  // gho_mpz_t & gho_llint
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_LLINT) {
    const gho_lint tmp = gho_coperand_to_lli(b);
    return mpz_cmp_si((*(const gho_mpz_t*)(a.p)).i, tmp) < 0;
  }
  // gho_mpz_t & gho_mpz_t
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_GHO_MPZ_T) {
    return mpz_cmp((*(const gho_mpz_t*)(a.p)).i, (*(const gho_mpz_t*)(b.p)).i) < 0;
  }
  #endif
  
  // Other
  else {
    gho_coperand_type_error_2("gho_cop_lesser", a, b);
  }
  return false;
}

/**
 * \brief a <= b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a <= b
 * @relates gho_coperand_t
 */
bool gho_cop_lesser_or_equal(const gho_coperand_t a, const gho_coperand_t b) {
  return gho_cop_lesser(a, b) || gho_cop_equal(a, b);
}

/**
 * \brief a > b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a > b
 * @relates gho_coperand_t
 */
bool gho_cop_greater(const gho_coperand_t a, const gho_coperand_t b) {
  return (gho_cop_lesser_or_equal(a, b) == false);
}

/**
 * \brief a <= b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a <= b
 * @relates gho_coperand_t
 */
bool gho_cop_greater_or_equal(const gho_coperand_t a, const gho_coperand_t b) {
  return (gho_cop_lesser(a, b) == false);
}
