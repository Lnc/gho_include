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
#include <ctype.h>

#include "../memory.h"
#include "../output.h"
#include "../input.h"


// Create & destroy

/**
 * @brief Return a new C string
 * @return a new C string
 * @relates gho_c_str_t
 */
char* gho_c_str_create() {
  char* c_str;
  c_str = gho_array_alloc(char, 1);
  c_str[0] = '\0';
  return c_str;
}

/**
 * @brief Return a new C string from a C string
 * @param[in] c_str A C string
 * @return a new C string
 * @relates gho_c_str_t
 */
char* gho_c_str_create_from_c_str(const char* const c_str) {
  return gho_c_str_copy(c_str);
}

/**
 * \brief Destroy a C string
 * \param[in] c_str A C string
 * @relates gho_c_str_t
 */
void gho_c_str_destroy(char** c_str) {
  free(*c_str); c_str = NULL;
}

/**
 * \brief Reset a C string
 * \param[in] c_str A C string
 * @relates gho_c_str_t
 */
void gho_c_str_reset(char** c_str) {
  gho_c_str_destroy(c_str);
  *c_str = gho_c_str_create();
}

// Output

/**
 * @brief Print a C string in a file with indentation
 * @param[in] file   A C file
 * @param[in] c_str  A C string
 * @param[in] indent Indentation (number of spaces)
 * @relates gho_c_str_t
 */
void gho_c_str_fprinti(FILE* file, const char* const c_str,
                       const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "%s", c_str);
}

/**
 * @brief Print a C string in a file
 * @param[in] file  A C file
 * @param[in] c_str A C string
 * @relates gho_c_str_t
 */
void gho_c_str_fprint(FILE* file, const char* const c_str) {
  gho_c_str_fprinti(file, c_str, 0);
}

/**
 * @brief Print a C string in stdout
 * @param[in] c_str A C string
 * @relates gho_c_str_t
 */
void gho_c_str_print(const char* const c_str) {
  gho_c_str_fprint(stdout, c_str);
}

/**
 * @brief Print a C string in a C string with indentation
 * @param[in] out    A C string
 * @param[in] c_str  A C string
 * @param[in] indent Indentation (number of spaces)
 * @relates gho_c_str_t
 */
void gho_c_str_sprinti(char** out, const char* const c_str,
                       const unsigned int indent) {
  gho_sprinti(out, indent);
  gho_c_str_add(out, c_str);
}

/**
 * @brief Print a C string in a C string
 * @param[in] out   A C string
 * @param[in] c_str A C string
 * @relates gho_c_str_t
 */
void gho_c_str_sprint(char** out, const char* const c_str) {
  gho_c_str_sprinti(out, c_str, 0);
}

// Input

/**
 * @brief Read a C string from a file
 * @param[in] file A C file
 * @return the C string read
 * @relates gho_c_str_t
 */
char* gho_c_str_fread(FILE* file) {
  gho_read_whitespace(file);
  char* r = gho_c_str_create();
  while (true) {
    const char c = (char)fgetc(file);
    if (c == EOF) { ungetc(c, file); break; }
    if (isspace(c) != 0) { break; }
    gho_c_str_add_char(&r, c);
  }
  return r;
}

/**
 * @brief Read a C string from a C string
 * @param[in] c_str A C string
 * @return the C string read
 * @relates gho_c_str_t
 */
char* gho_c_str_sread(const char** c_str) {
  gho_read_whitespace_from_c_str(c_str);
  char* r = gho_c_str_create();
  while (**c_str != '\0' && isspace(**c_str) == 0) {
    gho_c_str_add_char(&r, **c_str);
    ++(*c_str);
  }
  return r;
}

// Copy & comparisons

/**
 * @brief Copy a C string
 * @param[in] c_str A C string
 * @return the C string copied
 * @relates gho_c_str_t
 */
char* gho_c_str_copy(const char* const c_str) {
  char* r = gho_c_str_create();
  gho_c_str_add(&r, c_str);
  return r;
}

/**
 * @brief Equality between two C string
 * @param[in] a A C string
 * @param[in] b A C string
 * @return true if the C string are equals, false otherwise
 * @relates gho_c_str_t
 */
bool gho_c_str_equal(const char* const a, const char* const b) {
  return (strcmp(a, b) == 0);
}

/**
 * \brief Compare two C string
 * \param[in] a A C string
 * \param[in] b A C string
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 * @relates gho_c_str_t
 */
int gho_c_str_compare(const char* const a, const char* const b) {
  int c = strcmp(a, b);
  if (c < 0) { c = -1; }
  else if (c > 0) { c = 1; }
  return c;
}

// Size

/**
 * @brief Return the size of a C string
 * @param[in] c_str A C string
 * @return the size
 * @relates gho_c_str_t
 */
size_t gho_c_str_size(const char* const c_str) {
  return strlen(c_str);
}

/**
 * @brief Return true if the C string is empty, false otherwise
 * @param[in] c_str A C string
 * @return true if the C string is empty, false otherwise
 * @relates gho_c_str_t
 */
bool gho_c_str_empty(const char* const c_str) {
  return (gho_c_str_size(c_str) == 0);
}

// Add

/**
 * @brief Add a C string at the end
 * @param[in] c_str       A C string
 * @param[in] to_be_added The C string to be added
 * @relates gho_c_str_t
 */
void gho_c_str_add(char** c_str, const char* const to_be_added) {
  const size_t size_old = gho_c_str_size(*c_str);
  const size_t size_to_be_added = gho_c_str_size(to_be_added);
  gho_array_realloc(*c_str, char, size_old + size_to_be_added + 1);
  strcat(*c_str, to_be_added);
}

/**
 * @brief Add a char at the end
 * @param[in] c_str       A C string
 * @param[in] to_be_added The char to be added
 * @relates gho_c_str_t
 */
void gho_c_str_add_char(char** c_str, const char to_be_added) {
  const size_t size_old = gho_c_str_size(*c_str);
  gho_array_realloc(*c_str, char, size_old + 1 + 1);
  (*c_str)[size_old] = to_be_added;
  (*c_str)[size_old + 1] = '\0';
}

/**
 * @brief Add a char at index i
 * @param[in] c_str       A C string
 * @param[in] to_be_added The char to be added
 * @param[in] i           Index
 * @relates gho_c_str_t
 */
void gho_c_str_add_char_i(char** c_str, const char to_be_added,
                          const size_t i) {
  if (i >= gho_c_str_size(*c_str)) {
    fprintf(stderr, "ERROR: gho_c_str_add_char_i: out of range!\n");
    exit(1);
  }
  else {
    gho_c_str_add_char(c_str, ' ');
    for (size_t j = i; j < gho_c_str_size(*c_str) - 1; ++j) {
      (*c_str)[j + 1] = (*c_str)[j];
    }
    (*c_str)[i] = to_be_added;
  }
}

// Remove

/**
 * @brief Remove the char at index i
 * @param[in] c_str A c_str
 * @param[in] i     Index
 * @relates gho_c_str_t
 */
void gho_c_str_remove(char** c_str, const size_t i) {
  if (gho_c_str_size(*c_str) == 0) {
    fprintf(stderr, "ERROR: gho_c_str_remove: c_str is empty!\n");
    exit(1);
  }
  else if (i >= gho_c_str_size(*c_str)) {
    fprintf(stderr, "ERROR: gho_c_str_remove: out of range!\n");
    exit(1);
  }
  else {
    for (size_t j = i; j < gho_c_str_size(*c_str) - 1; ++j) {
      (*c_str)[j] = (*c_str)[j + 1];
    }
    (*c_str)[gho_c_str_size(*c_str) - 1] = '\0';
  }
}

/**
 * @brief Remove the last char
 * @param[in] c_str A c_str
 * @relates gho_c_str_t
 */
void gho_c_str_remove_last(char** c_str) {
  if (gho_c_str_size(*c_str) == 0) {
    fprintf(stderr, "ERROR: gho_c_str_remove_last: c_str is empty!\n");
    exit(1);
  }
  else {
    gho_c_str_remove(c_str, gho_c_str_size(*c_str) - 1);
  }
}

// Find

/**
 * \brief Find a value in a C string
 * \param[in] c_str A C string
 * \param[in] value The C string to be found
 * \return the index of the value found, the size of the string if not found
 *         or if value is empty
 * @relates gho_c_str_t
 */
size_t gho_c_str_find(const char* const c_str, const char* const value) {
  const size_t string_size = gho_c_str_size(c_str);
  const size_t value_size = gho_c_str_size(value);
  if (value_size == 0) { return string_size; }
  if (string_size < value_size) { return string_size; }
  const size_t i = gho_c_str_find_char(c_str, value[0]);
  if (i == string_size) { return string_size; }
  if (i + value_size > string_size) { return string_size; }
  size_t j;
  for (j = i + 1 ; j < i + value_size; ++j) {
    if (c_str[j] != value[j - i]) {
      return gho_c_str_find(c_str + i + value_size, value);
    }
  }
  return i;
}

/**
 * \brief Find a value in a C string
 * \param[in] c_str A C string
 * \param[in] value The char to be found
 * \return the index of the value found, the size of the string if not found
 * @relates gho_c_str_t
 */
size_t gho_c_str_find_char(const char* const c_str, const char value) {
  const size_t size = gho_c_str_size(c_str);
  for (size_t i = 0; i < size; ++i) {
    if (c_str[i] == value) { return i; }
  }
  return size;
}

/**
 * \brief Test if a value is in a C string
 * \param[in] c_str A C string
 * \param[in] value The C string to be found
 * \return true if the value is in the C string, false otherwise
 * @relates gho_c_str_t
 */
bool gho_c_str_contains(const char* const c_str, const char* const value) {
  return gho_c_str_find(c_str, value) != gho_c_str_size(c_str);
}

// Get line

/**
 * @brief Read a line from a file
 * @param[in] file A C file
 * @return the first line in the file
 * @relates gho_c_str_t
 */
char* gho_c_str_get_line(FILE* file) {
  return gho_c_str_get_line_delimiter(file, '\n');
}

/**
 * @brief Ignore a line from a file
 * @param[in] file A C file
 * @return the first line in the file
 * @relates gho_c_str_t
 */
void gho_c_str_ignore_line(FILE* file) {
  char* tmp = gho_c_str_get_line(file);
  gho_c_str_destroy(&tmp);
}

/**
 * @brief Peek a line from a file
 * @param[in] file A C file
 * @return the first line in the file
 * @relates gho_c_str_t
 */
char* gho_c_str_peek_line(FILE* file) {
  return gho_c_str_peek_line_delimiter(file, '\n');
}

/**
 * @brief Read a line from a file until a delimiter
 * @param[in] file      A C file
 * @param[in] delimiter The delimiter
 * @return the first line in the file until the delimiter is found
 * @relates gho_c_str_t
 */
char* gho_c_str_get_line_delimiter(FILE* file, const char delimiter) {
  char* r = gho_c_str_create();
  while (true) {
    const char c = (char)fgetc(file);
    if (c == EOF) { ungetc(c, file); break; }
    if (c == delimiter) { break; }
    gho_c_str_add_char(&r, c);
  }
  return r;
}

/**
 * @brief Ignore a line from a file until a delimiter
 * @param[in] file      A C file
 * @param[in] delimiter The delimiter
 * @return the first line in the file until the delimiter is found
 * @relates gho_c_str_t
 */
void gho_c_str_ignore_line_delimiter(FILE* file, const char delimiter) {
  char* tmp = gho_c_str_get_line_delimiter(file, delimiter);
  gho_c_str_destroy(&tmp);
}

/**
 * @brief Peek a line from a file until a delimiter
 * @param[in] file      A C file
 * @param[in] delimiter The delimiter
 * @return the first line in the file until the delimiter is found
 * @relates gho_c_str_t
 */
char* gho_c_str_peek_line_delimiter(FILE* file, const char delimiter) {
  char* r = gho_c_str_get_line_delimiter(file, delimiter);
  const size_t r_size = gho_c_str_size(r);
  ungetc('\n', file);
  for (size_t i = 0; i < r_size; ++i) {
    ungetc(r[r_size - i - 1], file);
  }
  return r;
}

/**
 * @brief Read a line from a C string
 * @param[in] c_str A C string
 * @return the first line in the C string
 * @relates gho_c_str_t
 */
char* gho_c_str_get_line_from_c_str(const char** c_str) {
  return gho_c_str_get_line_from_c_str_delimiter(c_str, '\n');
}

/**
 * @brief Ignore a line from a C string
 * @param[in] c_str A C string
 * @return the first line in the C string
 * @relates gho_c_str_t
 */
void gho_c_str_ignore_line_from_c_str(const char** c_str) {
  char* tmp = gho_c_str_get_line_from_c_str(c_str);
  gho_c_str_destroy(&tmp);
}

/**
 * @brief Peek a line from a C string
 * @param[in] c_str A C string
 * @return the first line in the C string
 * @relates gho_c_str_t
 */
char* gho_c_str_peek_line_from_c_str(const char** c_str) {
  return gho_c_str_peek_line_from_c_str_delimiter(c_str, '\n');
}

/**
 * @brief Read a line from a C string until a delimiter
 * @param[in] c_str     A C string
 * @param[in] delimiter The delimiter
 * @return the first line in the C string until the delimiter is found
 * @relates gho_c_str_t
 */
char* gho_c_str_get_line_from_c_str_delimiter(const char** c_str,
                                              const char delimiter) {
  char* r = gho_c_str_create();
  while (**c_str != '\0' && **c_str != delimiter) {
    gho_c_str_add_char(&r, **c_str);
    ++(*c_str);
  }
  if (**c_str != '\0') { ++(*c_str); }
  return r;
}

/**
 * @brief Ignore a line from a C string until a delimiter
 * @param[in] c_str     A C string
 * @param[in] delimiter The delimiter
 * @return the first line in the C string until the delimiter is found
 * @relates gho_c_str_t
 */
void gho_c_str_ignore_line_from_c_str_delimiter(const char** c_str,
                                                const char delimiter) {
  char* tmp = gho_c_str_get_line_from_c_str_delimiter(c_str, delimiter);
  gho_c_str_destroy(&tmp);
}

/**
 * @brief Peek a line from a C string until a delimiter
 * @param[in] c_str     A C string
 * @param[in] delimiter The delimiter
 * @return the first line in the C string until the delimiter is found
 * @relates gho_c_str_t
 */
char* gho_c_str_peek_line_from_c_str_delimiter(const char** c_str,
                                               const char delimiter) {
  char* r = gho_c_str_get_line_from_c_str_delimiter(c_str, delimiter);
  const size_t r_size = gho_c_str_size(r);
  --(*c_str);
  for (size_t i = 0; i < r_size; ++i) {
    --(*c_str);
  }
  return r;
}

// C++

#if defined(__cplusplus)

#include <string>

namespace gho
{
  /**
   * @brief Convert a gho_c_str_t (a C string) into a std::string
   * @param[in] c_str A C string
   * @return a std::string with c_str value
   */
  std::string to_std(const char* const c_str) {
    return std::string(c_str);
  }
}

#endif
