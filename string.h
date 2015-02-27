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


#ifndef GHO_STRING_H
#define GHO_STRING_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>


/**
 * \brief gho_string_t encapsulates a C string
 */
typedef struct {
  
  /// \brief String ('\0' terminated string)
  char* c_str;
  
} gho_string_t;


// Create & destroy
static inline
gho_string_t gho_string_create();
static inline
gho_string_t gho_string_create_from_c_str(const char* const c_str);
static inline
void gho_string_absorb_(gho_string_t* string, gho_string_t* string_moved);
static inline
void gho_string_absorb_c_str_(gho_string_t* string, char** c_str_moved);
static inline
void gho_string_destroy(gho_string_t* string);
static inline
void gho_string_reset(gho_string_t* string);

// Output
static inline
void gho_string_fprinti(FILE* file, const gho_string_t* const string,
                        const unsigned int indent);
static inline
void gho_string_fprint(FILE* file, const gho_string_t* const string);
static inline
void gho_string_print(const gho_string_t* const string);
static inline
void gho_string_sprinti(char** c_str, const gho_string_t* const string,
                        const unsigned int indent);
static inline
void gho_string_sprint(char** c_str, const gho_string_t* const string);

// Input
static inline
gho_string_t gho_string_fread(FILE* file);
static inline
gho_string_t gho_string_sread(const char** c_str);

// Copy & comparisons
static inline
gho_string_t gho_string_copy(const gho_string_t* const string);
static inline
void gho_string_copy_(const gho_string_t* const string, gho_string_t* copy);
static inline
bool gho_string_equal(const gho_string_t* const a,
                      const gho_string_t* const b);
static inline
bool gho_string_equal_c_str(const gho_string_t* const a, const char* const b);
static inline
int gho_string_compare(const gho_string_t* const a,
                       const gho_string_t* const b);

// Conversion
static inline
char* gho_string_to_c_str(const gho_string_t* const string);
static inline
gho_string_t gho_string_to_string(const gho_string_t* const string);

// Size
static inline
size_t gho_string_size(const gho_string_t* const string);
static inline
bool gho_string_empty(const gho_string_t* const string);

// Get & Set
static inline
char gho_string_at(const gho_string_t* const string, const size_t i);
static inline
void gho_string_set(gho_string_t* string, const size_t i, const char c);

// Add
static inline
void gho_string_add(gho_string_t* string,
                    const gho_string_t* const to_be_added);
static inline
void gho_string_add_char(gho_string_t* string, const char to_be_added);
static inline
void gho_string_add_c_str(gho_string_t* string, const char* const to_be_added);
static inline
void gho_string_add_char_i(gho_string_t* string, const char to_be_added,
                           const size_t i);

// Remove
static inline
void gho_string_remove(gho_string_t* string, const size_t i);
static inline
void gho_string_remove_last(gho_string_t* string);
static inline
void gho_string_remove_between(gho_string_t* string,
                               const size_t first, const size_t last);
static inline
void gho_string_remove_until(gho_string_t* string, const size_t i);
static inline
void gho_string_remove_after(gho_string_t* string, const size_t i);

// Find
static inline
size_t gho_string_find(const gho_string_t* const string,
                       const gho_string_t* const value);
static inline
size_t gho_string_find_c_str(const gho_string_t* const string,
                             const char* const value);
static inline
size_t gho_string_find_char(const gho_string_t* const string,
                            const char value);

// Get line
static inline
gho_string_t gho_string_get_line(FILE* file);
static inline
void gho_string_ignore_line(FILE* file);
static inline
gho_string_t gho_string_peek_line(FILE* file);
static inline
gho_string_t gho_string_get_line_delimiter(FILE* file, const char delimiter);
static inline
void gho_string_ignore_line_delimiter(FILE* file, const char delimiter);
static inline
gho_string_t gho_string_peek_line_delimiter(FILE* file, const char delimiter);
static inline
gho_string_t gho_string_get_line_from_c_str(const char** c_str);
static inline
void gho_string_ignore_line_from_c_str(const char** c_str);
static inline
gho_string_t gho_string_peek_line_from_c_str(const char** c_str);
static inline
gho_string_t gho_string_get_line_from_c_str_delimiter(const char** c_str,
                                                      const char delimiter);
static inline
void gho_string_ignore_line_from_c_str_delimiter(const char** c_str,
                                                const char delimiter);
static inline
gho_string_t gho_string_peek_line_from_c_str_delimiter(const char** c_str,
                                                       const char delimiter);

#include "implementation/string.h"

#endif
