/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function_initialize.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "psudoinverse_function_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "psudoinverse_function.h"
#include "psudoinverse_function_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void psudoinverse_function_initialize(void)
{
  psudoinverse_function_emx_init();
  psudoinverse_function_new();
  psudoinverse_function_init();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_psudoinverse_function = true;
}

/*
 * File trailer for psudoinverse_function_initialize.c
 *
 * [EOF]
 */
