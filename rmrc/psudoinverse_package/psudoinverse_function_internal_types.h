/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function_internal_types.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef PSUDOINVERSE_FUNCTION_INTERNAL_TYPES_H
#define PSUDOINVERSE_FUNCTION_INTERNAL_TYPES_H

/* Include Files */
#include "psudoinverse_function_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_30
#define typedef_cell_wrap_30
typedef struct {
  double f1[16];
} cell_wrap_30;
#endif /* typedef_cell_wrap_30 */

#ifndef typedef_rigidBody
#define typedef_rigidBody
typedef struct {
  bool matlabCodegenIsDeleted;
  c_robotics_manip_internal_Rigid *BodyInternal;
  e_robotics_manip_internal_Rigid *TreeInternal;
} rigidBody;
#endif /* typedef_rigidBody */

#endif
/*
 * File trailer for psudoinverse_function_internal_types.h
 *
 * [EOF]
 */
