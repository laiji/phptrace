/**
 * Copyright 2015 Qihoo 360
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PHPTRACE_TIME_H
#define PHPTRACE_TIME_H

#include <stdint.h>
#include <sys/resource.h>
#include <sys/time.h>

static inline uint32_t pt_time_sec()
{
    struct timeval tv;
    gettimeofday(&tv, 0);
    return (uint32_t)tv.tv_sec;
}

static inline uint64_t pt_time_usec()
{
    struct timeval tv;
    gettimeofday(&tv, 0);
    return (uint64_t)tv.tv_sec * 1000000 + (uint64_t)tv.tv_usec;
}

static inline uint64_t pt_cputime_usec()
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return (uint64_t)usage.ru_utime.tv_sec * 1000000 +
           (uint64_t)usage.ru_utime.tv_usec +
           (uint64_t)usage.ru_stime.tv_sec * 1000000 +
           (uint64_t)usage.ru_stime.tv_usec;
}

#endif
