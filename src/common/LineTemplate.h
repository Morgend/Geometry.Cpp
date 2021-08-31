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

#ifndef _GEOMETRY_COMMON_LINE_TEMPLATE_H_
#define _GEOMETRY_COMMON_LINE_TEMPLATE_H_

namespace geometry
{
    namespace common
    {
        template<class VectorType> class LineTemplate
        {
        public:
            virtual ~LineTemplate();

            inline bool isValid() const;

            inline const VectorType& constBasic() const;
            inline const VectorType& constDirection() const;

            inline VectorType basic() const;
            inline VectorType direction() const;

        protected:
            VectorType linePoint;
            VectorType lineDirection;
            bool valid;
        };

        template<class VectorType> LineTemplate<VectorType>::~LineTemplate()
        {
        }

        template<class VectorType> bool LineTemplate<VectorType>::isValid() const
        {
            return this->valid;
        }

        template<class VectorType> const VectorType& LineTemplate<VectorType>::constBasic() const
        {
            return this->linePoint;
        }

        template<class VectorType> const VectorType& LineTemplate<VectorType>::constDirection() const
        {
            return this->lineDirection;
        }

        template<class VectorType> VectorType LineTemplate<VectorType>::basic() const
        {
            return this->linePoint;
        }

        template<class VectorType> VectorType LineTemplate<VectorType>::direction() const
        {
            return this->lineDirection;
        }
    }
}

#endif
