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

/**
 * \brief i == 0
 * \param[in] i A gho_operand
 * \return i == 0
 */
bool gho_is_0(const gho_operand_t i) {
  return gho_equal_lli(i, 0);
}

/**
 * \brief i > 0
 * \param[in] i A gho_operand
 * \return i > 0
 */
bool gho_is_positif(const gho_operand_t i) {
  return gho_greater_lli(i, 0);
}

/**
 * \brief i < 0
 * \param[in] i A gho_operand
 * \return i < 0
 */
bool gho_is_negatif(const gho_operand_t i) {
  return gho_lesser_lli(i, 0);
}

/**
 * \brief i == 1
 * \param[in] i A gho_operand
 * \return i == 1
 */
bool gho_is_1(const gho_operand_t i) {
  return gho_equal_lli(i, 1);
}

/**
 * \brief i == -1
 * \param[in] i A gho_operand
 * \return i == -1
 */
bool gho_is_minus_1(const gho_operand_t i) {
  return gho_equal_lli(i, -1);
}

/**
 * \brief a == b
 * \param[in] a A gho_operand
 * \param[in] b A gho_llint
 * \return a == b
 */
bool gho_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a != b
 * \param[in] a A gho_operand
 * \param[in] b A gho_llint
 * \return a != b
 */
bool gho_not_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_not_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a < b
 * \param[in] a A gho_operand
 * \param[in] b A gho_llint
 * \return a < b
 */
bool gho_lesser_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_lesser(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a <= b
 * \param[in] a A gho_operand
 * \param[in] b A gho_llint
 * \return a <= b
 */
bool gho_lesser_or_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_lesser_or_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a > b
 * \param[in] a A gho_operand
 * \param[in] b A gho_llint
 * \return a > b
 */
bool gho_greater_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_greater(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}

/**
 * \brief a >= b
 * \param[in] a A gho_operand
 * \param[in] b A gho_llint
 * \return a >= b
 */
bool gho_greater_or_equal_lli(const gho_operand_t a, const gho_llint b) {
  gho_llint tmp = b;
  return gho_greater_or_equal(a, gho_operand_type(&tmp, GHO_TYPE_LLINT));
}
