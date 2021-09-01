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

#include "Quaternion.h"

#include "constants.h"

namespace geometry
{
    template<> const double BasicQuaternionTemplate<double>::ZERO = 0.0;
    template<> const double BasicQuaternionTemplate<double>::UNIT = 1.0;
    template<> const double BasicQuaternionTemplate<double>::EPSYLON = POSITIVE_EPSYLON_DOUBLE;
    template<> const double BasicQuaternionTemplate<double>::NEGATIVE_EPSYLON = NEGATIVE_EPSYLON_DOUBLE;
    template<> const double BasicQuaternionTemplate<double>::SQUARE_EPSYLON = POSITIVE_SQUARE_EPSYLON_DOUBLE;

    Quaternion::~Quaternion()
    {
    }

    template<> const float BasicQuaternionTemplate<float>::ZERO = 0.0f;
    template<> const float BasicQuaternionTemplate<float>::UNIT = 1.0f;
    template<> const float BasicQuaternionTemplate<float>::EPSYLON = POSITIVE_EPSYLON_FLOAT;
    template<> const float BasicQuaternionTemplate<float>::NEGATIVE_EPSYLON = NEGATIVE_EPSYLON_FLOAT;
    template<> const float BasicQuaternionTemplate<float>::SQUARE_EPSYLON = POSITIVE_SQUARE_EPSYLON_FLOAT;

    QuaternionF::~QuaternionF()
    {
    }
}
