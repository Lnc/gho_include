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


// Unary operators: ++ -- -

/**
 * \brief i += 1
 * \param[in] i A gho_operand
 */
void gho_increment(gho_operand_t i) {
  gho_add_lli(i, 1);
}

/**
 * \brief i -= 1
 * \param[in] i A gho_operand
 */
void gho_decrement(gho_operand_t i) {
  gho_sub_lli(i, 1);
}

/**
 * \brief i = -i
 * \param[in] i A gho_operand
 */
void gho_oppose(gho_operand_t i) {
  
  // int
  if (i.type == GHO_TYPE_INT) {
    *(int*)(i.p) = -*(int*)(i.p);
  }
  
  // gho_lint
  else if (i.type == GHO_TYPE_LINT) {
    *(gho_lint*)(i.p) = -*(gho_lint*)(i.p);
  }
  
  // gho_llint
  else if (i.type == GHO_TYPE_LLINT) {
    *(gho_llint*)(i.p) = -*(gho_llint*)(i.p);
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (i.type == GHO_TYPE_GHO_MPZ_T) {
    mpz_neg(((gho_mpz_t*)(i.p))->i, ((gho_mpz_t*)(i.p))->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_oppose", i);
  }
}
