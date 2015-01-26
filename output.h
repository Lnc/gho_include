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


#ifndef GHO_OUTPUT_H
#define GHO_OUTPUT_H


#include <stdio.h>


static inline
void gho_fprinti(FILE* file, const unsigned int indent);

static inline
void gho_sprinti(char** c_str, const unsigned int indent);

#include "implementation/output.h"

#endif
