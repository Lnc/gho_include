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


// Create & destroy

/**
 * \brief Return a new gho_any_t
 * \return a new gho_any_t
 * @relates gho_any_t
 */
gho_any_t gho_any_create() {
  gho_any_t any;
  any.any = NULL;
  any.type = GHO_TYPE_NULL;
  any.size_of_struct = 0;
  any.destroy_fct = NULL;
  any.fprinti_fct = NULL;
  any.sprinti_fct = NULL;
  any.copy_fct = NULL;
  any.equal_fct = NULL;
  any.to_string_fct = NULL;
  return any;
}

/**
 * \brief Destroy a gho_any_t
 * \param[in] any A gho_any_t
 * @relates gho_any_t
 */
void gho_any_destroy(gho_any_t* any) {
  any->destroy_fct(any->any);
  free(any->any);
  any->any = NULL;
  any->type = GHO_TYPE_NULL;
  any->size_of_struct = 0;
  any->destroy_fct = NULL;
  any->fprinti_fct = NULL;
  any->sprinti_fct = NULL;
  any->copy_fct = NULL;
  any->equal_fct = NULL;
  any->to_string_fct = NULL;
}

/**
 * \brief Erase a gho_any_t
 * \param[in] any A gho_any_t
 * @relates gho_any_t
 */
void gho_any_reset(gho_any_t* any) {
  gho_any_destroy(any);
  *any = gho_any_create();
}

// Output

/**
 * \brief Print a gho_any_t in a file with indentation
 * \param[in] file   A C file
 * \param[in] any    A gho_any_t
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_any_t
 */
void gho_any_fprinti(FILE* file, const gho_any_t* const any,
                     const unsigned int indent) {
  any->fprinti_fct(file, any->any, indent);
}

/**
 * \brief Print a gho_any_t in a file
 * \param[in] file A C file
 * \param[in] any  A gho_any_t
 * @relates gho_any_t
 */
void gho_any_fprint(FILE* file, const gho_any_t* const any) {
  gho_any_fprinti(file, any, 0);
}

/**
 * \brief Print a gho_any_t in stdout
 * \param[in] any A gho_any_t
 * @relates gho_any_t
 */
void gho_any_print(const gho_any_t* const any) {
  gho_any_fprint(stdout, any);
}

/**
 * \brief Print a gho_any_t in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] any    A gho_any_t
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_any_t
 */
void gho_any_sprinti(char** c_str, const gho_any_t* const any,
                     const unsigned int indent) {
  any->sprinti_fct(c_str, any->any, indent);
}

/**
 * \brief Print a gho_any_t in a C string
 * \param[in] c_str A C string
 * \param[in] any   A gho_any_t
 * @relates gho_any_t
 */
void gho_any_sprint(char** c_str, const gho_any_t* const any) {
  gho_any_sprinti(c_str, any, 0);
}

// Copy & comparisons

/**
 * \brief Copy a gho_any_t
 * \param[in] any A gho_any_t
 * \return the gho_any_t copied
 * @relates gho_any_t
 */
gho_any_t gho_any_copy(const gho_any_t* const any) {
  gho_any_t r = gho_any_create();
  gho_any_copy_(any, &r);
  return r;
}

/**
 * \brief Copy a gho_any_t
 * \param[in] any  A gho_any_t
 * \param[in] copy A pointer on an not initialized gho_any_t
 * \warning Do not use this function, use gho_any_copy
 * @relates gho_any_t
 */
void gho_any_copy_(const gho_any_t* const any, gho_any_t* copy) {
  copy->any = malloc(any->size_of_struct);
  any->copy_fct(any->any, copy->any);
  copy->type = any->type;
  copy->size_of_struct = any->size_of_struct;
  copy->destroy_fct = any->destroy_fct;
  copy->fprinti_fct = any->fprinti_fct;
  copy->sprinti_fct = any->sprinti_fct;
  copy->copy_fct = any->copy_fct;
  copy->equal_fct = any->equal_fct;
  copy->to_string_fct = any->to_string_fct;
}

/**
 * \brief Equality between two gho_any_t
 * \param[in] a A gho_any_t
 * \param[in] b A gho_any_t
 * \return true if the gho_any_t are equals, false otherwise
 * @relates gho_any_t
 */
bool gho_any_equal(const gho_any_t* const a, const gho_any_t* const b) {
  if (a->equal_fct == NULL || b->equal_fct == NULL) {
    return false;
  }
  else if (a->equal_fct == b->equal_fct) {
    return a->equal_fct(a->any, b->any);
  }
  else {
    return false;
  }
}

// Conversion

/**
 * \brief Convert a gho_any_t into a gho_string_t
 * \param[in] any A gho_any_t
 * \return the gho_string_t from the gho_any_t
 * @relates gho_any_t
 */
gho_string_t gho_any_to_string(const gho_any_t* const any) {
  return any->to_string_fct(any);
}

// Conversion for gho_string_t

/**
 * \brief Convert a gho_string_t into a gho_any_t
 * \param[in] string A gho_string_t
 * \return the gho_any_t from the gho_string_t
 * @relates gho_any_t
 */
gho_any_t gho_string_to_any(const gho_string_t* const string) {
  gho_any_t r = gho_any_create();
  r.type = GHO_TYPE_GHO_STRING;
  r.size_of_struct = sizeof(gho_string_t);
  gho_string_t* p = gho_alloc(gho_string_t); gho_string_copy_(string, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_string_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_string_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_string_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_string_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_string_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_string_to_string;
  return r;
}
