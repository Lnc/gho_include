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

/**
 * \brief a % b == 0
 * \param[in] a A gho_operand
 * \param[in] b A gho_operand
 * \return a % b == 0
 */
bool gho_is_divisible(const gho_operand_t a, const gho_operand_t b) {
  gho_operand_t copy = gho_operand_copy(&a);
  gho_floor_div_r(copy, b);
  const bool r = gho_is_0(copy);
  gho_operand_destroy(&copy);
  return r;
}

/**
 * \brief Return the size in base 2 of i
 * \param[in] i A gho_operand
 * \return the size in base 2 of i
 */
size_t gho_size_in_base_2(gho_operand_t i) {
  // TODO
  gho_operand_type_error_1("gho_size_in_base_2", i); return 0;
}

/**
 * \brief Return the size in base 10 of i
 * \param[in] i A gho_operand
 * \return the size in base 10 of i
 */
size_t gho_size_in_base_10(gho_operand_t i) {
  // TODO
  gho_operand_type_error_1("gho_size_in_base_10", i); return 0;
}
