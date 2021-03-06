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


#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>


/**
 * \defgroup gho_input_output gho_input_output
 * \brief Input / Output functions
 */


/**
 * @brief Read whitespace from a file
 * @param[in] file A C file
 * @ingroup gho_input_output
 */
void gho_read_whitespace(FILE* file) {
  while (true) {
    const char c = (char)fgetc(file);
    if (c == EOF || isspace(c) == 0) { ungetc(c, file); break; }
  }
}

/**
 * @brief Read whitespace from a C string
 * @param[in] c_str A C string
 * @ingroup gho_input_output
 */
void gho_read_whitespace_from_c_str(const char** c_str) {
  while (**c_str != '\0' && isspace(**c_str) != 0) {
    ++(*c_str);
  }
}