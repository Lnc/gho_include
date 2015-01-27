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


#ifndef GHO_CHAR_H
#define GHO_CHAR_H

#include <stdio.h>
#include <stdbool.h>

#include "string.h"
#include "any.h"


// Create & destroy
static inline
char gho_char_create();
static inline
void gho_char_destroy(char* c);
static inline
void gho_char_reset(char* c);

// Output
static inline
void gho_char_fprinti(FILE* file, const char* const c,
                      const unsigned int indent);
static inline
void gho_char_fprint(FILE* file, const char* const c);
static inline
void gho_char_print(const char* const c);
static inline
void gho_char_sprinti(char** c_str, const char* const c,
                      const unsigned int indent);
static inline
void gho_char_sprint(char** c_str, const char* const c);

// Input
static inline
char gho_char_fread(FILE* file);
static inline
char gho_char_sread(const char** c_str);

// Copy & comparisons
static inline
char gho_char_copy(const char* const c);
static inline
void gho_char_copy_(const char* const c, char* copy);
static inline
bool gho_char_equal(const char* const a, const char* const b);

// Conversion
static inline
gho_string_t gho_char_to_string(const char* const c);
static inline
gho_any_t gho_char_to_any(const char* const c);

// Peek
static inline
char gho_char_fpeek(FILE* file);
static inline
char gho_char_speek(const char** c_str);

#include "implementation/char.h"

#endif
