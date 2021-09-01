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
        // =================== Vector2 Template header =================== //

        template<typename FloatType> class BasicVector2Template
        {
        public:
            static const FloatType ZERO;
            static const FloatType UNIT;
            static const FloatType EPSYLON;
            static const FloatType NEGATIVE_EPSYLON;
            static const FloatType SQUARE_EPSYLON;

            FloatType x, y;

            virtual ~BasicVector2Template()
            {
            }

            inline void setToZero();

            inline bool isZero() const;
            inline bool isUnit() const;

            inline void setValues(const FloatType x, const FloatType y);
            inline void setValuesOf(const BasicVector2Template<FloatType> & vector);

            inline FloatType scalar(const FloatType x, const FloatType y) const;
            inline FloatType scalar(const BasicVector2Template<FloatType> & vector) const;

            inline FloatType operator*(const BasicVector2Template<FloatType> & vector) const;
        };

        // ==================== Vector2<double> header =================== //

        class Vector2F;

        class Vector2 : public BasicVector2Template<double>
        {
        public:

            inline Vector2();
            inline Vector2(const Vector2F & vector);
            inline Vector2(const double x, const double y);

            virtual ~Vector2();

            inline double module() const;

            inline bool normalize();

            inline void setValuesOf(const Vector2F & vector);

            inline Vector2F toFloat() const;

            inline Vector2 operator+(const Vector2 & vector) const;
            inline Vector2 operator-(const Vector2 & vector) const;
            inline Vector2 operator*(const double value) const;
            inline Vector2 operator/(const double value) const;

            inline Vector2 & operator+=(const Vector2 & vector);
            inline Vector2 & operator-=(const Vector2 & vector);
            inline Vector2 & operator*=(const double value);
            inline Vector2 & operator/=(const double value);
        };

        // ==================== Vector2<float> header ==================== //

        class Vector2F : public BasicVector2Template<float>
        {
        public:
            inline Vector2F();
            inline Vector2F(const Vector2 & vector);
            inline Vector2F(const float x, const float y);

            virtual ~Vector2F();

            inline float module() const;

            inline bool normalize();

            inline void setValuesOf(const Vector2 & vector);

            inline Vector2 toDouble() const;

            inline Vector2F operator+(const Vector2F & vector) const;
            inline Vector2F operator-(const Vector2F & vector) const;
            inline Vector2F operator*(const float value) const;
            inline Vector2F operator/(const float value) const;

            inline Vector2F & operator+=(const Vector2F & vector);
            inline Vector2F & operator-=(const Vector2F & vector);
            inline Vector2F & operator*=(const float value);
            inline Vector2F & operator/=(const float value);
        };

        // =============== Vector2 Template inline methods =============== //

        template<typename FloatType> void BasicVector2Template<FloatType>::setToZero()
        {
            this->x = ZERO;
            this->y = ZERO;
        }

        template<typename FloatType> bool BasicVector2Template<FloatType>::isZero() const
        {
            return this->x * this->x + this->y * this->y <= SQUARE_EPSYLON;
        }

        template<typename FloatType> bool BasicVector2Template<FloatType>::isUnit() const
        {
            FloatType difference = this->x * this->x + this->y * this->y - UNIT;
            return NEGATIVE_EPSYLON <= difference && difference <= EPSYLON;
        }

        template<typename FloatType> void BasicVector2Template<FloatType>::setValues(const FloatType x, const FloatType y)
        {
            this->x = x;
            this->y = y;
        }

        template<typename FloatType> void BasicVector2Template<FloatType>::setValuesOf(const BasicVector2Template<FloatType> & vector)
        {
            this->x = vector.x;
            this->y = vector.y;
        }

        template<typename FloatType> FloatType BasicVector2Template<FloatType>::scalar(const FloatType x, const FloatType y) const
        {
            return this->x * x + this->y * y;
        }

        template<typename FloatType> FloatType BasicVector2Template<FloatType>::scalar(const BasicVector2Template<FloatType> & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        template<typename FloatType> FloatType BasicVector2Template<FloatType>::operator*(const BasicVector2Template<FloatType> & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        // ================ Vector2<double> inline methods =============== //

        Vector2::Vector2()
        {
            this->x = ZERO;
            this->y = ZERO;
        }

        Vector2::Vector2(const Vector2F & vector)
        {
            this->x = vector.x;
            this->y = vector.y;
        }

        Vector2::Vector2(const double x, const double y)
        {
            this->x = x;
            this->y = y;
        }

        double Vector2::module() const
        {
            return sqrt(this->x * this->x + this->y * this->y);
        }

        bool Vector2::normalize()
        {
            double sqareModule = this->x * this->x + this->y * this->y;

            if (sqareModule <= POSITIVE_SQUARE_EPSYLON_DOUBLE)
            {
                this->setToZero();
                return false;
            }

            double module = sqrt(sqareModule);

            this->x /= module;
            this->y /= module;

            return true;
        }

        void Vector2::setValuesOf(const Vector2F & vector)
        {
            this->x = vector.x;
            this->y = vector.y;
        }

        Vector2F Vector2::toFloat() const
        {
            return Vector2F((float)this->x, (float)this->y);
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

        inline Vector2 operator*(const double value, const Vector2 & vector)
        {
            return Vector2(vector.x * value, vector.y * value);
        }

        // ================ Vector2<float> inline methods ================ //

        Vector2F::Vector2F()
        {
            this->x = ZERO;
            this->y = ZERO;
        }

        Vector2F::Vector2F(const Vector2& vector)
        {
            this->x = (float)vector.x;
            this->y = (float)vector.y;
        }

        Vector2F::Vector2F(const float x, const float y)
        {
            this->x = x;
            this->y = y;
        }

        float Vector2F::module() const
        {
            return sqrtf(this->x * this->x + this->y * this->y);
        }

        bool Vector2F::normalize()
        {
            float sqareModule = this->x * this->x + this->y * this->y;

            if (sqareModule <= POSITIVE_SQUARE_EPSYLON_DOUBLE)
            {
                this->setToZero();
                return false;
            }

            float module = sqrtf(sqareModule);

            this->x /= module;
            this->y /= module;

            return true;
        }

        void Vector2F::setValuesOf(const Vector2 & vector)
        {
            this->x = (float)vector.x;
            this->y = (float)vector.y;
        }

        Vector2 Vector2F::toDouble() const
        {
            return Vector2(this->x, this->y);
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

#endif /* _GEOMETRY_PLANIMETRY_VECTOR2_H_ */
