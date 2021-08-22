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

#include "Vector3.h"

namespace geometry
{
    namespace float32
    {
        namespace stereometry
        {
            class Matrix3x3
            {
            public:
                static const int TYPE_ZERO = 0x0;
                static const int TYPE_IDENTITY = 0x1;
                static const float DEFAULT_CELL_VALUE;

                float a1_1;
                float a1_2;
                float a1_3;

                float a2_1;
                float a2_2;
                float a2_3;

                float a3_1;
                float a3_2;
                float a3_3;

                inline Matrix3x3();
                inline Matrix3x3(const int type);
                virtual ~Matrix3x3();

                inline void loadIdentity();
                inline void loadZero();

                inline float determinant() const;

                Matrix3x3 operator* (const Matrix3x3 & matrix) const;
                inline Vector3 operator* (const Vector3 & vector3) const;
                inline Matrix3x3 operator* (const float value) const;
                inline Matrix3x3 operator/ (const float value) const;

                Matrix3x3 & operator*= (const Matrix3x3 & matrix);
                inline Matrix3x3 & operator*= (const float value);
                inline Matrix3x3 & operator/= (const float value);
            };

            Matrix3x3::Matrix3x3()
            {
                this->loadIdentity();
            }

            Matrix3x3::Matrix3x3(const int type)
            {
                if (type == TYPE_IDENTITY)
                {
                    this->loadIdentity();
                }
                else {
                    this->loadZero();
                }
            }

            void Matrix3x3::loadIdentity()
            {
                this->a1_1 = 1.0f;
                this->a1_2 = 0.0f;
                this->a1_3 = 0.0f;

                this->a2_1 = 0.0f;
                this->a2_2 = 1.0f;
                this->a2_3 = 0.0f;

                this->a3_1 = 0.0f;
                this->a3_2 = 0.0f;
                this->a3_3 = 1.0f;
            }

            void Matrix3x3::loadZero()
            {
                this->a1_1 = 0.0f;
                this->a1_2 = 0.0f;
                this->a1_3 = 0.0f;

                this->a2_1 = 0.0f;
                this->a2_2 = 0.0f;
                this->a2_3 = 0.0f;

                this->a3_1 = 0.0f;
                this->a3_2 = 0.0f;
                this->a3_3 = 0.0f;
            }

            float Matrix3x3::determinant() const
            {
                return    this->a1_1 * this->a2_2 * this->a3_3
                        + this->a1_2 * this->a2_3 * this->a3_1
                        + this->a2_1 * this->a3_2 * this->a1_3;
            }

            Vector3 Matrix3x3::operator* (const Vector3 & vector) const
            {
                return Vector3(
                        this->a1_1 * vector.x + this->a1_2 * vector.y + this->a1_3 * vector.z,
                        this->a2_1 * vector.x + this->a2_2 * vector.y + this->a2_3 * vector.z,
                        this->a3_1 * vector.x + this->a3_2 * vector.y + this->a3_3 * vector.z
                );
            }
/*
            Matrix3x3 Matrix3x3::operator* (const float value) const
            {
                return Matrix3x3(this->a1_1 * value, this->a1_2 * value, this->a2_1 * value, this->a2_2 * value);
            }

            Matrix3x3 Matrix3x3::operator/ (const float value) const
            {
                return Matrix3x3(this->a1_1 / value, this->a1_2 / value, this->a2_1 / value, this->a2_2 / value);
            }
*/
            Matrix3x3 & Matrix3x3::operator*= (const float value)
            {
                this->a1_1 *= value;
                this->a1_2 *= value;
                this->a1_3 *= value;

                this->a2_1 *= value;
                this->a2_2 *= value;
                this->a2_3 *= value;

                this->a3_1 *= value;
                this->a3_2 *= value;
                this->a3_3 *= value;

                return (*this);
            }

            Matrix3x3 & Matrix3x3::operator/= (const float value)
            {
                this->a1_1 /= value;
                this->a1_2 /= value;
                this->a1_3 /= value;

                this->a2_1 /= value;
                this->a2_2 /= value;
                this->a2_3 /= value;

                this->a3_1 /= value;
                this->a3_2 /= value;
                this->a3_3 /= value;

                return (*this);
            }
        } /* namespace planimetry */
    } /* namespace float32 */
} /* namespace geometry */

#endif /* __GEOMETRY_PLANIMETRY__MATRIX2X2FLOAT_H_ */
