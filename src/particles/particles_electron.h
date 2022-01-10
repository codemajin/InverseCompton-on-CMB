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

#ifndef PARTICLES_ELECTRON_H_
#define PARTICLES_ELECTRON_H_

#ifdef _cplusplus
extern "C" {
#endif

//==============================================================================
// Header File Include
//==============================================================================
#include "common_typedef.h"



//==============================================================================
// Export Scope Function Prototype
//==============================================================================
/**
 * @brief Calculates the Non-thermal electron flux
 * 
 * @param gamma     : Lorenrz Factor
 * @param norm      : Normalized Parameter
 * @param power     : Power
 * @param gamma_max : Maximum Lorenrz Factor (Cut-off)
 * @return F64      : Electron Flux
 */
extern F64 ParticlesElectron_CalcFlux(const F64 gamma, const F64 norm, const F64 power, const F64 gamma_max);



#ifdef _cplusplus
}
#endif

#endif

//******************************************************************************
// End of File
//******************************************************************************
