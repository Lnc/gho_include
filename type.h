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



#ifndef GHO_TYPE_H
#define GHO_TYPE_H


/**
 * \brief (Dynamic) types known
 */
typedef enum {
  
  // NULL
  GHO_TYPE_NULL,
  
  // C
  GHO_TYPE_CHAR,
  GHO_TYPE_INT,
  GHO_TYPE_LINT,
  GHO_TYPE_LLINT,
  GHO_TYPE_SIZE_T,
  GHO_TYPE_UINT,
  GHO_TYPE_LUINT,
  GHO_TYPE_LLUINT,
  GHO_TYPE_C_STR,
  
  // gho
  GHO_TYPE_GHO_STRING
  
} gho_type_t;


// Create
static inline
gho_type_t gho_type(const void* const p);

#include "implementation/type.h"

#endif
