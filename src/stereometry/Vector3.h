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
        // =================== Vector3 Template header =================== //

        template<typename FloatType> class BasicVector3Template
        {
        public:
            static const FloatType ZERO;
            static const FloatType UNIT;
            static const FloatType EPSYLON;
            static const FloatType NEGATIVE_EPSYLON;
            static const FloatType SQUARE_EPSYLON;

            FloatType x, y, z;

            virtual ~BasicVector3Template()
            {
            }

            inline void setToZero();

            inline bool isZero() const;
            inline bool isUnit() const;

            inline void setValues(const FloatType x, const FloatType y, const FloatType z);
            inline void setValuesOf(const BasicVector3Template<FloatType> & vector);

            inline FloatType scalar(const FloatType x, const FloatType y, const FloatType z) const;
            inline FloatType scalar(const BasicVector3Template<FloatType> & vector) const;

            inline FloatType triple(const BasicVector3Template<FloatType> & vector2, const BasicVector3Template<FloatType> & vector3) const;
        };

        // ==================== Vector3<double> header =================== //

        class Vector3F;

        class Vector3 : public BasicVector3Template<double>
        {
        public:
            inline Vector3();
            inline Vector3(const Vector3F& vector);
            inline Vector3(const double x, const double y, const double z);

            virtual ~Vector3();

            inline void setValuesOf(const Vector3F& vector);

            inline double module() const;

            inline bool normalize();

            inline Vector3F toFloat() const;

            inline Vector3 vector(const Vector3& vector) const;

            inline Vector3 operator+(const Vector3 & vector) const;
            inline Vector3 operator-(const Vector3 & vector) const;
            inline Vector3 operator*(const double value) const;
            inline Vector3 operator/(const double value) const;

            inline Vector3 & operator+=(const Vector3 & vector);
            inline Vector3 & operator-=(const Vector3 & vector);
            inline Vector3 & operator*=(const double value);
            inline Vector3 & operator*=(const Vector3 & vector);
            inline Vector3 & operator/=(const double value);
        };

        // ==================== Vector3<float> header ==================== //

        class Vector3F : public BasicVector3Template<float>
        {
        public:
            inline Vector3F();
            inline Vector3F(const Vector3 & vector);
            inline Vector3F(const float x, const float y, const float z);

            virtual ~Vector3F();

            inline void setValuesOf(const Vector3 & vector);

            inline float module() const;

            inline bool normalize();

            inline Vector3 toDouble() const;

            inline Vector3F vector(const Vector3F& vector) const;

            inline Vector3F operator+(const Vector3F & vector) const;
            inline Vector3F operator-(const Vector3F & vector) const;
            inline Vector3F operator*(const float value) const;
            inline Vector3F operator/(const float value) const;

            inline Vector3F & operator+=(const Vector3F & vector);
            inline Vector3F & operator-=(const Vector3F & vector);
            inline Vector3F & operator*=(const float value);
            inline Vector3F & operator*=(const Vector3F& vector);
            inline Vector3F & operator/=(const float value);
        };

        // =============== Vector3 Template inline methods =============== //

        template<typename FloatType> void BasicVector3Template<FloatType>::setToZero()
        {
            this->x = ZERO;
            this->y = ZERO;
            this->z = ZERO;
        }

        template<typename FloatType> bool BasicVector3Template<FloatType>::isZero() const
        {
            return this->x * this->x + this->y * this->y + this->z * this->z <= SQUARE_EPSYLON;
        }

        template<typename FloatType> bool BasicVector3Template<FloatType>::isUnit() const
        {
            FloatType difference = this->x * this->x + this->y * this->y + this->z * this->z - UNIT;
            return NEGATIVE_EPSYLON <= difference && difference <= EPSYLON;
        }

        template<typename FloatType> void BasicVector3Template<FloatType>::setValues(const FloatType x, const FloatType y, const FloatType z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        template<typename FloatType> void BasicVector3Template<FloatType>::setValuesOf(const BasicVector3Template<FloatType> & vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        template<typename FloatType> FloatType BasicVector3Template<FloatType>::scalar(const FloatType x, const FloatType y, const FloatType z) const
        {
            return this->x * x + this->y * y + this->z * z;
        }

        template<typename FloatType> FloatType BasicVector3Template<FloatType>::scalar(const BasicVector3Template<FloatType> & vector) const
        {
            return this->x * vector.x + this->y * vector.y + this->z * vector.z;
        }

        template<typename FloatType> FloatType BasicVector3Template<FloatType>::triple(const BasicVector3Template<FloatType> & vector2, const BasicVector3Template<FloatType> & vector3) const
        {
            return this->x * vector2.y *vector3.z
                 + this->y * vector2.z *vector3.x
                 + this->z * vector2.x *vector3.y
                 - this->z * vector2.y *vector3.x
                 - this->y * vector2.x *vector3.z
                 - this->x * vector2.z *vector3.y;
        }

        // ================ Vector3<double> inline methods =============== //

        Vector3::Vector3()
        {
            this->x = ZERO;
            this->y = ZERO;
            this->z = ZERO;
        }

        Vector3::Vector3(const Vector3F& vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        Vector3::Vector3(const double x, const double y, const double z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        void Vector3::setValuesOf(const Vector3F& vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        double Vector3::module() const
        {
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
        }

        bool Vector3::normalize()
        {
            double sqareModule = this->x * this->x + this->y * this->y + this->z * this->z;

            if (sqareModule <= SQUARE_EPSYLON)
            {
                this->setToZero();
                return false;
            }

            double module = sqrt(sqareModule);

            this->x /= module;
            this->y /= module;
            this->z /= module;

            return true;
        }

        Vector3F Vector3::toFloat() const
        {
            return Vector3F((float)this->x, (float)this->y, (float)this->z);
        }

        Vector3 Vector3::vector(const Vector3 & vector) const
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

        inline Vector3 operator*(const double value, const Vector3 & vector)
        {
            return Vector3(vector.x * value, vector.y * value, vector.z * value);
        }

        // ================ Vector3<float> inline methods ================ //

        Vector3F::Vector3F()
        {
            this->x = ZERO;
            this->y = ZERO;
            this->z = ZERO;
        }

        Vector3F::Vector3F(const Vector3 & vector)
        {
            this->x = (float)vector.x;
            this->y = (float)vector.y;
            this->z = (float)vector.z;
        }

        Vector3F::Vector3F(const float x, const float y, const float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        float Vector3F::module() const
        {
            return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
        }

        bool Vector3F::normalize()
        {
            float sqareModule = this->x * this->x + this->y * this->y + this->z * this->z;

            if (sqareModule <= SQUARE_EPSYLON)
            {
                this->setToZero();
                return false;
            }

            float module = sqrtf(sqareModule);

            this->x /= module;
            this->y /= module;
            this->z /= module;

            return true;
        }

        void Vector3F::setValuesOf(const Vector3 & vector)
        {
            this->x = (float)vector.x;
            this->y = (float)vector.y;
            this->z = (float)vector.z;
        }

        Vector3 Vector3F::toDouble() const
        {
            return Vector3(this->x, this->y, this->z);
        }

        Vector3F Vector3F::vector(const Vector3F& vector) const
        {
            return Vector3F(
                this->y * vector.z - this->z * vector.y,
                this->x * vector.z - this->z * vector.x,
                this->x * vector.y - this->y * vector.x
            );
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

        Vector3F & Vector3F::operator*=(const Vector3F& vector)
        {
            float x = this->y * vector.z - this->z * vector.y;
            float y = this->x * vector.z - this->z * vector.x;
            float z = this->x * vector.y - this->y * vector.x;

            this->x = x;
            this->y = y;
            this->z = z;

            return (*this);
        }

        Vector3F & Vector3F::operator/=(const float value)
        {
            this->x /= value;
            this->y /= value;
            this->z /= value;

            return (*this);
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

#endif /* _GEOMETRY_STEREOMETRY_VECTOR3_H_ */
