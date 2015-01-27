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


#ifndef GHO_INT_SIZE_T_H
#define GHO_INT_SIZE_T_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "../string.h"
#include "../any.h"


// Create & destroy
static inline
size_t gho_size_t_create();
static inline
void gho_size_t_destroy(size_t* i);
static inline
void gho_size_t_reset(size_t* i);

// Output
static inline
void gho_size_t_fprinti(FILE* file, const size_t* const i,
                        const unsigned int indent);
static inline
void gho_size_t_fprint(FILE* file, const size_t* const i);
static inline
void gho_size_t_print(const size_t* const i);
static inline
void gho_size_t_sprinti(char** c_str, const size_t* const i,
                        const unsigned int indent);
static inline
void gho_size_t_sprint(char** c_str, const size_t* const i);

// Input
static inline
size_t gho_size_t_fread(FILE* file);
static inline
size_t gho_size_t_sread(const char** c_str);

// Copy & comparisons
static inline
size_t gho_size_t_copy(const size_t* const i);
static inline
void gho_size_t_copy_(const size_t* const i, size_t* copy);
static inline
bool gho_size_t_equal(const size_t* const a, const size_t* const b);
static inline
int gho_size_t_compare(const size_t* const a, const size_t* const b);

// Conversion
static inline
gho_string_t gho_size_t_to_string(const size_t* const i);
static inline
gho_any_t gho_size_t_to_any(const size_t* const i);

#include "../implementation/int/size_t.h"

#endif
