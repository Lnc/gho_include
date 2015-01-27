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


#ifndef GHO_C_STR_H
#define GHO_C_STR_H

#include <stdio.h>
#include <stdbool.h>


// Typedef
typedef char* gho_c_str_t;

// Create & destroy
static inline
char* gho_c_str_create();
static inline
char* gho_c_str_create_from_c_str(const char* const c_str);
static inline
void gho_c_str_destroy(char** c_str);
static inline
void gho_c_str_reset(char** c_str);

// Output
static inline
void gho_c_str_fprinti(FILE* file, const char* const c_str,
                       const unsigned int indent);
static inline
void gho_c_str_fprint(FILE* file, const char* const c_str);
static inline
void gho_c_str_print(const char* const c_str);
static inline
void gho_c_str_sprinti(char** out, const char* const c_str,
                       const unsigned int indent);
static inline
void gho_c_str_sprint(char** out, const char* const c_str);

// Input
static inline
char* gho_c_str_fread(FILE* file);
static inline
char* gho_c_str_sread(const char** c_str);

// Copy & comparisons
static inline
char* gho_c_str_copy(const char* const c_str);
static inline
bool gho_c_str_equal(const char* const a, const char* const b);
static inline
int gho_c_str_compare(const char* const a, const char* const b);

// Size
static inline
size_t gho_c_str_size(const char* const c_str);
static inline
bool gho_c_str_empty(const char* const c_str);

// Add
static inline
void gho_c_str_add(char** c_str, const char* const to_be_added);
static inline
void gho_c_str_add_char(char** c_str, const char to_be_added);

// Remove
static inline
void gho_c_str_remove(char** c_str, const size_t i);
static inline
void gho_c_str_remove_last(char** c_str);

// Get line
static inline
char* gho_c_str_get_line(FILE* file);
static inline
void gho_c_str_ignore_line(FILE* file);
static inline
char* gho_c_str_get_line_delimiter(FILE* file, const char delimiter);
static inline
void gho_c_str_ignore_line_delimiter(FILE* file, const char delimiter);
static inline
char* gho_c_str_get_line_from_c_str(const char** c_str);
static inline
void gho_c_str_ignore_line_from_c_str(const char** c_str);
static inline
char* gho_c_str_get_line_from_c_str_delimiter(const char** c_str,
                                              const char delimiter);
static inline
void gho_c_str_ignore_line_from_c_str_delimiter(const char** c_str,
                                                const char delimiter);

#include "implementation/c_str.h"

#endif
