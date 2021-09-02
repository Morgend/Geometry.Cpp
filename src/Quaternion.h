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

#ifndef _GEOMETRY_QUATERNION_H_
#define _GEOMETRY_QUATERNION_H_

#include "constants.h"
#include <math.h>

namespace geometry
{
    // ================== Quaternion Template header ================== //

    template<typename FloatType> class BasicQuaternionTemplate
    {
    public:
        static const FloatType ZERO;
        static const FloatType UNIT;
        static const FloatType EPSYLON;
        static const FloatType NEGATIVE_EPSYLON;
        static const FloatType SQUARE_EPSYLON;

        FloatType w, x, y, z;

        virtual ~BasicQuaternionTemplate()
        {
        }

        inline void setValuesOf(const BasicQuaternionTemplate<FloatType> & q);
        inline void setValues(const FloatType w, const FloatType x, const FloatType y, const FloatType z);

        inline void setToZero();

        inline bool isZero() const;
        inline bool isUnit() const;
        inline bool isCloseTo(const FloatType w, const FloatType x, const FloatType y, const FloatType z) const;
        inline bool isCloseTo(const BasicQuaternionTemplate<FloatType>& quaternion) const;

        inline void conjugate();
    };


    // ================== Quaternion<double> header =================== //

    class QuaternionF;

    class Quaternion : public BasicQuaternionTemplate<double>
    {
    public:
        inline Quaternion();
        inline Quaternion(const QuaternionF & q);
        inline Quaternion(const double w, const double x, const double y, const double z);
        virtual ~Quaternion();

        inline void setValuesOf(const QuaternionF & q);

        inline Quaternion getConjugated() const;

        inline double module() const;

        inline bool normalize();

        inline QuaternionF toFloat() const;
    };


    // =================== Quaternion<float> header =================== //

    class QuaternionF : public BasicQuaternionTemplate<float>
    {
    public:

        inline QuaternionF();
        inline QuaternionF(const Quaternion & q);
        inline QuaternionF(const float w, const float x, const float y, const float z);
        virtual ~QuaternionF();

        inline void setValuesOf(const Quaternion & q);

        inline QuaternionF getConjugated() const;

        inline float module() const;

        inline bool normalize();

        inline Quaternion toDouble() const;
    };

    // ============== Quaternion Template inline methods ============== //


    template<typename FloatType> void BasicQuaternionTemplate<FloatType>::setValuesOf(const BasicQuaternionTemplate<FloatType> & q)
    {
        this->w = q.w;
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
    }

    template<typename FloatType> void BasicQuaternionTemplate<FloatType>::setValues(const FloatType w, const FloatType x, const FloatType y, const FloatType z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    template<typename FloatType> void BasicQuaternionTemplate<FloatType>::setToZero()
    {
        this->x = ZERO;
        this->y = ZERO;
        this->z = ZERO;
        this->w = ZERO;
    }

    template<typename FloatType> bool BasicQuaternionTemplate<FloatType>::isZero() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w <= SQUARE_EPSYLON;
    }

    template<typename FloatType> bool BasicQuaternionTemplate<FloatType>::isUnit() const
    {
        FloatType difference = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w - UNIT;

        return NEGATIVE_EPSYLON <= difference && difference <= EPSYLON;
    }

    template<typename FloatType> bool BasicQuaternionTemplate<FloatType>::isCloseTo(const FloatType w, const FloatType x, const FloatType y, const FloatType z) const
    {
        FloatType dw = this->w - w;
        FloatType dx = this->x - x;
        FloatType dy = this->y - y;
        FloatType dz = this->z - z;

        return dw * dw + dx * dx + dy * dy + dz * dz <= SQUARE_EPSYLON;
    }

    template<typename FloatType> bool BasicQuaternionTemplate<FloatType>::isCloseTo(const BasicQuaternionTemplate<FloatType>& quaternion) const
    {
        FloatType dw = this->w - vector.w;
        FloatType dx = this->x - vector.x;
        FloatType dy = this->y - vector.y;
        FloatType dz = this->z - vector.z;

        return dw * dw + dx * dx + dy * dy + dz * dz <= SQUARE_EPSYLON;

    }

    template<typename FloatType> void BasicQuaternionTemplate<FloatType>::conjugate()
    {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
    }

    // ============== Quaternion<double> inline methods =============== //

    Quaternion::Quaternion()
    {
        this->w = ZERO;
        this->x = ZERO;
        this->y = ZERO;
        this->z = ZERO;
    }

    Quaternion::Quaternion(const QuaternionF & q)
    {
        this->w = q.w;
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
    }

    Quaternion::Quaternion(const double w, const double x, const double y, const double z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void Quaternion::setValuesOf(const QuaternionF & q)
    {
        this->w = q.w;
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
    }

    Quaternion Quaternion::getConjugated() const
    {
        return Quaternion(this->w, -this->x, -this->y, -this->z);
    }

    double Quaternion::module() const
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    bool Quaternion::normalize()
    {
        double squareModule = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;

        if (squareModule < SQUARE_EPSYLON)
        {
            this->setToZero();
            return false;
        }

        double module = sqrt(squareModule);

        this->x /= module;
        this->y /= module;
        this->z /= module;
        this->w /= module;

        return true;
    }

    QuaternionF Quaternion::toFloat() const
    {
        return QuaternionF((float)this->w, (float)this->x, (float)this->y, (float)this->z);
    }

    // =============== Quaternion<float> inline methods =============== //

    QuaternionF::QuaternionF()
    {
        this->w = ZERO;
        this->x = ZERO;
        this->y = ZERO;
        this->z = ZERO;
    }

    QuaternionF::QuaternionF(const Quaternion & q)
    {
        this->w = (float)q.w;
        this->x = (float)q.x;
        this->y = (float)q.y;
        this->z = (float)q.z;
    }

    QuaternionF::QuaternionF(const float w, const float x, const float y, const float z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void QuaternionF::setValuesOf(const Quaternion & q)
    {
        this->w = (float)q.w;
        this->x = (float)q.x;
        this->y = (float)q.y;
        this->z = (float)q.z;
    }

    QuaternionF QuaternionF::getConjugated() const
    {
        return QuaternionF(this->w, -this->x, -this->y, -this->z);
    }

    float QuaternionF::module() const
    {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    bool QuaternionF::normalize()
    {
        float squareModule = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;

        if (squareModule < SQUARE_EPSYLON)
        {
            this->setToZero();
            return false;
        }

        float module = sqrtf(squareModule);

        this->x /= module;
        this->y /= module;
        this->z /= module;
        this->w /= module;

        return true;
    }

    Quaternion QuaternionF::toDouble() const
    {
        return Quaternion(this->w, this->x, this->y, this->z);
    }
}

#endif
