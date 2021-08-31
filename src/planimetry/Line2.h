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

#ifndef _GEOMETRY_PLANIMETRY_LINE2_H_
#define _GEOMETRY_PLANIMETRY_LINE2_H_

#include "Vector2.h"

namespace geometry
{
    namespace planimetry
    {
        class Line2F;

        class Line2
        {
        public:
            inline Line2();
            inline Line2(const Vector2& basicPoint, const Vector2& direction);
            inline Line2(const double basicX, const double basicY, const double directionX, const double directionY);
            virtual ~Line2();

            inline bool isValid() const;

            inline const Vector2& basic() const;
            inline const Vector2& direction() const;

            inline void setValuesOf(const Line2& line);
            inline void setValues(const Vector2& basicPoint, const Vector2& direction);
            inline void setValues(const double basicX, const double basicY, const double directionX, const double directionY);

            Vector2 pointAt(const float position) const;

        private:
            Vector2 linePoint;
            Vector2 lineDirection;
            bool valid;
        };

        Line2::Line2()
        {
            this->valid = false;
        }

        Line2::Line2(const Vector2& basicPoint, const Vector2& direction)
            : linePoint(basicPoint)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        Line2::Line2(const double basicX, const double basicY, const double directionX, const double directionY)
            : linePoint(basicX, basicY)
            , lineDirection(directionX, directionY)
        {
            this->valid = this->lineDirection.normalize();
        }

        bool Line2::isValid() const
        {
            return this->valid;
        }

        const Vector2& Line2::basic() const
        {
            return this->linePoint;
        }

        const Vector2& Line2::direction() const
        {
            return this->lineDirection;
        }

        Vector2 Line2::pointAt(const float position) const
        {
            return Vector2(
                linePoint.x + lineDirection.x * position,
                linePoint.y + lineDirection.y * position
            );
        }
    }
}

#endif
