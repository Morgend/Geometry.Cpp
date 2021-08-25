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

#ifndef _GEOMETRY_FLOAT32_PLANIMETRY_TRIANGLE_H_
#define _GEOMETRY_FLOAT32_PLANIMETRY_TRIANGLE_H_

#include "Vector2.h"

namespace geometry
{
    namespace float32
    {
        namespace planimetry
        {
            class Triangle2
            {
            public:
                Vector2 A;
                Vector2 B;
                Vector2 C;

                inline Triangle2();
                inline Triangle2(const Vector2& A, const Vector2& B, const Vector2& C);
                virtual ~Triangle2();

                inline Vector2 vectorAB() const;
                inline Vector2 vectorBA() const;
                inline Vector2 vectorBC() const;
                inline Vector2 vectorCB() const;
                inline Vector2 vectorAC() const;
                inline Vector2 vectorCA() const;

                inline float square() const;

                inline Vector2 getMedianCentre() const;
            };

            Triangle2::Triangle2()
            {
            }

            Triangle2::Triangle2(const Vector2& A, const Vector2& B, const Vector2& C)
            {
                this->A = A;
                this->B = B;
                this->C = C;
            }

            Vector2 Triangle2::vectorAB() const
            {
                return B - A;
            }

            Vector2 Triangle2::vectorBA() const
            {
                return A - B;
            }

            Vector2 Triangle2::vectorBC() const
            {
                return C - B;
            }

            Vector2 Triangle2::vectorCB() const
            {
                return B - C;
            }

            Vector2 Triangle2::vectorAC() const
            {
                return C - A;
            }

            Vector2 Triangle2::vectorCA() const
            {
                return A - C;
            }

            float Triangle2::square() const
            {
                float vectorMultiplication = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
                
                return 0.5f * (vectorMultiplication >= 0 ? vectorMultiplication : -vectorMultiplication);
            }

            Vector2 Triangle2::getMedianCentre() const
            {
                return Vector2((A.x + B.x + C.x) / 3.0f, (A.y + B.y + C.y) / 3.0f);
            }
        } /* namespace planimetry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_PLANIMETRY_TRIANGLE_H_ */
