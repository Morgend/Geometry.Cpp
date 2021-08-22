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

#ifndef _GEOMETRY_FLOAT32_ANGLE_H_
#define _GEOMETRY_FLOAT32_ANGLE_H_

namespace geometry
{
    namespace float32
    {
        typedef class Angle
        {
        public:
            static const float DEFAULT_VALUE;

            static const float DEGREES_IN_RADIAN;
            static const float GRADIANS_IN_RADIAN;
            static const float DEGREES_IN_GRADIAN;

            inline Angle();
            inline Angle(const float radians);
            virtual ~Angle();

            inline float radians() const;
            inline void setRadians(const float radians);

            inline float degrees() const;
            inline void setDegrees(const float degrees);

            inline float gradians() const;
            inline void setGradians(const float gradians);

            inline Angle & operator+=(const float radians);
            inline Angle & operator+=(const Angle & angle);
            inline Angle & operator-=(const float radians);
            inline Angle & operator-=(const Angle & angle);

            inline bool operator==(const float radians) const;
            inline bool operator==(const Angle & angle) const;

            inline operator float() const;

        private:
            float value;
        } AngleFloat, AngleFloat32;

        Angle::Angle()
        {
            this->value = Angle::DEFAULT_VALUE;
        }

        Angle::Angle(const float radians)
        {
            this->value = radians;
        }

        float Angle::radians() const
        {
            return this->value;
        }

        void Angle::setRadians(const float radians)
        {
            this->value = radians;
        }

        float Angle::degrees() const
        {
            return this->value * Angle::DEGREES_IN_RADIAN;
        }

        void Angle::setDegrees(const float degrees)
        {
            this->value = degrees / Angle::DEGREES_IN_RADIAN;
        }

        float Angle::gradians() const
        {
            return this->value * Angle::GRADIANS_IN_RADIAN;
        }

        void Angle::setGradians(const float gradians)
        {
            this->value = gradians / Angle::GRADIANS_IN_RADIAN;
        }


        Angle & Angle::operator+=(const float radians)
        {
            this->value += radians;
            return (*this);
        }

        Angle & Angle::operator+=(const Angle & angle)
        {
            this->value += angle.value;
            return (*this);
        }

        Angle & Angle::operator-=(const float radians)
        {
            this->value -= radians;
            return (*this);
        }

        Angle & Angle::operator-=(const Angle & angle)
        {
            this->value -= angle.value;
            return (*this);
        }

        bool Angle::operator==(const float radians) const
        {
            //TODO: change comparsion
            return this->value == radians;
        }

        bool Angle::operator==(const Angle & angle) const
        {
            //TODO: change comparsion
            return this->value == angle.value;
        }

        Angle::operator float() const
        {
            return this->value;
        }
    } /* namespace float32 */
} /* namespace geometry */

#endif /* _GEOMETRY_FLOAT32_ANGLE_H_ */
