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

#ifndef _GEOMETRY_STEREOMETRY_TRIANGLE3_F_H_
#define _GEOMETRY_STEREOMETRY_TRIANGLE3_F_H_

#include "Vector3F.h"

namespace geometry
{
    namespace stereometry
    {
        class Triangle3;

        class Triangle3F
        {
        public:
            Vector3F A;
            Vector3F B;
            Vector3F C;

            inline Triangle3F();
            inline Triangle3F(const Vector3F& A, const Vector3F& B, const Vector3F& C);
            virtual ~Triangle3F();

            inline Vector3F vectorAB() const;
            inline Vector3F vectorBA() const;
            inline Vector3F vectorBC() const;
            inline Vector3F vectorCB() const;
            inline Vector3F vectorAC() const;
            inline Vector3F vectorCA() const;

            inline float square() const;

            inline Vector3F getMedianCentre() const;

            Triangle3 toDouble() const;
        };

        Triangle3F::Triangle3F()
        {
        }

        Triangle3F::Triangle3F(const Vector3F& A, const Vector3F& B, const Vector3F& C)
        {
            this->A = A;
            this->B = B;
            this->C = C;
        }

        Vector3F Triangle3F::vectorAB() const
        {
            return B - A;
        }

        Vector3F Triangle3F::vectorBA() const
        {
            return A - B;
        }

        Vector3F Triangle3F::vectorBC() const
        {
            return C - B;
        }

        Vector3F Triangle3F::vectorCB() const
        {
            return B - C;
        }

        Vector3F Triangle3F::vectorAC() const
        {
            return C - A;
        }

        Vector3F Triangle3F::vectorCA() const
        {
            return A - C;
        }

        float Triangle3F::square() const
        {
            return 0.5f * ((B - A).vectorMultiply(C - A)).module();
        }

        Vector3F Triangle3F::getMedianCentre() const
        {
            return Vector3F((A.x + B.x + C.x) / 3.0f, (A.y + B.y + C.y) / 3.0f, (A.z + B.z + C.z) / 3.0f);
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_TRIANGLE3_F_H_ */
