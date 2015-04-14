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

#include "../memory.h"
#include "../c_str.h"
#include "../output.h"
#include "../int/size_t.h"


// Create & destroy

/**
 * \brief Return a new gho_matrix_T
 * \return a new gho_matrix_T
 */
gho_matrix_T_t gho_matrix_T_create() {
  gho_matrix_T_t matrix;
  matrix.type = gho_type_matrix_T;
  matrix.nb_row = 0u;
  matrix.nb_col = 0u;
  matrix.array = gho_array_alloc(T_t*, matrix.nb_row);
  return matrix;
}

/**
 * \brief Return a new gho_matrix_T
 * \param[in] nb_row Number of rows
 * \param[in] nb_col Number of columns
 * \return a new gho_matrix_T
 */
gho_matrix_T_t gho_matrix_T_create_n_m(const size_t nb_row,
                                       const size_t nb_col) {
  gho_matrix_T_t matrix;
  matrix.type = gho_type_matrix_T;
  matrix.nb_row = nb_row;
  matrix.nb_col = nb_col;
  matrix.array = gho_array_alloc(T_t*, matrix.nb_row);
  
  for (size_t i = 0; i < matrix.nb_row; ++i) {
    matrix.array[i] = gho_array_alloc(T_t, matrix.nb_col);
    for (size_t j = 0; j < matrix.nb_col; ++j) {
      matrix.array[i][j] = gho_T_create();
    }
  }
  return matrix;
}

/**
 * \brief Return a new gho_matrix_T
 * \param[in] nb_row        Number of rows
 * \param[in] nb_col        Number of columns
 * \param[in] default_value Default value for all elements
 * \return a new gho_matrix_T
 */
gho_matrix_T_t gho_matrix_T_create_n_m_copy(
                                       const size_t nb_row, const size_t nb_col,
                                       const T_t* const default_value) {
  gho_matrix_T_t matrix;
  matrix.type = gho_type_matrix_T;
  matrix.nb_row = nb_row;
  matrix.nb_col = nb_col;
  matrix.array = gho_array_alloc(T_t*, matrix.nb_row);
  
  for (size_t i = 0; i < matrix.nb_row; ++i) {
    matrix.array[i] = gho_array_alloc(T_t, matrix.nb_col);
    for (size_t j = 0; j < matrix.nb_col; ++j) {
      matrix.array[i][j] = gho_T_copy(default_value);
    }
  }
  return matrix;
}

/**
 * \brief Destroy a gho_matrix_T
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_destroy(gho_matrix_T_t* matrix) {
  for (size_t i = 0; i < matrix->nb_row; ++i) {
    for (size_t j = 0; j < matrix->nb_col; ++j) {
      gho_T_destroy(&matrix->array[i][j]);
    }
    free(matrix->array[i]); matrix->array[i] = NULL;
  }
  
  matrix->nb_row = 0u;
  matrix->nb_col = 0u;
  free(matrix->array); matrix->array = NULL;
}

/**
 * \brief Reset a gho_matrix_T
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_reset(gho_matrix_T_t* matrix) {
  gho_matrix_T_destroy(matrix);
  *matrix = gho_matrix_T_create();
}

// Output

/**
 * \brief Print a gho_matrix_T in a file with indentation
 * \param[in] file   A C file
 * \param[in] matrix A gho_matrix_T
 * \param[in] indent Indentation (number of spaces)
 */
void gho_matrix_T_fprinti(FILE* file, const gho_matrix_T_t* const matrix,
                          const unsigned int indent) {
  gho_fprinti(file, indent);
  fprintf(file, "{\n");
  for (size_t i = 0; i < matrix->nb_row; ++i) {
    gho_fprinti(file, indent);
    fprintf(file, "  { ");
    for (size_t j = 0; j < matrix->nb_col; ++j) {
      gho_T_fprint(file, &matrix->array[i][j]);
      if (j != matrix->nb_col - 1) { fprintf(file, ","); }
      fprintf(file, " ");
    }
    fprintf(file, "}");
    if (i != matrix->nb_row - 1) { fprintf(file, ","); }
    fprintf(file, "\n");
  }
  gho_fprinti(file, indent);
  fprintf(file, "}");
}

/**
 * \brief Print a gho_matrix_T in a file
 * \param[in] file   A C file
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_fprint(FILE* file, const gho_matrix_T_t* const matrix) {
  gho_matrix_T_fprinti(file, matrix, 0);
}

/**
 * \brief Print a gho_matrix_T in stdout
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_print(const gho_matrix_T_t* const matrix) {
  gho_matrix_T_fprint(stdout, matrix);
}

/**
 * \brief Print a gho_matrix_T in a C string with indentation
 * \param[in] c_str  A C string
 * \param[in] matrix A gho_matrix_T
 * \param[in] indent Indentation (number of spaces)
 */
void gho_matrix_T_sprinti(char** c_str, const gho_matrix_T_t* const matrix,
                          const unsigned int indent) {
  gho_sprinti(c_str, indent);
  gho_c_str_add(c_str, "{\n");
  for (size_t i = 0; i < matrix->nb_row; ++i) {
    gho_sprinti(c_str, indent);
    gho_c_str_add(c_str, "  { ");
    for (size_t j = 0; j < matrix->nb_col; ++j) {
      gho_T_sprint(c_str, &matrix->array[i][j]);
      if (j != matrix->nb_col - 1) { gho_c_str_add(c_str, ","); }
      gho_c_str_add(c_str, " ");
    }
    gho_c_str_add(c_str, "}");
    if (i != matrix->nb_row - 1) { gho_c_str_add(c_str, ","); }
    gho_c_str_add(c_str, "\n");
  }
  gho_sprinti(c_str, indent);
  gho_c_str_add(c_str, "}");
}

/**
 * \brief Print a gho_matrix_T in a C string
 * \param[in] c_str  A C string
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_sprint(char** c_str, const gho_matrix_T_t* const matrix) {
  gho_matrix_T_sprinti(c_str, matrix, 0);
}

// Copy & comparisons

/**
 * \brief Copy a gho_matrix_T
 * \param[in] vector A gho_matrix_T
 * \return the gho_matrix_T copied
 */
gho_matrix_T_t gho_matrix_T_copy(const gho_matrix_T_t* const matrix) {
  gho_matrix_T_t r;
  gho_matrix_T_copy_(matrix, &r);
  return r;
}

/**
 * \brief Copy a gho_matrix_T
 * \param[in] matrix A gho_matrix_T
 * \param[in] copy   A pointer on an not initialized gho_matrix_T
 * \warning Do not use this function, use gho_matrix_T_copy
 */
void gho_matrix_T_copy_(const gho_matrix_T_t* const matrix,
                        gho_matrix_T_t* copy) {
  *copy = gho_matrix_T_create_n_m(matrix->nb_row, matrix->nb_col);
  for (size_t i = 0; i < matrix->nb_row; ++i) {
    for (size_t j = 0; j < matrix->nb_col; ++j) {
      copy->array[i][j] = gho_T_copy(&matrix->array[i][j]);
    }
  }
}

/**
 * \brief Equality between two gho_matrix_T
 * \param[in] a A gho_matrix_T
 * \param[in] b A gho_matrix_T
 * \return true if the gho_matrix_T are equals, false otherwise
 */
bool gho_matrix_T_equal(const gho_matrix_T_t* const a,
                        const gho_matrix_T_t* const b) {
  if (a->nb_row != b->nb_row || a->nb_col != b->nb_col) { return false; }
  for (size_t i = 0; i < a->nb_row; ++i) {
    for (size_t j = 0; j < a->nb_col; ++j) {
      if (gho_T_equal(&a->array[i][j], &b->array[i][j]) == false) { return false; }
    }
  }
  return true;
}

// Conversion

/**
 * \brief Convert a gho_matrix_T into a gho_string
 * \param[in] matrix A gho_matrix_T
 * \return the gho_string from the gho_matrix_T
 */
gho_string_t gho_matrix_T_to_string(const gho_matrix_T_t* const matrix) {
  gho_string_t r = gho_string_create();
  gho_matrix_T_sprint(&r.c_str, matrix);
  return r;
}

/**
 * \brief Convert a gho_matrix_T into a gho_any
 * \param[in] matrix A gho_matrix_T
 * \return the gho_any from the gho_matrix_T
 */
gho_any_t gho_matrix_T_to_any(const gho_matrix_T_t* const matrix) {
  gho_any_t r = gho_any_create();
  r.size_of_struct = sizeof(gho_matrix_T_t);
  gho_matrix_T_t* p = gho_alloc(gho_matrix_T_t); gho_matrix_T_copy_(matrix, p);
  r.any = p; p = NULL;
  r.destroy_fct = (gho_destroy_fct_t)gho_matrix_T_destroy;
  r.fprinti_fct = (gho_fprinti_fct_t)gho_matrix_T_fprinti;
  r.sprinti_fct = (gho_sprinti_fct_t)gho_matrix_T_sprinti;
  r.copy_fct = (gho_copy_fct_t)gho_matrix_T_copy_;
  r.equal_fct = (gho_equal_fct_t)gho_matrix_T_equal;
  r.to_string_fct = (gho_to_string_fct_t)gho_matrix_T_to_string;
  return r;
}

// Size

/**
 * \brief Return the number of rows of a gho_matrix_T
 * \param[in] matrix A gho_matrix_T
 * \return the size
 */
size_t gho_matrix_T_nb_row(const gho_matrix_T_t* const matrix) {
  return matrix->nb_row;
}

/**
 * \brief Return the number of columns of a gho_matrix_T
 * \param[in] matrix A gho_matrix_T
 * \return the size
 */
size_t gho_matrix_T_nb_col(const gho_matrix_T_t* const matrix) {
  return matrix->nb_col;
}

/**
 * \brief Return true if the gho_matrix_T is empty, false otherwise
 * \param[in] matrix A gho_matrix_T
 * \return true if the gho_matrix_T is empty, false otherwise
 */
bool gho_matrix_T_empty(const gho_matrix_T_t* const matrix) {
  return (matrix->nb_row == 0 || matrix->nb_col == 0);
}

// Get & Set

/**
 * \brief Return the element at position (i, j)
 * \param[in] matrix A gho_matrix_T
 * \param[in] i      Index of the row
 * \param[in] j      Index of the column
 * \return the element at position (i, j)
 */
const T_t* gho_matrix_T_at(const gho_matrix_T_t* const matrix,
                                  const size_t i, const size_t j) {
  return &matrix->array[i][j];
}

/**
 * \brief Set the element at position (i, j)
 * \param[in] matrix A gho_matrix_T
 * \param[in] i      Index of the row
 * \param[in] j      Index of the column
 * \param[in] value  The value to be setted
 */
void gho_matrix_T_set(gho_matrix_T_t* matrix, const size_t i, const size_t j,
                      const T_t* const value) {
  gho_T_destroy(&matrix->array[i][j]);
  matrix->array[i][j] = gho_T_copy(value);
}

// Add & remove

/**
 * \brief Add a row at the end
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_add_row(gho_matrix_T_t* matrix) {
  gho_matrix_T_add_row_after(matrix, matrix->nb_row - 1);
}

/**
 * \brief Add a row before the index
 * \param[in] matrix A gho_matrix_T
 * \param[in] i      Index of a row
 */
void gho_matrix_T_add_row_before(gho_matrix_T_t* matrix, const size_t i) {
  if (i > matrix->nb_row) {
    fprintf(stderr, "ERROR: gho_matrix_T_add_row_before: invalid row index!\n");
    exit(1);
  }
  gho_matrix_T_t matrix_new =
    gho_matrix_T_create_n_m(matrix->nb_row + 1, matrix->nb_col);
  for (size_t n = 0; n < i; ++n) {
    for (size_t m = 0; m < matrix->nb_col; ++m) {
      gho_T_destroy(&matrix_new.array[n][m]);
      matrix_new.array[n][m] = gho_T_copy(&matrix->array[n][m]);
    }
  }
  for (size_t n = i + 1; n < matrix_new.nb_row; ++n) {
    for (size_t m = 0; m < matrix->nb_col; ++m) {
      gho_T_destroy(&matrix_new.array[n][m]);
      matrix_new.array[n][m] = gho_T_copy(&matrix->array[n - 1][m]);
    }
  }
  gho_matrix_T_destroy(matrix);
  *matrix = matrix_new;
}

/**
 * \brief Add a row after the index
 * \param[in] matrix A gho_matrix_T
 * \param[in] i      Index of a row
 */
void gho_matrix_T_add_row_after(gho_matrix_T_t* matrix, const size_t i) {
  gho_matrix_T_add_row_before(matrix, i + 1);
}

/**
 * \brief Add a column at the end
 * \param[in] matrix A gho_matrix_T
 */
void gho_matrix_T_add_col(gho_matrix_T_t* matrix) {
  gho_matrix_T_add_col_after(matrix, matrix->nb_col - 1);
}

/**
 * \brief Add a column before the index
 * \param[in] matrix A gho_matrix_T
 * \param[in] j      Index of a column
 */
void gho_matrix_T_add_col_before(gho_matrix_T_t* matrix, const size_t j) {
  if (j > matrix->nb_col) {
    fprintf(stderr, "ERROR: gho_matrix_T_add_col_before: invalid column index!\n");
    exit(1);
  }
  gho_matrix_T_t matrix_new =
    gho_matrix_T_create_n_m(matrix->nb_row, matrix->nb_col + 1);
  for (size_t n = 0; n < matrix->nb_row; ++n) {
    for (size_t m = 0; m < j; ++m) {
      gho_T_destroy(&matrix_new.array[n][m]);
      matrix_new.array[n][m] = gho_T_copy(&matrix->array[n][m]);
    }
    for (size_t m = j + 1; m < matrix_new.nb_col; ++m) {
      gho_T_destroy(&matrix_new.array[n][m]);
      matrix_new.array[n][m] = gho_T_copy(&matrix->array[n][m - 1]);
    }
  }
  gho_matrix_T_destroy(matrix);
  *matrix = matrix_new;
}

/**
 * \brief Add a column after the index
 * \param[in] matrix A gho_matrix_T
 * \param[in] j      Index of a column
 */
void gho_matrix_T_add_col_after(gho_matrix_T_t* matrix, const size_t j) {
  gho_matrix_T_add_col_before(matrix, j + 1);
}

/**
 * \brief Remove a row
 * \param[in] matrix A gho_matrix_T
 * \param[in] i      Index of a row
 */
void gho_matrix_T_remove_row(gho_matrix_T_t* matrix, const size_t i) {
  if (matrix->nb_row == 0) {
    fprintf(stderr, "ERROR: gho_matrix_T_remove_row: matrix is empty!\n");
    exit(1);
  }
  else if (i >= matrix->nb_row) {
    fprintf(stderr, "ERROR: gho_matrix_T_remove_row: invalid row index (");
    fprintf(stderr, "row index = ");
    gho_size_t_fprint(stderr, &i);
    fprintf(stderr, ", number of rows = ");
    gho_size_t_fprint(stderr, &matrix->nb_col);
    fprintf(stderr, ")!\n");
    exit(1);
  }
  else {
    for (size_t row = i; row < matrix->nb_row - 1; ++row) {
      for (size_t col = 0; col < matrix->nb_col; ++col) {
        gho_T_destroy(&matrix->array[row][col]);
        matrix->array[row][col] = gho_T_copy(&matrix->array[row + 1][col]);
      }
    }
    for (size_t col = 0; col < matrix->nb_col; ++col) {
      gho_T_destroy(&matrix->array[matrix->nb_row - 1][col]);
    }
    free(matrix->array[matrix->nb_row - 1]);
    matrix->array[matrix->nb_row - 1] = NULL;
    --matrix->nb_row;
  }
}

/**
 * \brief Remove a column
 * \param[in] matrix A gho_matrix_T
 * \param[in] j      Index of a column
 */
void gho_matrix_T_remove_col(gho_matrix_T_t* matrix, const size_t j) {
  if (matrix->nb_col == 0) {
    fprintf(stderr, "ERROR: gho_matrix_T_remove_col: matrix is empty!\n");
  }
  else if (j >= matrix->nb_col) {
    fprintf(stderr, "ERROR: gho_matrix_T_remove_col: invalid column index (");
    fprintf(stderr, "column index = ");
    gho_size_t_fprint(stderr, &j);
    fprintf(stderr, ", number of columns = ");
    gho_size_t_fprint(stderr, &matrix->nb_col);
    fprintf(stderr, ")!\n");
  }
  else {
    for (size_t row = 0; row < matrix->nb_row; ++row) {
      for (size_t col = j; col < matrix->nb_col - 1; ++col) {
        gho_T_destroy(&matrix->array[row][col]);
        matrix->array[row][col] = gho_T_copy(&matrix->array[row][col + 1]);
      }
      gho_T_destroy(&matrix->array[row][matrix->nb_col - 1]);
    }
    --matrix->nb_col;
  }
}
