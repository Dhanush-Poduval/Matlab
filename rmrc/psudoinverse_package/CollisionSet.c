/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: CollisionSet.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "CollisionSet.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : d_robotics_manip_internal_Colli *obj
 *                double maxElements
 * Return Type  : d_robotics_manip_internal_Colli *
 */
d_robotics_manip_internal_Colli *
CollisionSet_CollisionSet(d_robotics_manip_internal_Colli *obj,
                          double maxElements)
{
  static const void *t0_GeometryInternal = NULL;
  c_robotics_manip_internal_Colli expl_temp;
  d_robotics_manip_internal_Colli *b_obj;
  double d;
  int b_i;
  int i;
  int i1;
  int size_tmp_idx_1;
  b_obj = obj;
  b_obj->Size = 0.0;
  b_obj->MaxElements = maxElements;
  size_tmp_idx_1 = (int)b_obj->MaxElements;
  i = b_obj->CollisionGeometries->size[0] * b_obj->CollisionGeometries->size[1];
  b_obj->CollisionGeometries->size[0] = 1;
  b_obj->CollisionGeometries->size[1] = size_tmp_idx_1;
  c_emxEnsureCapacity_robotics_ma(b_obj->CollisionGeometries, i);
  d = b_obj->MaxElements;
  size_tmp_idx_1 = (int)d;
  for (b_i = 0; b_i < size_tmp_idx_1; b_i++) {
    expl_temp.CollisionPrimitive = (void *)t0_GeometryInternal;
    for (i1 = 0; i1 < 16; i1++) {
      expl_temp.LocalPose[i1] = iv[i1];
    }
    for (i1 = 0; i1 < 16; i1++) {
      expl_temp.WorldPose[i1] = iv[i1];
    }
    expl_temp.MeshScale[0] = 1.0;
    expl_temp.MeshScale[1] = 1.0;
    expl_temp.MeshScale[2] = 1.0;
    expl_temp.ColorAlpha[0] = 0.46666666666666667;
    expl_temp.ColorAlpha[1] = 0.67450980392156867;
    expl_temp.ColorAlpha[2] = 0.18823529411764706;
    expl_temp.ColorAlpha[3] = 1.0;
    b_obj->CollisionGeometries->data[b_i] = expl_temp;
  }
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * File trailer for CollisionSet.c
 *
 * [EOF]
 */
