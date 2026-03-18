/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: handle.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "handle.h"
#include "psudoinverse_function_types.h"
#include "rt_nonfinite.h"
#include "collisioncodegen_api.hpp"

/* Function Definitions */
/*
 * Arguments    : d_robotics_manip_internal_Colli *obj
 * Return Type  : void
 */
void handle_matlabCodegenDestructor(d_robotics_manip_internal_Colli *obj)
{
  c_robotics_manip_internal_Colli b_obj;
  int b_i;
  if (!obj->matlabCodegenIsDeleted) {
    double d;
    int i;
    obj->matlabCodegenIsDeleted = true;
    d = obj->Size;
    i = (int)d;
    for (b_i = 0; b_i < i; b_i++) {
      b_obj = obj->CollisionGeometries->data[b_i];
      collisioncodegen_destructGeometry(&b_obj.CollisionPrimitive);
      obj->CollisionGeometries->data[b_i] = b_obj;
    }
  }
}

/*
 * File trailer for handle.c
 *
 * [EOF]
 */
