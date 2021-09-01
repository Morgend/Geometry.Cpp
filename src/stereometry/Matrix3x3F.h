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

#ifndef _GEOMETRY_STEREOMETRY_MATRIX3X3_F_H_
#define _GEOMETRY_STEREOMETRY_MATRIX3X3_F_H_

#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        class Matrix3x3F
        {
        public:
            static const int TYPE_ZERO = 0x0;
            static const int TYPE_IDENTITY = 0x1;
            static const int CELL_AMOUNT = 9;
            static const float DEFAULT_CELL_VALUE;

            float r1c1;
            float r1c2;
            float r1c3;

            float r2c1;
            float r2c2;
            float r2c3;

            float r3c1;
            float r3c2;
            float r3c3;

            inline Matrix3x3F();
            inline Matrix3x3F(const int type);
            virtual ~Matrix3x3F();

            inline void loadIdentity();
            inline void loadZero();

            inline float determinant() const;

            Matrix3x3F operator* (const Matrix3x3F & matrix) const;
            inline Vector3F operator* (const Vector3F & vector3) const;
            inline Matrix3x3F operator* (const float value) const;
            inline Matrix3x3F operator/ (const float value) const;

            Matrix3x3F & operator*= (const Matrix3x3F & matrix);
            inline Matrix3x3F & operator*= (const float value);
            inline Matrix3x3F & operator/= (const float value);
        };

        Matrix3x3F::Matrix3x3F()
        {
            this->loadIdentity();
        }

        Matrix3x3F::Matrix3x3F(const int type)
        {
            if (type == TYPE_IDENTITY)
            {
                this->loadIdentity();
            }
            else {
                this->loadZero();
            }
        }

        void Matrix3x3F::loadIdentity()
        {
            this->r1c1 = 1.0f;
            this->r1c2 = 0.0f;
            this->r1c3 = 0.0f;

            this->r2c1 = 0.0f;
            this->r2c2 = 1.0f;
            this->r2c3 = 0.0f;

            this->r3c1 = 0.0f;
            this->r3c2 = 0.0f;
            this->r3c3 = 1.0f;
        }

        void Matrix3x3F::loadZero()
        {
            this->r1c1 = 0.0f;
            this->r1c2 = 0.0f;
            this->r1c3 = 0.0f;

            this->r2c1 = 0.0f;
            this->r2c2 = 0.0f;
            this->r2c3 = 0.0f;

            this->r3c1 = 0.0f;
            this->r3c2 = 0.0f;
            this->r3c3 = 0.0f;
        }

        float Matrix3x3F::determinant() const
        {
            return    this->r1c1 * this->r2c2 * this->r3c3
                    + this->r1c2 * this->r2c3 * this->r3c1
                    + this->r2c1 * this->r3c2 * this->r1c3;
        }

        Vector3F Matrix3x3F::operator* (const Vector3F & vector) const
        {
            return Vector3F(
                    this->r1c1 * vector.x + this->r1c2 * vector.y + this->r1c3 * vector.z,
                    this->r2c1 * vector.x + this->r2c2 * vector.y + this->r2c3 * vector.z,
                    this->r3c1 * vector.x + this->r3c2 * vector.y + this->r3c3 * vector.z
            );
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
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_MATRIX3X3_F_H_ */
