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


// Assignment: =0 =1 =-1 set set_i

/**
 * \brief i = 0
 * \param[in] i A gho_operand_t
 * @relates gho_operand_t
 */
void gho_set_0(gho_operand_t i) { gho_set_lli(i, 0); }

/**
 * \brief i = 1
 * \param[in] i A gho_operand_t
 * @relates gho_operand_t
 */
void gho_set_1(gho_operand_t i) { gho_set_lli(i, 1); }

/**
 * \brief i = -1
 * \param[in] i A gho_operand_t
 * @relates gho_operand_t
 */
void gho_set_minus_1(gho_operand_t i) { gho_set_lli(i, -1); }

/**
 * \brief r = i
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_operand_t
 * @relates gho_operand_t
 */
void gho_set(gho_operand_t r, const gho_operand_t i) {
  
  // int & int
  if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_INT) {
    *(int*)(r.p) = *(int*)(i.p);
  }
  // int & gho_lint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LINT) {
    #ifndef NDEBUG
    if (*(gho_lint*)(i.p) > INT_MAX) {
      fprintf(stderr, "ERROR: gho_set(int, gho_lint) overflow!\n");
      exit(1);
    }
    else if (*(gho_lint*)(i.p) < INT_MIN) {
      fprintf(stderr, "ERROR: gho_set(int, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *(int*)(r.p) = (int)*(gho_lint*)(i.p);
  }
  // int & gho_llint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LLINT) {
    #ifndef NDEBUG
    if (*(gho_llint*)(i.p) > INT_MAX) {
      fprintf(stderr, "ERROR: gho_set(int, gho_llint) overflow!\n");
      exit(1);
    }
    else if (*(gho_llint*)(i.p) < INT_MIN) {
      fprintf(stderr, "ERROR: gho_set(int, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *(int*)(r.p) = (int)*(gho_llint*)(i.p);
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_GHO_MPZ_T) {
    #ifndef NDEBUG
    if (mpz_fits_sint_p((*(gho_mpz_t*)(i.p)).i) == false) {
      fprintf(stderr, "ERROR: gho_set(int, gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    const gho_lint tmp = mpz_get_si((*(gho_mpz_t*)(i.p)).i);
    *(int*)(r.p) = (int)tmp;
  }
  #endif
  
  // gho_lint & int
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_INT) {
    *(gho_lint*)(r.p) = *(int*)(i.p);
  }
  // gho_lint & gho_lint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LINT) {
    *(gho_lint*)(r.p) = *(gho_lint*)(i.p);
  }
  // gho_lint & gho_llint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LLINT) {
    #ifndef NDEBUG
    if (*(gho_llint*)(i.p) > LONG_MAX) {
      fprintf(stderr, "ERROR: gho_set(gho_lint, gho_llint) overflow!\n");
      exit(1);
    }
    else if (*(gho_llint*)(i.p) < LONG_MIN) {
      fprintf(stderr, "ERROR: gho_set(gho_lint, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *(gho_lint*)(r.p) = (gho_lint)*(gho_llint*)(i.p);
  }
  #ifdef gho_with_gmp
  // gho_lint & mpz_t
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    #ifndef NDEBUG
    if (mpz_fits_slong_p((*(gho_mpz_t*)(i.p)).i) == false) {
      fprintf(stderr, "ERROR: gho_set(gho_lint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    const gho_lint tmp = mpz_get_si((*(gho_mpz_t*)(i.p)).i);
    *(gho_lint*)(r.p) = tmp;
  }
  #endif
  
  // gho_llint & int
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_INT) {
    *(gho_llint*)(r.p) = *(int*)(i.p);
  }
  // gho_llint & gho_lint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LINT) {
    *(gho_llint*)(r.p) = *(gho_lint*)(i.p);
  }
  // gho_llint & gho_llint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LLINT) {
    *(gho_llint*)(r.p) = *(gho_llint*)(i.p);
  }
  #ifdef gho_with_gmp
  // gho_llint & mpz_t
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    #ifndef NDEBUG
    if (mpz_fits_slong_p((*(gho_mpz_t*)(i.p)).i) == false) {
      fprintf(stderr, "ERROR: gho_set(gho_llint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    const gho_lint tmp = mpz_get_si((*(gho_mpz_t*)(i.p)).i);
    *(gho_lint*)(r.p) = tmp;
  }
  #endif
  
  #ifdef gho_with_gmp
  // mpz_t & int
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_INT) {
    mpz_set_si((*(gho_mpz_t*)(r.p)).i, *(gho_lint*)(i.p));
  }
  // mpz_t & gho_lint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LINT) {
    mpz_set_si((*(gho_mpz_t*)(r.p)).i, *(gho_lint*)(i.p));
  }
  // mpz_t & gho_llint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LLINT) {
    #ifndef NDEBUG
    if (*(gho_llint*)(i.p) > LONG_MAX) {
      fprintf(stderr, "ERROR: gho_set(mpz_t, gho_llint) overflow!\n");
      exit(1);
    }
    else if (*(gho_llint*)(i.p) < LONG_MIN) {
      fprintf(stderr, "ERROR: gho_set(mpz_t, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    mpz_set_si((*(gho_mpz_t*)(r.p)).i, *(gho_llint*)(i.p));
  }
  // mpz_t & mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    mpz_set((*(gho_mpz_t*)(r.p)).i, (*(gho_mpz_t*)(i.p)).i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_set", r, i);
  }
}

/**
 * \brief r = i
 * \param[in] r A gho_operand_t
 * \param[in] i A gho_llint
 * @relates gho_operand_t
 */
void gho_set_lli(gho_operand_t r, const gho_llint i) {
  gho_llint tmp = i;
  gho_set(r, gho_operand_type(&tmp, GHO_TYPE_LINT));
}
