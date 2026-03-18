/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef PSUDOINVERSE_FUNCTION_H
#define PSUDOINVERSE_FUNCTION_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void psudoinverse_function(const char endEffector[5],
                                  const double velocities[6],
                                  const double config[6], double x[6],
                                  double *y);

void psudoinverse_function_delete(void);

void psudoinverse_function_emx_free(void);

void psudoinverse_function_emx_init(void);

void psudoinverse_function_init(void);

void psudoinverse_function_new(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for psudoinverse_function.h
 *
 * [EOF]
 */
