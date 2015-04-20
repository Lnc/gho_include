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


// gho_sleep

/**
 * \brief Sleep s seconds
 * \param[in] s Number of seconds
 */
void gho_sleep(const unsigned int s) {
  gho_millisleep(s * 1000u);
}


// gho_millisleep

#if gho_unix

  #include <unistd.h>
  
  int usleep(unsigned long int);
  
  void gho_millisleep(const unsigned int ms) {
    usleep(ms * 1000u);
  }

#elif gho_windows

  #include <Windows.h>
  
  void gho_millisleep(const unsigned int ms) {
    Sleep(ms);
  }

#else

  #include <stdio.h>
  #include <stdlib.h>
  
  #include "../unused.h"
  
  void gho_millisleep(const unsigned int ms) {
    gho_unused(ms);
    fprintf(stderr, "ERROR: gho_millisleep is not implemented on "
                            "your system\n");
    exit(1);
  }

#endif
