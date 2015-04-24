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
 * \brief Return a new unsigned long int
 * \return a new unsigned long int
 * @relates gho_ullint
 */
gho_ullint gho_ullint_create() {
  return 0;
}

/**
 * \brief Destroy a unsigned long int
 * \param[in] i A unsigned long int
 * @relates gho_ullint
 */
void gho_ullint_destroy(gho_ullint* i) {
  *i = 0;
}

/**
 * \brief Reset a unsigned long int
 * \param[in] i A unsigned long int
 * @relates gho_ullint
 */
void gho_ullint_reset(gho_ullint* i) {
  *i = 0;
}

// Output

/**
 * \brief Print a unsigned long int in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A unsigned long int
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_ullint
 */
void gho_ullint_fprinti(FILE* file, const gho_ullint* const i,
                       const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%llu", *i);
}

/**
 * \brief Print a unsigned long int in a file
 * \param[in] file   A C file
 * \param[in] i      A unsigned long int
 * @relates gho_ullint
 */
void gho_ullint_fprint(FILE* file, const gho_ullint* const i) {
  gho_ullint_fprinti(file, i, 0);
}

/**
 * \brief Print a unsigned long int in stdout
 * \param[in] i A unsigned long int
 * @relates gho_ullint
 */
void gho_ullint_print(const gho_ullint* const i) {
  gho_ullint_fprint(stdout, i);
}

/**
 * \brief Print a unsigned long int in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A unsigned long int
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_ullint
 */
void gho_ullint_sprinti(char** c_str, const gho_ullint* const i,
                       const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_ullint_to_string(i);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a unsigned long int in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A unsigned long int
 * @relates gho_ullint
 */
void gho_ullint_sprint(char** c_str, const gho_ullint* const i) {
  gho_ullint_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a unsigned long int from a file
 * \param[in] file A C file
 * \return the unsigned long int read
 * @relates gho_ullint
 */
gho_ullint gho_ullint_fread(FILE* file) {
  gho_read_whitespace(file);
  gho_ullint r;
  fscanf(file, "%llu", &r);
  return r;
}

/**
 * \brief Read a unsigned long int from a C string
 * \param[in] c_str A C string
 * \return the unsigned long int read
 * @relates gho_ullint
 */
gho_ullint gho_ullint_sread(const char** c_str) {
  gho_read_whitespace_from_c_str(c_str);
  gho_ullint r = (gho_ullint)atoi(*c_str);
  while (**c_str != '\0' && isspace(**c_str) == 0 && isdigit(**c_str)) {
    ++(*c_str);
  }
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a unsigned long int
 * \param[in] i A unsigned long int
 * \return the unsigned long int copied
 * @relates gho_ullint
 */
gho_ullint gho_ullint_copy(const gho_ullint* const i) {
  return *i;
}

/**
 * \brief Copy a unsigned long int
 * \param[in] i    A unsigned long int
 * \param[in] copy A pointer on an not initialized unsigned long int
 * \warning Do not use this function, use gho_llint_copy
 * @relates gho_ullint
 */
void gho_ullint_copy_(const gho_ullint* const i, gho_ullint* copy) {
  *copy = *i;
}

/**
 * \brief Equality between two unsigned long int
 * \param[in] a A unsigned long int
 * \param[in] b A unsigned long int
 * \return true if the unsigned long int are equals, false otherwise
 * @relates gho_ullint
 */
bool gho_ullint_equal(const gho_ullint* const a, const gho_ullint* const b) {
  return *a == *b;
}

/**
 * \brief Compare two gho_ullint
 * \param[in] a A gho_ullint
 * \param[in] b A gho_ullint
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 * @relates gho_ullint
 */
int gho_ullint_compare(const gho_ullint* const a, const gho_ullint* const b) {
  if (*a < *b) { return -1; }
  else if (*a > *b) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a unsigned long int into a gho_string
 * \param[in] i A unsigned long int
 * \return the gho_string from the unsigned long int
 * @relates gho_ullint
 */
gho_string_t gho_ullint_to_string(const gho_ullint* const i) {
  gho_string_t r = gho_string_create();
  char tmp[sizeof(gho_ullint) * CHAR_BIT + 1] = { '\0' };
  sprintf(tmp, "%llu", *i);
  gho_string_add_c_str(&r, tmp);
  return r;
}

/**
 * \brief Convert a unsigned long int into a gho_any
 * \param[in] i A unsigned long int
 * \return the gho_any from the unsigned long int
 * @relates gho_ullint
 */
gho_any_t gho_ullint_to_any(const gho_ullint* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_ULINT;
  r.size_of_struct = sizeof(gho_ullint);
  gho_ullint* p = gho_alloc(gho_ullint); gho_ullint_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_ullint_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_ullint_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_ullint_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_ullint_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_ullint_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_ullint_to_string;
  return r;
}
