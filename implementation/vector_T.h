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

#include "../memory.h"
#include "../c_str.h"
#include "../char.h"
#include "../output.h"
#include "../math.h"


// Create & destroy

/**
 * \brief Return a new gho_vector_T
 * \return a new gho_vector_T
 * @relates gho_vector_T_t
 */
gho_vector_T_t gho_vector_T_create() {
  gho_vector_T_t vector;
  vector.type = gho_type_vector_T;
  vector.size = 0u;
  vector.capacity = 10u;
  vector.array = gho_array_alloc(T_t, vector.capacity);
  return vector;
}

/**
 * \brief Return a new gho_vector_T
 * \param[in] n Size of the vector
 * \return a new gho_vector_T
 * @relates gho_vector_T_t
 */
gho_vector_T_t gho_vector_T_create_n(const size_t n) {
  gho_vector_T_t vector;
  vector.type = gho_type_vector_T;
  vector.size = n;
  vector.capacity = vector.size;
  vector.array = gho_array_alloc(T_t, vector.capacity);
  
  for (size_t i = 0; i < vector.size; ++i) {
    vector.array[i] = gho_T_create();
  }
  return vector;
}

/**
 * \brief Return a new gho_vector_T
 * \param[in] n             Size of the vector
 * \param[in] default_value Default value for all elements
 * \return a new gho_vector_T
 * @relates gho_vector_T_t
 */
gho_vector_T_t gho_vector_T_create_n_copy(const size_t n,
                                          const T_t* const default_value) {
  gho_vector_T_t vector;
  vector.type = gho_type_vector_T;
  vector.size = n;
  vector.capacity = vector.size;
  vector.array = gho_array_alloc(T_t, vector.capacity);
  
  for (size_t i = 0; i < vector.size; ++i) {
    vector.array[i] = gho_T_copy(default_value);
  }
  return vector;
}

/**
 * \brief Destroy a gho_vector_T
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_destroy(gho_vector_T_t* vector) {
  for (size_t i = 0; i < vector->size; ++i) {
    gho_T_destroy(&vector->array[i]);
  }
  
  vector->size = 0u;
  vector->capacity = 0u;
  free(vector->array); vector->array = NULL;
}

/**
 * \brief Reset a gho_vector_T
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_reset(gho_vector_T_t* vector) {
  gho_vector_T_destroy(vector);
  *vector = gho_vector_T_create();
}

// Output

/**
 * \brief Print a gho_vector_T in a file with indentation
 * \param[in] file   A C file
 * \param[in] vector A gho_vector_T
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_vector_T_t
 */
void gho_vector_T_fprinti(FILE* file, const gho_vector_T_t* const vector,
                          const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "{ ");
  for (size_t i = 0; i < vector->size; ++i) {
    gho_T_fprint(file, &vector->array[i]);
    if (i != vector->size - 1) { fprintf(file, ","); }
    fprintf(file, " ");
  }
  fprintf(file, "}");
}

/**
 * \brief Print a gho_vector_T in a file
 * \param[in] file   A C file
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_fprint(FILE* file, const gho_vector_T_t* const vector) {
  gho_vector_T_fprinti(file, vector, 0);
}

/**
 * \brief Print a gho_vector_T in stdout
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_print(const gho_vector_T_t* const vector) {
  gho_vector_T_fprint(stdout, vector);
}

/**
 * \brief Print a gho_vector_T in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] vector A gho_vector_T
 * \param[in] indent Indentation (number of spaces)
 * @relates gho_vector_T_t
 */
void gho_vector_T_sprinti(char** c_str, const gho_vector_T_t* const vector,
                          const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_c_str_add(c_str, "{ ");
  for (size_t i = 0; i < vector->size; ++i) {
    gho_T_sprint(c_str, &vector->array[i]);
    if (i != vector->size - 1) { gho_c_str_add(c_str, ","); }
    gho_c_str_add(c_str, " ");
  }
  gho_c_str_add(c_str, "}");
}

/**
 * \brief Print a gho_vector_T in a C string
 * \param[in] c_str  A C string
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_sprint(char** c_str, const gho_vector_T_t* const vector) {
  gho_vector_T_sprinti(c_str, vector, 0);
}

// Input

#ifdef gho_T_fread
/**
 * @brief Read a gho_vector_T from a file
 * @param[in] file A C file
 * @return the gho_vector_T read
 * @relates gho_vector_T_t
 */
gho_vector_T_t gho_vector_T_fread(FILE* file) {
  gho_vector_T_t r = gho_vector_T_create();
  gho_read_whitespace(file);
  gho_char_fread(file); // '{'
  gho_read_whitespace(file);
  while (gho_char_fpeek(file) != '}') {
    // T
    T_t tmp = gho_T_fread(file);
    gho_vector_T_add(&r, &tmp);
    gho_T_destroy(&tmp);
    // ,
    gho_read_whitespace(file);
    if (gho_char_fpeek(file) == ',') {
      gho_char_fread(file); // ','
      gho_read_whitespace(file);
    }
  }
  gho_read_whitespace(file);
  gho_char_fread(file); // '}'
  return r;
}
#endif

#ifdef gho_T_sread
/**
 * @brief Read a gho_vector_T from a C string
 * @param[in] c_str A C string
 * @return the gho_vector_T read
 * @relates gho_vector_T_t
 */
gho_vector_T_t gho_vector_T_sread(const char** c_str) {
  gho_vector_T_t r = gho_vector_T_create();
  gho_read_whitespace_from_c_str(c_str);
  gho_char_sread(c_str); // '{'
  gho_read_whitespace_from_c_str(c_str);
  while (gho_char_speek(c_str) != '}') {
    // T
    T_t tmp = gho_T_sread(c_str);
    gho_vector_T_add(&r, &tmp);
    gho_T_destroy(&tmp);
    // ,
    gho_read_whitespace_from_c_str(c_str);
    if (gho_char_speek(c_str) == ',') {
      gho_char_sread(c_str); // ','
      gho_read_whitespace_from_c_str(c_str);
    }
  }
  gho_read_whitespace_from_c_str(c_str);
  gho_char_sread(c_str); // '}'
  return r;
}
#endif

// Copy & comparisons

/**
 * \brief Copy a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \return the gho_vector_T copied
 * @relates gho_vector_T_t
 */
gho_vector_T_t gho_vector_T_copy(const gho_vector_T_t* const vector) {
  gho_vector_T_t r;
  gho_vector_T_copy_(vector, &r);
  return r;
}

/**
 * \brief Copy a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \param[in] copy   A pointer on an not initialized gho_vector_T
 * \warning Do not use this function, use gho_vector_T_copy
 * @relates gho_vector_T_t
 */
void gho_vector_T_copy_(const gho_vector_T_t* const vector,
                        gho_vector_T_t* copy) {
  *copy = gho_vector_T_create();
  gho_vector_T_add_vector(copy, vector);
}

/**
 * \brief Equality between two gho_vector_T
 * \param[in] a A gho_vector_T
 * \param[in] b A gho_vector_T
 * \return true if the gho_vector_T are equals, false otherwise
 * @relates gho_vector_T_t
 */
bool gho_vector_T_equal(const gho_vector_T_t* const a,
                        const gho_vector_T_t* const b) {
  if (a->size != b->size) { return false; }
  
  for (size_t i = 0; i < a->size; ++i) {
    if (gho_T_equal(&a->array[i], &b->array[i]) == false) { return false; }
  }
  
  return true;
}

/**
 * \brief Equality between the nth first elements of a gho_vector_T
 * \param[in] a A gho_vector_T
 * \param[in] b A gho_vector_T
 * \param[in] n Number of elements to be compared
 * \return true if the nth first elements are equals, false otherwise
 * @relates gho_vector_T_t
 */
bool gho_vector_T_equal_n(const gho_vector_T_t* const a,
                          const gho_vector_T_t* const b,
                          const size_t n) {
  if (a->size < n || b->size < n) { return false; }
  
  for (size_t i = 0; i < n; ++i) {
    if (gho_T_equal(&a->array[i], &b->array[i]) == false) { return false; }
  }
  
  return true;
}

#ifdef gho_T_compare
/**
 * \brief Compare two gho_vector_T
 * \param[in] a A gho_vector_T
 * \param[in] b A gho_vector_T
 * \return -1 if a < b, 0 if a == b, 1 if a > b
 * @relates gho_vector_T_t
 */
int gho_vector_T_compare(const gho_vector_T_t* const a,
                         const gho_vector_T_t* const b) {
  const size_t size = gho_T_min(a->size, b->size);
  
  for (size_t i = 0; i < size; ++i) {
    int r = gho_T_compare(&a->array[i], &b->array[i]);
    if (r <= -1) { return -1; }
    else if (r >= 1) { return 1; }
  }
  
  if (a->size < b->size) { return -1; }
  else if (a->size > b->size) { return 1; }
  else { return 0; }
}
#endif

// Conversion

/**
 * \brief Convert a gho_vector_T into a gho_string
 * \param[in] vector A gho_vector_T
 * \return the gho_string from the gho_vector_T
 * @relates gho_vector_T_t
 */
gho_string_t gho_vector_T_to_string(const gho_vector_T_t* const vector) {
  gho_string_t r = gho_string_create();
  gho_vector_T_sprint(&r.c_str, vector);
  return r;
}

/**
 * \brief Convert a gho_vector_T into a gho_any
 * \param[in] vector A gho_vector_T
 * \return the gho_any from the gho_vector_T
 * @relates gho_vector_T_t
 */
gho_any_t gho_vector_T_to_any(const gho_vector_T_t* const vector) {
  gho_any_t r = gho_any_create();
  r.size_of_struct = sizeof(gho_vector_T_t);
  gho_vector_T_t* p = gho_alloc(gho_vector_T_t); gho_vector_T_copy_(vector, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_vector_T_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_vector_T_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_vector_T_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_vector_T_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_vector_T_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_vector_T_to_string;
  return r;
}

// Size

/**
 * \brief Return the size of a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \return the size
 * @relates gho_vector_T_t
 */
size_t gho_vector_T_size(const gho_vector_T_t* const vector) {
  return vector->size;
}

/**
 * \brief Return the capacity of a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \return the size
 * @relates gho_vector_T_t
 */
size_t gho_vector_T_capacity(const gho_vector_T_t* const vector) {
  return vector->capacity;
}

/**
 * \brief Return true if the gho_vector_T is empty, false otherwise
 * \param[in] vector A gho_vector_T
 * \return true if the gho_vector_T is empty, false otherwise
 * @relates gho_vector_T_t
 */
bool gho_vector_T_empty(const gho_vector_T_t* const vector) {
  return (vector->size == 0);
}

/**
 * \brief Update the capacity of a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \param[in] n      Size of the vector
 * @relates gho_vector_T_t
 */
void gho_vector_T_reserve(gho_vector_T_t* vector, const size_t n) {
  if (vector->capacity < n) {
    vector->capacity = n;
    gho_array_realloc(vector->array, T_t, vector->capacity);
  }
}

/**
 * \brief Update the size of a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \param[in] n      Size of the vector
 * @relates gho_vector_T_t
 */
void gho_vector_T_resize(gho_vector_T_t* vector, const size_t n) {
  if (vector->size < n) {
    gho_vector_T_reserve(vector, n);
    for (size_t i = vector->size; i < n; ++i) {
      vector->array[i] = gho_T_create();
    }
    vector->size = n;
  }
  else if (vector->size > n) {
    for (size_t i = n; i < vector->size; ++i) {
      gho_T_destroy(&vector->array[i]);
    }
    vector->size = n;
  }
}

// Get & Set

/**
 * \brief Return the element at position i
 * \param[in] vector A gho_vector_T
 * \param[in] i      Index
 * \return the element at position i
 * @relates gho_vector_T_t
 */
const T_t* gho_vector_T_at(const gho_vector_T_t* const vector, const size_t i) {
  return &vector->array[i];
}

/**
 * \brief Set the element at position i
 * \param[in] vector A gho_vector_T
 * \param[in] i      Index
 * \param[in] value  The value to be setted
 * @relates gho_vector_T_t
 */
void gho_vector_T_set(gho_vector_T_t* vector, const size_t i,
                      const T_t* const value) {
  gho_T_destroy(&vector->array[i]);
  vector->array[i] = gho_T_copy(value);
}

// Add, Insert & Remove

/**
 * \brief Add a T at the end
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be added
 * @relates gho_vector_T_t
 */
void gho_vector_T_add(gho_vector_T_t* vector, const T_t* const to_be_added) {
  if (vector->size + 1 <= vector->capacity) {
    vector->array[vector->size] = gho_T_copy(to_be_added);
    ++vector->size;
  } else {
    gho_vector_T_reserve(vector, vector->capacity + 10);
    gho_vector_T_add(vector, to_be_added);
  }
}

/**
 * \brief Add a T at the end
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be added
 * @relates gho_vector_T_t
 */
void gho_vector_T_add_T(gho_vector_T_t* vector, const T_t to_be_added) {
  gho_vector_T_add(vector, &to_be_added);
}

/**
 * \brief Add a T at the end (same as gho_vector_T_add)
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be added
 * @relates gho_vector_T_t
 */
void gho_vector_T_add_ptr(gho_vector_T_t* vector,
                          const T_t* const to_be_added) {
  gho_vector_T_add(vector, to_be_added);
}

/**
 * \brief Move a T at the end
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be moved and added
 * \warning The to_be_added variable is moved, do not use it
 *          after this function
 * @relates gho_vector_T_t
 */
void gho_vector_T_add_absorb(gho_vector_T_t* vector, T_t* to_be_added) {
  if (vector->size + 1 <= vector->capacity) {
    vector->array[vector->size] = *to_be_added;
    ++vector->size;
  } else {
    gho_vector_T_reserve(vector, vector->capacity + 10);
    gho_vector_T_add_absorb(vector, to_be_added);
  }
}

/**
 * \brief Add a gho_vector_T at the end
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The gho_vector_T to be added
 * @relates gho_vector_T_t
 */
void gho_vector_T_add_vector(gho_vector_T_t* vector,
                             const gho_vector_T_t* const to_be_added) {
  if (vector->size + to_be_added->size <= vector->capacity) {
    for (size_t i = 0; i < to_be_added->size; ++i) {
      vector->array[vector->size] = gho_T_copy(&to_be_added->array[i]);
      ++vector->size;
    }
  } else {
    gho_vector_T_reserve(vector, vector->size + to_be_added->size);
    gho_vector_T_add_vector(vector, to_be_added);
  }
}

/**
 * \brief Insert a T
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be inserted
 * \param[in] i           Index where the T will be inserted
 * @relates gho_vector_T_t
 */
void gho_vector_T_insert(gho_vector_T_t* vector,
                         const T_t* const to_be_added, const size_t i) {
  if (i > vector->size) {
    fprintf(stderr, "ERROR: gho_vector_T_insert: invalid index!\n");
    exit(1);
  }
  if (vector->size + 1 <= vector->capacity) {
    for (size_t j = vector->size + 1; j > i + 1; --j) {
      if (j != vector->size + 1) { gho_T_destroy(&vector->array[j - 1]); }
      vector->array[j - 1] = gho_T_copy(&vector->array[j - 2]);
    }
    if (i != vector->size) { gho_T_destroy(&vector->array[i]); }
    vector->array[i] = gho_T_copy(to_be_added);
    ++vector->size;
  } else {
    gho_vector_T_reserve(vector, vector->capacity + 10);
    gho_vector_T_insert(vector, to_be_added, i);
  }
}

/**
 * \brief Insert a T
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be inserted
 * \param[in] i           Index where the T will be inserted
 * @relates gho_vector_T_t
 */
void gho_vector_T_insert_T(gho_vector_T_t* vector,
                          const T_t to_be_added, const size_t i) {
  gho_vector_T_insert(vector, &to_be_added, i);
}

/**
 * \brief Insert a T (same as gho_vector_T_insert)
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be inserted
 * \param[in] i           Index where the T will be inserted
 * @relates gho_vector_T_t
 */
void gho_vector_T_insert_ptr(gho_vector_T_t* vector,
                             const T_t* const to_be_added, const size_t i) {
  gho_vector_T_insert(vector, to_be_added, i);
}

/**
 * \brief Move and insert a T
 * \param[in] vector      A gho_vector_T
 * \param[in] to_be_added The T to be moved and inserted
 * \param[in] i           Index where the T will be inserted
 * \warning The to_be_added variable is moved, do not use it
 *          after this function
 * @relates gho_vector_T_t
 */
void gho_vector_T_insert_absorb(gho_vector_T_t* vector,
                                T_t* to_be_added, const size_t i) {
  if (i > vector->size) {
    fprintf(stderr, "ERROR: gho_vector_T_insert: invalid index!\n");
    exit(1);
  }
  if (vector->size + 1 <= vector->capacity) {
    for (size_t j = vector->size + 1; j > i + 1; --j) {
      if (j != vector->size + 1) { gho_T_destroy(&vector->array[j - 1]); }
      vector->array[j - 1] = gho_T_copy(&vector->array[j - 2]);
    }
    if (i != vector->size) { gho_T_destroy(&vector->array[i]); }
    vector->array[i] = *to_be_added;
    ++vector->size;
  } else {
    gho_vector_T_reserve(vector, vector->capacity + 10);
    gho_vector_T_insert(vector, to_be_added, i);
  }
}

/**
 * \brief Remove the element at index i
 * \param[in] vector A gho_vector_T
 * \param[in] i      Index
 * @relates gho_vector_T_t
 */
void gho_vector_T_remove(gho_vector_T_t* vector, const size_t i) {
  if (gho_vector_T_size(vector) == 0) {
    fprintf(stderr, "ERROR: gho_vector_T_remove: vector is empty!\n");
    exit(1);
  }
  else if (i >= gho_vector_T_size(vector)) {
    fprintf(stderr, "ERROR: gho_vector_T_remove: out of range!\n");
    exit(1);
  }
  else {
    for (size_t j = i; j < gho_vector_T_size(vector) - 1; ++j) {
      vector->array[j] = gho_T_copy(&vector->array[j + 1]);
    }
    --vector->size;
  }
}

/**
 * \brief Remove last element if exists
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_remove_last(gho_vector_T_t* vector) {
  if (gho_vector_T_size(vector) == 0) {
    fprintf(stderr, "ERROR: gho_vector_T_remove_last: vector is empty!\n");
    exit(1);
  }
  --vector->size;
}

// Algorithm

/**
 * \brief Find a value in a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \param[in] v      The T to be found
 * \return the index of the value found, the size of the vector if not found
 * @relates gho_vector_T_t
 */
size_t gho_vector_T_find(gho_vector_T_t* vector, const T_t* const v) {
  for (size_t i = 0; i < vector->size; ++i) {
    if (gho_T_equal(&vector->array[i], v)) { return i; }
  }
  return vector->size;
}

/**
 * \brief Find a value in a gho_vector_T
 * \param[in] vector A gho_vector_T
 * \param[in] v      The T to be found
 * \return the index of the value found, the size of the vector if not found
 * @relates gho_vector_T_t
 */
size_t gho_vector_T_find_T(gho_vector_T_t* vector, const T_t v) {
  return gho_vector_T_find(vector, &v);
}

#ifdef gho_T_compare
/**
 * \brief Sort a gho_vector_T
 * \param[in] vector A gho_vector_T
 * @relates gho_vector_T_t
 */
void gho_vector_T_sort(gho_vector_T_t* vector) {
  typedef int (*compare_fct_t)(const void*, const void*);
  qsort(vector->array, vector->size,
        sizeof(vector->array[0]),
        (compare_fct_t)gho_T_compare);
}
#endif
