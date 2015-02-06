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
 * \brief Return a new gho_mpz
 * \return a new gho_mpz
 */
gho_mpz_t gho_mpz_create() {
  gho_mpz_t i;
  mpz_init(i.i);
  return i;
}

/**
 * \brief Destroy a gho_mpz
 * \param[in] i A gho_mpz
 */
void gho_mpz_destroy(gho_mpz_t* i) {
  mpz_clear(i->i);
}

/**
 * \brief Reset a gho_mpz
 * \param[in] i A gho_mpz
 */
void gho_mpz_reset(gho_mpz_t* i) {
  gho_mpz_destroy(i);
  *i = gho_mpz_create();
}

// Output

/**
 * \brief Print a gho_mpz in a file with indentation
 * \param[in] file   A C file
 * \param[in] i      A gho_mpz
 * \param[in] indent Indentation (number of spaces)
 */
void gho_mpz_fprinti(FILE* file, const gho_mpz_t* const i,
                       const unsigned int indent) {
  gho_fprinti(file, indent);
  mpz_out_str(file, 10, i->i);
}

/**
 * \brief Print a gho_mpz in a file
 * \param[in] file A C file
 * \param[in] i    A gho_mpz
 */
void gho_mpz_fprint(FILE* file, const gho_mpz_t* const i) {
  gho_mpz_fprinti(file, i, 0);
}

/**
 * \brief Print a gho_mpz in stdout
 * \param[in] i A gho_mpz
 */
void gho_mpz_print(const gho_mpz_t* const i) {
  gho_mpz_fprint(stdout, i);
}

/**
 * \brief Print a gho_mpz in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] i      A gho_mpz
 * \param[in] indent Indentation (number of spaces)
 */
void gho_mpz_sprinti(char** c_str, const gho_mpz_t* const i,
                        const unsigned int indent) {
  gho_sprinti(c_str, indent);
  char* tmp = NULL;
  tmp = mpz_get_str(tmp, 10, i->i);
  gho_c_str_add(c_str, tmp);
  free(tmp); tmp = NULL;
}

/**
 * \brief Print a gho_mpz in a C string
 * \param[in] c_str  A C string
 * \param[in] i      A gho_mpz
 */
void gho_mpz_sprint(char** c_str, const gho_mpz_t* const i) {
  gho_mpz_sprinti(c_str, i, 0);
}

// Input

/**
 * \brief Read a gho_mpz from a file
 * \param[in] file A C file
 * \return the gho_mpz read
 */
gho_mpz_t gho_mpz_fread(FILE* file) {
  gho_read_whitespace(file);
  gho_mpz_t i = gho_mpz_create();
  mpz_inp_str(i.i, file, 10);
  return i;
}

/**
 * \brief Read a gho_mpz from a C string
 * \param[in] c_str A C string
 * \return the gho_mpz read
 */
gho_mpz_t gho_mpz_sread(const char** c_str) {
  gho_read_whitespace_from_c_str(c_str);
  gho_mpz_t i = gho_mpz_create();
  char* tmp = gho_c_str_create();
  if (**c_str != '\0' && *(*c_str + 1) != '\0' &&
      **c_str == '-' && isdigit(*(*c_str + 1))) {
    gho_c_str_add_char(&tmp, **c_str);
    ++(*c_str);
  }
  while (**c_str != '\0' && isspace(**c_str) == 0 && isdigit(**c_str)) {
    gho_c_str_add_char(&tmp, **c_str);
    ++(*c_str);
  }
  mpz_set_str(i.i, tmp, 10);
  gho_c_str_destroy(&tmp);
  return i;
}

// Copy & comparisons

/**
 * \brief Copy a gho_mpz
 * \param[in] i A gho_mpz
 * \return the gho_mpz copied
 */
gho_mpz_t gho_mpz_copy(const gho_mpz_t* const i) {
  gho_mpz_t r;
  gho_mpz_copy_(i, &r);
  return r;
}

/**
 * \brief Copy a gho_mpz
 * \param[in] i    A gho_mpz
 * \param[in] copy A pointer on an not initialized gho_mpz
 * \warning Do not use this function, use gho_llint_copy
 */
void gho_mpz_copy_(const gho_mpz_t* const i, gho_mpz_t* copy) {
  *copy = gho_mpz_create();
  mpz_set(copy->i, i->i);
}

/**
 * \brief Equality between two gho_mpz
 * \param[in] a A gho_mpz
 * \param[in] b A gho_mpz
 * \return true if the gho_mpz are equals, false otherwise
 */
bool gho_mpz_equal(const gho_mpz_t* const a, const gho_mpz_t* const b) {
  return gho_mpz_compare(a, b) == 0;
}

/**
 * \brief Equality between a gho_mpz and a gho_lint
 * \param[in] a A gho_mpz
 * \param[in] b A gho_lint
 * \return true if the gho_mpz and the gho_lint are equals, false otherwise
 */
bool gho_mpz_equal_li(const gho_mpz_t* const a, const gho_lint b) {
  return gho_mpz_compare_li(a, b) == 0;
}

/**
 * \brief Compare two gho_mpz
 * \param[in] a A gho_mpz
 * \param[in] b A gho_mpz
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_mpz_compare(const gho_mpz_t* const a, const gho_mpz_t* const b) {
  const int c = mpz_cmp(a->i, b->i);
  if (c < 0) { return -1; }
  else if (c > 0) { return 1; }
  else { return 0; }
}

/**
 * \brief Compare a gho_mpz and a gho_lint
 * \param[in] a A gho_mpz
 * \param[in] b A gho_lint
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_mpz_compare_li(const gho_mpz_t* const a, const gho_lint b) {
  const int c = mpz_cmp_si(a->i, b);
  if (c < 0) { return -1; }
  else if (c > 0) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a gho_mpz into a gho_string
 * \param[in] i A gho_mpz
 * \return the gho_string from the gho_mpz
 */
gho_string_t gho_mpz_to_string(const gho_mpz_t* const i) {
  gho_string_t r = gho_string_create();
  gho_mpz_sprint(&r.c_str, i);
  return r;
}

/**
 * \brief Convert a gho_mpz into a gho_any
 * \param[in] i A gho_mpz
 * \return the gho_any from the gho_mpz
 */
gho_any_t gho_mpz_to_any(const gho_mpz_t* const i) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_GHO_MPZ_T;
  r.size_of_struct = sizeof(gho_mpz_t);
  gho_mpz_t* p = gho_alloc(gho_mpz_t); gho_mpz_copy_(i, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_mpz_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_mpz_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_mpz_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_mpz_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_mpz_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_mpz_to_string;
  return r;
}

// Set

/**
 * \brief a = b
 * \param[in] a A gho_mpz
 * \param[in] b A gho_lint
 */
void gho_mpz_set_li(gho_mpz_t a, const gho_lint b) {
  mpz_set_si(a.i, b);
}

// Arithmetic

/**
 * \brief Return a + b
 * \param[in] a A gho_mpz
 * \param[in] b A gho_lint
 * \return a + b
 */
gho_mpz_t gho_mpz_add_li(const gho_mpz_t a, const gho_lint b) {
  gho_mpz_t r = gho_mpz_create();
  if (b >= 0) { mpz_add_ui(r.i, a.i, (gho_ulint)b); }
  else { mpz_sub_ui(r.i, a.i, (gho_ulint)-b); }
  return r;
}

/**
 * \brief Return floor(a / b)
 * \param[in] a A gho_mpz
 * \param[in] b A gho_lint
 * \return floor(a / b)
 */
gho_mpz_t gho_mpz_floor_div_li(const gho_mpz_t a, const gho_lint b) {
  gho_mpz_t r = gho_mpz_create();
  if (b >= 0) { mpz_fdiv_q_ui(r.i, a.i, (gho_ulint)b); }
  else { mpz_fdiv_q_ui(r.i, a.i, (gho_ulint)-b); mpz_neg(r.i, r.i); }
  return r;
}
