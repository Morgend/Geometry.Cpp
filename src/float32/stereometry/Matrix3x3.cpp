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

#include "Matrix3x3.h"

namespace geometry
{
    namespace float32
    {
        namespace stereometry
        {
            const float Matrix3x3::DEFAULT_CELL_VALUE = 0.0f;

            Matrix3x3::~Matrix3x3()
            {
            }

            Matrix3x3 Matrix3x3::operator* (const Matrix3x3 & matrix) const
            {
                Matrix3x3 result;

                return result;
            }

            Matrix3x3 & Matrix3x3::operator*= (const Matrix3x3 & matrix)
            {
                float r1c1 = this->r1c1 * matrix.r1c1 + this->r1c2 * matrix.r2c1;
                float r1c2 = this->r1c1 * matrix.r1c2 + this->r1c2 * matrix.r2c2;
                float r2c1 = this->r2c1 * matrix.r1c1 + this->r2c2 * matrix.r2c1;
                float r2c2 = this->r2c1 * matrix.r1c2 + this->r2c2 * matrix.r2c2;

                this->r1c1 = r1c1;
                this->r1c2 = r1c2;
                this->r2c1 = r2c1;
                this->r2c2 = r2c2;

                return (*this);
            }
        } /* namespace stereometry */
    } /* namespace float32 */
} /* namespace geometry */