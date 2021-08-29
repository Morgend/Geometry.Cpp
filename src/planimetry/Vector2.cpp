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

#include "Vector2.h"
#include "Vector2F.h"

namespace geometry
{
    namespace planimetry
    {
        const double Vector2::DEFAULT_VALUE = 0.0;

        Vector2::Vector2(const Vector2F & vector)
        {
            this->x = vector.x;
            this->y = vector.y;
        }

        Vector2::~Vector2()
        {
        }

        Vector2F Vector2::toFloat() const
        {
            return Vector2F((float)this->x, (float)this->y);
        }
    } /* namespace planimetry */
} /* namespace geometry */
