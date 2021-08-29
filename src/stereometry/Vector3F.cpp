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

#include "Vector3F.h"
#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        const float Vector3F::DEFAULT_VALUE = 0.0f;

        Vector3F::Vector3F(const Vector3 & vector)
        {
            this->x = (float)vector.x;
            this->y = (float)vector.y;
            this->z = (float)vector.z;
        }

        Vector3F::~Vector3F()
        {
        }

        Vector3 Vector3F::toDouble() const
        {
            return Vector3(this->x, this->y, this->z);
        }
    } /* namespace stereometry */
} /* namespace geometry */
