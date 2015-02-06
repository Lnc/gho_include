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


#ifndef GHO_OPERAND_H
#define GHO_OPERAND_H

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#include "type.h"
#include "int.h"


/**
 * \brief gho_operand_t is a typed pointer on a existing object
 */
typedef struct {
  
  /// \brief Dynamic type
  gho_type_t type;
  
  /// \brief Pointer
  void* p;
  
} gho_operand_t;

// Create & destroy
static inline
gho_operand_t gho_operand_create();
static inline
void gho_operand_destroy(gho_operand_t* op);
static inline
void gho_operand_reset(gho_operand_t* op);

// Output
static inline
void gho_operand_fprinti(FILE* file, const gho_operand_t* const op,
                         const unsigned int indent);
static inline
void gho_operand_fprint(FILE* file, const gho_operand_t* const op);
static inline
void gho_operand_print(const gho_operand_t* const op);
static inline
void gho_operand_sprinti(char** c_str, const gho_operand_t* const op,
                        const unsigned int indent);
static inline
void gho_operand_sprint(char** c_str, const gho_operand_t* const op);

// Copy
static inline
gho_operand_t gho_operand_copy(const gho_operand_t* const op);
static inline
void gho_operand_copy_(const gho_operand_t* const op, gho_operand_t* copy);

// Binary operators: + - * / % pow gcd
static inline
void gho_add(gho_operand_t r, const gho_operand_t i);
static inline
void gho_sub(gho_operand_t r, const gho_operand_t i);
static inline
void gho_mul(gho_operand_t r, const gho_operand_t i);
static inline
void gho_div_exact(gho_operand_t r, const gho_operand_t i);
static inline
void gho_floor_div_q(gho_operand_t r, const gho_operand_t i);
static inline
void gho_floor_div_r(gho_operand_t r, const gho_operand_t i);
static inline
void gho_mod(gho_operand_t r, const gho_operand_t i);
static inline
void gho_pow(gho_operand_t r, const gho_operand_t i);
static inline
void gho_gcd(gho_operand_t r, const gho_operand_t i);

// Binary operators with immediate: + - * / % pow gcd with gho_llint immediate
static inline
void gho_add_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_sub_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_mul_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_div_exact_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_floor_div_q_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_floor_div_r_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_mod_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_pow_lli(gho_operand_t r, const gho_llint i);
static inline
void gho_gcd_lli(gho_operand_t r, const gho_llint i);

// Unary operators: ++ -- -
static inline
void gho_increment(gho_operand_t i);
static inline
void gho_decrement(gho_operand_t i);
static inline
void gho_oppose(gho_operand_t i);

// Comparison operators: == != < <= > >=
static inline
bool gho_equal(const gho_operand_t a, const gho_operand_t b);
static inline
bool gho_not_equal(const gho_operand_t a, const gho_operand_t b);
static inline
bool gho_lesser(const gho_operand_t a, const gho_operand_t b);
static inline
bool gho_lesser_or_equal(const gho_operand_t a, const gho_operand_t b);
static inline
bool gho_greater(const gho_operand_t a, const gho_operand_t b);
static inline
bool gho_greater_or_equal(const gho_operand_t a, const gho_operand_t b);

// Comparison operators: ==0 >0 <0 ==1 ==-1 ==i !=i <i <=i >i >=i
static inline
bool gho_is_0(const gho_operand_t i);
static inline
bool gho_is_positif(const gho_operand_t i);
static inline
bool gho_is_negatif(const gho_operand_t i);
static inline
bool gho_is_1(const gho_operand_t i);
static inline
bool gho_is_minus_1(const gho_operand_t i);
static inline
bool gho_equal_lli(const gho_operand_t a, const gho_llint b);
static inline
bool gho_not_equal_lli(const gho_operand_t a, const gho_llint b);
static inline
bool gho_lesser_lli(const gho_operand_t a, const gho_llint b);
static inline
bool gho_lesser_or_equal_lli(const gho_operand_t a, const gho_llint b);
static inline
bool gho_greater_lli(const gho_operand_t a, const gho_llint b);
static inline
bool gho_greater_or_equal_lli(const gho_operand_t a, const gho_llint b);

// Assignment: =0 =1 =-1 set set_i
static inline
void gho_set_0(gho_operand_t i);
static inline
void gho_set_1(gho_operand_t i);
static inline
void gho_set_minus_1(gho_operand_t i);
static inline
void gho_set(gho_operand_t r, const gho_operand_t i);
static inline
void gho_set_lli(gho_operand_t r, const gho_llint i);

// Mathematical functions: abs floor ceil log pow_10_floor pow_10_round
static inline
void gho_abs(gho_operand_t i);
static inline
void gho_floor(gho_operand_t i);
static inline
void gho_ceil(gho_operand_t i);
static inline
void gho_log2(gho_operand_t i);
static inline
void gho_log10(gho_operand_t i);
static inline
void gho_pow_10_floor(gho_operand_t i);
static inline
void gho_pow_10_round(gho_operand_t i);

// Other functions: is_divisible size_in_base
static inline
bool gho_is_divisible(const gho_operand_t a, const gho_operand_t b);
static inline
size_t gho_size_in_base_2(gho_operand_t i);
static inline
size_t gho_size_in_base_10(gho_operand_t i);

// Conversion to gho_operand
static inline
gho_operand_t gho_operand(void* p);
static inline
gho_operand_t gho_operand_type(void* p, const gho_type_t type);
static inline
gho_operand_t gho_operand_i(void* p, const size_t i);
static inline
gho_operand_t gho_operand_i_j(void* p, const size_t i, const size_t j);

// Conversion to integer
static inline
gho_llint gho_operand_to_lli(gho_operand_t i);
static inline
gho_lint gho_operand_to_li(gho_operand_t i);

#include "implementation/operand.h"

#endif
