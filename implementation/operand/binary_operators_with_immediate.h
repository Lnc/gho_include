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


// Binary operators with immediate: + - * / % pow gcd with gho_llint immediate

/**
 * \brief r += i
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_add_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_add(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r -= i
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_sub_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_sub(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r *= i
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_mul_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_mul(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r /= i (exact division)
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_div_exact_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_div_exact(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r /= i
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_floor_div_q_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_floor_div_q(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r = r % i (remainder operator)
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_floor_div_r_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_floor_div_r(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r = r % i (modulo operator)
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_mod_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_mod(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r = r ^ i (power)
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_pow_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_pow(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief r = greater_common_divisor(r, i)
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_gcd_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_gcd(r, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}
