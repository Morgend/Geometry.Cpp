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

#include <math.h>

#include "Vector2.h"

namespace geometry
{
    namespace float32
    {
        namespace planimetry
        {
            const float Vector2::DEFAULT_VALUE = 0.0f;

            Vector2::~Vector2()
            {
            }

            float Vector2::module() const
            {
                return sqrtf(this->x * this->x + this->y * this->y);
            }
        } /* namespace planimetry */
    } /* namespace float32 */
} /* namespace geometry */
