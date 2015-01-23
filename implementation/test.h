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


#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../memory.h"
#include "../output.h"
#include "../input.h"


/**
 * @brief Display an error message if condition is false
 * @param[in] condition     A boolean
 * @param[in] error_message Error message
 * @return 1 if condition is true, 0 if condition is false
 */
int gho_test(const bool condition, const char* const error_message) {
  if (condition) {
    return 1;
  }
  else {
    printf(error_message);
    return 0;
  }
}
