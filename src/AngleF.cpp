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

#include "AngleF.h"
//#include "Angle.h"

namespace geometry
{
    const float AngleF::DEFAULT_VALUE = 0.0;
    const float AngleF::DEGREES_IN_RADIAN  = 57.295779513f;
    const float AngleF::GRADIANS_IN_RADIAN = 63.661977237f;
    const float AngleF::DEGREES_IN_GRADIAN = 0.9f;

    AngleF::~AngleF()
    {
    }
} /* namespace geometry */