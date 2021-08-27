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

#include "Triangle3.h"
#include "Triangle3F.h"

namespace geometry
{
    namespace stereometry
    {
        Triangle3::~Triangle3()
        {
        }

        Triangle3F Triangle3::toFloat() const
        {
            Triangle3F result;

            result.A.x = (float)this->A.x;
            result.A.y = (float)this->A.y;
            result.A.z = (float)this->A.z;

            result.B.x = (float)this->B.x;
            result.B.y = (float)this->B.y;
            result.B.z = (float)this->B.z;

            result.C.x = (float)this->C.x;
            result.C.y = (float)this->C.y;
            result.C.z = (float)this->C.z;

            return result;
        }
    }
}
