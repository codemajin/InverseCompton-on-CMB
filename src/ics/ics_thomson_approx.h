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

#ifndef ICS_THOMSON_APPROX_H_
#define ICS_THOMSON_APPROX_H_

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
 * @brief       Calculates the Thomson approximation ICS spectrum
 * 
 * @param efin  Scattered Photon Energy [eV]
 * @param einit Incident Photon Energy [eV]
 * @param gamma Electron Lorentz Factor
 * @return F128  ICS flux on isotropic photon using Thomson approximation
 */
extern F128 IcsThomson_CalcFluxIso(const F128 efin, const F128 einit, const F128 gamma);

/**
 * @brief       Calaulates the minimum energy of scattered photon in case of
 *              Thomson approximation and isotropic photon
 * @param einit Incident Photon Energy [eV]
 * @param gamma Electron Lorentz Factor
 * @return F128  Minimum energy of scattered photon
 */
extern F128 IcsThomson_MinEnergyIso(const F128 einit, const F128 gamma);

/**
 * @brief       Calaulates the maximum energy of scattered photon in case of
 *              Thomson approximation and isotropic photon
 * @param einit Incident Photon Energy [eV]
 * @param gamma Electron Lorentz Factor
 * @return F128  Maximum energy of scattered photon
 */
extern F128 IcsThomson_MaxEnergyIso(const F128 einit, const F128 gamma);



#ifdef _cplusplus
}
#endif

#endif

//******************************************************************************
// End of File
//******************************************************************************
