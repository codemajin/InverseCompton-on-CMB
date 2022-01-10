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

#===========================================================
# Program Name
#===========================================================
APP_NAME := ics

#===========================================================
# Complier
#===========================================================
CC := gcc

#===========================================================
# Source Code
#===========================================================
APP_SOURCE_FILE += ../../src/common/common_physical_const.c
APP_SOURCE_FILE += ../../src/ics/ics_jones_approx.c
APP_SOURCE_FILE += ../../src/ics/ics_thomson_approx.c
APP_SOURCE_FILE += ../../src/numerics/numerics_simpson.c
APP_SOURCE_FILE += ../../src/numerics/numerics_trapezoidal.c
APP_SOURCE_FILE += ../../src/particles/particles_cmb.c
APP_SOURCE_FILE += ../../src/particles/particles_electron.c
APP_SOURCE_FILE += ../../src/main.c

#===========================================================
# Include Path
#===========================================================
APP_INCLUDE_DIR += ../../src/common/
APP_INCLUDE_DIR += ../../src/ics/
APP_INCLUDE_DIR += ../../src/numerics/
APP_INCLUDE_DIR += ../../src/particles/

#===========================================================
# Defined Symbols
#===========================================================
APP_DEFINE_SYMBOL := 

#===========================================================
# Library Path
#===========================================================
APP_LIBRARY_FILE += m
APP_LIBRARY_FILE += quadmath
APP_LIBRARY_PATH :=

#===========================================================
# Build Option
#===========================================================
OPTIMIZE_OPTION := -O2
INCLUDE_OPTION  := $(addprefix -I, $(APP_INCLUDE_DIR))
LIBRARY_OPTION  := $(addprefix -l, $(APP_LIBRARY_FILE)) $(addprefix -L, $(APP_LIBRARY_PATH))
DEFINE_OPTION   := $(addprefix -D, $(APP_DEFINE_SYMBOL))
DEBUG_OPTION    := 
WARNING_OPTION  := -Wall
OTHER_OPTION    := -std=c99 -fopenmp
EXE_FILE_NAME   := -o $(APP_NAME).elf



#===========================================================
# Build Command
#===========================================================
all:
	$(CC) $(OPTIMIZE_OPTION) $(INCLUDE_OPTION) $(DEFINE_OPTION) \
	$(DEBUG_OPTION) $(WARNING_OPTION) $(OTHER_OPTION) $(EXE_FILE_NAME) \
	$(APP_SOURCE_FILE) $(LIBRARY_OPTION)

clear:
	rm -f ./bin/*.o
	rm -f ./bin/*.exe

run:
	



#*******************************************************************************
# End of File
#*******************************************************************************
