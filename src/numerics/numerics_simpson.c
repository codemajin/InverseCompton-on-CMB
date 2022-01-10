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

#define NUMERICS_SIMPSON_C_

//==============================================================================
// Header File Include
//==============================================================================
#include "numerics_simpson.h"





//******************************************************************************
//! \breif      Numerical integration using Simpson rule
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  integrand : Function Pointer (Integrand)
//! \param[in]  range     : Integration Range
//! \return     Integrated value
//******************************************************************************
F64 NumericsSimpson_Integrate(INTEGRAND integrand, const INTEGRATION_RANGE *range)
{
    S32 i;
    F64 x, dx, dxp2, dxp6;
    F64 integrated = 0.0;
    F64 x0, x1, x2;
    
    dx = (range->Upper - range->Lower) / (F64)range->Iteration;
    dxp2 = dx / 2.0;
    dxp6 = dx / 6.0;
    
#ifdef _OPENMP
    #pragma omp parallel for reduction(+:integrated) private(x, x0, x1, x2)
#endif
    for (i = 0; i < range->Iteration; i++) {
        x  = range->Lower + dx * (F64)i;
        x0 = integrand(x);
        x1 = 4.0 * integrand(x + dxp2);
        x2 = integrand(x + dx);
        
        integrated += dxp6 * (x0 + x1 + x2);
    }
    
    return integrated;
}





//******************************************************************************
// End of File
//******************************************************************************
