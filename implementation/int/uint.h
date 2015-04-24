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
 * \brief Return a new unsigned int
 * \return a new unsigned int
 * @relates gho_uint
 */
gho_uint gho_uint_create() {
  return 0;
}

/**
 * \brief Destroy a unsigned int
 * \param[in] i A unsigned int
 * @relates gho_uint
 */
void gho_uint_destroy(gho_uint* i) {
  *i = 0;
}

/**
 * \brief Reset a unsigned int
 * \param[in] i A unsigned int
 * @relates gho_uint
 */
void gho_uint_reset(gho_uint* i) {
  *i = 0;
}

// Output

/**
 * \brief Print a unsigned int in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A unsigned int
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_uint
 */
void gho_uint_fprinti(FILE* file, const gho_uint* const i,
                      const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%u", *i);
}

/**
 * \brief Print a unsigned int in a file
 * \param[in] file   A C file
 * \param[in] i      A unsigned int
 * @relates gho_uint
 */
void gho_uint_fprint(FILE* file, const gho_uint* const i) {
  gho_uint_fprinti(file, i, 0);
}

/**
 * \brief Print a unsigned int in stdout
 * \param[in] i A unsigned int
 * @relates gho_uint
 */
void gho_uint_print(const gho_uint* const i) {
  gho_uint_fprint(stdout, i);
}

/**
 * \brief Print a unsigned int in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A unsigned int
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_uint
 */
void gho_uint_sprinti(char** c_str, const gho_uint* const i,
                      const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_uint_to_string(i);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a unsigned int in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A unsigned int
 * @relates gho_uint
 */
void gho_uint_sprint(char** c_str, const gho_uint* const i) {
  gho_uint_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a unsigned int from a file
 * \param[in] file A C file
 * \return the unsigned int read
 * @relates gho_uint
 */
gho_uint gho_uint_fread(FILE* file) {
  gho_read_whitespace(file);
  gho_uint r;
  fscanf(file, "%u", &r);
  return r;
}

/**
 * \brief Read a unsigned int from a C string
 * \param[in] c_str A C string
 * \return the unsigned int read
 * @relates gho_uint
 */
gho_uint gho_uint_sread(const char** c_str) {
  gho_read_whitespace_from_c_str(c_str);
  gho_uint r = (gho_uint)atoi(*c_str);
  while (**c_str != '\0' && isspace(**c_str) == 0 && isdigit(**c_str)) {
    ++(*c_str);
  }
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a unsigned int
 * \param[in] i A unsigned int
 * \return the unsigned int copied
 * @relates gho_uint
 */
gho_uint gho_uint_copy(const gho_uint* const i) {
  return *i;
}

/**
 * \brief Copy a unsigned int
 * \param[in] i    A unsigned int
 * \param[in] copy A pointer on an not initialized unsigned int
 * \warning Do not use this function, use gho_llint_copy
 * @relates gho_uint
 */
void gho_uint_copy_(const gho_uint* const i, gho_uint* copy) {
  *copy = *i;
}

/**
 * \brief Equality between two unsigned int
 * \param[in] a A unsigned int
 * \param[in] b A unsigned int
 * \return true if the unsigned int are equals, false otherwise
 * @relates gho_uint
 */
bool gho_uint_equal(const gho_uint* const a, const gho_uint* const b) {
  return *a == *b;
}

/**
 * \brief Compare two gho_uint
 * \param[in] a A gho_uint
 * \param[in] b A gho_uint
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 * @relates gho_uint
 */
int gho_uint_compare(const gho_uint* const a, const gho_uint* const b) {
  if (*a < *b) { return -1; }
  else if (*a > *b) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a unsigned int into a gho_string
 * \param[in] i A unsigned int
 * \return the gho_string from the unsigned int
 * @relates gho_uint
 */
gho_string_t gho_uint_to_string(const gho_uint* const i) {
  gho_string_t r = gho_string_create();
  char tmp[sizeof(gho_uint) * CHAR_BIT + 1] = { '\0' };
  sprintf(tmp, "%u", *i);
  gho_string_add_c_str(&r, tmp);
  return r;
}

/**
 * \brief Convert a unsigned int into a gho_any
 * \param[in] i A unsigned int
 * \return the gho_any from the unsigned int
 * @relates gho_uint
 */
gho_any_t gho_uint_to_any(const gho_uint* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_UINT;
  r.size_of_struct = sizeof(gho_uint);
  gho_uint* p = gho_alloc(gho_uint); gho_uint_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_uint_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_uint_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_uint_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_uint_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_uint_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_uint_to_string;
  return r;
}
