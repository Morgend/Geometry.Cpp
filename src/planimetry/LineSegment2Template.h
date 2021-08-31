/*
 * Copyright 2020-2021 Andrey Pokidov <andrey.pokidov@gmail.com>Line2
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

#ifndef _GEOMETRY_PLANIMETRY_LINE_SEGMENT2_TMPL_H_
#define _GEOMETRY_PLANIMETRY_LINE_SEGMENT2_TMPL_H_

namespace geometry
{
    namespace planimetry
    {
        template<class Vector2Type, typename FloatType> class LineSegment2Template
        {
        public:
            Vector2Type A;
            Vector2Type B;

            inline LineSegment2Template()
            {
            }

            inline LineSegment2Template(const Vector2& pointA, const Vector2& pointB)
                : A(pointA)
                , B(pointB)
            {
            }

            inline LineSegment2Template(const double xA, const double yA, const double xB, const double yB)
                : A(xA, yA)
                , B(xB, yB)
            {
            }

            inline void setValues(const Vector2Type& pointA, const Vector2Type& pointB)
            {
                this->A = pointA;
                this->B = pointB;
            }

            inline void setValues(const FloatType xA, const FloatType yA, const FloatType xB, const FloatType yB)
            {
                this->A.setValues(xA, yA);
                this->B.setValues(xB, yB);
            }
        };
    }
}

#endif
