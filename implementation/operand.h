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


#include "../memory.h"


// Create & destroy

// gho_operand_t

/**
 * \brief Return a new gho_operand_t
 * \return a new gho_operand_t
 */
gho_operand_t gho_operand_create() {
  gho_operand_t r;
  r.type = GHO_TYPE_NULL;
  r.p = NULL;
  return r;
}

/**
 * \brief Destroy a gho_operand_t
 * \param[in] op A gho_operand_t
 */
void gho_operand_destroy(gho_operand_t* op) {
  
  // int
  if (op->type == GHO_TYPE_INT) {
    gho_int_destroy((int*)(op->p));
  }
  
  // gho_lint
  else if (op->type == GHO_TYPE_LINT) {
    gho_lint_destroy((gho_lint*)(op->p));
  }
  
  // gho_llint
  else if (op->type == GHO_TYPE_LLINT) {
    gho_llint_destroy((gho_llint*)(op->p));
  }
  
  // gho_mpz_t
  else if (op->type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_destroy((gho_mpz_t*)(op->p));
  }
  
  free(op->p);
  
  op->type = GHO_TYPE_NULL;
  op->p = NULL;
}

/**
 * \brief Reset a gho_operand_t
 * \param[in] op A gho_operand_t
 */
void gho_operand_reset(gho_operand_t* op) {
  gho_operand_destroy(op);
  *op = gho_operand_create();
}

// gho_coperand_t

/**
 * \brief Return a new gho_operand_t
 * \return a new gho_operand_t
 */
gho_coperand_t gho_coperand_create() {
  gho_coperand_t r;
  r.type = GHO_TYPE_NULL;
  r.p = NULL;
  return r;
}

/**
 * \brief Destroy a gho_operand_t
 * \param[in] op A gho_operand_t
 */
void gho_coperand_destroy(gho_coperand_t* op) {
  op->type = GHO_TYPE_NULL;
  op->p = NULL;
}

/**
 * \brief Reset a gho_operand_t
 * \param[in] op A gho_operand_t
 */
void gho_coperand_reset(gho_coperand_t* op);

// Copy

// gho_operand_t

/**
 * \brief Copy a gho_operand_t
 * \param[in] op A gho_operand_t
 * \return the gho_operand_t copied
 */
gho_operand_t gho_operand_copy(const gho_operand_t* const op) {
  gho_operand_t r;
  gho_operand_copy_(op, &r);
  return r;
}

/**
 * \brief Copy a gho_operand_t
 * \param[in] op   A gho_operand_t
 * \param[in] copy A pointer on an not initialized gho_operand_t
 * \warning Do not use this function, use gho_char_copy
 */
void gho_operand_copy_(const gho_operand_t* const op, gho_operand_t* copy) {
  
  *copy = gho_operand_create();
  copy->type = op->type;
  
  // int
  if (copy->type == GHO_TYPE_INT) {
    copy->p = gho_alloc(int);
    *(int*)copy->p = gho_int_copy((int*)(op->p));
  }
  
  // gho_lint
  else if (copy->type == GHO_TYPE_LINT) {
    copy->p = gho_alloc(gho_lint);
    *(gho_lint*)copy->p = gho_lint_copy((gho_lint*)(op->p));
  }
  
  // gho_llint
  else if (copy->type == GHO_TYPE_LLINT) {
    copy->p = gho_alloc(gho_llint);
    *(gho_llint*)copy->p = gho_llint_copy((gho_llint*)(op->p));
  }
  
  // gho_mpz_t
  else if (copy->type == GHO_TYPE_GHO_MPZ_T) {
    copy->p = gho_alloc(gho_mpz_t);
    *(gho_mpz_t*)copy->p = gho_mpz_copy((gho_mpz_t*)(op->p));
  }
}

// gho_coperand_t

/**
 * \brief Copy a gho_coperand_t
 * \param[in] cop A gho_coperand_t
 * \return the gho_coperand_t copied
 */
gho_coperand_t gho_coperand_copy(const gho_coperand_t* const cop) {
  gho_coperand_t r;
  gho_coperand_copy_(cop, &r);
  return r;
}

/**
 * \brief Copy a gho_coperand_t
 * \param[in] cop  A gho_coperand_t
 * \param[in] copy A pointer on an not initialized gho_coperand_t
 * \warning Do not use this function, use gho_char_copy
 */
void gho_coperand_copy_(const gho_coperand_t* const cop, gho_coperand_t* copy) {
  copy->type = cop->type;
  copy->p = cop->p;
}


#include "operand/type_error.h"
#include "operand/assignment.h"
#include "operand/binary_operators.h"
#include "operand/binary_operators_with_immediate.h"
#include "operand/comparison_operators_with_0_and_1.h"
#include "operand/conversion_to_operand.h"
#include "operand/other_functions.h"
#include "operand/output.h"
#include "operand/comparison_operators.h"
#include "operand/conversion_to_integer.h"
#include "operand/mathematical_functions.h"
#include "operand/unary_operators.h"
