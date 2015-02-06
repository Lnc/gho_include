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
 * \brief Return a new size_t
 * \return a new size_t
 */
size_t gho_size_t_create() {
  return 0;
}

/**
 * \brief Destroy a size_t
 * \param[in] i A size_t
 */
void gho_size_t_destroy(size_t* i) {
  *i = 0;
}

/**
 * \brief Reset a size_t
 * \param[in] i A size_t
 */
void gho_size_t_reset(size_t* i) {
  *i = 0;
}

// Output

/**
 * \brief Print a size_t in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A size_t
 * \param[in] indent Indentation (number of spaces)
 */
void gho_size_t_fprinti(FILE* file, const size_t* const i,
                        const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%lu", *i);
}

/**
 * \brief Print a size_t in a file
 * \param[in] file   A C file
 * \param[in] i      A size_t
 */
void gho_size_t_fprint(FILE* file, const size_t* const i) {
  gho_size_t_fprinti(file, i, 0);
}

/**
 * \brief Print a size_t in stdout
 * \param[in] i A size_t
 */
void gho_size_t_print(const size_t* const i) {
  gho_size_t_fprint(stdout, i);
}

/**
 * \brief Print a size_t in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A size_t
 * \param[in] indent Indentation (number of spaces)
 */
void gho_size_t_sprinti(char** c_str, const size_t* const i,
                        const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_size_t_to_string(i);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a size_t in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A size_t
 */
void gho_size_t_sprint(char** c_str, const size_t* const i) {
  gho_size_t_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a size_t from a file
 * \param[in] file A C file
 * \return the size_t read
 */
size_t gho_size_t_fread(FILE* file) {
  gho_read_whitespace(file);
  size_t r;
  fscanf(file, "%lu", &r);
  return r;
}

/**
 * \brief Read a size_t from a C string
 * \param[in] c_str A C string
 * \return the size_t read
 */
size_t gho_size_t_sread(const char** c_str) {
  gho_read_whitespace_from_c_str(c_str);
  size_t r = (size_t)atoi(*c_str);
  while (**c_str != '\0' && isspace(**c_str) == 0 && isdigit(**c_str)) {
    ++(*c_str);
  }
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a size_t
 * \param[in] i A size_t
 * \return the size_t copied
 */
size_t gho_size_t_copy(const size_t* const i) {
  return *i;
}

/**
 * \brief Copy a size_t
 * \param[in] i    A size_t
 * \param[in] copy A pointer on an not initialized size_t
 * \warning Do not use this function, use gho_llint_copy
 */
void gho_size_t_copy_(const size_t* const i, size_t* copy) {
  *copy = *i;
}

/**
 * \brief Equality between two size_t
 * \param[in] a A size_t
 * \param[in] b A size_t
 * \return true if the size_t are equals, false otherwise
 */
bool gho_size_t_equal(const size_t* const a, const size_t* const b) {
  return *a == *b;
}

/**
 * \brief Compare two size_t
 * \param[in] a A size_t
 * \param[in] b A size_t
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_size_t_compare(const size_t* const a, const size_t* const b) {
  if (*a < *b) { return -1; }
  else if (*a > *b) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a size_t into a gho_string
 * \param[in] i A size_t
 * \return the gho_string from the size_t
 */
gho_string_t gho_size_t_to_string(const size_t* const i) {
  gho_string_t r = gho_string_create();
  char tmp[sizeof(size_t) * CHAR_BIT + 1] = { '\0' };
  sprintf(tmp, "%lu", *i);
  gho_string_add_c_str(&r, tmp);
  return r;
}

/**
 * \brief Convert a size_t into a gho_any
 * \param[in] i A size_t
 * \return the gho_any from the size_t
 */
gho_any_t gho_size_t_to_any(const size_t* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_SIZE_T;
  r.size_of_struct = sizeof(size_t);
  size_t* p = gho_alloc(size_t); gho_size_t_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_size_t_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_size_t_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_size_t_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_size_t_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_size_t_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_size_t_to_string;
  return r;
}
