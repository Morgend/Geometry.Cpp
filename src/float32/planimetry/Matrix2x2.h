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

#ifndef __GEOMETRY_PLANIMETRY__MATRIX2X2FLOAT_H_
#define __GEOMETRY_PLANIMETRY__MATRIX2X2FLOAT_H_

#include "Vector2.h"

namespace geometry
{
    namespace float32
    {
        namespace planimetry
        {
            class Matrix2x2
            {
            public:
                static const int TYPE_ZERO = 0x0;
                static const int TYPE_IDENTITY = 0x1;
                static const float DEFAULT_CELL_VALUE;

                float r1c1;
                float r1c2;
                float r2c1;
                float r2c2;

                inline Matrix2x2();
                inline Matrix2x2(const int type);
                inline Matrix2x2(const float r1c1, const float r1c2, const float r2c1, const float r2c2);
                virtual ~Matrix2x2();

                inline void loadIdentity();
                inline void loadZero();

                inline float determinant() const;

                inline Vector2 row1() const;
                inline Vector2 row2() const;

                inline Vector2 column1() const;
                inline Vector2 column2() const;

                Matrix2x2 operator* (const Matrix2x2 & matrix) const;
                inline Vector2 operator* (const Vector2 & vector) const;
                inline Matrix2x2 operator* (const float value) const;
                inline Matrix2x2 operator/ (const float value) const;

                Matrix2x2 & operator*= (const Matrix2x2 & matrix);
                inline Matrix2x2 & operator*= (const float value);
                inline Matrix2x2 & operator/= (const float value);
            };

            Matrix2x2::Matrix2x2()
            {
                this->loadIdentity();
            }

            Matrix2x2::Matrix2x2(const int type)
            {
                if (type == TYPE_IDENTITY)
                {
                    this->loadIdentity();
                }
                else {
                    this->loadZero();
                }
            }

            Matrix2x2::Matrix2x2(const float r1c1, const float r1c2, const float r2c1, const float r2c2)
            {
                this->r1c1 = r1c1;
                this->r1c2 = r1c2;
                this->r2c1 = r2c1;
                this->r2c2 = r2c2;
            }

            void Matrix2x2::loadIdentity()
            {
                this->r1c1 = 1.0f;
                this->r1c2 = 0.0f;
                this->r2c1 = 0.0f;
                this->r2c2 = 1.0f;
            }

            void Matrix2x2::loadZero()
            {
                this->r1c1 = DEFAULT_CELL_VALUE;
                this->r1c2 = DEFAULT_CELL_VALUE;
                this->r2c1 = DEFAULT_CELL_VALUE;
                this->r2c2 = DEFAULT_CELL_VALUE;
            }

            float Matrix2x2::determinant() const
            {
                return this->r1c1 * this->r2c2 - this->r1c2 * this->r2c1;
            }

            Vector2 Matrix2x2::row1() const
            {
                return Vector2(this->r1c1, this->r1c2);
            }

            Vector2 Matrix2x2::row2() const
            {
                return Vector2(this->r2c1, this->r2c2);
            }

            Vector2 Matrix2x2::column1() const
            {
                return Vector2(this->r1c1, this->r2c1);
            }

            Vector2 Matrix2x2::column2() const
            {
                return Vector2(this->r1c2, this->r2c2);
            }

            Vector2 Matrix2x2::operator* (const Vector2 & vector) const
            {
                return Vector2(this->r1c1 * vector.x + this->r1c2 * vector.y, this->r2c1 * vector.x + this->r2c2 * vector.y);
            }

            Matrix2x2 Matrix2x2::operator* (const float value) const
            {
                return Matrix2x2(this->r1c1 * value, this->r1c2 * value, this->r2c1 * value, this->r2c2 * value);
            }

            Matrix2x2 Matrix2x2::operator/ (const float value) const
            {
                return Matrix2x2(this->r1c1 / value, this->r1c2 / value, this->r2c1 / value, this->r2c2 / value);
            }

            Matrix2x2 & Matrix2x2::operator*= (const float value)
            {
                this->r1c1 *= value;
                this->r1c2 *= value;
                this->r2c1 *= value;
                this->r2c2 *= value;

                return (*this);
            }

            Matrix2x2 & Matrix2x2::operator/= (const float value)
            {
                this->r1c1 /= value;
                this->r1c2 /= value;
                this->r2c1 /= value;
                this->r2c2 /= value;

                return (*this);
            }
        } /* namespace planimetry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* __GEOMETRY_PLANIMETRY__MATRIX2X2FLOAT_H_ */
