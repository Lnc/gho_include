// Copyright © 2015 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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



// Output


/**
 * \brief Print a gho_operand_t in a file with indentation
 * \param[in] file   A C file
 * \param[in] op     A gho_operand_t
 * \param[in] indent Indentation (number of spaces)
 */
void gho_operand_fprinti(FILE* file, const gho_operand_t* const op,
                         const unsigned int indent) {
  // int
  if (op->type == GHO_TYPE_INT) {
    gho_int_fprinti(file, (int*)(op->p), indent);
  }
  
  // gho_lint
  else if (op->type == GHO_TYPE_LINT) {
    gho_lint_fprinti(file, (gho_lint*)(op->p), indent);
  }
  
  // gho_llint
  else if (op->type == GHO_TYPE_LLINT) {
    gho_llint_fprinti(file, (gho_llint*)(op->p), indent);
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (op->type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_fprinti(file, (gho_mpz_t*)(op->p), indent);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_operand_fprinti", *op);
  }
}

/**
 * \brief Print a gho_operand_t in a file
 * \param[in] file A C file
 * \param[in] op   A gho_operand_t
 */
void gho_operand_fprint(FILE* file, const gho_operand_t* const op) {
  gho_operand_fprinti(file, op, 0);
}


/**
 * \brief Print a gho_operand_t in stdout
 * \param[in] string A gho_operand_t
 */
void gho_operand_print(const gho_operand_t* const op) {
  gho_operand_fprint(stdout, op);
}

/**
 * \brief Print a gho_operand_t in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] op     A gho_operand_t
 * \param[in] indent Indentation (number of spaces)
 */
void gho_operand_sprinti(char** c_str, const gho_operand_t* const op,
                        const unsigned int indent) {
  // int
  if (op->type == GHO_TYPE_INT) {
    gho_int_sprinti(c_str, (int*)(op->p), indent);
  }
  
  // gho_lint
  else if (op->type == GHO_TYPE_LINT) {
    gho_lint_sprinti(c_str, (gho_lint*)(op->p), indent);
  }
  
  // gho_llint
  else if (op->type == GHO_TYPE_LLINT) {
    gho_llint_sprinti(c_str, (gho_llint*)(op->p), indent);
  }
  
  #ifdef gho_with_gmp
  // gho_mpz_t
  else if (op->type == GHO_TYPE_GHO_MPZ_T) {
    gho_mpz_sprinti(c_str, (gho_mpz_t*)(op->p), indent);
  }
  #endif
  
  // Other
  else {
    gho_operand_type_error_1("gho_operand_fprinti", *op);
  }
}

/**
 * \brief Print a gho_operand_t in a C string
 * \param[in] c_str A C string
 * \param[in] op    A gho_operand_t
 */
void gho_operand_sprint(char** c_str, const gho_operand_t* const op) {
  gho_operand_sprinti(c_str, op, 0);
}