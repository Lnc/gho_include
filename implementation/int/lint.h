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


#include <limits.h>
#include <ctype.h>
#include <stdlib.h>

#include "../../output.h"
#include "../../input.h"
#include "../../c_str.h"


// Create & destroy

/**
 * \brief Return a new long int
 * \return a new long int
 */
gho_lint gho_lint_create() {
  return 0;
}

/**
 * \brief Destroy a long int
 * \param[in] i A long int
 */
void gho_lint_destroy(gho_lint* i) {
  *i = 0;
}

/**
 * \brief Reset a long int
 * \param[in] i A long int
 */
void gho_lint_reset(gho_lint* i) {
  *i = 0;
}

// Output

/**
 * \brief Print a long int in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A long int
 * \param[in] indent indentation (number of spaces)
 */
void gho_lint_fprinti(FILE* file, const gho_lint* const i,
                      const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%li", *i);
}

/**
 * \brief Print a long int in a file
 * \param[in] file   A C file
 * \param[in] i      A long int
 */
void gho_lint_fprint(FILE* file, const gho_lint* const i) {
  gho_lint_fprinti(file, i, 0);
}

/**
 * \brief Print a long int in stdout
 * \param[in] i A long int
 */
void gho_lint_print(const gho_lint* const i) {
  printf("%li", *i);
}

/**
 * \brief Print a long int in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A long int
 * \param[in] indent indentation (number of spaces)
 */
void gho_lint_sprinti(char** c_str, const gho_lint* const i,
                      const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_lint_to_string(i);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a long int in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A long int
 */
void gho_lint_sprint(char** c_str, const gho_lint* const i) {
  gho_lint_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a long int from a file
 * \param[in] file A C file
 * \return the long int read
 */
gho_lint gho_lint_fread(FILE* file) {
  gho_lint r;
  fscanf(file, "%li", &r);
  gho_read_whitespace(file);
  return r;
}

/**
 * \brief Read a long int from a C string
 * \param[in] c_str A C string
 * \return the long int read
 */
gho_lint gho_lint_sread(const char** c_str) {
  gho_lint r = (gho_lint)atoi(*c_str);
  if (**c_str != '\0' && *(*c_str + 1) != '\0' &&
      **c_str == '-' && isdigit(*(*c_str + 1))) {
    ++(*c_str);
  }
  while (**c_str != '\0' && isspace(**c_str) == 0 && isdigit(**c_str)) {
    ++(*c_str);
  }
  gho_read_whitespace_from_c_str(c_str);
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a long int
 * \param[in] i A long int
 * \return the long int copied
 */
gho_lint gho_lint_copy(const gho_lint* const i) {
  return *i;
}

/**
 * \brief Copy a long int
 * \param[in] i    A long int
 * \param[in] copy A pointer on an not initialized long int
 * \warning Do not use this function, use gho_llint_copy
 */
void gho_lint_copy_(const gho_lint* const i, gho_lint* copy) {
  *copy = *i;
}

/**
 * \brief Equality between two long int
 * \param[in] a A long int
 * \param[in] b A long int
 * \return true if the long int are equals, false otherwise
 */
bool gho_lint_equal(const gho_lint* const a, const gho_lint* const b) {
  return *a == *b;
}

/**
 * \brief Compare two gho_lint
 * \param[in] a A gho_lint
 * \param[in] b A gho_lint
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_lint_compare(const gho_lint* const a, const gho_lint* const b) {
  if (*a < *b) { return -1; }
  else if (*a > *b) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a long int into a gho_string
 * \param[in] i A long int
 * \return the gho_string from the long int
 */
gho_string_t gho_lint_to_string(const gho_lint* const i) {
  gho_string_t r = gho_string_create();
  char tmp[sizeof(gho_lint) * CHAR_BIT + 1] = { '\0' };
  sprintf(tmp, "%li", *i);
  gho_string_add_c_str(&r, tmp);
  return r;
}

/**
 * \brief Convert a long int into a gho_any
 * \param[in] i A long int
 * \return the gho_any from the long int
 */
gho_any_t gho_lint_to_any(const gho_lint* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_LINT;
  r.size_of_struct = sizeof(gho_lint);
  gho_lint* p = gho_alloc(gho_lint); gho_lint_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_lint_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_lint_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_lint_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_lint_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_lint_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_lint_to_string;
  return r;
}
