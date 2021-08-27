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

#include "../AngleF.h"
#include "Matrix3x3F.h"
#include "Vector3F.h"

namespace geometry
{
    namespace stereometry
    {
        class Converter3F
        {
        public:
            Matrix3x3F warp;
            Vector3F shift;


            inline Converter3F();
            virtual ~Converter3F();

            inline void loadIdentity();

            inline Vector3F convert(const Vector3F & vector) const;
        };

        Converter3F::Converter3F()
        {
        }

        void Converter3F::loadIdentity()
        {
            this->warp.loadIdentity();
            this->shift.setToZero();
        }

        Vector3F Converter3F::convert(const Vector3F & vector) const
        {
            return Vector3F(
                    this->warp.r1c1 * vector.x + this->warp.r1c2 * vector.y + this->warp.r1c3 * vector.z + this->shift.x,
                    this->warp.r2c1 * vector.x + this->warp.r2c2 * vector.y + this->warp.r2c3 * vector.z + this->shift.y,
                    this->warp.r3c1 * vector.x + this->warp.r3c2 * vector.y + this->warp.r3c3 * vector.z + this->shift.z
            );
        }
    } /* namespace stereometry */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_PLANIMETRY_TRANSITION_H_ */
