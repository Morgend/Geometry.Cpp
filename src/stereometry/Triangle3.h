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

#ifndef _GEOMETRY_STEREOMETRY_TRIANGLE3_H_
#define _GEOMETRY_STEREOMETRY_TRIANGLE3_H_

#include "Vector3.h"

namespace geometry
{
    namespace stereometry
    {
        // ================== Triangle3 Template header ================== //

        template<typename FloatType, class VectorType> class BasicTriangle3Template
        {
        public:
            VectorType A, B, C;

            virtual ~BasicTriangle3Template();

            inline VectorType vectorAB() const;
            inline VectorType vectorBA() const;
            inline VectorType vectorBC() const;
            inline VectorType vectorCB() const;
            inline VectorType vectorAC() const;
            inline VectorType vectorCA() const;

            inline FloatType square() const;

            inline VectorType getMedianCentre() const;

            inline void setValuesOf(const BasicTriangle3Template<FloatType, VectorType>& triangle);
            inline void setValuesOf(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC);

        protected:
            BasicTriangle3Template();
            BasicTriangle3Template(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC);
        };

        // ================== Triangle3<double> header =================== //

        class Triangle3F;

        class Triangle3 : public BasicTriangle3Template<double, Vector3>
        {
        public:
            inline Triangle3();
            inline Triangle3(const Triangle3F& triangle);
            inline Triangle3(const Vector3& vertexA, const Vector3& vertexB, const Vector3& vertexC);
            virtual ~Triangle3();

            inline void setValuesOf(const Triangle3F& triangle);
            inline void setValuesOf(const Vector3F& vertexA, const Vector3F& vertexB, const Vector3F& vertexC);

            inline Triangle3F toFloat() const;
        };

        // =================== Triangle3<float> header =================== //

        class Triangle3F : public BasicTriangle3Template<float, Vector3F>
        {
        public:
            inline Triangle3F();
            inline Triangle3F(const Triangle3& triangle);
            inline Triangle3F(const Vector3F& vertexA, const Vector3F& vertexB, const Vector3F& vertexC);
            virtual ~Triangle3F();

            inline void setValuesOf(const Triangle3& triangle);
            inline void setValuesOf(const Vector3& vertexA, const Vector3& vertexB, const Vector3& vertexC);

            inline Triangle3 toDouble() const;
        };

        // ============== Triangle3 Template inline methods ============== //

        template<typename FloatType, class VectorType> BasicTriangle3Template<FloatType, VectorType>::BasicTriangle3Template()
        {
        }

        template<typename FloatType, class VectorType> BasicTriangle3Template<FloatType, VectorType>::BasicTriangle3Template(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC)
            : A(vertexA), B(vertexB), C(vertexC)
        {
        }

        template<typename FloatType, class VectorType> BasicTriangle3Template<FloatType, VectorType>::~BasicTriangle3Template()
        {
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::vectorAB() const
        {
            return B - A;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::vectorBA() const
        {
            return A - B;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::vectorBC() const
        {
            return C - B;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::vectorCB() const
        {
            return B - C;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::vectorAC() const
        {
            return C - A;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::vectorCA() const
        {
            return A - C;
        }

        template<typename FloatType, class VectorType> FloatType BasicTriangle3Template<FloatType, VectorType>::square() const
        {
            return ((B - A).vector(C - A)).module() / 2;
        }

        template<typename FloatType, class VectorType> VectorType BasicTriangle3Template<FloatType, VectorType>::getMedianCentre() const
        {
            return VectorType((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3, (A.z + B.z + C.z) / 3);
        }

        template<typename FloatType, class VectorType> void BasicTriangle3Template<FloatType, VectorType>::setValuesOf(const BasicTriangle3Template<FloatType, VectorType>& triangle)
        {
            this->A.x = triangle.A.x;
            this->A.y = triangle.A.y;
            this->A.z = triangle.A.z;

            this->B.x = triangle.B.x;
            this->B.y = triangle.B.y;
            this->B.z = triangle.B.z;

            this->C.x = triangle.C.x;
            this->C.y = triangle.C.y;
            this->C.z = triangle.C.z;
        }

        template<typename FloatType, class VectorType> void BasicTriangle3Template<FloatType, VectorType>::setValuesOf(const VectorType& vertexA, const VectorType& vertexB, const VectorType& vertexC)
        {
            this->A.x = vertexA.x;
            this->A.y = vertexA.y;
            this->A.z = vertexA.z;

            this->B.x = vertexB.x;
            this->B.y = vertexB.y;
            this->B.z = vertexB.z;

            this->C.x = vertexC.x;
            this->C.y = vertexC.y;
            this->C.z = vertexC.z;
        }

        // ============== Triangle3<double> inline methods =============== //

        Triangle3::Triangle3()
        {
        }

        Triangle3::Triangle3(const Triangle3F& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        Triangle3::Triangle3(const Vector3& vertexA, const Vector3& vertexB, const Vector3& vertexC)
            : BasicTriangle3Template<double, Vector3>(vertexA, vertexB, vertexC)
        {
        }

        void Triangle3::setValuesOf(const Triangle3F& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        void Triangle3::setValuesOf(const Vector3F& vertexA, const Vector3F& vertexB, const Vector3F& vertexC)
        {
            this->A.setValuesOf(vertexA);
            this->B.setValuesOf(vertexB);
            this->C.setValuesOf(vertexC);
        }

        Triangle3F Triangle3::toFloat() const
        {
            Triangle3F result;

            result.A.x = (float)this->A.x;
            result.A.y = (float)this->A.y;

            result.B.x = (float)this->B.x;
            result.B.y = (float)this->B.y;

            result.C.x = (float)this->C.x;
            result.C.y = (float)this->C.y;

            return result;
        }

        // =============== Triangle3<float> inline methods =============== //

        Triangle3F::Triangle3F()
        {
        }

        Triangle3F::Triangle3F(const Triangle3& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        Triangle3F::Triangle3F(const Vector3F& vertexA, const Vector3F& vertexB, const Vector3F& vertexC)
            : BasicTriangle3Template<float, Vector3F>(vertexA, vertexB, vertexC)
        {
        }

        void Triangle3F::setValuesOf(const Triangle3& triangle)
        {
            this->A.setValuesOf(triangle.A);
            this->B.setValuesOf(triangle.B);
            this->C.setValuesOf(triangle.C);
        }

        void Triangle3F::setValuesOf(const Vector3& vertexA, const Vector3& vertexB, const Vector3& vertexC)
        {
            this->A.setValuesOf(vertexA);
            this->B.setValuesOf(vertexB);
            this->C.setValuesOf(vertexC);
        }

        Triangle3 Triangle3F::toDouble() const
        {
            Triangle3 result;

            result.A.x = this->A.x;
            result.A.y = this->A.y;
            result.A.z = this->A.z;

            result.B.x = this->B.x;
            result.B.y = this->B.y;
            result.B.z = this->B.z;

            result.C.x = this->C.x;
            result.C.y = this->C.y;
            result.C.z = this->C.z;

            return result;
        }
    } /* namespace planimetry */
} /* namespace geometry */

#endif /* _GEOMETRY_STEREOMETRY_TRIANGLE3_H_ */
