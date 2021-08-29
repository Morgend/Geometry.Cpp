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

#include "Vector3.h"
#include "Vector3F.h"

namespace geometry
{
    namespace stereometry
    {
        const double Vector3::DEFAULT_VALUE = 0.0;

        Vector3::Vector3(const Vector3F& vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        Vector3::~Vector3()
        {
        }

        void Vector3::setValues(const Vector3F& vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        Vector3F Vector3::toFloat() const
        {
            return Vector3F((float)this->x, (float)this->y, (float)this->z);
        }
    } /* namespace stereometry */
} /* namespace geometry */
