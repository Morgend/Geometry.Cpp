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

#ifndef _GEOMETRY_STEREOMETRY_TRIANGLE3_H_
#define _GEOMETRY_STEREOMETRY_TRIANGLE3_H_

#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        class Triangle3F;

        class Triangle3
        {
        public:
            Vector3 A;
            Vector3 B;
            Vector3 C;

            inline Triangle3();
            inline Triangle3(const Vector3& A, const Vector3& B, const Vector3& C);
            virtual ~Triangle3();

            inline Vector3 vectorAB() const;
            inline Vector3 vectorBA() const;
            inline Vector3 vectorBC() const;
            inline Vector3 vectorCB() const;
            inline Vector3 vectorAC() const;
            inline Vector3 vectorCA() const;

            inline double square() const;

            inline Vector3 getMedianCentre() const;

            Triangle3F toFloat() const;
        };

        Triangle3::Triangle3()
        {
        }

        Triangle3::Triangle3(const Vector3& A, const Vector3& B, const Vector3& C)
        {
            this->A = A;
            this->B = B;
            this->C = C;
        }

        Vector3 Triangle3::vectorAB() const
        {
            return B - A;
        }

        Vector3 Triangle3::vectorBA() const
        {
            return A - B;
        }

        Vector3 Triangle3::vectorBC() const
        {
            return C - B;
        }

        Vector3 Triangle3::vectorCB() const
        {
            return B - C;
        }

        Vector3 Triangle3::vectorAC() const
        {
            return C - A;
        }

        Vector3 Triangle3::vectorCA() const
        {
            return A - C;
        }

        double Triangle3::square() const
        {
            return 0.5 * ((B - A).vectorMultiply(C - A)).module();
        }

        Vector3 Triangle3::getMedianCentre() const
        {
            return Vector3((A.x + B.x + C.x) / 3.0, (A.y + B.y + C.y) / 3.0, (A.z + B.z + C.z) / 3.0);
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_TRIANGLE3_H_ */
