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

#ifndef COMMON_TYPEDEF_H_
#define COMMON_TYPEDEF_H_

#ifdef _cplusplus
extern "C" {
#endif

//==============================================================================
// Header File Include
//==============================================================================
#include <stdint.h>



//==============================================================================
// Macro Definition
//==============================================================================
/*----------------------------------------------------------
 * Null Value Definition
 *----------------------------------------------------------*/
#ifndef NULL
#define NULL                        (      0U)
#endif

/*----------------------------------------------------------
 * Boolean Value Definition
 *----------------------------------------------------------*/
#ifndef TRUE
#define FALSE                       ((BOOL)0U)
#define TRUE                        ((BOOL)1U)
#endif

/*----------------------------------------------------------
 * Ratio of the circumference of a circle to its diameter
 *----------------------------------------------------------*/
#define MATH_PI                     (3.14159265358979323846)



//==============================================================================
// Type Definition
//==============================================================================
/*----------------------------------------------------------
 * Basic Type Definition
 *----------------------------------------------------------*/
typedef char                        CHAR;                   //!< ASCII
typedef unsigned char               BOOL;                   //!< Boolean
typedef int8_t                      S8;                     //!< 8-bit Signed Integer
typedef uint8_t                     U8;                     //!< 8-bit Unsigned Integer
typedef int16_t                     S16;                    //!< 16-bit Signed Integer
typedef uint16_t                    U16;                    //!< 16-bit Unsigned Integer
typedef int32_t                     S32;                    //!< 32-bit Signed Integer
typedef uint32_t                    U32;                    //!< 32-bit Unsigned Integer
typedef int64_t                     S64;                    //!< 64-bit Signed Integer
typedef uint64_t                    U64;                    //!< 64-bit Unsigned Integer
typedef float                       F32;                    //!< Single Precision Floating Point
typedef double                      F64;                    //!< Double Precision Floating Point



#ifdef _cplusplus
}
#endif

#endif

//******************************************************************************
// End of File
//******************************************************************************
