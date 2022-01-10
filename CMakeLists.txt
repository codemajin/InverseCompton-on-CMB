#*******************************************************************************
#  MIT License
# 
#  Copyright (c) 2022 Tomonobu Inayama
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#*******************************************************************************

cmake_minimum_required(VERSION 3.7.1)

add_executable(ics
  ./src/common/common_physical_const.c
  ./src/ics/ics_jones_approx.c
  ./src/ics/ics_thomson_approx.c
  ./src/numerics/numerics_simpson.c
  ./src/numerics/numerics_trapezoidal.c
  ./src/particles/particles_cmb.c
  ./src/particles/particles_electron.c
  ./src/main.c
)

include_directories(
  ./src/common/
  ./src/ics/
  ./src/numerics/
  ./src/particles/
)

if(UNIX OR MSYS OR CYGWIN)
  set(CMAKE_C_FLAGS "-Wall -O2 -std=c99")
  target_link_libraries(ics m)
  target_link_libraries(ics quadmath)
else()
  set(CMAKE_C_FLAGS "-Wall -O2")
endif()

find_package(OpenMP)

if(OPENMP_FOUND)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

#*******************************************************************************
# End of File
#*******************************************************************************
