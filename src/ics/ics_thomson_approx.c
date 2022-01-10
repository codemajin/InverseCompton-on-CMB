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

#define ICS_THOMSON_APPROX_C_

//==============================================================================
// Header File Include
//==============================================================================
#include <math.h>
#include "common_physical_const.h"
#include "ics_thomson_approx.h"



//==============================================================================
// File Scope Function Prototype
//==============================================================================
static inline F64 toBeta(const F64 gamma);





//******************************************************************************
//! \breif      Calculates the Thomson approximation ICS spectrum
//! \remark     1) Refer to eq.(23a) and (23b) of [arXiv:astro-ph/9606126v1]
//!             2) Number deinsity of photon is 1.0 (n0 = 1.0)
//! 
//! \callgraph  
//! 
//! \param[in]  efin  - Scattered Photon Energy [eV]
//! \param[in]  einit - Incident Photon Energy [eV]
//! \param[in]  gamma - Electron Lorentz Factor
//! \return     ICS flux on isotropic photon using Thomson approximation
//******************************************************************************
F64 IcsThomson_CalcFluxIso(const F64 efin, const F64 einit, const F64 gamma)
{
    register F64 flux;
    F64 tmp[5];
    register F64 beta, beta2, beta6, gamma2, gamma4;
    const F64 R0 = CLASIC_ELECTRON_RADIUS;
    const F64 C = LIGHT_SPEED;
    
    beta = toBeta(gamma);
    beta2 = beta * beta;
    beta6 = beta2 * beta2 * beta2;
    gamma2 = gamma * gamma;
    gamma4 = gamma2 * gamma2;
    
    //------------------------------------------------------
    // In case of photon energy lossing after the scattering
    //------------------------------------------------------
    if ((efin >= IcsThomson_MinEnergyIso(einit, gamma)) && (efin < einit)) {
        tmp[0]  = (beta * (beta2 + 3.0)) + ((9.0 - 4.0 * beta2) / gamma2);
        tmp[0] *= (1.0 + beta) * efin / einit;
        
        tmp[1]  = (beta * (beta2 + 3.0)) - ((9.0 - 4.0 * beta2) / gamma2);
        tmp[1] *= (1.0 - beta);
        
        tmp[2]  = log((efin * (1.0 + beta)) / (einit * (1.0 - beta)));
        tmp[2] *= (3.0 - beta2) * (1.0 + (efin / einit));
        tmp[2] *= (2.0 / gamma2);
        
        tmp[3]  = einit / (gamma4 * efin);
        
        tmp[4]  = (efin * efin) / (gamma4 * einit * einit);
        
        flux  = tmp[0] + tmp[1] - tmp[2] - tmp[3] + tmp[4];
        flux *= MATH_PI * R0 * R0 * C;
        flux /= 4.0 * beta6 * gamma2 * einit;
    }
    //------------------------------------------------------
    // In case of photon energy increasing after the scattering
    //------------------------------------------------------
    else if ((einit <= efin) && (efin <= IcsThomson_MaxEnergyIso(einit, gamma))) {
        tmp[0]  = (beta * (beta2 + 3.0)) + ((9.0 - 4.0 * beta2) / gamma2);
        tmp[0] *= (1.0 + beta);
        
        tmp[1]  = (beta * (beta2 + 3.0)) - ((9.0 - 4.0 * beta2) / gamma2);
        tmp[1] *= (1.0 - beta) * efin / einit;
        
        tmp[2]  = log((einit * (1.0 + beta)) / (efin * (1.0 - beta)));
        tmp[2] *= (3.0 - beta2) * (1.0 + (efin / einit));
        tmp[2] *= (2.0 / gamma2);
        
        tmp[3]  = einit / (gamma4 * efin);
        
        tmp[4]  = (efin * efin) / (gamma4 * einit * einit);
        
        flux  = tmp[0] + tmp[1] - tmp[2] + tmp[3] - tmp[4];
        flux *= MATH_PI * R0 * R0 * C;
        flux /= 4.0 * beta6 * gamma2 * einit;
    }
    else {
        flux = 0.0;
    }
    
    return flux;
}



//******************************************************************************
//! \breif      Calaulates the minimum energy of scattered photon in case of
//!             Thomson approximation and isotropic photon
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  einit - Incident Photon Energy [eV]
//! \param[in]  gamma - Electron Lorentz Factor
//! \return     Minimum energy of scattered photon
//******************************************************************************
F64 IcsThomson_MinEnergyIso(const F64 einit, const F64 gamma)
{
    F64 emin;
    F64 beta;

    beta  = toBeta(gamma);
    emin  = einit * (1.0 - beta) / (1.0 + beta);

    return emin;
}



//******************************************************************************
//! \breif      Calaulates the maximum energy of scattered photon in case of
//!             Thomson approximation and isotropic photon
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  einit - Incident Photon Energy [eV]
//! \param[in]  gamma - Electron Lorentz Factor
//! \return     Maximum energy of scattered photon
//******************************************************************************
F64 IcsThomson_MaxEnergyIso(const F64 einit, const F64 gamma)
{
    F64 emax;
    F64 beta;

    beta = toBeta(gamma);
    emax = einit * (1.0 + beta) / (1.0 - beta);

    return emax;
}



//******************************************************************************
//! \breif      Convert to adimensional electron velocity from Lorentz factor
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  gamma  - Electron Lorentz Factor
//! \return     Adimensional electron velocity corresponding Lorentz factor
//******************************************************************************
static inline F64 toBeta(const F64 gamma)
{
    F64 beta;

    beta  = sqrt(gamma + 1.0);
    beta *= sqrt(gamma - 1.0);
    beta /= gamma;

    return beta;
}





//******************************************************************************
// End of File
//******************************************************************************
