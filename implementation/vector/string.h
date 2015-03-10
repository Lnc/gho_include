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


// Add, Insert & Remove

/**
 * \brief Add a C string at the end
 * \param[in] vector      A gho_vector_string
 * \param[in] to_be_added The C string to be added
 */
void gho_vector_string_add_c_str(gho_vector_string_t* vector,
                                 const char* const to_be_added) {
  gho_string_t string = gho_string_create();
  gho_string_add_c_str(&string, to_be_added);
  gho_vector_string_add(vector, &string);
  gho_string_destroy(&string);
}

/**
 * \brief Insert a C string
 * \param[in] vector      A gho_vector_string
 * \param[in] to_be_added The C string to be inserted
 * \param[in] i           Index where the T will be inserted
 */
void gho_vector_string_insert_c_str(gho_vector_string_t* vector,
                                    const char* const to_be_added,
                                    const size_t i) {
  gho_string_t string = gho_string_create();
  gho_string_add_c_str(&string, to_be_added);
  gho_vector_string_insert(vector, &string, i);
  gho_string_destroy(&string);
}
