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


#ifndef GHO_ANY_H
#define GHO_ANY_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "string.h"
#include "type.h"
#include "memory.h"


// Typedef for functions
typedef void (*gho_destroy_fct_t)(void*);
typedef void (*gho_fprinti_fct_t)(FILE*, const void* const, const unsigned int);
typedef void (*gho_sprinti_fct_t)(char**, const void* const, const unsigned int);
typedef void (*gho_copy_fct_t)(const void* const, void*);
typedef bool (*gho_equal_fct_t)(const void* const, const void* const);
typedef gho_string_t (*gho_to_string_fct_t)(const void* const);

/**
 * \brief gho_any_t encapsulates any structure
 */
typedef struct {
  
  /// \brief Structure
  void* any;
  
  /// \brief Type of the structure
  gho_type_t type;
  
  /// \brief Size of the structure
  size_t size_of_struct;
  
  /// \brief destroy function
  gho_destroy_fct_t destroy_fct;
  
  /// \brief fprinti function
  gho_fprinti_fct_t fprinti_fct;
  
  /// \brief sprinti function
  gho_sprinti_fct_t sprinti_fct;
  
  /// \brief copy function
  gho_copy_fct_t copy_fct;
  
  /// \brief equal function
  gho_equal_fct_t equal_fct;
  
  /// \brief to_string function
  gho_to_string_fct_t to_string_fct;
  
} gho_any_t;


// Create & destroy
static inline
gho_any_t gho_any_create();
static inline
void gho_any_destroy(gho_any_t* any);
static inline
void gho_any_reset(gho_any_t* any);

// Output
static inline
void gho_any_fprinti(FILE* file, const gho_any_t* const any,
                     const unsigned int indent);
static inline
void gho_any_fprint(FILE* file, const gho_any_t* const any);
static inline
void gho_any_print(const gho_any_t* const any);
static inline
void gho_any_sprinti(char** c_str, const gho_any_t* const any,
                     const unsigned int indent);
static inline
void gho_any_sprint(char** c_str, const gho_any_t* const any);

// Copy & comparisons
static inline
gho_any_t gho_any_copy(const gho_any_t* const any);
static inline
void gho_any_copy_(const gho_any_t* const any, gho_any_t* copy);
static inline
bool gho_any_equal(const gho_any_t* const a, const gho_any_t* const b);

// Conversion
static inline
gho_string_t gho_any_to_string(const gho_any_t* const any);

// Conversion for gho_string_t
static inline
gho_any_t gho_string_to_any(const gho_string_t* const string);

#include "implementation/any.h"

#endif
