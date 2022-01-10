//******************************************************************************
// MIT License
//
// Copyright (c) 2022 Tomonobu Inayama
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//******************************************************************************

#ifndef NUMERICS_TRAPEZOIDAL_H_
#define NUMERICS_TRAPEZOIDAL_H_

#ifdef _cplusplus
extern "C" {
#endif

//==============================================================================
// Header File Include
//==============================================================================
#include "common_typedef.h"
#include "numerics_integration.h"



//==============================================================================
// Export Scope Function Prototype
//==============================================================================
/**
 * @brief           Numerical integration using trapezoidal rule
 * 
 * @param integrand Function Pointer (Integrand)
 * @param range     Integration Range
 * @return F64      Integrated value
 */
extern F64 NumericsTrapezoidal_Inetegrate(INTEGRAND integrand, const INTEGRATION_RANGE *range);

/**
 * @brief           Numerical multiple integration using trapezoidal rule
 * 
 * @param integrand Function Pointer (Integrand)
 * @param range_x   Integration Range for X-axis
 * @param range_y   Integration Range for Y-axis
 * @return F64      Integrated value
 */
extern F64 NumericsTrapezoidal_Inetegrate2d(MULTIPLE_INTEGRAND  integrand, const INTEGRATION_RANGE *range_x, const INTEGRATION_RANGE *range_y);

/**
 * @brief           Numerical triple integration using trapezoidal rule
 * 
 * @param integrand Function Pointer (Integrand)
 * @param range_x   Integration Range for X-axis
 * @param range_y   Integration Range for Y-axis
 * @param range_z   Integration Range for Z-axis
 * @return F64      Integrated value
 */
extern F64 NumericsTrapezoidal_Inetegrate3d(TRIPLE_INTEGRAND integrand, const INTEGRATION_RANGE *range_x, const INTEGRATION_RANGE *range_y, const INTEGRATION_RANGE *range_z);



#ifdef _cplusplus
}
#endif

#endif

//******************************************************************************
// End of File
//******************************************************************************
