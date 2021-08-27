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

#ifndef _GEOMETRY_PLANIMETRY_TRIANGLE2_F_H_
#define _GEOMETRY_PLANIMETRY_TRIANGLE2_F_H_

#include "Vector2F.h"

namespace geometry
{
    namespace planimetry
    {
        class Triangle2;

        class Triangle2F
        {
        public:
            Vector2F A;
            Vector2F B;
            Vector2F C;

            inline Triangle2F();
            inline Triangle2F(const Vector2F& A, const Vector2F& B, const Vector2F& C);
            virtual ~Triangle2F();

            inline Vector2F vectorAB() const;
            inline Vector2F vectorBA() const;
            inline Vector2F vectorBC() const;
            inline Vector2F vectorCB() const;
            inline Vector2F vectorAC() const;
            inline Vector2F vectorCA() const;

            inline float square() const;

            inline Vector2F getMedianCentre() const;

            Triangle2 toDouble() const;
        };

        Triangle2F::Triangle2F()
        {
        }

        Triangle2F::Triangle2F(const Vector2F& A, const Vector2F& B, const Vector2F& C)
        {
            this->A = A;
            this->B = B;
            this->C = C;
        }

        Vector2F Triangle2F::vectorAB() const
        {
            return B - A;
        }

        Vector2F Triangle2F::vectorBA() const
        {
            return A - B;
        }

        Vector2F Triangle2F::vectorBC() const
        {
            return C - B;
        }

        Vector2F Triangle2F::vectorCB() const
        {
            return B - C;
        }

        Vector2F Triangle2F::vectorAC() const
        {
            return C - A;
        }

        Vector2F Triangle2F::vectorCA() const
        {
            return A - C;
        }

        float Triangle2F::square() const
        {
            float vectorMultiplication = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
                
            return 0.5f * (vectorMultiplication >= 0 ? vectorMultiplication : -vectorMultiplication);
        }

        Vector2F Triangle2F::getMedianCentre() const
        {
            return Vector2F((A.x + B.x + C.x) / 3.0f, (A.y + B.y + C.y) / 3.0f);
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_PLANIMETRY_TRIANGLE2_F_H_ */
