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

#ifndef NUMERICS_INTEGRATION_H_
#define NUMERICS_INTEGRATION_H_

#ifdef _cplusplus
extern "C" {
#endif

//==============================================================================
// Header File Include
//==============================================================================
#include "common_typedef.h"



//==============================================================================
// Type Definition
//==============================================================================
//----------------------------------------------------------
//! Integration Range
//----------------------------------------------------------
typedef struct integration_range_t {
    F64         Lower;          //!< Lower
    F64         Upper;          //!< Upper
    U32         Iteration;      //!< Iteration Count
}INTEGRATION_RANGE;

//----------------------------------------------------------
//! Integrand
//----------------------------------------------------------
typedef F64 (*INTEGRAND)(const F64 x);

//----------------------------------------------------------
//! Integrand for multiple integration
//----------------------------------------------------------
typedef F64 (*MULTIPLE_INTEGRAND)(const F64 x, const F64 y);

//----------------------------------------------------------
//! Integrand for triple integration
//----------------------------------------------------------
typedef F64 (*TRIPLE_INTEGRAND)(const F64 x, const F64 y, const F64 z); 



#ifdef _cplusplus
}
#endif

#endif

//******************************************************************************
// End of File
//******************************************************************************
