/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: eml_rand_mt19937ar.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "eml_rand_mt19937ar.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : unsigned int b_state[625]
 * Return Type  : void
 */
void eml_rand_mt19937ar(unsigned int b_state[625])
{
  int mti;
  unsigned int r;
  r = 5489U;
  b_state[0] = 5489U;
  for (mti = 0; mti < 623; mti++) {
    r = ((r ^ r >> 30U) * 1812433253U + (unsigned int)mti) + 1U;
    b_state[mti + 1] = r;
  }
  b_state[624] = 624U;
}

/*
 * File trailer for eml_rand_mt19937ar.c
 *
 * [EOF]
 */
