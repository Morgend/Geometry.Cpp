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

#ifndef _GEOMETRY_FLOAT64_ANGLE_H_
#define _GEOMETRY_FLOAT64_ANGLE_H_

namespace geometry
{
    namespace float64
    {
        typedef class Angle
        {
        public:
            static const double DEFAULT_VALUE;

            static const double DEGREES_IN_RADIAN;
            static const double GRADIANS_IN_RADIAN;
            static const double DEGREES_IN_GRADIAN;

            inline Angle();
            inline Angle(const double radians);
            virtual ~Angle();

            inline double radians() const;
            inline void setRadians(const double radians);

            inline double degrees() const;
            inline void setDegrees(const double degrees);

            inline double gradians() const;
            inline void setGradians(const double gradians);

            inline Angle & operator+=(const double radians);
            inline Angle & operator+=(const Angle & angle);
            inline Angle & operator-=(const double radians);
            inline Angle & operator-=(const Angle & angle);

            inline bool operator==(const double radians) const;
            inline bool operator==(const Angle & angle) const;

            inline operator double() const;

        private:
            double value;
        } AngleDouble, AngleFloat64;

        Angle::Angle()
        {
            this->value = Angle::DEFAULT_VALUE;
        }

        Angle::Angle(const double radians)
        {
            this->value = radians;
        }

        double Angle::radians() const
        {
            return this->value;
        }

        void Angle::setRadians(const double radians)
        {
            this->value = radians;
        }

        double Angle::degrees() const
        {
            return this->value * Angle::DEGREES_IN_RADIAN;
        }

        void Angle::setDegrees(const double degrees)
        {
            this->value = degrees / Angle::DEGREES_IN_RADIAN;
        }

        double Angle::gradians() const
        {
            return this->value * Angle::GRADIANS_IN_RADIAN;
        }

        void Angle::setGradians(const double gradians)
        {
            this->value = gradians / Angle::GRADIANS_IN_RADIAN;
        }

        Angle & Angle::operator+=(const double radians)
        {
            this->value += radians;
            return (*this);
        }

        Angle & Angle::operator+=(const Angle & angle)
        {
            this->value += angle.value;
            return (*this);
        }

        Angle & Angle::operator-=(const double radians)
        {
            this->value -= radians;
            return (*this);
        }

        Angle & Angle::operator-=(const Angle & angle)
        {
            this->value -= angle.value;
            return (*this);
        }

        bool Angle::operator==(const double radians) const
        {
            //TODO: change comparsion
            return this->value == radians;
        }

        bool Angle::operator==(const Angle & angle) const
        {
            //TODO: change comparsion
            return this->value == angle.value;
        }

        Angle::operator double() const
        {
            return this->value;
        }
    } /* namespace float64 */
} /* namespace geometry */

#endif /* GEOMETRY_FLOAT64_ANGLE_H_ */
