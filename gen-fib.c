/* Generate Fibonacci table data.

Copyright 2001, 2002, 2004, 2012, 2014 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#include <stdio.h>
#include "bootstrap.c"

mpz_t  *f;
int    fnum, fib_limit, luc_limit;

void
generate (int numb_bits)
{
  mpz_t  limit, l;
  int    falloc, i;

  mpz_init2 (limit, numb_bits + 1);
  mpz_setbit (limit, numb_bits);

  /* fib(2n) > 2^n, so use 2n as a limit for the table size */
  falloc = 2 * numb_bits;
  f = (mpz_t*) xmalloc (falloc * sizeof (*f));

  mpz_init_set_ui (f[0], 1L);  /* F[-1] */
  mpz_init_set_ui (f[1], 0L);  /* F[0] */

  mpz_init (l);

  for (i = 2; ; i++)
    {
      assert (i < falloc);

      /* F[i] = F[i-1] + F[i-2] */
      mpz_init (f[i]);
      mpz_add (f[i], f[i-1], f[i-2]);
      if (mpz_cmp (f[i], limit) >= 0)
        break;

      fnum = i+1;
      fib_limit = i-1;

      /* L[i] = F[i]+2*F[i-1] */
      mpz_add (l, f[i], f[i-1]);
      mpz_add (l, l, f[i-1]);

      if (mpz_cmp (l, limit) < 0)
        luc_limit = i-1;
    }

  mpz_clear (limit);
}


void
header (int numb_bits)
{
  printf ("/* This file generated by gen-fib.c - DO NOT EDIT. */\n");
  printf ("\n");
  printf ("#if GMP_NUMB_BITS != %d\n", numb_bits);
  printf ("Error, error, this data is for %d bits\n", numb_bits);
  printf ("#endif\n");
  printf ("\n");
  printf ("#define FIB_TABLE_LIMIT         %d\n", fib_limit);
  printf ("#define FIB_TABLE_LUCNUM_LIMIT  %d\n", luc_limit);
}

void
table (int numb_bits)
{
  int  i;

  printf ("/* This file generated by gen-fib.c - DO NOT EDIT. */\n");
  printf ("\n");
  printf ("#include \"gmp.h\"\n");
  printf ("#include \"gmp-impl.h\"\n");
  printf ("\n");
  printf ("#if GMP_NUMB_BITS != %d\n", numb_bits);
  printf ("Error, error, this data is for %d bits\n", numb_bits);
  printf ("#endif\n");
  printf ("\n");
  printf ("const mp_limb_t\n");
  printf ("__gmp_fib_table[FIB_TABLE_LIMIT+2] = {\n");

  for (i = 0; i < fnum; i++)
    {
      printf ("  CNST_LIMB (0x");
      mpz_out_str (stdout, 16, f[i]);
      printf ("),  /* %d */\n", i-1);
    }
  printf ("};\n");
}

int
main (int argc, char *argv[])
{
  int  limb_bits, nail_bits, numb_bits;

  if (argc != 4)
    {
      fprintf (stderr, "Usage: gen-bases <header|table> <limbbits> <nailbits>\n");
      exit (1);
    }

  limb_bits = atoi (argv[2]);
  nail_bits = atoi (argv[3]);

  if (limb_bits <= 0
      || nail_bits < 0
      || nail_bits >= limb_bits)
    {
      fprintf (stderr, "Invalid limb/nail bits: %d %d\n",
               limb_bits, nail_bits);
      exit (1);
    }
  numb_bits = limb_bits - nail_bits;

  generate (numb_bits);

  if (strcmp (argv[1], "header") == 0)
    header (numb_bits);
  else if (strcmp (argv[1], "table") == 0)
    table (numb_bits);
  else
    {
      fprintf (stderr, "Invalid header/table choice: %s\n", argv[1]);
      exit (1);
    }

  return 0;
}
