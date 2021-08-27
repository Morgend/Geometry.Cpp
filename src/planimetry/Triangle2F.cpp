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

#include "Triangle2F.h"
#include "Triangle2.h"

namespace geometry
{
    namespace planimetry
    {
        Triangle2F::~Triangle2F()
        {
        }

        Triangle2 Triangle2F::toDouble() const
        {
            Triangle2 result;

            result.A.x = this->A.x;
            result.A.y = this->A.y;

            result.B.x = this->B.x;
            result.B.y = this->B.y;

            result.C.x = this->C.x;
            result.C.y = this->C.y;

            return result;
        }
    }
}
