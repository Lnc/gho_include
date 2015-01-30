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


#ifndef GHO_START_AND_SIZE_H
#define GHO_START_AND_SIZE_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "string.h"
#include "any.h"
#include "int/size_t.h"


/**
 * \brief gho_start_and_size_t encapsulates a C string
 */
typedef struct {
  
  /// \brief Start
  size_t start;
  
  /// \brief Size
  size_t size;
  
} gho_start_and_size_t;


// Create & destroy
static inline
gho_start_and_size_t gho_start_and_size_create();
static inline
void gho_start_and_size_destroy(gho_start_and_size_t* start_and_size);
static inline
void gho_start_and_size_reset(gho_start_and_size_t* start_and_size);

// Output
static inline
void gho_start_and_size_fprinti(FILE* file,
                               const gho_start_and_size_t* const start_and_size,
                               const unsigned int indent);
static inline
void gho_start_and_size_fprint(FILE* file,
                             const gho_start_and_size_t* const start_and_size);
static inline
void gho_start_and_size_print(
                             const gho_start_and_size_t* const start_and_size);
static inline
void gho_start_and_size_sprinti(char** c_str,
                               const gho_start_and_size_t* const start_and_size,
                               const unsigned int indent);
static inline
void gho_start_and_size_sprint(char** c_str,
                             const gho_start_and_size_t* const start_and_size);

// Input
static inline
gho_start_and_size_t gho_start_and_size_fread(FILE* file);
static inline
gho_start_and_size_t gho_start_and_size_sread(const char** c_str);

// Copy & comparisons
static inline
gho_start_and_size_t gho_start_and_size_copy(
                             const gho_start_and_size_t* const start_and_size);
static inline
void gho_start_and_size_copy_(const gho_start_and_size_t* const start_and_size,
                              gho_start_and_size_t* copy);
static inline
bool gho_start_and_size_equal(const gho_start_and_size_t* const a,
                              const gho_start_and_size_t* const b);

// Conversion
static inline
gho_string_t gho_start_and_size_to_string(
                             const gho_start_and_size_t* const start_and_size);
static inline
gho_any_t gho_start_and_size_to_any(
                             const gho_start_and_size_t* const start_and_size);

#include "implementation/start_and_size.h"

#endif
