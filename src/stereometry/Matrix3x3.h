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

#ifndef _GEOMETRY_STEREOMETRY_MATRIX3X3_H_
#define _GEOMETRY_STEREOMETRY_MATRIX3X3_H_

#include "../types.h"
#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        // ================== Matrix3x3 Template header ================== //

        template <typename FloatType, class VectorType> class Matrix3x3Template
        {
        public:
            static const int32bit ZERO_MATRIX = 0x0;
            static const int32bit IDENTITY_MATRIX = 0x1;

            static const FloatType ZERO;
            static const FloatType UNIT;

            FloatType r1c1;
            FloatType r1c2;
            FloatType r1c3;

            FloatType r2c1;
            FloatType r2c2;
            FloatType r2c3;

            FloatType r3c1;
            FloatType r3c2;
            FloatType r3c3;

            inline Matrix3x3Template();
            inline Matrix3x3Template(const int32bit matrixType);
            virtual ~Matrix3x3Template();

            inline void setToIdentity();
            inline void setToZero();

            inline FloatType determinant() const;

            inline VectorType row1() const;
            inline VectorType row2() const;
            inline VectorType row3() const;

            inline VectorType column1() const;
            inline VectorType column2() const;
            inline VectorType column3() const;

            inline VectorType operator* (const VectorType & vector) const;
        };


        template <typename FloatType, class VectorType> Matrix3x3Template<FloatType, VectorType>::Matrix3x3Template()
        {
            this->setToIdentity();
        }

        template <typename FloatType, class VectorType> Matrix3x3Template<FloatType, VectorType>::Matrix3x3Template(const int32bit matrixType)
        {
            if (matrixType == ZERO_MATRIX) {
                this->setToZero();
            }
            else {
                this->setToIdentity();
            }
        }

        template <typename FloatType, class VectorType> Matrix3x3Template<FloatType, VectorType>::~Matrix3x3Template()
        {
        }

        template <typename FloatType, class VectorType> void Matrix3x3Template<FloatType, VectorType>::setToIdentity()
        {
            this->r1c1 = UNIT;
            this->r1c2 = ZERO;
            this->r1c3 = ZERO;

            this->r2c1 = ZERO;
            this->r2c2 = UNIT;
            this->r2c3 = ZERO;

            this->r3c1 = ZERO;
            this->r3c2 = ZERO;
            this->r3c3 = UNIT;
        }

        template <typename FloatType, class VectorType> void Matrix3x3Template<FloatType, VectorType>::setToZero()
        {
            this->r1c1 = ZERO;
            this->r1c2 = ZERO;
            this->r1c3 = ZERO;

            this->r2c1 = ZERO;
            this->r2c2 = ZERO;
            this->r2c3 = ZERO;

            this->r3c1 = ZERO;
            this->r3c2 = ZERO;
            this->r3c3 = ZERO;
        }

        template <typename FloatType, class VectorType> FloatType Matrix3x3Template<FloatType, VectorType>::determinant() const
        {
            return    this->r1c1 * this->r2c2 * this->r3c3
                    + this->r1c2 * this->r2c3 * this->r3c1
                    + this->r2c1 * this->r3c2 * this->r1c3
                    - this->r1c3 * this->r2c2 * this->r3c1
                    - this->r1c2 * this->r2c1 * this->r3c3
                    - this->r1c1 * this->r2c3 * this->r3c2;
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::row1() const
        {
            return VectorType(this->r1c1, this->r1c2, this->r1c3);
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::row2() const
        {
            return VectorType(this->r2c1, this->r2c2, this->r2c3);
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::row3() const
        {
            return VectorType(this->r3c1, this->r3c2, this->r3c3);
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::column1() const
        {
            return VectorType(this->r1c1, this->r2c1, this->r3c1);
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::column2() const
        {
            return VectorType(this->r1c2, this->r2c2, this->r3c2);
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::column3() const
        {
            return VectorType(this->r1c3, this->r2c3, this->r3c3);
        }

        template <typename FloatType, class VectorType> VectorType Matrix3x3Template<FloatType, VectorType>::operator* (const VectorType & vector) const
        {
            return VectorType(
                    this->r1c1 * vector.x + this->r1c2 * vector.y + this->r1c3 * vector.z,
                    this->r2c1 * vector.x + this->r2c2 * vector.y + this->r2c3 * vector.z,
                    this->r3c1 * vector.x + this->r3c2 * vector.y + this->r3c3 * vector.z
            );
        }

        // =================== Matrix3x3<float> header =================== //

        class Matrix3x3;

        class Matrix3x3F : public Matrix3x3Template<float, Vector3F>
        {
        public:

            inline Matrix3x3F();
            inline Matrix3x3F(const int type);
            inline Matrix3x3F(const Matrix3x3 & matrix);
            virtual ~Matrix3x3F();

            inline Matrix3x3 toDouble() const;

            Matrix3x3F operator* (const Matrix3x3F & matrix) const;
            inline Matrix3x3F operator* (const float value) const;
            inline Matrix3x3F operator/ (const float value) const;

            Matrix3x3F & operator*= (const Matrix3x3F & matrix);
            inline Matrix3x3F & operator*= (const float value);
            inline Matrix3x3F & operator/= (const float value);
        };

        // =================== Matrix3x3<double> header ================== //

        class Matrix3x3 : public Matrix3x3Template<double, Vector3>
        {
        public:

            inline Matrix3x3();
            inline Matrix3x3(const int type);
            inline Matrix3x3(const Matrix3x3F & matrix);
            virtual ~Matrix3x3();

            inline Matrix3x3F toFloat() const;

            Matrix3x3 operator* (const Matrix3x3 & matrix) const;
            inline Matrix3x3 operator* (const double value) const;
            inline Matrix3x3 operator/ (const double value) const;

            Matrix3x3 & operator*= (const Matrix3x3 & matrix);
            inline Matrix3x3 & operator*= (const double value);
            inline Matrix3x3 & operator/= (const double value);
        };

        // =================== Matrix3x3<float> methods ================== //

        Matrix3x3F::Matrix3x3F()
            : Matrix3x3Template<float, Vector3F>()
        {
        }

        Matrix3x3F::Matrix3x3F(const int matrixType)
            : Matrix3x3Template<float, Vector3F>(matrixType)
        {
        }

        Matrix3x3F::Matrix3x3F(const Matrix3x3 & matrix)
        {
            this->r1c1 = (float)matrix.r1c1;
            this->r1c2 = (float)matrix.r1c2;
            this->r1c3 = (float)matrix.r1c3;

            this->r2c1 = (float)matrix.r2c1;
            this->r2c2 = (float)matrix.r2c2;
            this->r2c3 = (float)matrix.r2c3;

            this->r3c1 = (float)matrix.r3c1;
            this->r3c2 = (float)matrix.r3c2;
            this->r3c3 = (float)matrix.r3c3;
        }

        Matrix3x3 Matrix3x3F::toDouble() const
        {
            return Matrix3x3(*this);
        }

        Matrix3x3F Matrix3x3F::operator* (const float value) const
        {
            Matrix3x3F result(*this);
            result *= value;
            return result;
        }

        Matrix3x3F Matrix3x3F::operator/ (const float value) const
        {
            Matrix3x3F result(*this);
            result /= value;
            return result;
        }

        Matrix3x3F & Matrix3x3F::operator*= (const float value)
        {
            this->r1c1 *= value;
            this->r1c2 *= value;
            this->r1c3 *= value;

            this->r2c1 *= value;
            this->r2c2 *= value;
            this->r2c3 *= value;

            this->r3c1 *= value;
            this->r3c2 *= value;
            this->r3c3 *= value;

            return (*this);
        }

        Matrix3x3F & Matrix3x3F::operator/= (const float value)
        {
            this->r1c1 /= value;
            this->r1c2 /= value;
            this->r1c3 /= value;

            this->r2c1 /= value;
            this->r2c2 /= value;
            this->r2c3 /= value;

            this->r3c1 /= value;
            this->r3c2 /= value;
            this->r3c3 /= value;

            return (*this);
        }

        // ================== Matrix2x2<double> methods ================== //

        Matrix3x3::Matrix3x3()
            : Matrix3x3Template<double, Vector3>()
        {
        }

        Matrix3x3::Matrix3x3(const int matrixType)
            : Matrix3x3Template<double, Vector3>(matrixType)
        {
        }

        Matrix3x3::Matrix3x3(const Matrix3x3F & matrix)
        {
            this->r1c1 = matrix.r1c1;
            this->r1c2 = matrix.r1c2;
            this->r1c3 = matrix.r1c3;

            this->r2c1 = matrix.r2c1;
            this->r2c2 = matrix.r2c2;
            this->r2c3 = matrix.r2c3;

            this->r3c1 = matrix.r3c1;
            this->r3c2 = matrix.r3c2;
            this->r3c3 = matrix.r3c3;
        }

        Matrix3x3F Matrix3x3::toFloat() const
        {
            return Matrix3x3F(*this);
        }

        Matrix3x3 Matrix3x3::operator* (const double value) const
        {
            Matrix3x3 result(*this);
            result *= value;
            return result;
        }

        Matrix3x3 Matrix3x3::operator/ (const double value) const
        {
            Matrix3x3 result(*this);
            result /= value;
            return result;
        }

        Matrix3x3 & Matrix3x3::operator*= (const double value)
        {
            this->r1c1 *= value;
            this->r1c2 *= value;
            this->r1c3 *= value;

            this->r2c1 *= value;
            this->r2c2 *= value;
            this->r2c3 *= value;

            this->r3c1 *= value;
            this->r3c2 *= value;
            this->r3c3 *= value;

            return (*this);
        }

        Matrix3x3 & Matrix3x3::operator/= (const double value)
        {
            this->r1c1 /= value;
            this->r1c2 /= value;
            this->r1c3 /= value;

            this->r2c1 /= value;
            this->r2c2 /= value;
            this->r2c3 /= value;

            this->r3c1 /= value;
            this->r3c2 /= value;
            this->r3c3 /= value;

            return (*this);
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_MATRIX3X3_F_H_ */
