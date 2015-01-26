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


#ifndef GHO_INT_UINT_H
#define GHO_INT_UINT_H

#include <stdio.h>
#include <stdbool.h>

#include "../string.h"
#include "../any.h"


// Typedef
typedef unsigned int gho_uint;


// Create & destroy
static inline
gho_uint gho_uint_create();
static inline
void gho_uint_destroy(gho_uint* i);
static inline
void gho_uint_reset(gho_uint* i);

// Output
static inline
void gho_uint_fprinti(FILE* file, const gho_uint* const i,
                     const unsigned int indent);
static inline
void gho_uint_fprint(FILE* file, const gho_uint* const i);
void gho_uint_print(const gho_uint* const i);
static inline
void gho_uint_sprinti(char** c_str, const gho_uint* const i,
                     const unsigned int indent);
static inline
void gho_uint_sprint(char** c_str, const gho_uint* const i);

// Input
static inline
gho_uint gho_uint_fread(FILE* file);
static inline
gho_uint gho_uint_sread(const char** c_str);

// Copy & comparisons
static inline
gho_uint gho_uint_copy(const gho_uint* const i);
static inline
void gho_uint_copy_(const gho_uint* const i, gho_uint* copy);
static inline
bool gho_uint_equal(const gho_uint* const a, const gho_uint* const b);

// Conversion
static inline
gho_string_t gho_uint_to_string(const gho_uint* const i);
static inline
gho_any_t gho_uint_to_any(const gho_uint* const i);

#include "../implementation/int/uint.h"

#endif
