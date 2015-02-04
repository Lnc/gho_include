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


// Conversion to integer

/**
 * \brief Convert a gho_operand into a gho_llint
 * \param[in] i A gho_operand
 * \return the gho_llint from the gho_operand
 */
gho_llint gho_operand_to_lli(gho_operand_t i) {
  
  // int
  if (i.type == GHO_TYPE_INT) {
    return *(int*)(i.p);
  }
  
  // gho_lint
  else if (i.type == GHO_TYPE_LINT) {
    return *(gho_lint*)(i.p);
  }
  
  // gho_llint
  else if (i.type == GHO_TYPE_LLINT) {
    return *(gho_llint*)(i.p);
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (i.type == GHO_TYPE_GHO_MPZ_T) {
    #ifndef NDEBUG
    if (mpz_fits_slong_p(((gho_mpz_t*)(i.p))->i) == false) {
      fprintf(stderr, "ERROR: gho_operand_to_lli(gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    return mpz_get_si(((gho_mpz_t*)(i.p))->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_operand_to_lli", i);
  }
}

/**
 * \brief Convert a gho_operand into a gho_lint
 * \param[in] i A gho_operand
 * \return the gho_lint from the gho_operand
 */
gho_lint gho_operand_to_li(gho_operand_t i) {
  
  // int
  if (i.type == GHO_TYPE_INT) {
    return *(int*)(i.p);
  }
  
  // gho_lint
  else if (i.type == GHO_TYPE_LINT) {
    return *(gho_lint*)(i.p);
  }
  
  // gho_llint
  else if (i.type == GHO_TYPE_LLINT) {
    #ifndef NDEBUG
    if (*(gho_llint*)(i.p) > LONG_MAX) {
      fprintf(stderr, "ERROR: gho_operand_to_li(gho_llint) overflow!\n");
      exit(1);
    }
    else if (*(gho_llint*)(i.p) < LONG_MIN) {
      fprintf(stderr, "ERROR: gho_operand_to_li(gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    return *(gho_llint*)(i.p);
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (i.type == GHO_TYPE_GHO_MPZ_T) {
    #ifndef NDEBUG
    if (mpz_fits_slong_p(((gho_mpz_t*)(i.p))->i) == false) {
      fprintf(stderr, "ERROR: gho_operand_to_lli(gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    return mpz_get_si(((gho_mpz_t*)(i.p))->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_operand_to_li", i);
  }
}
