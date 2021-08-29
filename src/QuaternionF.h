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

#ifndef _GEOMETRY_QUATERNION_F_H_
#define _GEOMETRY_QUATERNION_F_H_

#include "constants.h"
#include <math.h>

namespace geometry
{
    class QuaternionF
    {
    public:
        static const float DEFAULT_VALUE;


        float w;
        float x;
        float y;
        float z;

        inline QuaternionF();
        inline QuaternionF(const float w, const float x, const float y, const float z);
        virtual ~QuaternionF();

        inline void setValuesOf(const QuaternionF& q);
        inline void setValues(const float w, const float x, const float y, const float z);

        inline void setToZero();

        inline bool isZero() const;

        inline void conjugate();

        inline QuaternionF getConjugated() const;

        float module() const;

        bool normalize();
    };

    QuaternionF::QuaternionF()
    {
        this->w = DEFAULT_VALUE;
        this->x = DEFAULT_VALUE;
        this->y = DEFAULT_VALUE;
        this->z = DEFAULT_VALUE;
    }

    QuaternionF::QuaternionF(const float w, const float x, const float y, const float z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void QuaternionF::setValuesOf(const QuaternionF& q)
    {
        this->w = q.w;
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
    }

    void QuaternionF::setValues(const float w, const float x, const float y, const float z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void QuaternionF::setToZero()
    {
        this->x = DEFAULT_VALUE;
        this->y = DEFAULT_VALUE;
        this->z = DEFAULT_VALUE;
        this->w = DEFAULT_VALUE;
    }

    bool QuaternionF::isZero() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w <= POSITIVE_SQUARE_EPSYLON_FLOAT;
    }

    void QuaternionF::conjugate()
    {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
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

        if (squareModule < POSITIVE_SQUARE_EPSYLON_DOUBLE)
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
}

#endif
