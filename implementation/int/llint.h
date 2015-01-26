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
 * \brief Return a new long long int
 * \return a new long long int
 */
gho_llint gho_llint_create() {
  return 0;
}

/**
 * \brief Destroy a long long int
 * \param[in] i A long long int
 */
void gho_llint_destroy(gho_llint* i) {
  *i = 0;
}

/**
 * \brief Reset a long long int
 * \param[in] i A long long int
 */
void gho_llint_reset(gho_llint* i) {
  *i = 0;
}

// Output

/**
 * \brief Print a long long int in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A long long int
 * \param[in] indent indentation (number of spaces)
 */
void gho_llint_fprinti(FILE* file, const gho_llint* const i,
                      const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%lli", *i);
}

/**
 * \brief Print a long long int in a file
 * \param[in] file   A C file
 * \param[in] i      A long long int
 */
void gho_llint_fprint(FILE* file, const gho_llint* const i) {
  gho_llint_fprinti(file, i, 0);
}

/**
 * \brief Print a long long int in stdout
 * \param[in] i A long long int
 */
void gho_llint_print(const gho_llint* const i) {
  printf("%lli", *i);
}

/**
 * \brief Print a long long int in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A long long int
 * \param[in] indent indentation (number of spaces)
 */
void gho_llint_sprinti(char** c_str, const gho_llint* const i,
                      const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_llint_to_string(i);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a long long int in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A long long int
 */
void gho_llint_sprint(char** c_str, const gho_llint* const i) {
  gho_llint_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a long long int from a file
 * \param[in] file A C file
 * \return the long long int read
 */
gho_llint gho_llint_fread(FILE* file) {
  gho_llint r;
  fscanf(file, "%lli", &r);
  gho_read_whitespace(file);
  return r;
}

/**
 * \brief Read a long long int from a C string
 * \param[in] c_str A C string
 * \return the long long int read
 */
gho_llint gho_llint_sread(const char** c_str) {
  gho_llint r = (gho_llint)atoi(*c_str);
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
 * \brief Copy a long long int
 * \param[in] i A long long int
 * \return the long long int copied
 */
gho_llint gho_llint_copy(const gho_llint* const i) {
  return *i;
}

/**
 * \brief Copy a long long int
 * \param[in] i    A long long int
 * \param[in] copy A pointer on an not initialized long long int
 * \warning Do not use this function, use gho_llint_copy
 */
void gho_llint_copy_(const gho_llint* const i, gho_llint* copy) {
  *copy = *i;
}

/**
 * \brief Equality between two long long int
 * \param[in] a A long long int
 * \param[in] b A long long int
 * \return true if the long long int are equals, false otherwise
 */
bool gho_llint_equal(const gho_llint* const a, const gho_llint* const b) {
  return *a == *b;
}

// Conversion

/**
 * \brief Convert a long long int into a gho_string
 * \param[in] i A long long int
 * \return the gho_string from the long long int
 */
gho_string_t gho_llint_to_string(const gho_llint* const i) {
  gho_string_t r = gho_string_create();
  char tmp[sizeof(gho_llint) * CHAR_BIT + 1] = { '\0' };
  sprintf(tmp, "%lli", *i);
  gho_string_add_c_str(&r, tmp);
  return r;
}

/**
 * \brief Convert a long long int into a gho_any
 * \param[in] i A long long int
 * \return the gho_any from the long long int
 */
gho_any_t gho_llint_to_any(const gho_llint* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_LLINT;
  r.size_of_struct = sizeof(gho_llint);
  gho_llint* p = gho_alloc(gho_llint); gho_llint_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_llint_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_llint_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_llint_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_llint_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_llint_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_llint_to_string;
  return r;
}
