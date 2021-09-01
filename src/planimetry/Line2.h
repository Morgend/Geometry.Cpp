/*
 * Copyright 2020-2021 Andrey Pokidov <andrey.pokidov@gmail.com>Line2
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

#ifndef _GEOMETRY_PLANIMETRY_LINE2_H_
#define _GEOMETRY_PLANIMETRY_LINE2_H_

#include "Vector2.h"

namespace geometry
{
    namespace planimetry
    {
        // ==================== Line2 Template header ==================== //

        template <typename FloatType, class VectorType> class Line2Template
        {
        public:
            virtual ~Line2Template();

            inline bool isValid() const;
            inline bool isDegenerate() const;

            inline const VectorType& constPoint() const;
            inline const VectorType& constDirection() const;

            inline VectorType point() const;
            inline VectorType direction() const;

            inline void setValues(const VectorType& point, const VectorType& direction);
            inline void setValues(const FloatType pointX, const FloatType pointY, const FloatType directionX, const FloatType directionY);
            inline void moveAt(const VectorType& distance);
            inline void moveTo(const VectorType& point);
            inline void setDirection(const VectorType& direction);

            inline VectorType pointAt(const FloatType position) const;

        protected:
            inline Line2Template();
            inline Line2Template(const VectorType& point, const VectorType& direction);
            inline Line2Template(const FloatType pointX, const FloatType pointY, const FloatType directionX, const FloatType directionY);

        private:
            VectorType linePoint;
            VectorType lineDirection;
            bool valid;
        };

        // ==================== Line2<double> header ===================== //

        class Line2F;
        class Ray2;
        class Ray2F;

        class Line2 : public Line2Template<double, Vector2>
        {
        public:
            inline Line2();
            inline Line2(const Vector2& point, const Vector2& direction);
            inline Line2(const double pointX, const double pointY, const double directionX, const double directionY);
            virtual ~Line2();

            inline Line2F toFloat() const;
        };

        // ===================== Line2<float> header ===================== //

        class Line2F : public Line2Template<float, Vector2F>
        {
        public:
            inline Line2F();
            inline Line2F(const Vector2F& point, const Vector2F& direction);
            inline Line2F(const float pointX, const float pointY, const float directionX, const float directionY);
            virtual ~Line2F();

            inline Line2 toDouble() const;
        };

        // ===================== Ray2<double> header ===================== //

        class Ray2 : public Line2Template<double, Vector2>
        {
        public:
            inline Ray2();
            inline Ray2(const Vector2& point, const Vector2& direction);
            inline Ray2(const double pointX, const double pointY, const double directionX, const double directionY);
            virtual ~Ray2();

            inline Ray2F toFloat() const;
        };

        // ====================== Ray2<float> header ===================== //

        class Ray2F : public Line2Template<float, Vector2F>
        {
        public:
            inline Ray2F();
            inline Ray2F(const Vector2F& point, const Vector2F& direction);
            inline Ray2F(const float pointX, const float pointY, const float directionX, const float directionY);
            virtual ~Ray2F();

            inline Ray2 toDouble() const;
        };

        // ================ Line2 Template inline methods ================ //

        template <typename FloatType, class VectorType> Line2Template<FloatType, VectorType>::Line2Template()
        {
            this->valid = false;
        }

        template <typename FloatType, class VectorType> Line2Template<FloatType, VectorType>::Line2Template(const VectorType& point, const VectorType& direction)
            : linePoint(point)
            , lineDirection(direction)
        {
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> Line2Template<FloatType, VectorType>::Line2Template(const FloatType pointX, const FloatType pointY, const FloatType directionX, const FloatType directionY)
            : linePoint(pointX, pointY)
            , lineDirection(directionX, directionY)
        {
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> Line2Template<FloatType, VectorType>::~Line2Template()
        {
        }

        template <typename FloatType, class VectorType> bool Line2Template<FloatType, VectorType>::isValid() const
        {
            return this->valid;
        }

        template <typename FloatType, class VectorType> bool Line2Template<FloatType, VectorType>::isDegenerate() const
        {
            return !this->valid;
        }

        template <typename FloatType, class VectorType> const VectorType& Line2Template<FloatType, VectorType>::constPoint() const
        {
            return this->linePoint;
        }

        template <typename FloatType, class VectorType> const VectorType& Line2Template<FloatType, VectorType>::constDirection() const
        {
            return this->lineDirection;
        }

        template <typename FloatType, class VectorType> VectorType Line2Template<FloatType, VectorType>::point() const
        {
            return this->linePoint;
        }

        template <typename FloatType, class VectorType> VectorType Line2Template<FloatType, VectorType>::direction() const
        {
            return this->lineDirection;
        }

        template <typename FloatType, class VectorType> void Line2Template<FloatType, VectorType>::setValues(const VectorType& point, const VectorType& direction)
        {
            this->linePoint = point;
            this->lineDirection = direction;
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> void Line2Template<FloatType, VectorType>::setValues(const FloatType pointX, const FloatType pointY, const FloatType directionX, const FloatType directionY)
        {
            this->linePoint.setValues(pointX, pointY);
            this->linePoint.setValues(directionX, directionY);
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> void Line2Template<FloatType, VectorType>::moveAt(const VectorType& distance)
        {
            this->linePoint += distance;
        }

        template <typename FloatType, class VectorType> void Line2Template<FloatType, VectorType>::moveTo(const VectorType& point)
        {
            this->linePoint = point;
        }

        template <typename FloatType, class VectorType> void Line2Template<FloatType, VectorType>::setDirection(const VectorType& direction)
        {
            this->lineDirection = direction;
            this->valid = this->lineDirection.normalize();
        }

        template <typename FloatType, class VectorType> VectorType Line2Template<FloatType, VectorType>::pointAt(const FloatType position) const
        {
            return VectorType(this->linePoint.x + this->lineDirection.x * position, this->linePoint.y + this->lineDirection.y * position);
        }

        // ================ Line2<double> inline methods ================= //

        Line2::Line2()
            : Line2Template<double, Vector2>()
        {
        }

        Line2::Line2(const Vector2& point, const Vector2& direction)
            : Line2Template<double, Vector2>(point, direction)
        {
        }

        Line2::Line2(const double pointX, const double pointY, const double directionX, const double directionY)
            : Line2Template<double, Vector2>(pointX, pointY, directionX, directionY)
        {
        }

        Line2F Line2::toFloat() const
        {
            return Line2F((float)this->constPoint().x, (float)this->constPoint().y, (float)this->constDirection().x, (float)this->constDirection().y);
        }

        // ================= Line2<float> inline methods ================= //

        Line2F::Line2F()
            : Line2Template<float, Vector2F>()
        {
        }

        Line2F::Line2F(const Vector2F& point, const Vector2F& direction)
            : Line2Template<float, Vector2F>(point, direction)
        {
        }

        Line2F::Line2F(const float pointX, const float pointY, const float directionX, const float directionY)
            : Line2Template<float, Vector2F>(pointX, pointY, directionX, directionY)
        {
        }

        Line2 Line2F::toDouble() const
        {
            return Line2(this->constPoint().x, this->constPoint().y, this->constDirection().x, this->constDirection().y);
        }

        // ================ Ray2<double> inline methods ================= //

        Ray2::Ray2()
            : Line2Template<double, Vector2>()
        {
        }

        Ray2::Ray2(const Vector2& point, const Vector2& direction)
            : Line2Template<double, Vector2>(point, direction)
        {
        }

        Ray2::Ray2(const double pointX, const double pointY, const double directionX, const double directionY)
            : Line2Template<double, Vector2>(pointX, pointY, directionX, directionY)
        {
        }

        Ray2F Ray2::toFloat() const
        {
            return Ray2F((float)this->constPoint().x, (float)this->constPoint().y, (float)this->constDirection().x, (float)this->constDirection().y);
        }

        // ================= Ray2<float> inline methods ================= //

        Ray2F::Ray2F()
            : Line2Template<float, Vector2F>()
        {
        }

        Ray2F::Ray2F(const Vector2F& point, const Vector2F& direction)
            : Line2Template<float, Vector2F>(point, direction)
        {
        }

        Ray2F::Ray2F(const float pointX, const float pointY, const float directionX, const float directionY)
            : Line2Template<float, Vector2F>(pointX, pointY, directionX, directionY)
        {
        }

        Ray2 Ray2F::toDouble() const
        {
            return Ray2(this->constPoint().x, this->constPoint().y, this->constDirection().x, this->constDirection().y);
        }
    }
}

#endif
