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
                float a1_1 = this->a1_1 * matrix.a1_1 + this->a1_2 * matrix.a2_1;
                float a1_2 = this->a1_1 * matrix.a1_2 + this->a1_2 * matrix.a2_2;
                float a2_1 = this->a2_1 * matrix.a1_1 + this->a2_2 * matrix.a2_1;
                float a2_2 = this->a2_1 * matrix.a1_2 + this->a2_2 * matrix.a2_2;

                this->a1_1 = a1_1;
                this->a1_2 = a1_2;
                this->a2_1 = a2_1;
                this->a2_2 = a2_2;

                return (*this);
            }
        } /* namespace stereometry */
    } /* namespace float32 */
} /* namespace geometry */
