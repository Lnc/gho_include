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


// Comparison operators: ==0 >0 <0 ==1 ==-1 ==i !=i <i <=i >i >=i

// gho_operand_t

/**
 * \brief i == 0
 * \param[in] i A gho_operand_t
 * \return i == 0
 * @relates gho_operand_t
 */
bool gho_op_is_0(const gho_operand_t i) {
  return gho_op_equal_lli(i, 0);
}

/**
 * \brief i > 0
 * \param[in] i A gho_operand_t
 * \return i > 0
 * @relates gho_operand_t
 */
bool gho_op_is_positif(const gho_operand_t i) {
  return gho_op_greater_lli(i, 0);
}

/**
 * \brief i < 0
 * \param[in] i A gho_operand_t
 * \return i < 0
 * @relates gho_operand_t
 */
bool gho_op_is_negatif(const gho_operand_t i) {
  return gho_op_lesser_lli(i, 0);
}

/**
 * \brief i == 1
 * \param[in] i A gho_operand_t
 * \return i == 1
 * @relates gho_operand_t
 */
bool gho_op_is_1(const gho_operand_t i) {
  return gho_op_equal_lli(i, 1);
}

/**
 * \brief i == -1
 * \param[in] i A gho_operand_t
 * \return i == -1
 * @relates gho_operand_t
 */
bool gho_op_is_minus_1(const gho_operand_t i) {
  return gho_op_equal_lli(i, -1);
}

/**
 * \brief a == b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_llint
 * \return a == b
 * @relates gho_operand_t
 */
bool gho_op_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_op_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a != b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_llint
 * \return a != b
 * @relates gho_operand_t
 */
bool gho_op_not_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_op_not_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a < b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_llint
 * \return a < b
 * @relates gho_operand_t
 */
bool gho_op_lesser_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_op_lesser(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a <= b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_llint
 * \return a <= b
 * @relates gho_operand_t
 */
bool gho_op_lesser_or_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_op_lesser_or_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a > b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_llint
 * \return a > b
 * @relates gho_operand_t
 */
bool gho_op_greater_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_op_greater(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a >= b
 * \param[in] a A gho_operand_t
 * \param[in] b A gho_llint
 * \return a >= b
 * @relates gho_operand_t
 */
bool gho_op_greater_or_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_op_greater_or_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

// gho_coperand_t

/**
 * \brief i == 0
 * \param[in] i A gho_coperand_t
 * \return i == 0
 * @relates gho_coperand_t
 */
bool gho_cop_is_0(const gho_coperand_t i) {
  return gho_cop_equal_lli(i, 0);
}

/**
 * \brief i > 0
 * \param[in] i A gho_coperand_t
 * \return i > 0
 * @relates gho_coperand_t
 */
bool gho_cop_is_positif(const gho_coperand_t i) {
  return gho_cop_greater_lli(i, 0);
}

/**
 * \brief i < 0
 * \param[in] i A gho_coperand_t
 * \return i < 0
 * @relates gho_coperand_t
 */
bool gho_cop_is_negatif(const gho_coperand_t i) {
  return gho_cop_lesser_lli(i, 0);
}

/**
 * \brief i == 1
 * \param[in] i A gho_coperand_t
 * \return i == 1
 * @relates gho_coperand_t
 */
bool gho_cop_is_1(const gho_coperand_t i) {
  return gho_cop_equal_lli(i, 1);
}

/**
 * \brief i == -1
 * \param[in] i A gho_coperand_t
 * \return i == -1
 * @relates gho_coperand_t
 */
bool gho_cop_is_minus_1(const gho_coperand_t i) {
  return gho_cop_equal_lli(i, -1);
}

/**
 * \brief a == b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_llint
 * \return a == b
 * @relates gho_coperand_t
 */
bool gho_cop_equal_lli(const gho_coperand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_cop_equal(a, gho_coperand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a != b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_llint
 * \return a != b
 * @relates gho_coperand_t
 */
bool gho_cop_not_equal_lli(const gho_coperand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_cop_not_equal(a, gho_coperand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a < b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_llint
 * \return a < b
 * @relates gho_coperand_t
 */
bool gho_cop_lesser_lli(const gho_coperand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_cop_lesser(a, gho_coperand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a <= b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_llint
 * \return a <= b
 * @relates gho_coperand_t
 */
bool gho_cop_lesser_or_equal_lli(const gho_coperand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_cop_lesser_or_equal(a, gho_coperand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a > b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_llint
 * \return a > b
 * @relates gho_coperand_t
 */
bool gho_cop_greater_lli(const gho_coperand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_cop_greater(a, gho_coperand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a >= b
 * \param[in] a A gho_coperand_t
 * \param[in] b A gho_llint
 * \return a >= b
 * @relates gho_coperand_t
 */
bool gho_cop_greater_or_equal_lli(const gho_coperand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_cop_greater_or_equal(a, gho_coperand_type(&tmp, GHO_TYPE_LLINT));
}
