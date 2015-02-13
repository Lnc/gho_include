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


#include "../../math.h"


// Binary operators: + - * / % pow gcd

// Overflow detection: http://stackoverflow.com/a/1514309

/**
 * \brief r += i
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_add(gho_operand_t r, const gho_operand_t i) {
  
  // int & int
  if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_INT) {
    int* p_r = (int*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += *p_i;
  }
  // int & gho_lint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LINT) {
    int* p_r = (int*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, gho_lint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += (int)*p_i;
  }
  // int & gho_llint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LLINT) {
    int* p_r = (int*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, gho_llint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += (int)*p_i;
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_GHO_MPZ_T) {
    int* p_r = (int*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r > 0 && p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, gho_mpz_t) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(int, gho_mpz_t) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += (int)p_i;
  }
  #endif
  
  // gho_lint & int
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_INT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += *p_i;
  }
  // gho_lint & gho_lint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, gho_lint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += *p_i;
  }
  // gho_lint & gho_llint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LLINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, gho_llint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += (gho_lint)*p_i;
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r > 0 && p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_lint, gho_mpz_t) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += (gho_lint)p_i;
  }
  #endif
  
  // gho_llint & int
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_INT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += *p_i;
  }
  // gho_llint & gho_lint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, gho_lint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += *p_i;
  }
  // gho_llint & gho_llint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LLINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, gho_llint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += *p_i;
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r > 0 && p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_add(gho_llint, gho_mpz_t) underflow!\n");
      exit(1);
    }
    #endif
    *p_r += p_i;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_INT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const int* const p_i = (int*)(i.p);
    if (*p_i > 0) {
      mpz_add_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else if (*p_i < 0) {
      mpz_sub_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
    }
  }
  // gho_mpz_t & gho_lint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    if (*p_i > 0) {
      mpz_add_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else if (*p_i < 0) {
      mpz_sub_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
    }
  }
  // gho_mpz_t & gho_llint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LLINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    if (tmp_i > 0) {
      mpz_add_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
    }
    else if (tmp_i < 0) {
      mpz_sub_ui(p_r->i, p_r->i, (gho_ulint)-tmp_i);
    }
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_add(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_add", r, i);
  }
}

/**
 * \brief r -= i
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_sub(gho_operand_t r, const gho_operand_t i) {
  
  // int & int
  if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_INT) {
    int* p_r = (int*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= *p_i;
  }
  // int & gho_lint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LINT) {
    int* p_r = (int*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, gho_lint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= (int)*p_i;
  }
  // int & gho_llint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LLINT) {
    int* p_r = (int*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, gho_llint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= (int)*p_i;
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_GHO_MPZ_T) {
    int* p_r = (int*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r > 0 && p_i < 0 && -p_i > INT_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, gho_mpz_t) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && p_i > 0 && -p_i < INT_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(int, gho_mpz_t) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= (int)p_i;
  }
  #endif
  
  // gho_lint & int
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_INT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r-= *p_i;
  }
  // gho_lint & gho_lint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, gho_lint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= *p_i;
  }
  // gho_lint & gho_llint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LLINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, gho_llint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= (gho_lint)*p_i;
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r > 0 && p_i < 0 && -p_i > LONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && p_i > 0 && -p_i < LONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_lint, gho_mpz_t) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= (gho_lint)p_i;
  }
  #endif
  
  // gho_llint & int
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_INT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= *p_i;
  }
  // gho_llint & gho_lint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, gho_lint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, gho_lint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= *p_i;
  }
  // gho_llint & gho_llint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LLINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r > 0 && *p_i < 0 && -*p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, gho_llint) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && *p_i > 0 && -*p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, gho_llint) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= *p_i;
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r > 0 && p_i < 0 && -p_i > LLONG_MAX - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, int) overflow!\n");
      exit(1);
    }
    if (*p_r < 0 && p_i > 0 && -p_i < LLONG_MIN - *p_r) {
      fprintf(stderr, "ERROR: gho_sub(gho_llint, int) underflow!\n");
      exit(1);
    }
    #endif
    *p_r -= p_i;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_INT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const int* const p_i = (int*)(i.p);
    if (*p_i > 0) {
      mpz_add_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else if (*p_i < 0) {
      mpz_sub_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
    }
  }
  // gho_mpz_t & gho_lint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    if (*p_i > 0) {
      mpz_add_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else if (*p_i < 0) {
      mpz_sub_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
    }
  }
  // gho_mpz_t & gho_llint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LLINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    if (tmp_i > 0) {
      mpz_add_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
    }
    else if (tmp_i < 0) {
      mpz_sub_ui(p_r->i, p_r->i, (gho_ulint)-tmp_i);
    }
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_add(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_sub", r, i);
  }
}

/**
 * \brief r *= i
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_mul(gho_operand_t r, const gho_operand_t i) {
  
  // int & int
  if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_INT) {
    int* p_r = (int*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && abs(*p_i) > INT_MAX / abs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(int, int) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= *p_i;
  }
  // int & gho_lint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LINT) {
    int* p_r = (int*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && labs(*p_i) > INT_MAX / abs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(int, gho_lint) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= (int)*p_i;
  }
  // int & gho_llint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LLINT) {
    int* p_r = (int*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && llabs(*p_i) > INT_MAX / abs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(int, gho_llint) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= (int)*p_i;
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_GHO_MPZ_T) {
    int* p_r = (int*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r != 0 && p_i != 0 && llabs(p_i) > INT_MAX / abs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(int, gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= (int)p_i;
  }
  #endif
  
  // gho_lint & int
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_INT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && abs(*p_i) > LONG_MAX / labs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_lint, int) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= *p_i;
  }
  // gho_lint & gho_lint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && labs(*p_i) > LONG_MAX / labs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_lint, gho_lint) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= *p_i;
  }
  // gho_lint & gho_llint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LLINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && p_i != 0 && llabs(*p_i) > LONG_MAX / labs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_lint, gho_llint) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= (gho_lint)*p_i;
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r != 0 && p_i != 0 && llabs(p_i) > LONG_MAX / labs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_lint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= (gho_lint)p_i;
  }
  #endif
  
  // gho_llint & int
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_INT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const int* const p_i = (int*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && abs(*p_i) > LLONG_MAX / llabs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_llint, int) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= *p_i;
  }
  // gho_llint & gho_lint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && labs(*p_i) > LLONG_MAX / llabs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_llint, gho_lint) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= *p_i;
  }
  // gho_llint & gho_llint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LLINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    #ifndef NDEBUG
    if (*p_r != 0 && *p_i != 0 && llabs(*p_i) > LLONG_MAX / llabs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_llint, gho_llint) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= *p_i;
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    #ifndef NDEBUG
    if (*p_r != 0 && p_i != 0 && llabs(p_i) > LLONG_MAX / llabs(*p_r)) {
      fprintf(stderr, "ERROR: gho_mul(gho_llint, gho_mpz_t) overflow!\n");
      exit(1);
    }
    #endif
    *p_r *= p_i;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_INT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const int* const p_i = (int*)(i.p);
    mpz_mul_si(p_r->i, p_r->i, *p_i);
  }
  // gho_mpz_t & gho_lint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    mpz_mul_si(p_r->i, p_r->i, *p_i);
  }
  // gho_mpz_t & gho_llint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LLINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    mpz_mul_si(p_r->i, p_r->i, tmp_i);
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_mul(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_mul", r, i);
  }
}

/**
 * \brief r /= i (exact division)
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_div_exact(gho_operand_t r, const gho_operand_t i) {
  
  #ifndef NDEBUG
  if (gho_op_is_0(i)) {
    fprintf(stderr, "ERROR: gho_div_exact(r, i): i can not be equal to 0!\n");
    exit(1);
  }
  #endif
  
  // Not gho_mpz_t & *
  if (r.type != GHO_TYPE_GHO_MPZ_T) {
    gho_floor_div_q(r, i);
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t & not gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type != GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    if (tmp_i > 0) {
      mpz_divexact_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
    }
    else {
      mpz_divexact_ui(p_r->i, p_r->i, (gho_ulint)-tmp_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_divexact(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_div_exact", r, i);
  }
}

/**
 * \brief r /= i
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_floor_div_q(gho_operand_t r, const gho_operand_t i) {
  
  #ifndef NDEBUG
  if (gho_op_is_0(i)) {
    fprintf(stderr, "ERROR: gho_floor_div_q(r, i): i can not be equal to 0!\n");
    exit(1);
  }
  #endif
  
  // int & int
  if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_INT) {
    int* p_r = (int*)(r.p);
    const int* const p_i = (int*)(i.p);
    *p_r /= *p_i;
  }
  // int & gho_lint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LINT) {
    int* p_r = (int*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    *p_r /= (int)*p_i;
  }
  // int & gho_llint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LLINT) {
    int* p_r = (int*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    *p_r /= (int)*p_i;
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_GHO_MPZ_T) {
    int* p_r = (int*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    *p_r /= (int)p_i;
  }
  #endif
  
  // gho_lint & int
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_INT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const int* const p_i = (int*)(i.p);
    *p_r /= *p_i;
  }
  // gho_lint & gho_lint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    *p_r /= *p_i;
  }
  // gho_lint & gho_llint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LLINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    *p_r /= (gho_lint)*p_i;
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    *p_r /= (gho_lint)p_i;
  }
  #endif
  
  // gho_llint & int
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_INT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const int* const p_i = (int*)(i.p);
    *p_r /= *p_i;
  }
  // gho_llint & gho_lint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    *p_r /= *p_i;
  }
  // gho_llint & gho_llint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LLINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    *p_r /= *p_i;
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    *p_r /= p_i;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_INT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const int* const p_i = (int*)(i.p);
    if (*p_i > 0) {
      mpz_fdiv_q_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else {
      mpz_fdiv_q_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_lint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    if (*p_i > 0) {
      mpz_fdiv_q_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else {
      mpz_fdiv_q_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_llint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LLINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    if (tmp_i > 0) {
      mpz_fdiv_q_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
    }
    else {
      mpz_fdiv_q_ui(p_r->i, p_r->i, (gho_ulint)-tmp_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_fdiv_q(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_floor_div_q", r, i);
  }
}

/**
 * \brief r = r % i (remainder operator)
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_floor_div_r(gho_operand_t r, const gho_operand_t i) {
  
  #ifndef NDEBUG
  if (gho_op_is_0(i)) {
    fprintf(stderr, "ERROR: gho_floor_div_r(r, i): i can not be equal to 0!\n");
    exit(1);
  }
  #endif
  
  // int & int
  if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_INT) {
    int* p_r = (int*)(r.p);
    const int* const p_i = (int*)(i.p);
    *p_r %= *p_i;
  }
  // int & gho_lint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LINT) {
    int* p_r = (int*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    *p_r %= (int)*p_i;
  }
  // int & gho_llint
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_LLINT) {
    int* p_r = (int*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    *p_r %= (int)*p_i;
  }
  #ifdef gho_with_gmp
  // int & gho_mpz_t
  else if (r.type == GHO_TYPE_INT && i.type == GHO_TYPE_GHO_MPZ_T) {
    int* p_r = (int*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    *p_r %= (int)p_i;
  }
  #endif
  
  // gho_lint & int
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_INT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const int* const p_i = (int*)(i.p);
    *p_r %= *p_i;
  }
  // gho_lint & gho_lint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    *p_r %= *p_i;
  }
  // gho_lint & gho_llint
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_LLINT) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    *p_r %= (gho_lint)*p_i;
  }
  #ifdef gho_with_gmp
  // gho_lint & gho_mpz_t
  else if (r.type == GHO_TYPE_LINT && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_lint* p_r = (gho_lint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    *p_r %= (gho_lint)p_i;
  }
  #endif
  
  // gho_llint & int
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_INT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const int* const p_i = (int*)(i.p);
    *p_r %= *p_i;
  }
  // gho_llint & gho_lint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    *p_r %= *p_i;
  }
  // gho_llint & gho_llint
  else if (r.type == GHO_TYPE_LLINT && i.type == GHO_TYPE_LLINT) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint* const p_i = (gho_llint*)(i.p);
    *p_r %= *p_i;
  }
  #ifdef gho_with_gmp
  // gho_llint & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_llint* p_r = (gho_llint*)(r.p);
    const gho_llint p_i = gho_operand_to_lli(i);
    *p_r %= p_i;
  }
  #endif
  
  #ifdef gho_with_gmp
  // gho_mpz_t & int
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_INT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const int* const p_i = (int*)(i.p);
    if (*p_i > 0) {
      mpz_fdiv_r_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else {
      mpz_fdiv_r_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_lint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint* const p_i = (gho_lint*)(i.p);
    if (*p_i > 0) {
      mpz_fdiv_r_ui(p_r->i, p_r->i, (gho_ulint)*p_i);
    }
    else {
      mpz_fdiv_r_ui(p_r->i, p_r->i, (gho_ulint)-*p_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_llint
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_LLINT) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    if (tmp_i > 0) {
      mpz_fdiv_r_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
    }
    else {
      mpz_fdiv_r_ui(p_r->i, p_r->i, (gho_ulint)-tmp_i);
      mpz_neg(p_r->i, p_r->i);
    }
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_fdiv_r(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_floor_div_r", r, i);
  }
}

/**
 * \brief r = r % i (modulo operator)
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_mod(gho_operand_t r, const gho_operand_t i) {
  gho_floor_div_r(r, i);
  gho_abs(r);
}

/**
 * \brief r = r ^ i (power)
 * \param[in] r A gho_operand
 * \param[in] i A gho_operand
 */
void gho_pow(gho_operand_t r, const gho_operand_t i) {
  
  #ifndef NDEBUG
  if (gho_op_is_negatif(i)) {
    fprintf(stderr, "ERROR: gho_pow(r, i): i can not be lesser than 0!\n");
    exit(1);
  }
  #endif
  
  // i == 0
  if (gho_op_is_0(i)) {
    gho_set_1(r);
    return;
  }
  
  // i == 1
  if (gho_op_is_0(i)) {
    return;
  }
  
  // Not gho_mpz_t & *
  if (r.type != GHO_TYPE_GHO_MPZ_T) {
    const gho_llint tmp_r = gho_operand_to_lli(r);
    const gho_llint tmp_i = gho_operand_to_lli(i);
    for (gho_llint n = 0; n < tmp_i; ++n) {
      gho_mul_lli(r, tmp_r);
    }
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t & not gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type != GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    mpz_pow_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    mpz_pow_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_pow", r, i);
  }
}

/**
 * \brief r = greater_common_divisor(r, i)
 * \param[in] fonction_name Name of the function
 * \param[in] r             A gho_operand
 * \param[in] i             A gho_operand
 */
void gho_gcd(gho_operand_t r, const gho_operand_t i) {
  
  // Not gho_mpz_t & *
  if (r.type != GHO_TYPE_GHO_MPZ_T) {
    const gho_llint tmp_r = gho_operand_to_lli(r);
    const gho_llint tmp_i = gho_operand_to_lli(i);
    gho_set_lli(r, gho_llint_gcd(tmp_r, tmp_i));
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t & not gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type != GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    const gho_lint tmp_i = gho_operand_to_li(i);
    if (tmp_i > 0) {
      mpz_gcd_ui(p_r->i, p_r->i, (gho_ulint)tmp_i);
    }
    else {
      mpz_gcd_ui(p_r->i, p_r->i, (gho_ulint)-tmp_i);
    }
  }
  // gho_mpz_t & gho_mpz_t
  else if (r.type == GHO_TYPE_GHO_MPZ_T && i.type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_t* p_r = (gho_mpz_t*)(r.p);
    gho_mpz_t* p_i = (gho_mpz_t*)(i.p);
    mpz_gcd(p_r->i, p_r->i, p_i->i);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_2("gho_gcd", r, i);
  }
}
