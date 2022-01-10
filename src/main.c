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

#define MAIN_C_

//==============================================================================
// Header File Include
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include "common_typedef.h"
#include "ics_jones_approx.h"
#include "ics_thomson_approx.h"
#include "numerics_trapezoidal.h"
#include "particles_cmb.h"
#include "particles_electron.h"


//==============================================================================
// Macro Definitios
//==============================================================================
#define USE_JONES_APPROX                    (1)
#define USE_THOMSON_APPROX                  (2)
#define INTEGRATION_RANGE_EINIT_LOWER       (1.0E-15)
#define INTEGRATION_RANGE_EINIT_UPPER       (1.0E+4)
#define INTEGRATION_RANGE_EINIT_ITERATION   (500)
#define INTEGRATION_RANGE_GAMMA_LOWER       (1.0E+1)
#define INTEGRATION_RANGE_GAMMA_UPPER_PLUS  (1.0E+2)
#define INTEGRATION_RANGE_GAMMA_ITERATION   (500)
#define FLUX_CALC_STRIDE_LOG                (0.1000)



//==============================================================================
// File Scope Global Variables
//==============================================================================
//----------------------------------------------------------
//! Jones approximation or Thomson approximation
//----------------------------------------------------------
static S32 icsMode = 0;

//----------------------------------------------------------
// Electron Flux Parameter
//----------------------------------------------------------
static F64 normFactor    = 0.0;         //!< Normalization Factor
static F64 spectrumPower = 0.0;         //!< Power
static F64 gammaMax      = 0.0;         //!< Maximum Lorentz Factor

//----------------------------------------------------------
//! Energy currently being calculated
//----------------------------------------------------------
static F64 emittedEnergy = 0.0;



//******************************************************************************
//! \breif      Get the current time as a string.
//! \remark
//!
//! \callgraph
//!
//! \param      None
//! \return     current time
//******************************************************************************
static const CHAR *getCurrentTime(void)
{
    time_t now;
    struct tm *ts;
    static CHAR date_time[64];

    //------------------------------------------------------
    // Get the current time
    //------------------------------------------------------
    now = time(NULL);
    ts  = localtime(&now);

    //------------------------------------------------------
    // Create file name
    //------------------------------------------------------
    strftime(date_time, sizeof(date_time), "%Y/%m/%d %H:%M:%S", ts);

    return (const CHAR *)&date_time[0];
}



//******************************************************************************
//! \breif     Get the file name
//! \remark
//!
//! \callgraph
//!
//! \param[in]  mode - 1 : Use Jones Approximation, 2 : Thomson Approximation
//! \return     File name
//******************************************************************************
static const CHAR *getFileName(const S32 mode)
{
    time_t now;
    struct tm *ts;
    static CHAR name[64];

    //------------------------------------------------------
    // Get the current time
    //------------------------------------------------------
    now = time(NULL);
    ts  = localtime(&now);

    //------------------------------------------------------
    // Create file name
    //------------------------------------------------------
    switch (mode) {
    case USE_JONES_APPROX:
        strftime(name, sizeof(name), "ics_jones_%Y%m%d%H%M%S.log", ts);
        break;
    case USE_THOMSON_APPROX:
        strftime(name, sizeof(name), "ics_thomson_%Y%m%d%H%M%S.log", ts);
        break;
    default:
        printf("[ERROR] ");
        exit(EXIT_FAILURE);
        break;
    }

    return (const CHAR *)&name[0];
}



//******************************************************************************
//! \breif      Read the ICS calculation mode from the console.
//! \remark
//!
//! \callgraph
//!
//! \param      None
//! \return     1 : Use Jones Approximation, 2 : Thomson Approximation
//******************************************************************************
static S32 readIcsCalcMode(void)
{
    S32 mode, scan_result;

    printf("Enter the ICS calculation mode (1 or 2).\n");
    printf("  1 : ICS flux on CMB and non-thermal electron using Jones Approximation\n");
    printf("  2 : ICS flux on CMB and non-thermal electron using Thomson Approximation\n");
    printf("[User's Operation] Mode = ");

    scan_result = scanf("%d", &mode);
    printf("\n");

    if (scan_result == 0) {
        printf("[ERROR] The input values are invalid.");
        exit(EXIT_FAILURE);
    }

    if ((mode != USE_JONES_APPROX) && (mode != USE_THOMSON_APPROX)) {
        printf("[ERROR] Select 1 (Jones) or 2 (Thomson) for calculation mode ...\n\n");
        exit(EXIT_FAILURE);
    }

    return mode;
}



//******************************************************************************
//! \breif      Get the inverse compton scattering energy range from console
//! \remark
//!
//! \callgraph
//!
//! \param[out] lower : Lower enegry of inverse compton scattering [eV]
//! \param[out] upper : Upper enegry of inverse compton scattering [eV]
//! \return     Inverse compton scattering angle [dgree]
//******************************************************************************
static void readIcsFluxEnergyRange(F64 *lower, F64 *upper)
{
    S32 scan_results[2];

    printf("Enter the energy range to calculate the ICS Flux [eV]\n");

    printf("[User's Operation] Lower= ");
    scan_results[0] = scanf("%lE", lower);

    printf("[User's Operation] Upper= ");
    scan_results[1] = scanf("%lE", upper);

    if ((scan_results[0] == 0) || (scan_results[1] == 0)) {
        printf("[ERROR] The input values are invalid.");
        exit(EXIT_FAILURE);
    }

    printf("\n");

    return;
}


//******************************************************************************
//! \breif      Get electron spectrum information from the console
//! \remark
//!
//! \callgraph
//!
//! \param[out] norm    Normalization Factor
//! \param[out] power   Power of spectrum
//! \param[out] gmax    Maximum Lorentz Factor
//! \return     None
//******************************************************************************
static void readElectronSpectrum(F64 *norm, F64 *power, F64 *gmax)
{
    S32 scan_results[3];

    printf("Enter the electron spectrum factors.\n");
    printf("Where the spectrum equation is E(r) = N0 r^(-p) exp(- r / rmax),\n");
    printf("  r    : Lorentz factor\n");
    printf("  N0   : Normalization factor\n");
    printf("  p    : Power\n");
    printf("  rmax : Mmaximum Lorentz factor\n");

    printf("[User's Operation] N0   = ");
    scan_results[0] = scanf("%lE", norm);

    printf("[User's Operation] p    = ");
    scan_results[1] = scanf("%lE", power);

    printf("[User's Operation] rmax = ");
    scan_results[2] = scanf("%lE", gmax);

    if ((scan_results[0] == 0) || (scan_results[1] == 0) || (scan_results[2] == 0)) {
        printf("[ERROR] The input values are invalid.");
        exit(EXIT_FAILURE);
    }

    printf("\n");

    return;
}


//******************************************************************************
//! \breif      Integrand used for the ICS flux calculation.
//! \remark
//!
//! \callgraph
//!
//! \param[in]  einit   Incident photon energy [eV]
//! \param[in]  gamma   Lorentz factor
//! \return     Flux
//******************************************************************************
static F64 icsFluxIntegrand(const F64 einit, const F64 gamma)
{
    F64 flux;

    flux = PatriclesCmb_CalcFlux(einit);
    flux *= ParticlesElectron_CalcFlux(gamma, normFactor, spectrumPower, gammaMax);

    if (icsMode == USE_JONES_APPROX) {
        flux *= IcsJones_CalcFluxIso(emittedEnergy, einit, gamma);
    }
    else {
        flux *= IcsThomson_CalcFluxIso(emittedEnergy, einit, gamma);
    }

    return flux;
}

int main(int argc, char* argv[])
{
    INTEGRATION_RANGE gammaRange, energyRange;
    F64 lower, upper, lower_log, upper_log, energy_log, flux;
    S32 n_calc_points, i;
    const CHAR* file_name;
    FILE* fp;

    // Read calculation conditions from the console.
    icsMode = readIcsCalcMode();
    readElectronSpectrum(&normFactor, &spectrumPower, &gammaMax);
    readIcsFluxEnergyRange(&lower, &upper);

    // Calculation range
    lower_log  = log10(lower);
    upper_log  = log10(upper);
    n_calc_points = (S32)((upper_log - lower_log) / FLUX_CALC_STRIDE_LOG);

    // Integration Range
    energyRange.Lower = INTEGRATION_RANGE_EINIT_LOWER;
    energyRange.Upper = INTEGRATION_RANGE_EINIT_UPPER;
    energyRange.Iteration = INTEGRATION_RANGE_EINIT_ITERATION;
    gammaRange.Lower = INTEGRATION_RANGE_GAMMA_LOWER;
    gammaRange.Upper = gammaMax * INTEGRATION_RANGE_GAMMA_UPPER_PLUS;
    gammaRange.Iteration = INTEGRATION_RANGE_GAMMA_ITERATION;

    // File
    file_name = getFileName(icsMode);
    if ((fp = fopen(file_name, "w")) == NULL){
        printf("[ERROR] %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Print start time
    printf("Start Time : %s\n\n", getCurrentTime());

    // ICS Flux Calculation Loop
    for (i = 0, energy_log = lower_log; i < n_calc_points; i++, energy_log += FLUX_CALC_STRIDE_LOG) {
        emittedEnergy = pow(10.0, energy_log);
        flux = NumericsTrapezoidal_Inetegrate2d(&icsFluxIntegrand, (const INTEGRATION_RANGE *)&energyRange, (const INTEGRATION_RANGE *)&gammaRange);

        printf("[%03d/%03d] %.8E %.8E\n", i + 1, n_calc_points, emittedEnergy, flux);
        fprintf(fp, "%.8E %.8E\n", emittedEnergy, flux);
    }

    // Print end time
    printf("\nEnd Time : %s\n\n", getCurrentTime());
    fclose(fp);

    return EXIT_SUCCESS;
}





//******************************************************************************
// End of File
//******************************************************************************
