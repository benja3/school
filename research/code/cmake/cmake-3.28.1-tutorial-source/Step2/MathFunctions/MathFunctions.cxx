#include "MathFunctions.h"
#include <math.h>

#ifdef USE_MYMATH
  #include "mysqrt.h"
#endif

// TODO 11: include cmath

// TODO 10: Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH
#include "mysqrt.h"

namespace mathfunctions {
double sqrt(double x)
{
  // TODO 9: If USE_MYMATH is defined, use detail::mysqrt.
  // Otherwise, use std::sqrt.

  #ifdef USE_MYMATH
    return detail::mysqrt(x);
  #else
    return std::sqrt(x);
  #endif

}
}
