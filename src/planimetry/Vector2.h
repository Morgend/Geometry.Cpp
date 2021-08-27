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

#ifndef _GEOMETRY_PLANIMETRY_VECTOR2_H_
#define _GEOMETRY_PLANIMETRY_VECTOR2_H_

#include <math.h>

#include "../constants.h"

namespace geometry
{
    namespace planimetry
    {
        class Vector2F;

        typedef class Vector2
        {
        public:
            static const double DEFAULT_VALUE;

            double x;
            double y;

            inline Vector2();
            inline Vector2(const double x, const double y);

            virtual ~Vector2();

            inline void setToZero();

            inline void setValues(const double x, const double y);

            inline double scalar(const double x, const double y) const;
            inline double scalar(const Vector2 & vector) const;

            inline double module() const;

            Vector2F toFloat() const;

            inline Vector2 operator+(const Vector2 & vector) const;
            inline Vector2 operator-(const Vector2 & vector) const;
            inline Vector2 operator*(const double value) const;
            inline Vector2 operator/(const double value) const;

            inline Vector2 & operator+=(const Vector2 & vector);
            inline Vector2 & operator-=(const Vector2 & vector);
            inline Vector2 & operator*=(const double value);
            inline Vector2 & operator/=(const double value);

            inline double operator*(const Vector2 & vector) const;
        } Vector2Double;

        Vector2::Vector2()
        {
            this->x = DEFAULT_VALUE;
            this->y = DEFAULT_VALUE;
        }

        Vector2::Vector2(const double x, const double y)
        {
            this->x = x;
            this->y = y;
        }

        void Vector2::setToZero()
        {
            this->x = DEFAULT_VALUE;
            this->y = DEFAULT_VALUE;
        }

        void Vector2::setValues(const double x, const double y)
        {
            this->x = x;
            this->y = y;
        }

        double Vector2::scalar(const double x, const double y) const
        {
            return this->x * x + this->y * y;
        }

        double Vector2::scalar(const Vector2 & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        double Vector2::module() const
        {
            return sqrt(this->x * this->x + this->y * this->y);
        }

        Vector2 Vector2::operator+(const Vector2 & vector) const
        {
            return Vector2(this->x + vector.x, this->y + vector.y);
        }

        Vector2 Vector2::operator-(const Vector2 & vector) const
        {
            return Vector2(this->x - vector.x, this->y - vector.y);
        }

        Vector2 Vector2::operator*(const double value) const
        {
            return Vector2(this->x * value, this->y * value);
        }

        Vector2 Vector2::operator/(const double value) const
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

        Vector2 & Vector2::operator*=(const double value)
        {
            this->x *= value;
            this->y *= value;

            return (*this);
        }

        Vector2 & Vector2::operator/=(const double value)
        {
            this->x /= value;
            this->y /= value;

            return (*this);
        }

        double Vector2::operator*(const Vector2 & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        inline Vector2 operator*(const double value, const Vector2 & vector)
        {
            return Vector2(vector.x * value, vector.y * value);
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_PLANIMETRY_VECTOR2_H_ */
