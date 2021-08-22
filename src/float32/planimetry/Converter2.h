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

#ifndef _GEOMETRY_FLOAT32_PLANIMETRY_TRANSITION_H_
#define _GEOMETRY_FLOAT32_PLANIMETRY_TRANSITION_H_

#include "../Angle.h"
#include "Matrix2x2.h"
#include "Vector2.h"

namespace geometry
{
    namespace float32
    {
        namespace planimetry
        {
            class Converter2
            {
            public:
                Matrix2x2 warp;
                Vector2 shift;


                inline Converter2();
                virtual ~Converter2();

                inline void loadIdentity();

                void loadTransformation(const Angle & turn, const Vector2 & shift);

                inline Vector2 convert(const Vector2 & vector) const;
            };

            Converter2::Converter2()
            {
            }

            void Converter2::loadIdentity()
            {
                this->warp.loadIdentity();
                this->shift.setToZero();
            }

            Vector2 Converter2::convert(const Vector2 & vector) const
            {
                return Vector2(
                        this->warp.r1c1 * vector.x + this->warp.r1c2 * vector.y + this->shift.x,
                        this->warp.r2c1 * vector.x + this->warp.r2c2 * vector.y + this->shift.y
                );
            }
        } /* namespace planimetry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_PLANIMETRY_TRANSITION_H_ */
