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

#ifndef _GEOMETRY_PLANIMETRY_MATRIX2X2_H_
#define _GEOMETRY_PLANIMETRY_MATRIX2X2_H_

#include "../types.h"
#include "Vector2.h"

namespace geometry
{
    namespace planimetry
    {
        // ================== Matrix2x2 Template header ================== //

        template <typename FloatType, class VectorType> class Matrix2x2Template
        {
        public:
            static const int32bit ZERO_MATRIX = 0x0;
            static const int32bit IDENTITY_MATRIX = 0x1;

            static const FloatType ZERO;
            static const FloatType UNIT;

            FloatType r1c1;
            FloatType r1c2;
            FloatType r2c1;
            FloatType r2c2;

            inline Matrix2x2Template();
            inline Matrix2x2Template(const int32bit matrixType);
            virtual ~Matrix2x2Template();

            inline void setToIdentity();
            inline void setToZero();

            inline FloatType determinant() const;

            inline VectorType row1() const;
            inline VectorType row2() const;

            inline VectorType column1() const;
            inline VectorType column2() const;

            inline VectorType operator* (const VectorType & vector) const;
        };

        // ================= Matrix2x2 Template methods ================== //

        template <typename FloatType, class VectorType> Matrix2x2Template<FloatType, VectorType>::Matrix2x2Template()
        {
            this->setToIdentity();
        }

        template <typename FloatType, class VectorType> Matrix2x2Template<FloatType, VectorType>::Matrix2x2Template(const int32bit matrixType)
        {
            if (matrixType == ZERO_MATRIX) {
                this->setToZero();
            }
            else {
                this->setToIdentity();
            }
        }

        template <typename FloatType, class VectorType> Matrix2x2Template<FloatType, VectorType>::~Matrix2x2Template()
        {
        }

        template <typename FloatType, class VectorType> void Matrix2x2Template<FloatType, VectorType>::setToIdentity()
        {
            this->r1c1 = UNIT;
            this->r1c2 = ZERO;
            this->r2c1 = ZERO;
            this->r2c2 = UNIT;
        }

        template <typename FloatType, class VectorType> void Matrix2x2Template<FloatType, VectorType>::setToZero()
        {
            this->r1c1 = ZERO;
            this->r1c2 = ZERO;
            this->r2c1 = ZERO;
            this->r2c2 = ZERO;
        }

        template <typename FloatType, class VectorType> FloatType Matrix2x2Template<FloatType, VectorType>::determinant() const
        {
            return this->r1c1 * this->r2c2 - this->r1c2 * this->r2c1;
        }

        template <typename FloatType, class VectorType> VectorType Matrix2x2Template<FloatType, VectorType>::row1() const
        {
            return VectorType(this->r1c1, this->r1c2);
        }

        template <typename FloatType, class VectorType> VectorType Matrix2x2Template<FloatType, VectorType>::row2() const
        {
            return VectorType(this->r2c1, this->r2c2);
        }

        template <typename FloatType, class VectorType> VectorType Matrix2x2Template<FloatType, VectorType>::column1() const
        {
            return VectorType(this->r1c1, this->r2c1);
        }

        template <typename FloatType, class VectorType> VectorType Matrix2x2Template<FloatType, VectorType>::column2() const
        {
            return VectorType(this->r1c2, this->r2c2);
        }

        template <typename FloatType, class VectorType> VectorType Matrix2x2Template<FloatType, VectorType>::operator* (const VectorType & vector) const
        {
            return VectorType(this->r1c1 * vector.x + this->r1c2 * vector.y, this->r2c1 * vector.x + this->r2c2 * vector.y);
        }

        // =================== Matrix2x2<float> header =================== //

        class Matrix2x2;

        class Matrix2x2F : public Matrix2x2Template<float, Vector2F>
        {
        public:
            inline Matrix2x2F();
            inline Matrix2x2F(const int matrixType);
            inline Matrix2x2F(const float r1c1, const float r1c2, const float r2c1, const float r2c2);
            inline Matrix2x2F(const Matrix2x2 & matrix);
            virtual ~Matrix2x2F();

            inline Matrix2x2 toDouble() const;

            Matrix2x2F operator* (const Matrix2x2F & matrix) const;
            inline Matrix2x2F operator* (const float value) const;
            inline Matrix2x2F operator/ (const float value) const;

            Matrix2x2F & operator*= (const Matrix2x2F & matrix);
            inline Matrix2x2F & operator*= (const float value);
            inline Matrix2x2F & operator/= (const float value);
        };

        // =================== Matrix2x2<double> header ================== //

        class Matrix2x2 : public Matrix2x2Template<double, Vector2>
        {
        public:
            inline Matrix2x2();
            inline Matrix2x2(const int matrixType);
            inline Matrix2x2(const double r1c1, const double r1c2, const double r2c1, const double r2c2);
            inline Matrix2x2(const Matrix2x2F & matrix);
            virtual ~Matrix2x2();

            inline Matrix2x2F toFloat() const;

            Matrix2x2 operator* (const Matrix2x2 & matrix) const;
            inline Matrix2x2 operator* (const double value) const;
            inline Matrix2x2 operator/ (const double value) const;

            Matrix2x2 & operator*= (const Matrix2x2 & matrix);
            inline Matrix2x2 & operator*= (const double value);
            inline Matrix2x2 & operator/= (const double value);
        };

        // =================== Matrix2x2<float> methods ================== //

        Matrix2x2F::Matrix2x2F()
            : Matrix2x2Template<float, Vector2F>()
        {
        }

        Matrix2x2F::Matrix2x2F(const int matrixType)
            : Matrix2x2Template<float, Vector2F>(matrixType)
        {
        }

        Matrix2x2F::Matrix2x2F(const float r1c1, const float r1c2, const float r2c1, const float r2c2)
        {
            this->r1c1 = r1c1;
            this->r1c2 = r1c2;
            this->r2c1 = r2c1;
            this->r2c2 = r2c2;
        }

        Matrix2x2F::Matrix2x2F(const Matrix2x2 & matrix)
        {
            this->r1c1 = (float)matrix.r1c1;
            this->r1c2 = (float)matrix.r1c2;
            this->r2c1 = (float)matrix.r2c1;
            this->r2c2 = (float)matrix.r2c2;
        }

        Matrix2x2 Matrix2x2F::toDouble() const
        {
            return Matrix2x2(*this);
        }

        Matrix2x2F Matrix2x2F::operator* (const float value) const
        {
            return Matrix2x2F(this->r1c1 * value, this->r1c2 * value, this->r2c1 * value, this->r2c2 * value);
        }

        Matrix2x2F Matrix2x2F::operator/ (const float value) const
        {
            return Matrix2x2F(this->r1c1 / value, this->r1c2 / value, this->r2c1 / value, this->r2c2 / value);
        }

        Matrix2x2F & Matrix2x2F::operator*= (const float value)
        {
            this->r1c1 *= value;
            this->r1c2 *= value;
            this->r2c1 *= value;
            this->r2c2 *= value;

            return (*this);
        }

        Matrix2x2F & Matrix2x2F::operator/= (const float value)
        {
            this->r1c1 /= value;
            this->r1c2 /= value;
            this->r2c1 /= value;
            this->r2c2 /= value;

            return (*this);
        }

        // ================== Matrix2x2<double> methods ================== //

        Matrix2x2::Matrix2x2()
            : Matrix2x2Template<double, Vector2>()
        {
        }

        Matrix2x2::Matrix2x2(const int matrixType)
            : Matrix2x2Template<double, Vector2>(matrixType)
        {
        }

        Matrix2x2::Matrix2x2(const double r1c1, const double r1c2, const double r2c1, const double r2c2)
        {
            this->r1c1 = r1c1;
            this->r1c2 = r1c2;
            this->r2c1 = r2c1;
            this->r2c2 = r2c2;
        }

        Matrix2x2::Matrix2x2(const Matrix2x2F & matrix)
        {
            this->r1c1 = matrix.r1c1;
            this->r1c2 = matrix.r1c2;
            this->r2c1 = matrix.r2c1;
            this->r2c2 = matrix.r2c2;
        }

        Matrix2x2F Matrix2x2::toFloat() const
        {
            return Matrix2x2F(*this);
        }

        Matrix2x2 Matrix2x2::operator* (const double value) const
        {
            return Matrix2x2(this->r1c1 * value, this->r1c2 * value, this->r2c1 * value, this->r2c2 * value);
        }

        Matrix2x2 Matrix2x2::operator/ (const double value) const
        {
            return Matrix2x2(this->r1c1 / value, this->r1c2 / value, this->r2c1 / value, this->r2c2 / value);
        }

        Matrix2x2 & Matrix2x2::operator*= (const double value)
        {
            this->r1c1 *= value;
            this->r1c2 *= value;
            this->r2c1 *= value;
            this->r2c2 *= value;

            return (*this);
        }

        Matrix2x2 & Matrix2x2::operator/= (const double value)
        {
            this->r1c1 /= value;
            this->r1c2 /= value;
            this->r2c1 /= value;
            this->r2c2 /= value;

            return (*this);
        }

    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_PLANIMETRY_MATRIX2X2_F_H_ */
