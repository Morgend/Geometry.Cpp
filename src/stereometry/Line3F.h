/*
 * Copyright 2020-2021 Andrey Pokidov <andrey.pokidov@gmail.com>Line3F
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

#ifndef _GEOMETRY_STEREOMETRY_LINE3_F_H_
#define _GEOMETRY_STEREOMETRY_LINE3_F_H_

#include "Vector3F.h"

namespace geometry
{
    namespace stereometry
    {
        class Line3F
        {
        public:
            inline Line3F();
            inline Line3F(const Vector3F& basicPoint, const Vector3F& direction);
            virtual ~Line3F();

            inline bool isValid() const;

            inline const Vector3F& basic() const;
            inline const Vector3F& direction() const;

            Vector3F pointAt(const float position) const;

        private:
            Vector3F linePoint;
            Vector3F lineDirection;
            bool valid;
        };

        Line3F::Line3F()
        {
            this->valid = false;
        }

        Line3F::Line3F(const Vector3F& basicPoint, const Vector3F& direction)
            : linePoint(basicPoint)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        bool Line3F::isValid() const
        {
            return this->valid;
        }

        const Vector3F& Line3F::basic() const
        {
            return this->linePoint;
        }

        const Vector3F& Line3F::direction() const
        {
            return this->lineDirection;
        }

        Vector3F Line3F::pointAt(const float position) const
        {
            return Vector3F(
                linePoint.x + lineDirection.x * position,
                linePoint.y + lineDirection.y * position,
                linePoint.z + lineDirection.z * position
            );
        }
    }
}

#endif
