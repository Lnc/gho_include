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


#include "../char.h"
#include "../output.h"
#include "../input.h"
#include "../c_str.h"


// Create & destroy

/**
 * \brief Return a new char
 * \return a new char
 */
char gho_char_create() {
  return 'a';
}

/**
 * \brief Destroy a char
 * \param[in] c A char
 */
void gho_char_destroy(char* c) {
  *c = 'a';
}

/**
 * \brief Reset a char
 * \param[in] c A char
 */
void gho_char_reset(char* c) {
  *c = 'a';
}

// Output

/**
 * \brief Print a char in a file with indentation
 * \param[in] file   A C file
 * \param[in] c      A char
 * \param[in] indent Indentation (number of spaces)
 */
void gho_char_fprinti(FILE* file, const char* const c,
                      const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%c", *c);
}

/**
 * \brief Print a char in a file
 * \param[in] file A C file
 * \param[in] c    A char
 */
void gho_char_fprint(FILE* file, const char* const c) {
  gho_char_fprinti(file, c, 0);
}

/**
 * \brief Print a char in stdout
 * \param[in] c A char
 */
void gho_char_print(const char* const c) {
  gho_char_fprint(stdout, c);
}

/**
 * \brief Print a char in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] c      A char
 * \param[in] indent Indentation (number of spaces)
 */
void gho_char_sprinti(char** c_str, const char* const c,
                      const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_string_t s = gho_char_to_string(c);
  gho_c_str_add(c_str, s.c_str);
  gho_string_destroy(&s);
}

/**
 * \brief Print a char in a C string
 * \param[in] c_str A C string
 * \param[in] c     A char
 */
void gho_char_sprint(char** c_str, const char* const c) {
  gho_char_sprinti(c_str, c, 0);
}

// Input

/**
 * \brief Read a char from a file
 * \param[in] file A C file
 * \return the char read
 */
char gho_char_fread(FILE* file) {
  char r;
  fscanf(file, "%c", &r);
  return r;
}

/**
 * \brief Read a char from a C string
 * \param[in] c_str A C string
 * \return the char read
 */
char gho_char_sread(const char** c_str) {
  char r = **c_str;
  ++(*c_str);
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a char
 * \param[in] c A char
 * \return the char copied
 */
char gho_char_copy(const char* const c) {
  return *c;
}

/**
 * \brief Copy a char
 * \param[in] c    A char
 * \param[in] copy A pointer on an not initialized char
 * \warning Do not use this function, use gho_char_copy
 */
void gho_char_copy_(const char* const c, char* copy) {
  *copy = *c;
}

/**
 * \brief Equality between two char
 * \param[in] a A char
 * \param[in] b A char
 * \return true if the char are equals, false otherwise
 */
bool gho_char_equal(const char* const a, const char* const b) {
  return *a == *b;
}

/**
 * \brief Compare two char
 * \param[in] a A char
 * \param[in] b A char
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_char_compare(const char* const a, const char* const b) {
  if (*a < *b) { return -1; }
  else if (*a > *b) { return 1; }
  else { return 0; }
}

// Conversion

/**
 * \brief Convert a char into a gho_string
 * \param[in] c A char
 * \return the gho_string from the char
 */
gho_string_t gho_char_to_string(const char* const c) {
  gho_string_t r = gho_string_create();
  gho_string_add_char(&r, *c);
  return r;
}

/**
 * \brief Convert a char into a gho_any
 * \param[in] c A char
 * \return the gho_any from the char
 */
gho_any_t gho_char_to_any(const char* const c) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_INT;
  r.size_of_struct = sizeof(char);
  char* p = gho_alloc(char); gho_char_copy_(c, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_char_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_char_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_char_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_char_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_char_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_char_to_string;
  return r;
}

// Peek

/**
 * \brief Peek a char from a file
 * \param[in] file A C file
 * \return the char read
 */
char gho_char_fpeek(FILE* file) {
  int r = fgetc(file);
  ungetc(r, file);
  return (char)r;
}

/**
 * \brief Peek a char from a C string
 * \param[in] c_str A C string
 * \return the char read
 */
char gho_char_speek(const char** c_str) {
  char r = **c_str;
  return r;
}
