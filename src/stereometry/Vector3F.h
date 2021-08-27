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

#ifndef _GEOMETRY_STEREOMETRY_VECTOR3_F_H_
#define _GEOMETRY_STEREOMETRY_VECTOR3_F_H_

#include "../constants.h"

#include <math.h>

namespace geometry
{
    namespace stereometry
    {
        typedef class Vector3F
        {
        public:
            static const float DEFAULT_VALUE;

            float x;
            float y;
            float z;

            inline Vector3F();
            inline Vector3F(const float x, const float y, const float z);

            virtual ~Vector3F();

            inline bool isZero() const;

            inline void setToZero();
            inline void setValues(const float x, const float y, const float z);

            inline float scalar(const float x, const float y, const float z) const;
            inline float scalar(const Vector3F & vector) const;

            inline float module() const;

            inline Vector3F operator+(const Vector3F & vector) const;
            inline Vector3F operator-(const Vector3F & vector) const;
            inline Vector3F operator*(const float value) const;
            inline Vector3F operator/(const float value) const;

            inline Vector3F & operator+=(const Vector3F & vector);
            inline Vector3F & operator-=(const Vector3F & vector);
            inline Vector3F & operator*=(const float value);
            inline Vector3F & operator/=(const float value);

            inline float operator*(const Vector3F & vector) const;
        } Vector3FFloat, Vector3FFloat32;

        Vector3F::Vector3F()
        {
            this->x = Vector3F::DEFAULT_VALUE;
            this->y = Vector3F::DEFAULT_VALUE;
            this->z = Vector3F::DEFAULT_VALUE;
        }

        Vector3F::Vector3F(const float x, const float y, const float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        bool Vector3F::isZero() const
        {
            return this->x * this->x + this->y * this->y + this->z * this->z <= POSITIVE_SQUARE_EPSYLON_FLOAT;
        }

        void Vector3F::setToZero()
        {
            this->x = Vector3F::DEFAULT_VALUE;
            this->y = Vector3F::DEFAULT_VALUE;
            this->z = Vector3F::DEFAULT_VALUE;
        }

        void Vector3F::setValues(const float x, const float y, const float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        float Vector3F::scalar(const float x, const float y, const float z) const
        {
            return this->x * x + this->y * y + this->z * z;
        }

        float Vector3F::scalar(const Vector3F & vector) const
        {
            return this->x * vector.x + this->y * vector.y + this->z * vector.z;
        }

        float Vector3F::module() const
        {
            return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
        }

        Vector3F Vector3F::operator+(const Vector3F & vector) const
        {
            return Vector3F(this->x + vector.x, this->y + vector.y, this->z + vector.z);
        }

        Vector3F Vector3F::operator-(const Vector3F & vector) const
        {
            return Vector3F(this->x - vector.x, this->y - vector.y, this->z - vector.z);
        }

        Vector3F Vector3F::operator*(const float value) const
        {
            return Vector3F(this->x * value, this->y * value, this->z * value);
        }

        Vector3F Vector3F::operator/(const float value) const
        {
            return Vector3F(this->x / value, this->y / value, this->z / value);
        }

        Vector3F & Vector3F::operator+=(const Vector3F & vector)
        {
            this->x += vector.x;
            this->y += vector.y;
            this->z += vector.z;

            return (*this);
        }

        Vector3F & Vector3F::operator-=(const Vector3F & vector)
        {
            this->x -= vector.x;
            this->y -= vector.y;
            this->z -= vector.z;

            return (*this);
        }

        Vector3F & Vector3F::operator*=(const float value)
        {
            this->x *= value;
            this->y *= value;
            this->z *= value;

            return (*this);
        }

        Vector3F & Vector3F::operator/=(const float value)
        {
            this->x /= value;
            this->y /= value;
            this->z /= value;

            return (*this);
        }

        float Vector3F::operator*(const Vector3F & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        inline Vector3F operator*(const float value, const Vector3F & vector)
        {
            return Vector3F(vector.x * value, vector.y * value, vector.z * value);
        }

        inline Vector3F operator*(const double value, const Vector3F & vector)
        {
            return Vector3F((float)(vector.x * value), (float)(vector.y * value), (float)(vector.z * value));
        }
    } /* namespace stereometry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_VECTOR3_F_H_ */
