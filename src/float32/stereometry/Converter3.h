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
#include "Matrix3x3.h"
#include "Vector3.h"

namespace geometry
{
    namespace float32
    {
        namespace stereometry
        {
            class Converter3
            {
            public:
                Matrix3x3 warp;
                Vector3 shift;


                inline Converter3();
                virtual ~Converter3();

                inline void loadIdentity();

                inline Vector3 convert(const Vector3 & vector) const;
            };

            Converter3::Converter3()
            {
            }

            void Converter3::loadIdentity()
            {
                this->warp.loadIdentity();
                this->shift.setToZero();
            }

            Vector3 Converter3::convert(const Vector3 & vector) const
            {
                return Vector3(
                        this->warp.a1_1 * vector.x + this->warp.a1_2 * vector.y + this->warp.a1_3 * vector.z + this->shift.x,
                        this->warp.a2_1 * vector.x + this->warp.a2_2 * vector.y + this->warp.a2_3 * vector.z + this->shift.y,
                        this->warp.a3_1 * vector.x + this->warp.a3_2 * vector.y + this->warp.a3_3 * vector.z + this->shift.z
                );
            }
        } /* namespace stereometry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_PLANIMETRY_TRANSITION_H_ */
