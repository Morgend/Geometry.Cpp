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

#ifndef _GEOMETRY_PLANIMETRY_TRIANGLE2_H_
#define _GEOMETRY_PLANIMETRY_TRIANGLE2_H_

#include "Vector2.h"

namespace geometry
{
    namespace planimetry
    {
        // ================== Triangle2 Template header ================== //

        template<typename FloatType, class VectorType> class BasicTriangle2Template
        {
        public:
            VectorType A, B, C;

            virtual ~BasicTriangle2Template();

            inline VectorType vectorAB() const;
            inline VectorType vectorBA() const;
            inline VectorType vectorBC() const;
            inline VectorType vectorCB() const;
            inline VectorType vectorAC() const;
            inline VectorType vectorCA() const;

            inline FloatType square() const;

            inline VectorType getMedianCentre() const;

            inline void setValuesOf(const BasicTriangle2Template<FloatType, VectorType>& triangle);
            inline void setValuesOf(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC);

        protected:
            BasicTriangle2Template();
            BasicTriangle2Template(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC);
            BasicTriangle2Template(const FloatType xA, const FloatType yA, const FloatType xB, const FloatType yB, const FloatType xC, const FloatType yC);
        };

        // ================== Triangle2<double> header =================== //

        class Triangle2F;

        class Triangle2 : public BasicTriangle2Template<double, Vector2>
        {
        public:
            inline Triangle2();
            inline Triangle2(const Triangle2F& triangle);
            inline Triangle2(const Vector2& vertexA, const Vector2& vertexB, const Vector2& vertexC);
            inline Triangle2(const double xA, const double yA, const double xB, const double yB, const double xC, const double yC);
            virtual ~Triangle2();

            inline void setValuesOf(const Triangle2F& triangle);
            inline void setValuesOf(const Vector2F& vertexA, const Vector2F& vertexB, const Vector2F& vertexC);

            inline Triangle2F toFloat() const;
        };

        // =================== Triangle2<float> header =================== //

        class Triangle2F : public BasicTriangle2Template<float, Vector2F>
        {
        public:
            inline Triangle2F();
            inline Triangle2F(const Triangle2& triangle);
            inline Triangle2F(const Vector2F& vertexA, const Vector2F& vertexB, const Vector2F& vertexC);
            inline Triangle2F(const float xA, const float yA, const float xB, const float yB, const float xC, const float yC);
            virtual ~Triangle2F();

            inline void setValuesOf(const Triangle2& triangle);
            inline void setValuesOf(const Vector2& vertexA, const Vector2& vertexB, const Vector2& vertexC);

            inline Triangle2 toDouble() const;
        };

        // ============== Triangle2 Template inline methods ============== //

        template<typename FloatType, class VectorType> BasicTriangle2Template<FloatType, VectorType>::BasicTriangle2Template()
        {
        }

        template<typename FloatType, class VectorType> BasicTriangle2Template<FloatType, VectorType>::BasicTriangle2Template(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC)
            : A(vertexA), B(vertexB), C(vertexC)
        {
        }

        template<typename FloatType, class VectorType> BasicTriangle2Template<FloatType, VectorType>::BasicTriangle2Template(const FloatType xA, const FloatType yA, const FloatType xB, const FloatType yB, const FloatType xC, const FloatType yC)
            : A(xA, yA), B(xB, yB), C(xC, yC)
        {
        }

        template<typename FloatType, class VectorType> BasicTriangle2Template<FloatType, VectorType>::~BasicTriangle2Template()
        {
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::vectorAB() const
        {
            return B - A;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::vectorBA() const
        {
            return A - B;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::vectorBC() const
        {
            return C - B;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::vectorCB() const
        {
            return B - C;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::vectorAC() const
        {
            return C - A;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::vectorCA() const
        {
            return A - C;
        }

        template<typename FloatType, class VectorType> FloatType BasicTriangle2Template<FloatType, VectorType>::square() const
        {
            double vectorMultiplication = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

            return (vectorMultiplication >= 0 ? vectorMultiplication : -vectorMultiplication) / 2;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle2Template<FloatType, VectorType>::getMedianCentre() const
        {
            return VectorType((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3);
        }

        template<typename FloatType, class VectorType> void BasicTriangle2Template<FloatType, VectorType>::setValuesOf(const BasicTriangle2Template<FloatType, VectorType>& triangle)
        {
            this->A = triangle.A;
            this->B = triangle.B;
            this->C = triangle.C;
        }

        template<typename FloatType, class VectorType> void BasicTriangle2Template<FloatType, VectorType>::setValuesOf(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC)
        {
            this->A = vertexA;
            this->B = vertexB;
            this->C = vertexC;
        }

        // ============== Triangle2<double> inline methods =============== //

        Triangle2::Triangle2()
        {
        }

        Triangle2::Triangle2(const Triangle2F& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        Triangle2::Triangle2(const Vector2& vertexA, const Vector2& vertexB, const Vector2& vertexC)
            : BasicTriangle2Template<double, Vector2>(vertexA, vertexB, vertexC)
        {
        }

        Triangle2::Triangle2(const double xA, const double yA, const double xB, const double yB, const double xC, const double yC)
            : BasicTriangle2Template<double, Vector2>(xA, yA, xB, yB, xC, yC)
        {
        }

        void Triangle2::setValuesOf(const Triangle2F& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        void Triangle2::setValuesOf(const Vector2F& vertexA, const Vector2F& vertexB, const Vector2F& vertexC)
        {
            this->A.setValuesOf(vertexA);
            this->B.setValuesOf(vertexB);
            this->C.setValuesOf(vertexC);
        }

        Triangle2F Triangle2::toFloat() const
        {
            Triangle2F result;

            result.A.x = (float)this->A.x;
            result.A.y = (float)this->A.y;

            result.B.x = (float)this->B.x;
            result.B.y = (float)this->B.y;

            result.C.x = (float)this->C.x;
            result.C.y = (float)this->C.y;

            return result;
        }

        // =============== Triangle2<float> inline methods =============== //

        Triangle2F::Triangle2F()
        {
        }

        Triangle2F::Triangle2F(const Triangle2& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        Triangle2F::Triangle2F(const Vector2F& vertexA, const Vector2F& vertexB, const Vector2F& vertexC)
            : BasicTriangle2Template<float, Vector2F>(vertexA, vertexB, vertexC)
        {
        }

        Triangle2F::Triangle2F(const float xA, const float yA, const float xB, const float yB, const float xC, const float yC)
            : BasicTriangle2Template<float, Vector2F>(xA, yA, xB, yB, xC, yC)
        {
        }

        void Triangle2F::setValuesOf(const Triangle2& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        void Triangle2F::setValuesOf(const Vector2& vertexA, const Vector2& vertexB, const Vector2& vertexC)
        {
            this->A.setValuesOf(vertexA);
            this->B.setValuesOf(vertexB);
            this->C.setValuesOf(vertexC);
        }

        Triangle2 Triangle2F::toDouble() const
        {
            Triangle2 result;

            result.A.x = this->A.x;
            result.A.y = this->A.y;

            result.B.x = this->B.x;
            result.B.y = this->B.y;

            result.C.x = this->C.x;
            result.C.y = this->C.y;

            return result;
        }

    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_PLANIMETRY_TRIANGLE2_H_ */
