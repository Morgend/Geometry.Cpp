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

#include "Converter2F.h"

#include <math.h>

namespace geometry
{
    namespace planimetry
    {
        Converter2F::~Converter2F()
        {
        }

        void Converter2F::buildConvesion(const AngleF & turn, const Vector2F & shift)
        {
            float cos = cosf(turn.radians());
            float sin = sinf(turn.radians());

            this->warp.r1c1 = cos;
            this->warp.r1c2 = -sin;
            this->warp.r2c1 = sin;
            this->warp.r2c2 = cos;

            this->shift = shift;
        }
    } /* namespace planimetry */
} /* namespace geometry */
