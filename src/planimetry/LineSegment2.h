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

#ifndef _GEOMETRY_PLANIMETRY_LINE_SEGMENT2_H_
#define _GEOMETRY_PLANIMETRY_LINE_SEGMENT2_H_

#include "Vector2.h"
#include "LineSegment2Template.h"

namespace geometry
{
    namespace planimetry
    {
        class LineSegment2 : public LineSegment2Template<Vector2, double>
        {
        public:
            Vector2 A;
            Vector2 B;

            inline LineSegment2();
            inline LineSegment2(const Vector2& pointA, const Vector2& pointB);
            inline LineSegment2(const double xA, const double yA, const double xB, const double yB);

            virtual ~LineSegment2();

            inline void setValues(const Vector2& pointA, const Vector2& pointB);
            inline void setValues(const double xA, const double yA, const double xB, const double yB);

            inline Vector2 pointAt(const double position) const;
        };

        LineSegment2::LineSegment2()
        {
        }

        LineSegment2::LineSegment2(const Vector2& pointA, const Vector2& pointB)
            : A(pointA)
            , B(pointB)
        {
        }

        LineSegment2::LineSegment2(const double xA, const double yA, const double xB, const double yB)
            : A(xA, yA)
            , B(xB, yB)
        {
        }

        void LineSegment2::setValues(const Vector2& pointA, const Vector2& pointB)
        {
            this->A = pointA;
            this->B = pointB;
        }

        void LineSegment2::setValues(const double xA, const double yA, const double xB, const double yB)
        {
            this->A.setValues(xA, yA);
            this->B.setValues(xB, yB);
        }

        Vector2 LineSegment2::pointAt(const double position) const
        {
            double positionB = 1.0 - position;
            return Vector2(this->A.x * position + this->B.x * positionB, this->A.y * position + this->B.y * positionB);
        }
    }
}

#endif
