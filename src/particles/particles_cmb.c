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

#define PARTICLES_CMB_C_

//==============================================================================
// Header File Include
//==============================================================================
#include <math.h>
#include "common_typedef.h"
#include "common_physical_const.h"
#include "particles_cmb.h"




//==============================================================================
// Header File Include
//==============================================================================
//----------------------------------------------------------
//! CMB Temperature [T] (Block Body Radiation)
//----------------------------------------------------------
static const F64 CMB_TEMP = 2.72;





//******************************************************************************
//! \breif      Calculates the CMB flux
//! \remark     
//! 
//! \callgraph  
//! 
//! \param[in]  energy : CMB Photon Energy [eV]
//! \return     CMB Flux [cm^(-3) eV^(-1)]
//******************************************************************************
F64 PatriclesCmb_CalcFlux(const F64 energy)
{
    register F64 flux;
    const F64 hc = PLANK_CONST * LIGHT_SPEED;

    if (0.0 < energy) {
        flux = exp(energy / (BOLTZMANN_CONST * CMB_TEMP));
        flux -= 1.0;
        flux = (energy * energy) / flux;
        flux /= (MATH_PI * MATH_PI * hc * hc * hc);
    }
    else {
        flux  = 0.0;
    }

    return flux;
}





//******************************************************************************
// End of File
//******************************************************************************
