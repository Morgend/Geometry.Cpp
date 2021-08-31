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
    namespace common
    {
        template<typename FloatType, class ContreteVectorType> class Vector2Template
        {
        public:
            static const FloatType DEFAULT_VALUE;

            FloatType x;
            FloatType y;

            virtual ~Vector2Template();

            inline void setToZero();

            inline void setValues(const FloatType x, const FloatType y);

            inline FloatType scalar(const FloatType x, const FloatType y) const;
            inline FloatType scalar(const Vector2Template& vector) const;

            inline ContreteVectorType operator+(const Vector2Template& vector) const;
            inline ContreteVectorType operator-(const Vector2Template& vector) const;
            inline ContreteVectorType operator*(const FloatType value) const;
            inline ContreteVectorType operator/(const FloatType value) const;

            inline ContreteVectorType& operator+=(const Vector2Template& vector);
            inline ContreteVectorType& operator-=(const Vector2Template& vector);
            inline ContreteVectorType& operator*=(const FloatType value);
            inline ContreteVectorType& operator/=(const FloatType value);

            inline FloatType operator*(const Vector2Template& vector) const;
        };

        template<typename FloatType> Vector2Template<FloatType>::~Vector2Template()
        {
        }

        template<typename FloatType> void Vector2Template<FloatType>::setToZero()
        {
            this->x = DEFAULT_VALUE;
            this->y = DEFAULT_VALUE;
        }

        template<typename FloatType> void Vector2Template<FloatType>::setValues(const FloatType x, const FloatType y)
        {
            this->x = x;
            this->y = y;
        }

        template<typename FloatType> FloatType Vector2Template<FloatType>::scalar(const FloatType x, const FloatType y) const
        {
            return this->x * x + this->y * y;
        }

        template<typename FloatType> FloatType Vector2Template<FloatType>::scalar(const Vector2Template<FloatType> & vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        template<typename FloatType> Vector2Template<FloatType> Vector2Template<FloatType>::operator+(const Vector2Template& vector) const
        {
            return Vector2Template(this->x + vector.x, this->y + vector.y);
        }

        template<typename FloatType> Vector2Template<FloatType> Vector2Template<FloatType>::operator-(const Vector2Template& vector) const
        {
            return Vector2Template(this->x - vector.x, this->y - vector.y);
        }

        template<typename FloatType> Vector2Template<FloatType> Vector2Template<FloatType>::operator*(const FloatType value) const
        {
            return Vector2Template(this->x * value, this->y * value);
        }

        Vector2Template Vector2Template::operator/(const FloatType value) const
        {
            return Vector2Template(this->x / value, this->y / value);
        }

        Vector2Template& Vector2Template::operator+=(const Vector2Template& vector)
        {
            this->x += vector.x;
            this->y += vector.y;

            return (*this);
        }

        Vector2Template& Vector2Template::operator-=(const Vector2Template& vector)
        {
            this->x -= vector.x;
            this->y -= vector.y;

            return (*this);
        }

        Vector2Template& Vector2Template::operator*=(const FloatType value)
        {
            this->x *= value;
            this->y *= value;

            return (*this);
        }

        Vector2Template& Vector2Template::operator/=(const FloatType value)
        {
            this->x /= value;
            this->y /= value;

            return (*this);
        }

        FloatType Vector2Template::operator*(const Vector2Template& vector) const
        {
            return this->x * vector.x + this->y * vector.y;
        }

        inline Vector2Template operator*(const FloatType value, const Vector2Template& vector)
        {
            return Vector2Template(vector.x * value, vector.y * value);
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_PLANIMETRY_VECTOR2_H_ */
