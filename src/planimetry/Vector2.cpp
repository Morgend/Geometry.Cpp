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

#include "../constants.h"

namespace geometry
{
    namespace planimetry
    {
        template<> const double BasicVector2Template<double>::ZERO = 0.0;
        template<> const double BasicVector2Template<double>::UNIT = 1.0;
        template<> const double BasicVector2Template<double>::EPSYLON = POSITIVE_EPSYLON_DOUBLE;
        template<> const double BasicVector2Template<double>::NEGATIVE_EPSYLON = NEGATIVE_EPSYLON_DOUBLE;
        template<> const double BasicVector2Template<double>::SQUARE_EPSYLON = POSITIVE_SQUARE_EPSYLON_DOUBLE;

        Vector2::~Vector2()
        {
        }

        template<> const float BasicVector2Template<float>::ZERO = 0.0f;
        template<> const float BasicVector2Template<float>::UNIT = 1.0f;
        template<> const float BasicVector2Template<float>::EPSYLON = POSITIVE_EPSYLON_FLOAT;
        template<> const float BasicVector2Template<float>::NEGATIVE_EPSYLON = NEGATIVE_EPSYLON_FLOAT;
        template<> const float BasicVector2Template<float>::SQUARE_EPSYLON = POSITIVE_SQUARE_EPSYLON_FLOAT;

        Vector2F::~Vector2F()
        {
        }
    } /* namespace planimetry */
} /* namespace geometry */
