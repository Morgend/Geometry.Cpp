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
    class Quaternion
    {
    public:
        static const double DEFAULT_VALUE;


        double w;
        double x;
        double y;
        double z;

        inline Quaternion();
        inline Quaternion(const double w, const double x, const double y, const double z);
        virtual ~Quaternion();

        inline void setValuesOf(const Quaternion & q);
        inline void setValues(const double w, const double x, const double y, const double z);

        inline void setToZero();

        inline bool isZero() const;

        inline void conjugate();

        inline Quaternion getConjugated() const;

        double module() const;

        bool normalize();
    };

    Quaternion::Quaternion()
    {
        this->w = DEFAULT_VALUE;
        this->x = DEFAULT_VALUE;
        this->y = DEFAULT_VALUE;
        this->z = DEFAULT_VALUE;
    }

    Quaternion::Quaternion(const double w, const double x, const double y, const double z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void Quaternion::setValuesOf(const Quaternion & q)
    {
        this->w = q.w;
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
    }

    void Quaternion::setValues(const double w, const double x, const double y, const double z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void Quaternion::setToZero()
    {
        this->x = DEFAULT_VALUE;
        this->y = DEFAULT_VALUE;
        this->z = DEFAULT_VALUE;
        this->w = DEFAULT_VALUE;
    }

    bool Quaternion::isZero() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w <= POSITIVE_SQUARE_EPSYLON_DOUBLE;
    }

    void Quaternion::conjugate()
    {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
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

        if (squareModule < POSITIVE_SQUARE_EPSYLON_DOUBLE)
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
}

#endif
