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

#ifndef _GEOMETRY_STEREOMETRY_VECTOR3_H_
#define _GEOMETRY_STEREOMETRY_VECTOR3_H_

#include "../constants.h"

#include <math.h>

namespace geometry
{
    namespace stereometry
    {
        typedef class Vector3
        {
        public:
            static const double DEFAULT_VALUE;

            double x;
            double y;
            double z;

            inline Vector3();
            inline Vector3(const double x, const double y, const double z);

            virtual ~Vector3();

            inline bool isZero() const;

            inline void setToZero();
            inline void setValues(const double x, const double y, const double z);

            inline double scalar(const double x, const double y, const double z) const;
            inline double scalar(const Vector3 & vector) const;

            inline double module() const;

            inline Vector3 vectorMultiply(const Vector3& vector) const;

            inline Vector3 operator+(const Vector3 & vector) const;
            inline Vector3 operator-(const Vector3 & vector) const;
            inline Vector3 operator*(const double value) const;
            inline Vector3 operator/(const double value) const;

            inline Vector3 & operator+=(const Vector3 & vector);
            inline Vector3 & operator-=(const Vector3 & vector);
            inline Vector3 & operator*=(const double value);
            inline Vector3 & operator*=(const Vector3 & vector);
            inline Vector3 & operator/=(const double value);

            inline double operator*(const Vector3 & vector) const;
        } Vector3double, Vector3double32;

        Vector3::Vector3()
        {
            this->x = Vector3::DEFAULT_VALUE;
            this->y = Vector3::DEFAULT_VALUE;
            this->z = Vector3::DEFAULT_VALUE;
        }

        Vector3::Vector3(const double x, const double y, const double z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        bool Vector3::isZero() const
        {
            return this->x * this->x + this->y * this->y + this->z * this->z <= POSITIVE_SQUARE_EPSYLON_DOUBLE;
        }

        void Vector3::setToZero()
        {
            this->x = Vector3::DEFAULT_VALUE;
            this->y = Vector3::DEFAULT_VALUE;
            this->z = Vector3::DEFAULT_VALUE;
        }

        void Vector3::setValues(const double x, const double y, const double z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        double Vector3::scalar(const double x, const double y, const double z) const
        {
            return this->x * x + this->y * y + this->z * z;
        }

        double Vector3::scalar(const Vector3 & vector) const
        {
            return this->x * vector.x + this->y * vector.y + this->z * vector.z;
        }

        double Vector3::module() const
        {
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
        }

        inline Vector3 Vector3::vectorMultiply(const Vector3 & vector) const
        {
            return Vector3(
                this->y * vector.z - this->z * vector.y,
                this->x * vector.z - this->z * vector.x,
                this->x * vector.y - this->y * vector.x
            );
        }

        Vector3 Vector3::operator+(const Vector3 & vector) const
        {
            return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
        }

        Vector3 Vector3::operator-(const Vector3 & vector) const
        {
            return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
        }

        Vector3 Vector3::operator*(const double value) const
        {
            return Vector3(this->x * value, this->y * value, this->z * value);
        }

        Vector3 Vector3::operator/(const double value) const
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

        Vector3 & Vector3::operator*=(const double value)
        {
            this->x *= value;
            this->y *= value;
            this->z *= value;

            return (*this);
        }

        Vector3 & Vector3::operator*=(const Vector3 & vector)
        {
            double x = this->y * vector.z - this->z * vector.y;
            double y = this->x * vector.z - this->z * vector.x;
            double z = this->x * vector.y - this->y * vector.x;

            this->x = x;
            this->y = y;
            this->z = z;

            return (*this);
        }

        Vector3 & Vector3::operator/=(const double value)
        {
            this->x /= value;
            this->y /= value;
            this->z /= value;

            return (*this);
        }

        double Vector3::operator*(const Vector3 & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        inline Vector3 operator*(const double value, const Vector3 & vector)
        {
            return Vector3(vector.x * value, vector.y * value, vector.z * value);
        }
    } /* namespace stereometry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_VECTOR3_H_ */
