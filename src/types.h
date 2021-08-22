/*
 * Copyright 2020-2021 Andrey Pokidov <andrey.pokidov@gmail.com>
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

#ifndef _GEOMETRY_TYPES_H_
#define _GEOMETRY_TYPES_H_

#include <stdint.h>

namespace geometry
{
    typedef int8_t int8bit;
    typedef uint8_t uint8bit;

    typedef int16_t int16bit;
    typedef uint16_t uint16bit;

    typedef int32_t int32bit;
    typedef uint32_t uint32bit;

    typedef int64_t int64bit;
    typedef uint64_t uint64bit;

    typedef float float32bit;
    typedef double float64bit;

    typedef char char8bit;
    typedef wchar_t char16bit;
    typedef uint32_t char32bit;

    typedef void * pointer;
}

#endif
