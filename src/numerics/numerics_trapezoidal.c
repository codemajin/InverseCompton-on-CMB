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

#define NUMERICS_TRAPEZOIDAL_C_

//==============================================================================
// Header File Include
//==============================================================================
#include <math.h>
#include "numerics_trapezoidal.h"





//******************************************************************************
//! \breif      Numerical integration using trapezoidal rule
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  integrand : Function Pointer (Integrand)
//! \param[in]  range     : Integration Range
//! \return     Integrated value
//******************************************************************************
F64 NumericsTrapezoidal_Inetegrate(INTEGRAND integrand, const INTEGRATION_RANGE *range)
{
    register F64 x, dx;
    register S32 i;
    register F64 integrated = 0.0;

    dx = (range->Upper - range->Lower) / (F64)range->Iteration;

    for (i = 0, x = range->Lower; i < range->Iteration; i++, x += dx) {
        integrated += (integrand(x) + integrand(x + dx)) * dx * 0.50;
    }

    return integrated;
}



//******************************************************************************
//! \breif      Numerical multiple integration using trapezoidal rule
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  integrand : Function Pointer (Integrand)
//! \param[in]  range_x   : Integration Range for X-axis
//! \param[in]  range_y   : Integration Range for Y-axis
//! \return     Integrated value
//******************************************************************************
F64 NumericsTrapezoidal_Inetegrate2d(MULTIPLE_INTEGRAND  integrand, const INTEGRATION_RANGE *range_x, const INTEGRATION_RANGE *range_y)
{
    register F64 x, y, dx, dy;
    register F64 logx, logy;
    register F64 dlogx, dlogy;
    register F64 logx_lower, logx_upper, logy_lower, logy_upper;
    register F64 sum, integrated;

    logx_lower = log10(range_x->Lower);
    logx_upper = log10(range_x->Upper);
    logy_lower = log10(range_y->Lower);
    logy_upper = log10(range_y->Upper);

    dlogx = (logx_upper - logx_lower) / (F64)range_x->Iteration;
    dlogy = (logy_upper - logy_lower) / (F64)range_y->Iteration;

    for (integrated = 0.0, logx = logx_lower; logx <= logx_upper; logx += dlogx) {
        x = pow(10.0, logx);
        dx = pow(10.0, (logx + dlogx)) - x;

        for (sum = 0.0, logy = logy_lower; logy <= logy_upper; logy += dlogy) {
            y  = pow(10.0, logy);
            dy = pow(10.0, (logy + dlogy)) - y;

            sum += (integrand(x, y) + integrand(x + dx, y + dy)) * dx * dy * 0.50;
        }
        integrated += sum;
    }

    return integrated;
}



//******************************************************************************
//! \breif      Numerical triple integration using trapezoidal rule
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  integrand : Function Pointer (Integrand)
//! \param[in]  range_x   : Integration Range for X-axis
//! \param[in]  range_y   : Integration Range for Y-axis
//! \param[in]  range_z   : Integration Range for Z-axis
//! \return     Integrated value
//******************************************************************************
F64 NumericsTrapezoidal_Inetegrate3d(TRIPLE_INTEGRAND integrand, const INTEGRATION_RANGE *range_x, const INTEGRATION_RANGE *range_y, const INTEGRATION_RANGE *range_z)
{
    register    F64   x, y, z, dx, dy, dz;
    register    F64   sumy, sumz, integrated;

    dx = (range_x->Upper - range_x->Lower) / (F64)range_x->Iteration;
    dy = (range_y->Upper - range_y->Lower) / (F64)range_y->Iteration;
    dz = (range_z->Upper - range_z->Lower) / (F64)range_z->Iteration;

    for (integrated = 0.0, x = range_x->Lower; x < range_x->Upper; x += dx) {
        for (sumy = 0.0, y = range_y->Lower; y <= range_y->Upper; y += dy) {
            for (sumz = 0.0, z = range_z->Lower; z <= range_z->Upper; z += dz) {
                sumz += (integrand(x, y, z) + integrand(x + dx, y + dy, z + dz)) * dx * dy * dz * 0.50;
            }
            sumy += sumz;
        }
        integrated += sumy;
    }

    return integrated;
}





//******************************************************************************
// End of File
//******************************************************************************
