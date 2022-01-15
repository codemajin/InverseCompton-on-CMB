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

#define ICS_JONES_APPROX_C_

//==============================================================================
// Header File Include
//==============================================================================
#include <math.h>
#include "common_physical_const.h"
#include "ics_jones_approx.h"





//******************************************************************************
//! \breif      Calculates the Jones approximation ICS spectrum
//! \remark     Refer to eq.(8) and (9) of [Phys.Rev., 167, 1159]
//! 
//! \callgraph  
//! 
//! \param[in]  efin  : Scattered Photon Energy [eV]
//! \param[in]  einit : Incident Photon Energy [eV]
//! \param[in]  gamma : Electron Lorentz Factor
//! \return     ICS flux on isotropic photon using Jones approximation
//******************************************************************************
F64 IcsJones_CalcFluxIso(const F64 efin, const F64 einit, const F64 gamma)
{
    register F64 flux;
    F64 tmp[4];
    register F64 gamma2, gamma4;
    register F64 q;
    const F64 R0 = CLASIC_ELECTRON_RADIUS;
    const F64 C = LIGHT_SPEED;

    gamma2 = gamma * gamma;
    gamma4 = gamma2 * gamma2;

    //------------------------------------------------------
    // In case of photon energy lossing after the scattering
    //------------------------------------------------------
    if ((efin > IcsJones_MinEnegyIso(einit, gamma)) && (efin < einit)) {
        tmp[0]  = (4.0 * gamma2 * efin) / einit;
        tmp[0] -=  1.0;

        flux  = MATH_PI * R0 * R0 * C * tmp[0];
        flux /= 2.0 * gamma4 * einit;
    }
    //------------------------------------------------------
    // In case of photon energy increasing after the scattering
    //------------------------------------------------------
    else if ((einit <= efin) && (efin < IcsJones_MaxEnegyIso(einit, gamma))) {
        q = efin / (gamma * ELECTRON_REST_ENERGY);
        q = 1.0 - q;
        q *= 4.0 * einit * gamma2;
        q  = efin / q;

        tmp[0]  = 2.0 * q * log(q);

        tmp[1]  = 1.0 + (2.0 * q);
        tmp[1] *= (1.0 - q);

        tmp[2]  = (4.0 * einit * gamma * q) / ELECTRON_REST_ENERGY;

        tmp[3]  = 0.5 * tmp[2] * tmp[2];
        tmp[3] /= 1.0 + tmp[2];
        tmp[3] *= 1.0 - q;

        flux  = tmp[0] + tmp[1] + tmp[3];
        flux *= 2.0 * MATH_PI * R0 * R0 * C;
        flux /= gamma2 * einit;
    }
    else {
        flux = 0.0;
    }

    return flux;
}



//******************************************************************************
//! \breif      Calaulates the minimum energy of scattered photon in case of
//!             Jones approximation and isotropic photon
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  einit - Incident Photon Energy [eV]
//! \param[in]  gamma - Electron Lorentz Factor
//! \return     Minimum energy of scattered photon
//******************************************************************************
F64 IcsJones_MinEnegyIso(const F64 einit, const F64 gamma)
{
    return einit / (4.0 * gamma * gamma);
}



//******************************************************************************
//! \breif      Calaulates the maximum energy of scattered photon in case of
//!             Jones approximation and isotropic photon
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  einit - Incident Photon Energy [eV]
//! \param[in]  gamma - Electron Lorentz Factor
//! \return     Maximum energy of scattered photon
//******************************************************************************
F64 IcsJones_MaxEnegyIso(const F64 einit, const F64 gamma)
{
    F64  emax;
    F64  alpha;

    alpha  = einit / ELECTRON_REST_ENERGY;

    emax = 4.0 * einit * gamma * gamma;
    emax /= 1.0 + 4.0 * alpha * gamma;

    return emax;
}





//******************************************************************************
// End of File
//******************************************************************************
