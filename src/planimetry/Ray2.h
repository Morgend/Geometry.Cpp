/*
 * Copyright 2020-2021 Andrey Pokidov <andrey.pokidov@gmail.com>Ray2
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

#ifndef _GEOMETRY_PLANIMETRY_RAY2_H_
#define _GEOMETRY_PLANIMETRY_RAY2_H_

#include "Vector2.h"

namespace geometry
{
    namespace planimetry
    {
        class Ray2
        {
        public:
            inline Ray2();
            inline Ray2(const Vector2& basicPoint, const Vector2& direction);
            virtual ~Ray2();

            inline bool isValid() const;

            inline const Vector2& basic() const;
            inline const Vector2& direction() const;

            Vector2 pointAt(const float position) const;

        private:
            Vector2 linePoint;
            Vector2 lineDirection;
            bool valid;
        };

        Ray2::Ray2()
        {
            this->valid = false;
        }

        Ray2::Ray2(const Vector2& basicPoint, const Vector2& direction)
            : linePoint(basicPoint)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        bool Ray2::isValid() const
        {
            return this->valid;
        }

        const Vector2& Ray2::basic() const
        {
            return this->linePoint;
        }

        const Vector2& Ray2::direction() const
        {
            return this->lineDirection;
        }

        Vector2 Ray2::pointAt(const float position) const
        {
            return Vector2(
                linePoint.x + lineDirection.x * position,
                linePoint.y + lineDirection.y * position
            );
        }
    }
}

#endif
