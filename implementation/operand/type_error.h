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


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// gho_operand_type_error_N

static inline
void gho_operand_type_error_1(const char* const fonction_name,
                              const gho_operand_t a);
static inline
void gho_operand_type_error_2(const char* const fonction_name,
                              const gho_operand_t a,
                              const gho_operand_t b);
static inline
void gho_operand_type_error_3(const char* const fonction_name,
                              const gho_operand_t a,
                              const gho_operand_t b,
                              const gho_operand_t c);

/**
 * \brief Display error for one gho_operand
 * \param[in] fonction_name Name of the function
 * \param[in] a             A gho_operand
 */
void gho_operand_type_error_1(const char* const fonction_name,
                              const gho_operand_t a) {
  fprintf(stderr, "TODO: %s is not implemented for type (%i)\n",
                  fonction_name, a.type);
  exit(1);
}

/**
 * \brief Display error for two gho_operand
 * \param[in] fonction_name Name of the function
 * \param[in] a             A gho_operand
 * \param[in] b             A gho_operand
 */
void gho_operand_type_error_2(const char* const fonction_name,
                              const gho_operand_t a,
                              const gho_operand_t b) {
  fprintf(stderr, "TODO: %s is not implemented for types (%i, %i)\n",
                  fonction_name, a.type, b.type);
  exit(1);
}

/**
 * \brief Display error for three gho_operand
 * \param[in] fonction_name Name of the function
 * \param[in] a             A gho_operand
 * \param[in] b             A gho_operand
 * \param[in] c             A gho_operand
 */
void gho_operand_type_error_3(const char* const fonction_name,
                              const gho_operand_t a,
                              const gho_operand_t b,
                              const gho_operand_t c) {
  fprintf(stderr, "TODO: %s is not implemented for types (%i, %i, %i)\n",
                  fonction_name, a.type, b.type, c.type);
  exit(1);
}
