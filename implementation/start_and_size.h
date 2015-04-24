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


#include <limits.h>
#include <ctype.h>
#include <stdlib.h>

#include "../output.h"
#include "../c_str.h"
#include "../char.h"


// Create & destroy

/**
 * \brief Return a new gho_start_and_size_t
 * \return a new gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
gho_start_and_size_t gho_start_and_size_create() {
  gho_start_and_size_t r;
  r.start = 0u;
  r.size = 0u;
  return r;
}

/**
 * \brief Destroy a gho_start_and_size_t
 * \param[in] start_and_size A gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_destroy(gho_start_and_size_t* start_and_size) {
  start_and_size->start = 0u;
  start_and_size->size = 0u;
}

/**
 * \brief Reset a gho_start_and_size_t
 * \param[in] start_and_size A gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_reset(gho_start_and_size_t* start_and_size) {
  start_and_size->start = 0u;
  start_and_size->size = 0u;
}

// Output

/**
 * \brief Print a gho_start_and_size_t in a file with indentation
 * \param[in] file           A C file
 * \param[in] start_and_size A gho_start_and_size_t
 * \param[in] indent         Indentation (number of spaces)
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_fprinti(FILE* file,
                               const gho_start_and_size_t* const start_and_size,
                               const unsigned int indent) {
  gho_fprinti(file, indent);
  gho_c_str_fprint(file, "{ ");
  gho_size_t_fprint(file, &start_and_size->start);
  gho_c_str_fprint(file, ", ");
  gho_size_t_fprint(file, &start_and_size->size);
  gho_c_str_fprint(file, " }");
}

/**
 * \brief Print a gho_start_and_size_t in a file
 * \param[in] file           A C file
 * \param[in] start_and_size A gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_fprint(FILE* file,
                             const gho_start_and_size_t* const start_and_size) {
  gho_start_and_size_fprinti(file, start_and_size, 0);
}

/**
 * \brief Print a gho_start_and_size_t in stdout
 * \param[in] start_and_size A gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_print(
                             const gho_start_and_size_t* const start_and_size) {
  gho_start_and_size_fprint(stdout, start_and_size);
}

/**
 * \brief Print a v in a C string with indentation
 * \param[in] c_str          A C string
 * \param[in] start_and_size A gho_start_and_size_t
 * \param[in] indent         Indentation (number of spaces)
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_sprinti(char** c_str,
                               const gho_start_and_size_t* const start_and_size,
                               const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_c_str_sprint(c_str, "{ ");
  gho_size_t_sprint(c_str, &start_and_size->start);
  gho_c_str_sprint(c_str, ", ");
  gho_size_t_sprint(c_str, &start_and_size->size);
  gho_c_str_sprint(c_str, " }");
}

/**
 * \brief Print a gho_start_and_size_t in a C string
 * \param[in] c_str          A C string
 * \param[in] start_and_size A gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_sprint(char** c_str,
                             const gho_start_and_size_t* const start_and_size) {
  gho_start_and_size_sprinti(c_str, start_and_size, 0);
}

// Input

/**
 * \brief Read a gho_start_and_size_t from a file
 * \param[in] file A C file
 * \return the gho_start_and_size_t read
 * @relates gho_start_and_size_t
 */
gho_start_and_size_t gho_start_and_size_fread(FILE* file) {
  gho_start_and_size_t r;
  gho_read_whitespace(file); gho_char_fread(file); // "{ "
  r.start = gho_size_t_fread(file);
  gho_read_whitespace(file); gho_char_fread(file); // ", "
  r.size = gho_size_t_fread(file);
  gho_read_whitespace(file); gho_char_fread(file); // "}"
  return r;
}

/**
 * \brief Read a gho_start_and_size_t from a C string
 * \param[in] c_str A C string
 * \return the gho_start_and_size_t read
 * @relates gho_start_and_size_t
 */
gho_start_and_size_t gho_start_and_size_sread(const char** c_str) {
  gho_start_and_size_t r;
  gho_read_whitespace_from_c_str(c_str); gho_char_sread(c_str); // "{ "
  r.start = gho_size_t_sread(c_str);
  gho_read_whitespace_from_c_str(c_str); gho_char_sread(c_str); // ", "
  r.size = gho_size_t_sread(c_str);
  gho_read_whitespace_from_c_str(c_str); gho_char_sread(c_str); // "}"
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a gho_start_and_size_t
 * \param[in] start_and_size A gho_start_and_size_t
 * \return the gho_start_and_size_t copied
 * @relates gho_start_and_size_t
 */
gho_start_and_size_t gho_start_and_size_copy(
                             const gho_start_and_size_t* const start_and_size) {
  gho_start_and_size_t r;
  gho_start_and_size_copy_(start_and_size, &r);
  return r;
}

/**
 * \brief Copy a gho_start_and_size_t
 * \param[in] start_and_size A gho_start_and_size_t
 * \param[in] copy           A pointer on an not initialized
 *                           gho_start_and_size_t
 * \warning Do not use this function, use gho_llint_copy
 * @relates gho_start_and_size_t
 */
void gho_start_and_size_copy_(const gho_start_and_size_t* const start_and_size,
                              gho_start_and_size_t* copy) {
  copy->start = start_and_size->start;
  copy->size = start_and_size->size;
}

/**
 * \brief Equality between two gho_start_and_size_t
 * \param[in] a A gho_start_and_size_t
 * \param[in] b A gho_start_and_size_t
 * \return true if the gho_start_and_size_t are equals, false otherwise
 * @relates gho_start_and_size_t
 */
bool gho_start_and_size_equal(const gho_start_and_size_t* const a,
                              const gho_start_and_size_t* const b) {
  return a->start == b->start && a->size == b->size;
}

// Conversion

/**
 * \brief Convert a gho_start_and_size_t into a gho_string_t
 * \param[in] start_and_size A gho_start_and_size_t
 * \return the gho_string_t from the gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
gho_string_t gho_start_and_size_to_string(
                             const gho_start_and_size_t* const start_and_size) {
  gho_string_t r = gho_string_create();
  gho_start_and_size_sprint(&r.c_str, start_and_size);
  return r;
}

/**
 * \brief Convert a gho_start_and_size_t into a gho_any_t
 * \param[in] start_and_size A gho_start_and_size_t
 * \return the gho_any_t from the gho_start_and_size_t
 * @relates gho_start_and_size_t
 */
gho_any_t gho_start_and_size_to_any(
                             const gho_start_and_size_t* const start_and_size) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_GHO_START_AND_SIZE;
  r.size_of_struct = sizeof(gho_start_and_size_t);
  gho_start_and_size_t* p = gho_alloc(gho_start_and_size_t);
  gho_start_and_size_copy_(start_and_size, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_start_and_size_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_start_and_size_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_start_and_size_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_start_and_size_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_start_and_size_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_start_and_size_to_string;
  return r;
}
