/*
 * Copyright 2020-2021 Andrey Pokidov <andrey.pokidov@gmail.com>Ray2F
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

#ifndef _GEOMETRY_PLANIMETRY_RAY2_F_H_
#define _GEOMETRY_PLANIMETRY_RAY2_F_H_

#include "Vector2F.h"

namespace geometry
{
    namespace planimetry
    {
        class Ray2F
        {
        public:
            inline Ray2F();
            inline Ray2F(const Vector2F& basicPoint, const Vector2F& direction);
            virtual ~Ray2F();

            inline bool isValid() const;

            inline const Vector2F& basic() const;
            inline const Vector2F& direction() const;

            Vector2F pointAt(const float position) const;

        private:
            Vector2F linePoint;
            Vector2F lineDirection;
            bool valid;
        };

        Ray2F::Ray2F()
        {
            this->valid = false;
        }

        Ray2F::Ray2F(const Vector2F& basicPoint, const Vector2F& direction)
            : linePoint(basicPoint)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        bool Ray2F::isValid() const
        {
            return this->valid;
        }

        const Vector2F& Ray2F::basic() const
        {
            return this->linePoint;
        }

        const Vector2F& Ray2F::direction() const
        {
            return this->lineDirection;
        }

        Vector2F Ray2F::pointAt(const float position) const
        {
            return Vector2F(
                linePoint.x + lineDirection.x * position,
                linePoint.y + lineDirection.y * position
            );
        }
    }
}

#endif
