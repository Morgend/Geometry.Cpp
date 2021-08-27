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

#ifndef _GEOMETRY_PLANIMETRY_VECTOR2_F_H_
#define _GEOMETRY_PLANIMETRY_VECTOR2_F_H_

#include <math.h>

#include "../constants.h"

namespace geometry
{
    namespace planimetry
    {
        class Vector2;

        typedef class Vector2F
        {
        public:
            static const float DEFAULT_VALUE;

            float x;
            float y;

            inline Vector2F();
            inline Vector2F(const float x, const float y);

            virtual ~Vector2F();

            inline bool isZero() const;

            inline void setToZero();
            inline void setValues(const float x, const float y);

            inline float scalar(const float x, const float y) const;
            inline float scalar(const Vector2F & vector) const;

            inline float module() const;

            Vector2 toDouble() const;

            inline Vector2F operator+(const Vector2F & vector) const;
            inline Vector2F operator-(const Vector2F & vector) const;
            inline Vector2F operator*(const float value) const;
            inline Vector2F operator/(const float value) const;

            inline Vector2F & operator+=(const Vector2F & vector);
            inline Vector2F & operator-=(const Vector2F & vector);
            inline Vector2F & operator*=(const float value);
            inline Vector2F & operator/=(const float value);

            inline float operator*(const Vector2F & vector) const;
        } Vector2FFloat, Vector2FFloat32;

        Vector2F::Vector2F()
        {
            this->x = Vector2F::DEFAULT_VALUE;
            this->y = Vector2F::DEFAULT_VALUE;
        }

        Vector2F::Vector2F(const float x, const float y)
        {
            this->x = x;
            this->y = y;
        }

        bool Vector2F::isZero() const
        {
            return this->x * this->x + this->y * this->y <= POSITIVE_SQUARE_EPSYLON_FLOAT;
        }

        void Vector2F::setToZero()
        {
            this->x = Vector2F::DEFAULT_VALUE;
            this->y = Vector2F::DEFAULT_VALUE;
        }

        void Vector2F::setValues(const float x, const float y)
        {
            this->x = x;
            this->y = y;
        }

        float Vector2F::scalar(const float x, const float y) const
        {
            return this->x * x + this->y * y;
        }

        float Vector2F::scalar(const Vector2F & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        float Vector2F::module() const
        {
            return sqrtf(this->x * this->x + this->y * this->y);
        }

        Vector2F Vector2F::operator+(const Vector2F & vector) const
        {
            return Vector2F(this->x + vector.x, this->y + vector.y);
        }

        Vector2F Vector2F::operator-(const Vector2F & vector) const
        {
            return Vector2F(this->x - vector.x, this->y - vector.y);
        }

        Vector2F Vector2F::operator*(const float value) const
        {
            return Vector2F(this->x * value, this->y * value);
        }

        Vector2F Vector2F::operator/(const float value) const
        {
            return Vector2F(this->x / value, this->y / value);
        }

        Vector2F & Vector2F::operator+=(const Vector2F & vector)
        {
            this->x += vector.x;
            this->y += vector.y;

            return (*this);
        }

        Vector2F & Vector2F::operator-=(const Vector2F & vector)
        {
            this->x -= vector.x;
            this->y -= vector.y;

            return (*this);
        }

        Vector2F & Vector2F::operator*=(const float value)
        {
            this->x *= value;
            this->y *= value;

            return (*this);
        }

        Vector2F & Vector2F::operator/=(const float value)
        {
            this->x /= value;
            this->y /= value;

            return (*this);
        }

        float Vector2F::operator*(const Vector2F & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        inline Vector2F operator*(const float value, const Vector2F & vector)
        {
            return Vector2F(vector.x * value, vector.y * value);
        }

        inline Vector2F operator*(const double value, const Vector2F & vector)
        {
            return Vector2F((float)(vector.x * value), (float)(vector.y * value));
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_PLANIMETRY_VECTOR2_F_H_ */
