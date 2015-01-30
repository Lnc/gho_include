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
 * \brief Return a new int
 * \return a new int
 */
int gho_int_create() {
  return 0;
}

/**
 * \brief Destroy a int
 * \param[in] i A int
 */
void gho_int_destroy(int* i) {
  *i = 0;
}

/**
 * \brief Reset a int
 * \param[in] i A int
 */
void gho_int_reset(int* i) {
  *i = 0;
}

// Output

/**
 * \brief Print a int in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A int
 * \param[in] indent Indentation (number of spaces)
 */
void gho_int_fprinti(FILE* file, const int* const i,
                     const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%i", *i);
}

/**
 * \brief Print a int in a file
 * \param[in] file   A C file
 * \param[in] i      A int
 */
void gho_int_fprint(FILE* file, const int* const i) {
  gho_int_fprinti(file, i, 0);
}

/**
 * \brief Print a int in stdout
 * \param[in] i A int
 */
void gho_int_print(const int* const i) {
  gho_int_fprint(stdout, i);
}

/**
 * \brief Print a int in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A int
 * \param[in] indent Indentation (number of spaces)
 */
void gho_int_sprinti(char** c_str, const int* const i,
                     const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_int_to_string(i);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a int in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A int
 */
void gho_int_sprint(char** c_str, const int* const i) {
  gho_int_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a int from a file
 * \param[in] file A C file
 * \return the int read
 */
int gho_int_fread(FILE* file) {
  int r;
  fscanf(file, "%i", &r);
  gho_read_whitespace(file);
  return r;
}

/**
 * \brief Read a int from a C string
 * \param[in] c_str A C string
 * \return the int read
 */
int gho_int_sread(const char** c_str) {
  int r = atoi(*c_str);
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
 * \brief Copy a int
 * \param[in] i A int
 * \return the int copied
 */
int gho_int_copy(const int* const i) {
  return *i;
}

/**
 * \brief Copy a int
 * \param[in] i    A int
 * \param[in] copy A pointer on an not initialized int
 * \warning Do not use this function, use gho_llint_copy
 */
void gho_int_copy_(const int* const i, int* copy) {
 *copy = *i;
}

/**
 * \brief Equality between two int
 * \param[in] a A int
 * \param[in] b A int
 * \return true if the int are equals, false otherwise
 */
bool gho_int_equal(const int* const a, const int* const b) {
  return *a == *b;
}

/**
 * \brief Compare two int
 * \param[in] a A int
 * \param[in] b A int
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_int_compare(const int* const a, const int* const b) {
  if (*a < *b) { return -1; }
  else if (*a > *b) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a int into a gho_string
 * \param[in] i A int
 * \return the gho_string from the int
 */
gho_string_t gho_int_to_string(const int* const i) {
  gho_string_t r = gho_string_create();
  char tmp[sizeof(int) * CHAR_BIT + 1] = { '\0' };
  sprintf(tmp, "%i", *i);
  gho_string_add_c_str(&r, tmp);
  return r;
}

/**
 * \brief Convert a int into a gho_any
 * \param[in] i A int
 * \return the gho_any from the int
 */
gho_any_t gho_int_to_any(const int* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_INT;
  r.size_of_struct = sizeof(int);
  int* p = gho_alloc(int); gho_int_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_int_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_int_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_int_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_int_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_int_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_int_to_string;
  return r;
}
