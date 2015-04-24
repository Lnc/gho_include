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


// Other functions: is_divisible size_in_base

// gho_operand_t

/**
 * \brief Swap a and b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * @relates gho_operand_t
 */
void gho_op_swap(const gho_operand_t a, const gho_operand_t b) {
  
  // int & int
  if (a.type == GHO_TYPE_INT && b.type == GHO_TYPE_INT) {
    gho_T_swap(int, *(int*)(a.p), *(int*)(b.p));
  }
  
  // gho_lint & gho_lint
  else if (a.type == GHO_TYPE_LINT && b.type == GHO_TYPE_LINT) {
    gho_T_swap(gho_lint, *(gho_lint*)(a.p), *(gho_lint*)(b.p));
  }
  
  // gho_llint & gho_llint
  else if (a.type == GHO_TYPE_LLINT && b.type == GHO_TYPE_LLINT) {
    gho_T_swap(gho_llint, *(gho_lint*)(a.p), *(gho_lint*)(b.p));
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t & gho_mpz_t
  else if (a.type == GHO_TYPE_GHO_MPZ_T && b.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_swap((gho_mpz_t*)(a.p), (gho_mpz_t*)(b.p));
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_op_swap", a, b);
  }
}

/**
 * \brief a % b == 0
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_operand_t
 * \return a % b == 0
 * @relates gho_operand_t
 */
bool gho_op_is_divisible(const gho_operand_t a, const gho_operand_t b) {
  gho_operand_t copy = gho_operand_copy(&a);
  gho_floor_div_r(copy, b);
  const bool r = gho_op_is_0(copy);
  gho_operand_destroy(&copy);
  return r;
}

/**
 * \brief Return the size in base 2 of i
 * \param[in] i A gho_operand_t
 * \return the size in base 2 of i
 * @relates gho_operand_t
 */
size_t gho_op_size_in_base_2(gho_operand_t i) {
  // TODO
  gho_operand_type_error_1("gho_op_size_in_base_2", i); return 0;
}

/**
 * \brief Return the size in base 10 of i
 * \param[in] i A gho_operand_t
 * \return the size in base 10 of i
 * @relates gho_operand_t
 */
size_t gho_op_size_in_base_10(gho_operand_t i) {
  // TODO
  gho_operand_type_error_1("gho_op_size_in_base_10", i); return 0;
}

// gho_coperand_t

/**
 * \brief a % b == 0
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_coperand_t
 * \return a % b == 0
 * @relates gho_coperand_t
 */
bool gho_cop_is_divisible(const gho_coperand_t a, const gho_coperand_t b) {
  // TODO
  gho_coperand_type_error_2("gho_cop_is_divisible", a, b); return 0;
}

/**
 * \brief Return the size in base 2 of i
 * \param[in] i A gho_coperand_t
 * \return the size in base 2 of i
 * @relates gho_coperand_t
 */
size_t gho_cop_size_in_base_2(gho_coperand_t i) {
  // TODO
  gho_coperand_type_error_1("gho_cop_size_in_base_2", i); return 0;
}

/**
 * \brief Return the size in base 10 of i
 * \param[in] i A gho_coperand_t
 * \return the size in base 10 of i
 * @relates gho_coperand_t
 */
size_t gho_cop_size_in_base_10(gho_coperand_t i) {
  // TODO
  gho_coperand_type_error_1("gho_cop_size_in_base_10", i); return 0;
}
