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


#ifndef GHO_MATH_H
#define GHO_MATH_H

#include <math.h>


/**
 * \brief Return the smallest of a and b
 * \param[in] a A value
 * \param[in] b A value
 * \return the smallest value
 */
#define gho_min(a, b) \
  (((a) < (b)) ? (a) : (b))

/**
 * \brief Return the largest of a and b
 * \param[in] a A value
 * \param[in] b A value
 * \return the largest value
 */
#define gho_max(a, b) \
  (((a) > (b)) ? (a) : (b))

/**
 * \brief Return ceil((double)n / (double)d)
 * \param[in] n Numerator
 * \param[in] d Denominator
 * \return ceil((double)n / (double)d)
 */
#define gho_ceil_div(n, d) \
  ceil(((double)(n)) / ((double)(d)))

/**
 * \brief Return floor((double)n / (double)d)
 * \param[in] n Numerator
 * \param[in] d Denominator
 * \return floor((double)n / (double)d)
 */
#define gho_floor_div(n, d) \
  floor(((double)(n)) / ((double)(d)))

#endif
