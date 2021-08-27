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

#ifndef _GEOMETRY_ANGLE_F_H_
#define _GEOMETRY_ANGLE_F_H_

namespace geometry
{
    typedef class AngleF
    {
    public:
        static const float DEFAULT_VALUE;

        static const float DEGREES_IN_RADIAN;
        static const float GRADIANS_IN_RADIAN;
        static const float DEGREES_IN_GRADIAN;

        inline AngleF();
        inline AngleF(const float radians);
        virtual ~AngleF();

        inline float radians() const;
        inline void setRadians(const float radians);

        inline float degrees() const;
        inline void setDegrees(const float degrees);

        inline float gradians() const;
        inline void setGradians(const float gradians);

        inline AngleF & operator+=(const float radians);
        inline AngleF & operator+=(const AngleF & angle);
        inline AngleF & operator-=(const float radians);
        inline AngleF & operator-=(const AngleF & angle);

        inline bool operator==(const float radians) const;
        inline bool operator==(const AngleF & angle) const;

        inline operator float() const;

    private:
        float value;
    } AngleFFloat, AngleFFloat32;

    AngleF::AngleF()
    {
        this->value = AngleF::DEFAULT_VALUE;
    }

    AngleF::AngleF(const float radians)
    {
        this->value = radians;
    }

    float AngleF::radians() const
    {
        return this->value;
    }

    void AngleF::setRadians(const float radians)
    {
        this->value = radians;
    }

    float AngleF::degrees() const
    {
        return this->value * AngleF::DEGREES_IN_RADIAN;
    }

    void AngleF::setDegrees(const float degrees)
    {
        this->value = degrees / AngleF::DEGREES_IN_RADIAN;
    }

    float AngleF::gradians() const
    {
        return this->value * AngleF::GRADIANS_IN_RADIAN;
    }

    void AngleF::setGradians(const float gradians)
    {
        this->value = gradians / AngleF::GRADIANS_IN_RADIAN;
    }


    AngleF & AngleF::operator+=(const float radians)
    {
        this->value += radians;
        return (*this);
    }

    AngleF & AngleF::operator+=(const AngleF & angle)
    {
        this->value += angle.value;
        return (*this);
    }

    AngleF & AngleF::operator-=(const float radians)
    {
        this->value -= radians;
        return (*this);
    }

    AngleF & AngleF::operator-=(const AngleF & angle)
    {
        this->value -= angle.value;
        return (*this);
    }

    bool AngleF::operator==(const float radians) const
    {
        //TODO: change comparsion
        return this->value == radians;
    }

    bool AngleF::operator==(const AngleF & angle) const
    {
        //TODO: change comparsion
        return this->value == angle.value;
    }

    AngleF::operator float() const
    {
        return this->value;
    }
} /* namespace geometry */

#endif /* _GEOMETRY_ANGLE_F_H_ */
