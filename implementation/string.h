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


#include <stdlib.h>
#include <string.h>

#include "../c_str.h"


// Create & destroy

/**
 * \brief Return a new gho_string
 * \return a new gho_string
 */
gho_string_t gho_string_create() {
  gho_string_t string;
  string.c_str = gho_c_str_create();
  return string;
}

/**
 * \brief Return a new gho_string from a C string
 * \param[in] c_str A C string
 * \return a new gho_string
 */
gho_string_t gho_string_create_from_c_str(const char* const c_str) {
  gho_string_t string = gho_string_create();
  gho_string_add_c_str(&string, c_str);
  return string;
}

/**
 * \brief Move a gho_string in a gho_string
 * \param[in] string       A gho_string
 * \param[in] string_moved A gho_string
 * \warning The string_moved variable is moved, do not use it after this function
 */
void gho_string_absorb_(gho_string_t* string, gho_string_t* string_moved) {
  gho_string_destroy(string);
  string->c_str = string_moved->c_str;
  string_moved->c_str = NULL;
}

/**
 * \brief Move a C string in a gho_string
 * \param[in] string      A gho_string
 * \param[in] c_str_moved A C string
 * \warning The string_moved variable is moved, do not use it after this function
 */
void gho_string_absorb_c_str_(gho_string_t* string, char** c_str_moved) {
  gho_string_destroy(string);
  string->c_str = *c_str_moved;
  *c_str_moved = NULL;
}

/**
 * \brief Destroy a gho_string
 * \param[in] string A gho_string
 */
void gho_string_destroy(gho_string_t* string) {
  gho_c_str_destroy(&string->c_str);
}

/**
 * \brief Reset a gho_string
 * \param[in] string A gho_string
 */
void gho_string_reset(gho_string_t* string) {
  gho_c_str_reset(&string->c_str);
}

// Output

/**
 * \brief Print a gho_string in a file with indentation
 * \param[in] file   A C file
 * \param[in] string A gho_string
 * \param[in] indent Indentation (number of spaces)
 */
void gho_string_fprinti(FILE* file, const gho_string_t* const string,
                        const unsigned int indent) {
  gho_c_str_fprinti(file, string->c_str, indent);
}

/**
 * \brief Print a gho_string in a file
 * \param[in] file   A C file
 * \param[in] string A gho_string
 */
void gho_string_fprint(FILE* file, const gho_string_t* const string) {
  gho_c_str_fprinti(file, string->c_str, 0);
}

/**
 * \brief Print a gho_string in stdout
 * \param[in] string A gho_string
 */
void gho_string_print(const gho_string_t* const string) {
  gho_c_str_fprint(stdout, string->c_str);
}

/**
 * \brief Print a gho_string in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] string A gho_string
 * \param[in] indent Indentation (number of spaces)
 */
void gho_string_sprinti(char** c_str, const gho_string_t* const string,
                        const unsigned int indent) {
  gho_c_str_sprinti(c_str, string->c_str, indent);
}

/**
 * \brief Print a gho_string in a C string
 * \param[in] c_str  A C string
 * \param[in] string A gho_string
 */
void gho_string_sprint(char** c_str, const gho_string_t* const string) {
  gho_c_str_sprint(c_str, string->c_str);
}

// Input

/**
 * \brief Read a gho_string from a file
 * \param[in] file A C file
 * \return the gho_string read
 */
gho_string_t gho_string_fread(FILE* file) {
  gho_string_t r = gho_string_create();
  char* c_str_read = gho_c_str_fread(file);
  gho_string_absorb_c_str_(&r, &c_str_read);
  return r;
}

/**
 * \brief Read a gho_string from a C string
 * \param[in] c_str A C string
 * \return the gho_string read
 */
gho_string_t gho_string_sread(const char** c_str) {
  gho_string_t r = gho_string_create();
  char* c_str_read = gho_c_str_sread(c_str);
  gho_string_absorb_c_str_(&r, &c_str_read);
  return r;
}

// Copy & comparisons

/**
 * \brief Copy a gho_string
 * \param[in] string A gho_string
 * \return the gho_string copied
 */
gho_string_t gho_string_copy(const gho_string_t* const string) {
  gho_string_t r;
  gho_string_copy_(string, &r);
  return r;
}

/**
 * \brief Copy a gho_string
 * \param[in] string A gho_string
 * \param[in] copy   A pointer on an not initialized gho_string
 * \warning Do not use this function, use gho_string_copy
 */
void gho_string_copy_(const gho_string_t* const string, gho_string_t* copy) {
  *copy = gho_string_create();;
  gho_string_add(copy, string);
}

/**
 * \brief Equality between two gho_string
 * \param[in] a A gho_string
 * \param[in] b A gho_string
 * \return true if the gho_string are equals, false otherwise
 */
bool gho_string_equal(const gho_string_t* const a,
                      const gho_string_t* const b) {
  return gho_c_str_equal(a->c_str, b->c_str);
}

/**
 * \brief Equality between a gho_string and a C string
 * \param[in] a A gho_string
 * \param[in] b A C string
 * \return true if the gho_string and the C string are equals, false otherwise
 */
bool gho_string_equal_c_str(const gho_string_t* const a, const char* const b) {
  return gho_c_str_equal(a->c_str, b);
}

/**
 * \brief Compare two gho_string
 * \param[in] a A gho_string
 * \param[in] b A gho_string
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 */
int gho_string_compare(const gho_string_t* const a,
                       const gho_string_t* const b) {
  return gho_c_str_compare(a->c_str, b->c_str);
}

// Conversion

/**
 * \brief Convert a gho_string into a C string
 * \param[in] string A gho_string
 * \return the C string from the gho_string
 */
char* gho_string_to_c_str(const gho_string_t* const string) {
  return gho_c_str_copy(string->c_str);
}

/**
 * \brief Convert a gho_string into a gho_string
 * \param[in] string A gho_string
 * \return the gho_string from the gho_string
 */
gho_string_t gho_string_to_string(const gho_string_t* const string) {
  return gho_string_copy(string);
}

// Size

/**
 * \brief Return the size of a gho_string
 * \param[in] string A gho_string
 * \return the size
 */
size_t gho_string_size(const gho_string_t* const string) {
  return gho_c_str_size(string->c_str);
}

/**
 * \brief Return true if the gho_string is empty, false otherwise
 * \param[in] string A gho_string
 * \return true if the gho_string is empty, false otherwise
 */
bool gho_string_empty(const gho_string_t* const string) {
  return gho_c_str_empty(string->c_str);
}

// Get & Set

/**
 * \brief Return the element at position i
 * \param[in] string A gho_string
 * \param[in] i      Index
 * \return the element at position i
 */
char gho_string_at(const gho_string_t* const string, const size_t i) {
  return string->c_str[i];
}

/**
 * \brief Set the element at position i
 * \param[in] string A gho_string
 * \param[in] i      Index
 * \param[in] c      A char
 */
void gho_string_set(gho_string_t* string, const size_t i, const char c) {
  string->c_str[i] = c;
}

// Add

/**
 * \brief Add a gho_string at the end
 * \param[in] string      A gho_string
 * \param[in] to_be_added The gho_string to be added
 */
void gho_string_add(gho_string_t* string,
                    const gho_string_t* const to_be_added) {
  gho_c_str_add(&string->c_str, to_be_added->c_str);
}

/**
 * \brief Add a C string at the end
 * \param[in] string      A gho_string
 * \param[in] to_be_added The C string to be added
 */
void gho_string_add_c_str(gho_string_t* string, const char* const to_be_added) {
  gho_c_str_add(&string->c_str, to_be_added);
}

/**
 * \brief Add a char at the end
 * \param[in] string      A gho_string
 * \param[in] to_be_added The char to be added
 */
void gho_string_add_char(gho_string_t* string, const char to_be_added) {
  gho_c_str_add_char(&string->c_str, to_be_added);
}

// Remove

/**
 * \brief Remove the char at index i
 * \param[in] string A gho_string
 * \param[in] i      Index
 */
void gho_string_remove(gho_string_t* string, const size_t i) {
  gho_c_str_remove(&string->c_str, i);
}

/**
 * \brief Remove the last char
 * \param[in] string A gho_string
 */
void gho_string_remove_last(gho_string_t* string) {
  gho_c_str_remove_last(&string->c_str);
}

// Get line

/**
 * \brief Read a line from a file
 * \param[in] file A C file
 * \return the first line in the file
 */
gho_string_t gho_string_get_line(FILE* file) {
  return gho_string_get_line_delimiter(file, '\n');
}

/**
 * \brief Ignore a line from a file
 * \param[in] file A C file
 * \return the first line in the file
 */
void gho_string_ignore_line(FILE* file) {
  gho_c_str_ignore_line(file);
}

/**
 * \brief Peek a line from a file
 * \param[in] file A C file
 * \return the first line in the file
 */
gho_string_t gho_string_peek_line(FILE* file) {
  return gho_string_peek_line_delimiter(file, '\n');
}

/**
 * \brief Read a line from a file until a delimiter
 * \param[in] file      A C file
 * \param[in] delimiter The delimiter
 * \return the first line in the file until the delimiter is found
 */
gho_string_t gho_string_get_line_delimiter(FILE* file, const char delimiter) {
  gho_string_t r = gho_string_create();
  char* c_str_line = gho_c_str_get_line_delimiter(file, delimiter);
  gho_string_absorb_c_str_(&r, &c_str_line);
  return r;
}

/**
 * \brief Ignore a line from a file until a delimiter
 * \param[in] file      A C file
 * \param[in] delimiter The delimiter
 * \return the first line in the file until the delimiter is found
 */
void gho_string_ignore_line_delimiter(FILE* file, const char delimiter) {
  gho_c_str_ignore_line_delimiter(file, delimiter);
}

/**
 * \brief Peek a line from a file until a delimiter
 * \param[in] file      A C file
 * \param[in] delimiter The delimiter
 * \return the first line in the file until the delimiter is found
 */
gho_string_t gho_string_peek_line_delimiter(FILE* file, const char delimiter) {
  gho_string_t r = gho_string_create();
  char* c_str_line = gho_c_str_peek_line_delimiter(file, delimiter);
  gho_string_absorb_c_str_(&r, &c_str_line);
  return r;
}

/**
 * \brief Read a line from a C string
 * \param[in] c_str A C string
 * \return the first line in the C string
 */
gho_string_t gho_string_get_line_from_c_str(const char** c_str) {
  return gho_string_get_line_from_c_str_delimiter(c_str, '\n');
}

/**
 * \brief Ignore a line from a C string
 * \param[in] c_str A C string
 * \return the first line in the C string
 */
void gho_string_ignore_line_from_c_str(const char** c_str) {
  gho_c_str_get_line_from_c_str(c_str);
}

/**
 * \brief Peek a line from a C string
 * \param[in] c_str A C string
 * \return the first line in the C string
 */
gho_string_t gho_string_peek_line_from_c_str(const char** c_str) {
  return gho_string_peek_line_from_c_str_delimiter(c_str, '\n');
}

/**
 * \brief Read a line from a C string until a delimiter
 * \param[in] c_str     A C string
 * \param[in] delimiter The delimiter
 * \return the first line in the C string until the delimiter is found
 */
gho_string_t gho_string_get_line_from_c_str_delimiter(const char** c_str,
                                                      const char delimiter) {
  gho_string_t r = gho_string_create();
  char* c_str_line = gho_c_str_get_line_from_c_str_delimiter(c_str, delimiter);
  gho_string_absorb_c_str_(&r, &c_str_line);
  return r;
}

/**
 * \brief Read a line from a C string until a delimiter
 * \param[in] c_str     A C string
 * \param[in] delimiter The delimiter
 * \return the first line in the C string until the delimiter is found
 */
void gho_string_ignore_line_from_c_str_delimiter(const char** c_str,
                                                 const char delimiter) {
  gho_c_str_get_line_from_c_str_delimiter(c_str, delimiter);
}

/**
 * \brief Peek a line from a C string until a delimiter
 * \param[in] c_str     A C string
 * \param[in] delimiter The delimiter
 * \return the first line in the C string until the delimiter is found
 */
gho_string_t gho_string_peek_line_from_c_str_delimiter(const char** c_str,
                                                       const char delimiter) {
  gho_string_t r = gho_string_create();
  char* c_str_line = gho_c_str_peek_line_from_c_str_delimiter(c_str, delimiter);
  gho_string_absorb_c_str_(&r, &c_str_line);
  return r;
}

// C++

#if defined(__cplusplus)

namespace gho
{
  /**
   * @brief Convert a gho_string_t into a std::string
   * @param[in] gho_string A gho string
   * @return a std::string with gho_string value
   */
  std::string to_std(const gho_string_t & gho_string) {
    return std::string(gho_string.c_str);
  }
}

#endif
