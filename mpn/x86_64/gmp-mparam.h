/* AMD K7 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000, 2001, 2002, 2003, 2004 Free Software
Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#define BITS_PER_MP_LIMB 64
#define BYTES_PER_MP_LIMB 8


/* 1400 MHz Opteron */

/* Generated by tuneup.c, 2004-12-15, gcc 3.3 */

#define MUL_KARATSUBA_THRESHOLD          22
#define MUL_TOOM3_THRESHOLD              81

#define SQR_BASECASE_THRESHOLD            5
#define SQR_KARATSUBA_THRESHOLD          26
#define SQR_TOOM3_THRESHOLD              93

#define MULLOW_BASECASE_THRESHOLD         0  /* always */
#define MULLOW_DC_THRESHOLD              31
#define MULLOW_MUL_N_THRESHOLD          363

#define DIV_SB_PREINV_THRESHOLD           0  /* always */
#define DIV_DC_THRESHOLD                 67
#define POWM_THRESHOLD                  128

#define HGCD_SCHOENHAGE_THRESHOLD       200
#define GCD_ACCEL_THRESHOLD               3
#define GCD_SCHOENHAGE_THRESHOLD        514
#define GCDEXT_SCHOENHAGE_THRESHOLD     514
#define JACOBI_BASE_METHOD                1

#define MOD_1_NORM_THRESHOLD              0  /* always */
#define MOD_1_UNNORM_THRESHOLD            0  /* always */
#define USE_PREINV_DIVREM_1               1  /* native */
#define USE_PREINV_MOD_1                  1
#define DIVREM_2_THRESHOLD                0  /* always */
#define DIVEXACT_1_THRESHOLD              0  /* always (native) */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always (native) */

#define GET_STR_DC_THRESHOLD             12
#define GET_STR_PRECOMPUTE_THRESHOLD     18
#define SET_STR_THRESHOLD              9394

#define MUL_FFT_TABLE  { 560, 1184, 2880, 5888, 15360, 36864, 0 }
#define MUL_FFT_MODF_THRESHOLD          576
#define MUL_FFT_THRESHOLD              4992

#define SQR_FFT_TABLE  { 624, 1312, 2880, 5888, 15360, 28672, 0 }
#define SQR_FFT_MODF_THRESHOLD          640
#define SQR_FFT_THRESHOLD              4992
