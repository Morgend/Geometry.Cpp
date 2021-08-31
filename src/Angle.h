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

#ifndef _GEOMETRY_ANGLE_H_
#define _GEOMETRY_ANGLE_H_

namespace geometry
{
    enum AngleScale
    {
        RADIANS = 0x0,
        DEGREES = 0x1,
        GRADIANS = 0x2
    };

    // =================== AngleTemplate header =================== //

    template<typename FloatType> class AngleTemplate
    {
    public:
        static const FloatType DEFAULT_VALUE;

        static const FloatType DEGREES_IN_RADIAN;
        static const FloatType GRADIANS_IN_RADIAN;
        static const FloatType DEGREES_IN_GRADIAN;

        virtual ~AngleTemplate()
        {
        }

        inline void setValueOf(const AngleTemplate<FloatType>& angle);

        inline FloatType radians() const;
        inline void setRadians(const FloatType radians);

        inline FloatType degrees() const;
        inline void setDegrees(const FloatType degrees);

        inline FloatType gradians() const;
        inline void setGradians(const FloatType gradians);

        inline operator FloatType() const;

    protected:
        FloatType value;
    };

    // =================== Angle<double> header =================== //

    class AngleF;

    class Angle : public AngleTemplate<double>
    {
    public:
        inline Angle();
        inline Angle(const AngleF & angle);
        inline Angle(const double radians);
        inline Angle(const double angle, const AngleScale scale);
        virtual ~Angle();

        inline void setValueOf(const AngleF& angle);

        inline AngleF toFloat() const;

        inline Angle operator+(const double radians) const;
        inline Angle operator+(const Angle& angle) const;
        inline Angle operator-(const double radians) const;
        inline Angle operator-(const Angle& angle) const;
        inline Angle operator*(const double value) const;
        inline Angle operator/(const double value) const;
        inline double operator/(const Angle& angle) const;

        inline Angle& operator+=(const double radians);
        inline Angle& operator+=(const Angle& angle);
        inline Angle& operator-=(const double radians);
        inline Angle& operator-=(const Angle& angle);
        inline Angle& operator*=(const double value);
        inline Angle& operator/=(const double value);

        inline bool operator==(const double radians) const;
        inline bool operator==(const Angle& angle) const;
    };

    // =================== Angle<float> header ==================== //

    class AngleF : public AngleTemplate<float>
    {
    public:
        inline AngleF();
        inline AngleF(const Angle& angle);
        inline AngleF(const float radians);
        inline AngleF(const float angle, const AngleScale scale);
        virtual ~AngleF();

        inline void setValueOf(const Angle& angle);

        inline Angle toDouble() const;

        inline AngleF operator+(const float radians) const;
        inline AngleF operator+(const AngleF& angle) const;
        inline AngleF operator-(const float radians) const;
        inline AngleF operator-(const AngleF& angle) const;
        inline AngleF operator*(const float value) const;
        inline AngleF operator/(const float value) const;
        inline float operator/(const AngleF& angle) const;

        inline AngleF& operator+=(const float radians);
        inline AngleF& operator+=(const AngleF& angle);
        inline AngleF& operator-=(const float radians);
        inline AngleF& operator-=(const AngleF& angle);
        inline AngleF& operator*=(const float value);
        inline AngleF& operator/=(const float value);

        inline bool operator==(const float radians) const;
        inline bool operator==(const AngleF& angle) const;
    };

    // =============== AngleTemplate inline methods =============== //

    template<typename FloatType> void AngleTemplate<FloatType>::setValueOf(const AngleTemplate<FloatType>& angle)
    {
        this->value = angle.value;
    }

    template<typename FloatType> FloatType AngleTemplate<FloatType>::radians() const
    {
        return this->value;
    }

    template<typename FloatType> void AngleTemplate<FloatType>::setRadians(const FloatType radians)
    {
        this->value = radians;
    }

    template<typename FloatType> FloatType AngleTemplate<FloatType>::degrees() const
    {
        return this->value * DEGREES_IN_RADIAN;
    }

    template<typename FloatType> void AngleTemplate<FloatType>::setDegrees(const FloatType degrees)
    {
        this->value = degrees / DEGREES_IN_RADIAN;
    }

    template<typename FloatType> FloatType AngleTemplate<FloatType>::gradians() const
    {
        return this->value * GRADIANS_IN_RADIAN;
    }

    template<typename FloatType> void AngleTemplate<FloatType>::setGradians(const FloatType gradians)
    {
        this->value = degrees / GRADIANS_IN_RADIAN;
    }

    template<typename FloatType> AngleTemplate<FloatType>::operator FloatType() const
    {
        return this->value;
    }

    // =============== Angle<double> inline methods =============== //

    Angle::Angle()
    {
        this->value = DEFAULT_VALUE;
    }

    Angle::Angle(const AngleF& angle)
    {
        this->value = angle.radians();
    }

    Angle::Angle(const double radians)
    {
        this->value = radians;
    }

    Angle::Angle(const double angle, const AngleScale scale)
    {
        switch(scale)
        {
        case DEGREES:
            this->value = angle / DEGREES_IN_RADIAN;
            break;

        case GRADIANS:
            this->value = angle / GRADIANS_IN_RADIAN;
            break;

        default:
            this->value = angle;
        }
    }

    void Angle::setValueOf(const AngleF& angle)
    {
        this->value = angle.radians();
    }

    AngleF Angle::toFloat() const
    {
        return AngleF((float)this->value);
    }

    Angle Angle::operator+(const double radians) const
    {
        return Angle(this->value + radians);
    }

    Angle Angle::operator+(const Angle& angle) const
    {
        return Angle(this->value + angle.value);
    }

    Angle Angle::operator-(const double radians) const
    {
        return Angle(this->value - radians);
    }

    Angle Angle::operator-(const Angle& angle) const
    {
        return Angle(this->value - angle.value);
    }

    Angle Angle::operator*(const double value) const
    {
        return Angle(this->value * value);
    }

    Angle Angle::operator/(const double value) const
    {
        return Angle(this->value / value);
    }

    double Angle::operator/(const Angle& angle) const
    {
        return this->value / angle.value;
    }

    Angle& Angle::operator+=(const double radians)
    {
        this->value += radians;
        return (*this);
    }

    Angle& Angle::operator+=(const Angle& angle)
    {
        this->value += angle.value;
        return (*this);
    }

    Angle& Angle::operator-=(const double radians)
    {
        this->value -= radians;
        return (*this);
    }

    Angle& Angle::operator-=(const Angle& angle)
    {
        this->value -= angle.value;
        return (*this);
    }

    Angle& Angle::operator*=(const double value)
    {
        this->value *= value;
        return (*this);
    }

    Angle& Angle::operator/=(const double value)
    {
        this->value /= value;
        return (*this);
    }

    bool Angle::operator==(const double radians) const
    {
        //TODO: change comparsion
        return this->value == radians;
    }

    bool Angle::operator==(const Angle& angle) const
    {
        //TODO: change comparsion
        return this->value == angle.value;
    }

    // =============== Angle<float> inline methods ================ //

    AngleF::AngleF()
    {
        this->value = AngleF::DEFAULT_VALUE;
    }

    AngleF::AngleF(const Angle& angle)
    {
        this->value = (float)angle.radians();
    }

    AngleF::AngleF(const float radians)
    {
        this->value = radians;
    }

    AngleF::AngleF(const float angle, const AngleScale scale)
    {
        switch (scale)
        {
        case DEGREES:
            this->value = angle / DEGREES_IN_RADIAN;
            break;

        case GRADIANS:
            this->value = angle / GRADIANS_IN_RADIAN;
            break;

        default:
            this->value = angle;
        }
    }

    void AngleF::setValueOf(const Angle& angle)
    {
        this->value = (float)angle.radians();
    }

    Angle AngleF::toDouble() const
    {
        return Angle(this->value);
    }

    AngleF AngleF::operator+(const float radians) const
    {
        return AngleF(this->value + radians);
    }

    AngleF AngleF::operator+(const AngleF& angle) const
    {
        return AngleF(this->value + angle.value);
    }

    AngleF AngleF::operator-(const float radians) const
    {
        return AngleF(this->value - radians);
    }

    AngleF AngleF::operator-(const AngleF& angle) const
    {
        return AngleF(this->value - angle.value);
    }

    AngleF AngleF::operator*(const float value) const
    {
        return AngleF(this->value * value);
    }

    AngleF AngleF::operator/(const float value) const
    {
        return AngleF(this->value / value);
    }

    float AngleF::operator/(const AngleF& angle) const
    {
        return this->value / angle.value;
    }

    AngleF& AngleF::operator+=(const float radians)
    {
        this->value += radians;
        return (*this);
    }

    AngleF& AngleF::operator+=(const AngleF& angle)
    {
        this->value += angle.value;
        return (*this);
    }

    AngleF& AngleF::operator-=(const float radians)
    {
        this->value -= radians;
        return (*this);
    }

    AngleF& AngleF::operator-=(const AngleF& angle)
    {
        this->value -= angle.value;
        return (*this);
    }

    AngleF& AngleF::operator*=(const float value)
    {
        this->value *= value;
        return (*this);
    }

    AngleF& AngleF::operator/=(const float value)
    {
        this->value /= value;
        return (*this);
    }

    bool AngleF::operator==(const float radians) const
    {
        //TODO: change comparsion
        return this->value == radians;
    }

    bool AngleF::operator==(const AngleF& angle) const
    {
        //TODO: change comparsion
        return this->value == angle.value;
    }

    // =========================== End ============================ //

} /* namespace geometry */

#endif /* GEOMETRY_FLOAT64_ANGLE_H_ */
