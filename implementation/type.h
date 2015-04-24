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


// Create

/**
 * @brief Struct to get gho_type_t
 * @ingroup gho_type
 */
typedef struct {
  gho_type_t type;
} gho_struct_with_type_field_t;

/**
 * \brief Return the gho type
 * \param[in] p A pointer on a structure which has the type as first field
 * \return the gho type
 * @ingroup gho_type
 */
gho_type_t gho_type(const void* const p) {
  return ((const gho_struct_with_type_field_t* const)p)->type;
}
