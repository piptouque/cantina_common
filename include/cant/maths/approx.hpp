//
// Created by binabik on 13/09/2020.
//

#ifndef CANTINA_MATHS_APPROX_HPP
#define CANTINA_MATHS_APPROX_HPP

#pragma once

#include <cant/common/types.hpp>

#include <cant/common/CantinaException.hpp>

#include <cant/common/macro.hpp>
CANTINA_MATHS_NAMESPACE_BEGIN

CANT_CONSTEXPR type_i c_defaultUlp = 2;

// approx in lower case to pretend it's a namespace
// although the template arguments kind of give it away.
template <typename T, int ulp = c_defaultUlp>
class approx
{
   public:
    /** -- methods -- **/
    CANT_NODISCARD static bool
      equal(T a, T b);

    /*
     * All comparisions are ... or equal
     * approximation implies giving up on strict ordering.
     */
    CANT_NODISCARD static bool
      greater(T a, T b);
    CANT_NODISCARD static bool
      lower(T a, T b);

    CANT_NODISCARD static bool
      inRange(T a, T b, T val);

    template <typename Scalar_T>
    CANT_NODISCARD static T
      barycentre(T a, T b, Scalar_T lambda);

   private:
    /** -- methods -- **/
    CANT_NODISCARD static T
      errorMargin(T a, T b);
};

CANTINA_MATHS_NAMESPACE_END
#include <cant/common/undef_macro.hpp>

#include <cant/maths/approx.inl>

#endif  // CANTINA_MATHS_APPROX_HPP
