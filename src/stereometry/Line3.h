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

#ifndef _GEOMETRY_STEREOMETRY_LINE3_H_
#define _GEOMETRY_STEREOMETRY_LINE3_H_

#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        // ==================== Line3 Template header ==================== //

        template <typename FloatType, class VectorType> class Line3Template
        {
        public:
            virtual ~Line3Template();

            inline bool isValid() const;
            inline bool isDegenerate() const;

            inline const VectorType& constPoint() const;
            inline const VectorType& constDirection() const;

            inline VectorType point() const;
            inline VectorType direction() const;

            inline void setValues(const VectorType& point, const VectorType& direction);
            inline void setValues(const FloatType pointX, const FloatType pointY, const FloatType pointZ, const FloatType directionX, const FloatType directionY, const FloatType directionZ);
            inline void moveAt(const VectorType& distance);
            inline void moveTo(const VectorType& point);
            inline void setDirection(const VectorType& direction);

            inline VectorType pointAt(const FloatType position) const;

        protected:
            inline Line3Template();
            inline Line3Template(const VectorType& point, const VectorType& direction);
            inline Line3Template(const FloatType pointX, const FloatType pointY, const FloatType pointZ, const FloatType directionX, const FloatType directionY, const FloatType directionZ);

        private:
            VectorType linePoint;
            VectorType lineDirection;
            bool valid;
        };

        // ==================== Line3<double> header ===================== //

        class Line3F;
        class Ray3;
        class Ray3F;

        class Line3 : public Line3Template<double, Vector3>
        {
        public:
            inline Line3();
            inline Line3(const Vector3& point, const Vector3& direction);
            inline Line3(const double pointX, const double pointY, const double pointZ, const double directionX, const double directionY, const double directionZ);
            virtual ~Line3();

            inline Line3F toFloat() const;
        };

        // ===================== Line3<float> header ===================== //

        class Line3F : public Line3Template<float, Vector3F>
        {
        public:
            inline Line3F();
            inline Line3F(const Vector3F& point, const Vector3F& direction);
            inline Line3F(const float pointX, const float pointY, const float pointZ, const float directionX, const float directionY, const float directionZ);
            virtual ~Line3F();

            inline Line3 toDouble() const;
        };

        // ===================== Ray3<double> header ===================== //

        class Ray3 : public Line3Template<double, Vector3>
        {
        public:
            inline Ray3();
            inline Ray3(const Vector3& point, const Vector3& direction);
            inline Ray3(const double pointX, const double pointY, const double pointZ, const double directionX, const double directionY, const double directionZ);
            virtual ~Ray3();

            inline Ray3F toFloat() const;
        };

        // ====================== Ray3<float> header ===================== //

        class Ray3F : public Line3Template<float, Vector3F>
        {
        public:
            inline Ray3F();
            inline Ray3F(const Vector3F& point, const Vector3F& direction);
            inline Ray3F(const float pointX, const float pointY, const float pointZ, const float directionX, const float directionY, const float directionZ);
            virtual ~Ray3F();

            inline Ray3 toDouble() const;
        };

        // ================ Line3 Template inline methods ================ //

        template <typename FloatType, class VectorType> Line3Template<FloatType, VectorType>::Line3Template()
        {
            this->valid = false;
        }

        template <typename FloatType, class VectorType> Line3Template<FloatType, VectorType>::Line3Template(const VectorType& point, const VectorType& direction)
            : linePoint(point)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> Line3Template<FloatType, VectorType>::Line3Template(const FloatType pointX, const FloatType pointY, const FloatType pointZ, const FloatType directionX, const FloatType directionY, const FloatType directionZ)
            : linePoint(pointX, pointY, pointZ)
            , lineDirection(directionX, directionY, directionZ)
        {
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> Line3Template<FloatType, VectorType>::~Line3Template()
        {
        }

        template <typename FloatType, class VectorType> bool Line3Template<FloatType, VectorType>::isValid() const
        {
            return this->valid;
        }

        template <typename FloatType, class VectorType> bool Line3Template<FloatType, VectorType>::isDegenerate() const
        {
            return !this->valid;
        }

        template <typename FloatType, class VectorType> const VectorType& Line3Template<FloatType, VectorType>::constPoint() const
        {
            return this->linePoint;
        }

        template <typename FloatType, class VectorType> const VectorType& Line3Template<FloatType, VectorType>::constDirection() const
        {
            return this->lineDirection;
        }

        template <typename FloatType, class VectorType> VectorType Line3Template<FloatType, VectorType>::point() const
        {
            return this->linePoint;
        }

        template <typename FloatType, class VectorType> VectorType Line3Template<FloatType, VectorType>::direction() const
        {
            return this->lineDirection;
        }

        template <typename FloatType, class VectorType> void Line3Template<FloatType, VectorType>::setValues(const VectorType& point, const VectorType& direction)
        {
            this->linePoint = point;
            this->lineDirection = direction;
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> void Line3Template<FloatType, VectorType>::setValues(const FloatType pointX, const FloatType pointY, const FloatType pointZ, const FloatType directionX, const FloatType directionY, const FloatType directionZ)
        {
            this->linePoint.setValues(pointX, pointY, pointZ);
            this->linePoint.setValues(directionX, directionY, directionZ);
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> void Line3Template<FloatType, VectorType>::moveAt(const VectorType& distance)
        {
            this->linePoint += distance;
        }

        template <typename FloatType, class VectorType> void Line3Template<FloatType, VectorType>::moveTo(const VectorType& point)
        {
            this->linePoint = point;
        }

        template <typename FloatType, class VectorType> void Line3Template<FloatType, VectorType>::setDirection(const VectorType& direction)
        {
            this->lineDirection = direction;
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> VectorType Line3Template<FloatType, VectorType>::pointAt(const FloatType position) const
        {
            return VectorType(this->linePoint.x + this->lineDirection.x * position, this->linePoint.y + this->lineDirection.y * position);
        }

        // ================ Line3<double> inline methods ================= //

        Line3::Line3()
            : Line3Template<double, Vector3>()
        {
        }

        Line3::Line3(const Vector3& point, const Vector3& direction)
            : Line3Template<double, Vector3>(point, direction)
        {
        }

        Line3::Line3(const double pointX, const double pointY, const double pointZ, const double directionX, const double directionY, const double directionZ)
            : Line3Template<double, Vector3>(pointX, pointY, pointZ, directionX, directionY, directionZ)
        {
        }

        Line3F Line3::toFloat() const
        {
            return Line3F((float)this->constPoint().x, (float)this->constPoint().y, (float)this->constPoint().z, (float)this->constDirection().x, (float)this->constDirection().y, (float)this->constDirection().z);
        }

        // ================= Line3<float> inline methods ================= //

        Line3F::Line3F()
            : Line3Template<float, Vector3F>()
        {
        }

        Line3F::Line3F(const Vector3F& point, const Vector3F& direction)
            : Line3Template<float, Vector3F>(point, direction)
        {
        }

        Line3F::Line3F(const float pointX, const float pointY, const float pointZ, const float directionX, const float directionY, const float directionZ)
            : Line3Template<float, Vector3F>(pointX, pointY, pointZ, directionX, directionY, directionZ)
        {
        }

        Line3 Line3F::toDouble() const
        {
            return Line3(this->constPoint().x, this->constPoint().y, this->constPoint().z, this->constDirection().x, this->constDirection().y, this->constDirection().z);
        }

        // ================ Ray3<double> inline methods ================= //

        Ray3::Ray3()
            : Line3Template<double, Vector3>()
        {
        }

        Ray3::Ray3(const Vector3& point, const Vector3& direction)
            : Line3Template<double, Vector3>(point, direction)
        {
        }

        Ray3::Ray3(const double pointX, const double pointY, const double pointZ, const double directionX, const double directionY, const double directionZ)
            : Line3Template<double, Vector3>(pointX, pointY, pointZ, directionX, directionY, directionZ)
        {
        }

        Ray3F Ray3::toFloat() const
        {
            return Ray3F((float)this->constPoint().x, (float)this->constPoint().y, (float)this->constPoint().z, (float)this->constDirection().x, (float)this->constDirection().y, (float)this->constDirection().z);
        }

        // ================= Ray3<float> inline methods ================= //

        Ray3F::Ray3F()
            : Line3Template<float, Vector3F>()
        {
        }

        Ray3F::Ray3F(const Vector3F& point, const Vector3F& direction)
            : Line3Template<float, Vector3F>(point, direction)
        {
        }

        Ray3F::Ray3F(const float pointX, const float pointY, const float pointZ, const float directionX, const float directionY, const float directionZ)
        : Line3Template<float, Vector3F>(pointX, pointY, pointZ, directionX, directionY, directionZ)
        {
        }

        Ray3 Ray3F::toDouble() const
        {
            return Ray3(this->constPoint().x, this->constPoint().y, this->constPoint().z, this->constDirection().x, this->constDirection().y, this->constDirection().z);
        }
    }
}

#endif
