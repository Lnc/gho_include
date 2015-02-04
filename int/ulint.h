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


#ifndef GHO_INT_ULINT_H
#define GHO_INT_ULINT_H

#include <stdio.h>
#include <stdbool.h>

#include "../string.h"
#include "../any.h"


// Typedef
typedef unsigned long int gho_ulint;


// Create & destroy
static inline
gho_ulint gho_ulint_create();
static inline
void gho_ulint_destroy(gho_ulint* i);
static inline
void gho_ulint_reset(gho_ulint* i);

// Output
static inline
void gho_ulint_fprinti(FILE* file, const gho_ulint* const i,
                      const unsigned int indent);
static inline
void gho_ulint_fprint(FILE* file, const gho_ulint* const i);
void gho_ulint_print(const gho_ulint* const i);
static inline
void gho_ulint_sprinti(char** c_str, const gho_ulint* const i,
                      const unsigned int indent);
static inline
void gho_ulint_sprint(char** c_str, const gho_ulint* const i);

// Input
static inline
gho_ulint gho_ulint_fread(FILE* file);
static inline
gho_ulint gho_ulint_sread(const char** c_str);

// Copy & comparisons
static inline
gho_ulint gho_ulint_copy(const gho_ulint* const i);
static inline
void gho_ulint_copy_(const gho_ulint* const i, gho_ulint* copy);
static inline
bool gho_ulint_equal(const gho_ulint* const a, const gho_ulint* const b);
static inline
int gho_ulint_compare(const gho_ulint* const a, const gho_ulint* const b);

// Conversion
static inline
gho_string_t gho_ulint_to_string(const gho_ulint* const i);
static inline
gho_any_t gho_ulint_to_any(const gho_ulint* const i);

#include "../implementation/int/ulint.h"

#endif
