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

#ifndef _GEOMETRY_FLOAT32_PLANIMETRY_VECTOR2_H_
#define _GEOMETRY_FLOAT32_PLANIMETRY_VECTOR2_H_

#include "../../utilities.h"

namespace geometry
{
    namespace float32
    {
        namespace planimetry
        {
            typedef class Vector2
            {
            public:
                static const float DEFAULT_VALUE;

                float x;
                float y;

                inline Vector2();
                inline Vector2(const float x, const float y);

                virtual ~Vector2();

                inline bool isZero() const;

                inline void setToZero();
                inline void setValues(const float x, const float y);

                inline float scalar(const float x, const float y) const;
                inline float scalar(const Vector2 & vector) const;

                float module() const;

                inline Vector2 operator+(const Vector2 & vector) const;
                inline Vector2 operator-(const Vector2 & vector) const;
                inline Vector2 operator*(const float value) const;
                inline Vector2 operator/(const float value) const;

                inline Vector2 & operator+=(const Vector2 & vector);
                inline Vector2 & operator-=(const Vector2 & vector);
                inline Vector2 & operator*=(const float value);
                inline Vector2 & operator/=(const float value);

                inline float operator*(const Vector2 & vector) const;
            } Vector2Float, Vector2Float32;

            Vector2::Vector2()
            {
                this->x = Vector2::DEFAULT_VALUE;
                this->y = Vector2::DEFAULT_VALUE;
            }

            Vector2::Vector2(const float x, const float y)
            {
                this->x = x;
                this->y = y;
            }

            bool Vector2::isZero() const
            {
                return this->x * this->x + this->y * this->y <= POSITIVE_SQUARE_EPSYLON_FLOAT;
            }

            void Vector2::setToZero()
            {
                this->x = Vector2::DEFAULT_VALUE;
                this->y = Vector2::DEFAULT_VALUE;
            }

            void Vector2::setValues(const float x, const float y)
            {
                this->x = x;
                this->y = y;
            }

            float Vector2::scalar(const float x, const float y) const
            {
                return this->x * x + this->y * y;
            }

            float Vector2::scalar(const Vector2 & vector) const
            {
                return this->x * vector.x + this->y * vector.y;
            }

            Vector2 Vector2::operator+(const Vector2 & vector) const
            {
                return Vector2(this->x + vector.x, this->y + vector.y);
            }

            Vector2 Vector2::operator-(const Vector2 & vector) const
            {
                return Vector2(this->x - vector.x, this->y - vector.y);
            }

            Vector2 Vector2::operator*(const float value) const
            {
                return Vector2(this->x * value, this->y * value);
            }

            Vector2 Vector2::operator/(const float value) const
            {
                return Vector2(this->x / value, this->y / value);
            }

            Vector2 & Vector2::operator+=(const Vector2 & vector)
            {
                this->x += vector.x;
                this->y += vector.y;

                return (*this);
            }

            Vector2 & Vector2::operator-=(const Vector2 & vector)
            {
                this->x -= vector.x;
                this->y -= vector.y;

                return (*this);
            }

            Vector2 & Vector2::operator*=(const float value)
            {
                this->x *= value;
                this->y *= value;

                return (*this);
            }

            Vector2 & Vector2::operator/=(const float value)
            {
                this->x /= value;
                this->y /= value;

                return (*this);
            }

            float Vector2::operator*(const Vector2 & vector) const
            {
                return this->x * vector.x + this->y * vector.y;
            }

            inline Vector2 operator*(const float value, const Vector2 & vector)
            {
                return Vector2(vector.x * value, vector.y * value);
            }

            inline Vector2 operator*(const double value, const Vector2 & vector)
            {
                return Vector2((float)(vector.x * value), (float)(vector.y * value));
            }
        } /* namespace planimetry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_PLANIMETRY_VECTOR2_H_ */
