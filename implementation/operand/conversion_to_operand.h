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


#include "../../vector/int.h"
#include "../../matrix/int.h"
#include "../../matrix/lint.h"
#include "../../matrix/llint.h"
#include "../../matrix/mpz_t.h"


// Conversion to gho_operand_t

/**
 * \brief Create a gho_operand_t
 * \param[in] p A generic type which works with gho_type function
 * \return the gho_operand_t created
 */
gho_operand_t gho_operand(void* p) {
  return gho_operand_type(p, gho_type(p));
}

/**
 * \brief Create a gho_operand_t
 * \param[in] p    A generic type
 * \param[in] type A gho_dynamic_type
 * \return the gho_operand_t created
 */
gho_operand_t gho_operand_type(void* p, const gho_type_t type) {
  gho_operand_t r = { type, p };
  return r;
}

/**
 * \brief Create a gho_operand_t
 * \param[in] p A generic type which works with gho_type function
 * \param[in] i An index
 * \return the gho_operand_t created
 */
gho_operand_t gho_operand_i(void* p, const size_t i) {
  
  gho_operand_t r = { gho_type(p), NULL };
  
  if (r.type == GHO_TYPE_VECTOR_INT) {
    r.type = GHO_TYPE_INT;
    r.p = &((gho_vector_int_t*)p)->array[i];
  }
  
  // Other
  else {
    gho_operand_type_error_1("gho_operand_i", r);
  }
  
  return r;
}

/**
 * \brief Create a gho_operand_t
 * \param[in] p A generic type which works with gho_type function
 * \param[in] i An index
 * \param[in] j An index
 * \return the gho_operand_t created
 */
gho_operand_t gho_operand_i_j(void* p, const size_t i, const size_t j) {
  
  gho_operand_t r = { gho_type(p), NULL };
  
  if (r.type == GHO_TYPE_MATRIX_INT) {
    r.type = GHO_TYPE_INT;
    r.p = &((gho_matrix_int_t*)p)->array[i][j];
  }
  
  else if (r.type == GHO_TYPE_MATRIX_LINT) {
    r.type = GHO_TYPE_LINT;
    r.p = &((gho_matrix_lint_t*)p)->array[i][j];
  }
  
  else if (r.type == GHO_TYPE_MATRIX_LLINT) {
    r.type = GHO_TYPE_LLINT;
    r.p = &((gho_matrix_llint_t*)p)->array[i][j];
  }
  
  #ifdef gho_with_gmp
  else if (r.type == GHO_TYPE_MATRIX_MPZ_T) {
    r.type = GHO_TYPE_GHO_MPZ_T;
    r.p = &((gho_matrix_mpz_t*)p)->array[i][j];
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_operand_i_j", r);
  }
  
  return r;
}

// Conversion to gho_coperand_t

/**
 * \brief Create a gho_coperand_t
 * \param[in] p A generic type which works with gho_type function
 * \return the gho_coperand_t created
 */
gho_coperand_t gho_coperand(const void* p) {
  return gho_coperand_type(p, gho_type(p));
}

/**
 * \brief Create a gho_coperand_t
 * \param[in] p    A generic type
 * \param[in] type A gho_dynamic_type
 * \return the gho_coperand_t created
 */
gho_coperand_t gho_coperand_type(const void* p, const gho_type_t type) {
  gho_coperand_t r = { type, p };
  return r;
}

/**
 * \brief Create a gho_coperand_t
 * \param[in] p A generic type which works with gho_type function
 * \param[in] i An index
 * \return the gho_coperand_t created
 */
gho_coperand_t gho_coperand_i(const void* p, const size_t i) {
  
  gho_coperand_t r = { gho_type(p), NULL };
  
  if (r.type == GHO_TYPE_VECTOR_INT) {
    r.type = GHO_TYPE_INT;
    r.p = &((const gho_vector_int_t*)p)->array[i];
  }
  
  // Other
  else {
    gho_coperand_type_error_1("gho_coperand_i", r);
  }
  
  return r;
}

/**
 * \brief Create a gho_coperand_t
 * \param[in] p A generic type which works with gho_type function
 * \param[in] i An index
 * \param[in] j An index
 * \return the gho_coperand_t created
 */
gho_coperand_t gho_coperand_i_j(const void* p, const size_t i, const size_t j) {
  
  gho_coperand_t r = { gho_type(p), NULL };
  
  if (r.type == GHO_TYPE_MATRIX_INT) {
    r.type = GHO_TYPE_INT;
    r.p = &((const gho_matrix_int_t*)p)->array[i][j];
  }
  
  else if (r.type == GHO_TYPE_MATRIX_LINT) {
    r.type = GHO_TYPE_LINT;
    r.p = &((const gho_matrix_lint_t*)p)->array[i][j];
  }
  
  else if (r.type == GHO_TYPE_MATRIX_LLINT) {
    r.type = GHO_TYPE_LLINT;
    r.p = &((const gho_matrix_llint_t*)p)->array[i][j];
  }
  
  #ifdef gho_with_gmp
  else if (r.type == GHO_TYPE_MATRIX_MPZ_T) {
    r.type = GHO_TYPE_GHO_MPZ_T;
    r.p = &((const gho_matrix_mpz_t*)p)->array[i][j];
  }
  #endif
  
  // Other
  else {
    gho_coperand_type_error_1("gho_coperand_i_j", r);
  }
  
  return r;
}
