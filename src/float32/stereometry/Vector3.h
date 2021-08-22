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

#ifndef _GEOMETRY_FLOAT32_STEREOMETRY_VECTOR2_H_
#define _GEOMETRY_FLOAT32_STEREOMETRY_VECTOR2_H_

#include "../../utilities.h"

#include <math.h>

namespace geometry
{
    namespace float32
    {
        namespace stereometry
        {
            typedef class Vector3
            {
            public:
                static const float DEFAULT_VALUE;

                float x;
                float y;
                float z;

                inline Vector3();
                inline Vector3(const float x, const float y, const float z);

                virtual ~Vector3();

                inline bool isZero() const;

                inline void setToZero();
                inline void setValues(const float x, const float y, const float z);

                inline float scalar(const float x, const float y, const float z) const;
                inline float scalar(const Vector3 & vector) const;

                inline float module() const;

                inline Vector3 operator+(const Vector3 & vector) const;
                inline Vector3 operator-(const Vector3 & vector) const;
                inline Vector3 operator*(const float value) const;
                inline Vector3 operator/(const float value) const;

                inline Vector3 & operator+=(const Vector3 & vector);
                inline Vector3 & operator-=(const Vector3 & vector);
                inline Vector3 & operator*=(const float value);
                inline Vector3 & operator/=(const float value);

                inline float operator*(const Vector3 & vector) const;
            } Vector3Float, Vector3Float32;

            Vector3::Vector3()
            {
                this->x = Vector3::DEFAULT_VALUE;
                this->y = Vector3::DEFAULT_VALUE;
                this->z = Vector3::DEFAULT_VALUE;
            }

            Vector3::Vector3(const float x, const float y, const float z)
            {
                this->x = x;
                this->y = y;
                this->z = z;
            }

            bool Vector3::isZero() const
            {
                return this->x * this->x + this->y * this->y + this->z * this->z <= POSITIVE_SQUARE_EPSYLON_FLOAT;
            }

            void Vector3::setToZero()
            {
                this->x = Vector3::DEFAULT_VALUE;
                this->y = Vector3::DEFAULT_VALUE;
                this->z = Vector3::DEFAULT_VALUE;
            }

            void Vector3::setValues(const float x, const float y, const float z)
            {
                this->x = x;
                this->y = y;
                this->z = z;
            }

            float Vector3::scalar(const float x, const float y, const float z) const
            {
                return this->x * x + this->y * y + this->z * z;
            }

            float Vector3::scalar(const Vector3 & vector) const
            {
                return this->x * vector.x + this->y * vector.y + this->z * vector.z;
            }

            float Vector3::module() const
            {
                return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
            }

            Vector3 Vector3::operator+(const Vector3 & vector) const
            {
                return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
            }

            Vector3 Vector3::operator-(const Vector3 & vector) const
            {
                return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
            }

            Vector3 Vector3::operator*(const float value) const
            {
                return Vector3(this->x * value, this->y * value, this->z * value);
            }

            Vector3 Vector3::operator/(const float value) const
            {
                return Vector3(this->x / value, this->y / value, this->z / value);
            }

            Vector3 & Vector3::operator+=(const Vector3 & vector)
            {
                this->x += vector.x;
                this->y += vector.y;
                this->z += vector.z;

                return (*this);
            }

            Vector3 & Vector3::operator-=(const Vector3 & vector)
            {
                this->x -= vector.x;
                this->y -= vector.y;
                this->z -= vector.z;

                return (*this);
            }

            Vector3 & Vector3::operator*=(const float value)
            {
                this->x *= value;
                this->y *= value;
                this->z *= value;

                return (*this);
            }

            Vector3 & Vector3::operator/=(const float value)
            {
                this->x /= value;
                this->y /= value;
                this->z /= value;

                return (*this);
            }

            float Vector3::operator*(const Vector3 & vector) const
            {
                return this->x * vector.x + this->y * vector.y;
            }

            inline Vector3 operator*(const float value, const Vector3 & vector)
            {
                return Vector3(vector.x * value, vector.y * value, vector.z * value);
            }

            inline Vector3 operator*(const double value, const Vector3 & vector)
            {
                return Vector3((float)(vector.x * value), (float)(vector.y * value), (float)(vector.z * value));
            }
        } /* namespace stereometry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_STEREOMETRY_VECTOR2_H_ */
