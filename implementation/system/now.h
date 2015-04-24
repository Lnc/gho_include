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


// gho_now_seconds

#include <time.h>

/**
 * \brief Time since 1970 in seconds
 * \return time since 1970 in seconds
 * @ingroup gho_system
 */
long double gho_now_seconds() {
  
  #if gho_unix
  
    return gho_now_milliseconds() / 1000.0;
  
  #elif gho_windows
  
    return gho_now_milliseconds() / 1000.0;
  
  #else
  
    return (long double)time(NULL);
  
  #endif
}


// gho_get_time_of_day

/**
 * \brief Contains seconds and microseconds
 * @ingroup gho_system
 */
typedef struct {
  
    /// Seconds
    unsigned long long int seconds;
    
    /// Microseconds
    unsigned long long int microseconds;
  
} gho_seconds_and_microseconds_t;

/**
 * \brief Time since 1970
 * \param[in] sec_and_microsec A gho_seconds_and_microseconds_t
 * \return time since 1970
 * @ingroup gho_system
 */
static inline
void gho_get_time_of_day(gho_seconds_and_microseconds_t* sec_and_microsec);

#if gho_unix

  #include <sys/time.h>
  
  void gho_get_time_of_day(gho_seconds_and_microseconds_t* sec_and_microsec) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec_and_microsec->seconds = (unsigned long long int)tv.tv_sec;
    sec_and_microsec->microseconds = (unsigned long long int)tv.tv_usec;
  }

#elif gho_windows

  // http://stackoverflow.com/questions/10905892/equivalent-of-gettimeday-for-windows
  
  #include <Windows.h>
  
  void gho_get_time_of_day(gho_seconds_and_microseconds_t* sec_and_microsec) {
    static const unsigned long long int uint64_t epoch = 116444736000000000ULL;
    
    SYSTEMTIME system_time;
    FILETIME file_time;
    unsigned long long int time;
    
    GetSystemTime( &system_time );
    SystemTimeToFileTime(&system_time, &file_time);
    
    time = (unsigned long long int)file_time.dwLowDateTime;
    time += (unsigned long long int)file_time.dwHighDateTime << 32;
    
    sec_and_microsec->seconds = (time - epoch) / 10000000ULL;
    sec_and_microsec->microseconds =
      (unsigned long long int)system_time.wMilliseconds * 1000ULL;
  }

#else

  #include <stdio.h>
  #include <stdlib.h>
  
  #include "../unused.h"
  
  void gho_get_time_of_day(gho_seconds_and_microseconds_t* sec_and_microsec) {
    gho_unused(sec_and_microsec);
    fprintf(stderr, "ERROR: gho_get_time_of_day is not implemented on "
                            "your system\n");
    exit(1);
  }

#endif


// gho_now_microseconds

/**
 * \brief Time since 1970 in milliseconds
 * \return time since 1970 in milliseconds
 * @ingroup gho_system
 */
long double gho_now_milliseconds() {
  gho_seconds_and_microseconds_t sec_and_microsec;
  gho_get_time_of_day(&sec_and_microsec);
  return ((long double)sec_and_microsec.seconds * 1000.0 +
          (long double)sec_and_microsec.microseconds / 1000.0);
}
