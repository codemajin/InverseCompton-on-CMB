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

#ifndef COMMON_PHYSICAL_CONST_H_
#define COMMON_PHYSICAL_CONST_H_

#ifdef _cplusplus
extern "C" {
#endif

//==============================================================================
// Header File Include
//==============================================================================
#include "common_typedef.h"



//==============================================================================
// Export Scope Variables
//==============================================================================
//----------------------------------------------------------
// Common Physical Constants
//----------------------------------------------------------
extern const F64 LIGHT_SPEED;                               //!< Light Speed [cm/s]
extern const F64 BOLTZMANN_CONST;                           //!< Boltzmann Constant [eV/K]
extern const F64 PLANK_CONST;                               //!< Plank Constant [eV s]
extern const F64 CLASIC_ELECTRON_RADIUS;                    //!< Classical Electron Radius [cm]
extern const F64 ELECTRON_REST_ENERGY;                      //!< Electron Rest Energy [eV]


#ifdef _cplusplus
}
#endif

#endif

//******************************************************************************
// End of File
//******************************************************************************
