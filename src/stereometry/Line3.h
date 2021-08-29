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

#ifndef _GEOMETRY_STEREOMETRY_LINE3_H_
#define _GEOMETRY_STEREOMETRY_LINE3_H_

#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        class Line3
        {
        public:
            inline Line3();
            inline Line3(const Vector3& basicPoint, const Vector3& direction);
            virtual ~Line3();

            inline bool isValid() const;

            inline const Vector3& basic() const;
            inline const Vector3& direction() const;

            Vector3 pointAt(const double position) const;

        private:
            Vector3 linePoint;
            Vector3 lineDirection;
            bool valid;
        };

        Line3::Line3()
        {
            this->valid = false;
        }

        Line3::Line3(const Vector3& basicPoint, const Vector3& direction)
            : linePoint(basicPoint)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        bool Line3::isValid() const
        {
            return this->valid;
        }

        const Vector3& Line3::basic() const
        {
            return this->linePoint;
        }

        const Vector3& Line3::direction() const
        {
            return this->lineDirection;
        }

        Vector3 Line3::pointAt(const double position) const
        {
            return Vector3(
                linePoint.x + lineDirection.x * position,
                linePoint.y + lineDirection.y * position,
                linePoint.z + lineDirection.z * position
            );
        }
    }
}

#endif
