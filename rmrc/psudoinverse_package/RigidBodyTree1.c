/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: RigidBodyTree1.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "RigidBodyTree1.h"
#include "CollisionSet.h"
#include "FrameTree.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_internal_types.h"
#include "psudoinverse_function_types.h"
#include "rand.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : e_robotics_manip_internal_Rigid *obj
 * Return Type  : e_robotics_manip_internal_Rigid *
 */
e_robotics_manip_internal_Rigid *
RigidBodyTree_RigidBodyTree(e_robotics_manip_internal_Rigid *obj)
{
  static const char jname[14] = {'d', 'u', 'm', 'm', 'y', 'b', 'o',
                                 'd', 'y', '1', '_', 'j', 'n', 't'};
  c_robotics_manip_internal_Chara s;
  e_robotics_manip_internal_Rigid *b_obj;
  double unusedExpr[5];
  int i;
  b_obj = obj;
  b_rand(unusedExpr);
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->Base.NameInternal = s;
  s = b_obj->Base.NameInternal;
  s.Length = 4.0;
  s.Vector[0] = 'b';
  s.Vector[1] = 'a';
  s.Vector[2] = 's';
  s.Vector[3] = 'e';
  b_obj->Base.NameInternal = s;
  rigidBodyJoint_rigidBodyJoint(&b_obj->Base.JointInternal);
  b_obj->Base.JointInternal.InTree = false;
  CollisionSet_CollisionSet(&b_obj->Base.CollisionsInternal, 0.0);
  b_obj->Base.matlabCodegenIsDeleted = false;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->coder_buffer_pobj0.NameInternal = s;
  s = b_obj->coder_buffer_pobj0.NameInternal;
  s.Length = 10.0;
  for (i = 0; i < 10; i++) {
    s.Vector[i] = cv[i];
  }
  b_obj->coder_buffer_pobj0.NameInternal = s;
  b_rigidBodyJoint_rigidBodyJoint(&b_obj->coder_buffer_pobj0.JointInternal,
                                  jname);
  b_obj->coder_buffer_pobj0.JointInternal.InTree = false;
  CollisionSet_CollisionSet(&b_obj->coder_buffer_pobj0.CollisionsInternal, 0.0);
  b_obj->coder_buffer_pobj0.matlabCodegenIsDeleted = false;
  b_obj->Bodies[0] = &b_obj->coder_buffer_pobj0;
  b_rand(unusedExpr);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : f_robotics_manip_internal_Rigid *obj
 *                const double qvec[6]
 *                cell_wrap_30 Ttree_data[]
 *                int Ttree_size[2]
 * Return Type  : void
 */
void RigidBodyTree_forwardKinematics(f_robotics_manip_internal_Rigid *obj,
                                     const double qvec[6],
                                     cell_wrap_30 Ttree_data[],
                                     int Ttree_size[2])
{
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv1[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *b_obj;
  double b[16];
  double b_I[16];
  double b_a[16];
  double b_b[16];
  double tempR[9];
  double k;
  double n;
  double result_data_idx_3;
  int b_i;
  int i;
  int i1;
  int jtilecol;
  n = obj->NumBodies;
  Ttree_size[0] = 1;
  i = (int)n;
  Ttree_size[1] = (int)n;
  if ((int)n != 0) {
    for (jtilecol = 0; jtilecol < i; jtilecol++) {
      for (i1 = 0; i1 < 16; i1++) {
        Ttree_data[jtilecol].f1[i1] = iv[i1];
      }
    }
  }
  k = 1.0;
  e_emxInitStruct_robotics_manip_(&expl_temp);
  for (b_i = 0; b_i < i; b_i++) {
    double a[16];
    double d;
    int a_tmp;
    int b_index;
    int b_tmp;
    int exitg1;
    int i2;
    char obj_Vector[200];
    bool result;
    body = obj->Bodies[b_i];
    n = body->JointInternal->PositionNumber;
    d = k + n;
    if (k > d - 1.0) {
      i2 = -1;
      a_tmp = 0;
    } else {
      i2 = (int)k - 2;
      a_tmp = (int)(d - 1.0);
    }
    n = obj->BodyParentFrameIdx[b_i];
    if (obj->Bodies[b_i]->ParentIndex > 0.0) {
      c_emxCopyStruct_robotics_manip_(
          &expl_temp,
          &obj->Bodies[(int)obj->Bodies[b_i]->ParentIndex - 1]->FramesInternal);
      FrameTree_transformUsingFrameID(expl_temp.FrameParents,
                                      expl_temp.FrameRigidTransforms, n, a);
    } else {
      FrameTree_transformUsingFrameID(
          obj->Base.FramesInternal.FrameParents,
          obj->Base.FramesInternal.FrameRigidTransforms, n, a);
    }
    b_obj = body->JointInternal;
    for (jtilecol = 0; jtilecol < 16; jtilecol++) {
      b_a[jtilecol] = b_obj->JointToParentTransform[jtilecol];
    }
    n = b_obj->TypeInternal.Length;
    for (jtilecol = 0; jtilecol < 200; jtilecol++) {
      obj_Vector[jtilecol] = b_obj->TypeInternal.Vector[jtilecol];
    }
    if (n < 1.0) {
      b_tmp = 0;
    } else {
      b_tmp = (int)n;
    }
    result = false;
    if (b_tmp == 8) {
      b_index = 0;
      do {
        exitg1 = 0;
        if (b_index < 8) {
          if (b_cv[b_index] != obj_Vector[b_index]) {
            exitg1 = 1;
          } else {
            b_index++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      b_index = 0;
    } else {
      result = false;
      if (b_tmp == 9) {
        b_index = 0;
        do {
          exitg1 = 0;
          if (b_index < 9) {
            if (cv1[b_index] != obj_Vector[b_index]) {
              exitg1 = 1;
            } else {
              b_index++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        b_index = 1;
      } else {
        result = false;
        if (b_tmp == 8) {
          b_index = 0;
          do {
            exitg1 = 0;
            if (b_index < 8) {
              if (b_cv1[b_index] != obj_Vector[b_index]) {
                exitg1 = 1;
              } else {
                b_index++;
              }
            } else {
              result = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (result) {
          b_index = 2;
        } else {
          b_index = -1;
        }
      }
    }
    switch (b_index) {
    case 0: {
      double R[9];
      double v[3];
      double sth;
      rigidBodyJoint_get_JointAxis(b_obj, v);
      n = v[0];
      k = v[1];
      sth = v[2];
      b_index = ((a_tmp - i2) - 1 != 0);
      for (jtilecol = 0; jtilecol < b_index; jtilecol++) {
        result_data_idx_3 = qvec[i2 + 1];
      }
      double c_b;
      double cth;
      double d_tempR_tmp;
      double f_tempR_tmp;
      double g_tempR_tmp;
      double normRowMatrix_idx_1;
      double normRowMatrix_tmp;
      double tempR_tmp;
      normRowMatrix_tmp = 1.0 / sqrt((n * n + k * k) + sth * sth);
      v[0] = n * normRowMatrix_tmp;
      v[1] = k * normRowMatrix_tmp;
      v[2] = sth * normRowMatrix_tmp;
      cth = cos(result_data_idx_3);
      sth = sin(result_data_idx_3);
      tempR_tmp = v[0] * v[0] * (1.0 - cth) + cth;
      tempR[0] = tempR_tmp;
      n = v[0] * v[1] * (1.0 - cth);
      k = v[2] * sth;
      normRowMatrix_idx_1 = n - k;
      tempR[1] = normRowMatrix_idx_1;
      normRowMatrix_tmp = v[0] * v[2] * (1.0 - cth);
      c_b = v[1] * sth;
      d_tempR_tmp = normRowMatrix_tmp + c_b;
      tempR[2] = d_tempR_tmp;
      f_tempR_tmp = n + k;
      tempR[3] = f_tempR_tmp;
      g_tempR_tmp = v[1] * v[1] * (1.0 - cth) + cth;
      tempR[4] = g_tempR_tmp;
      k = v[1] * v[2] * (1.0 - cth);
      n = v[0] * sth;
      sth = k - n;
      tempR[5] = sth;
      normRowMatrix_tmp -= c_b;
      tempR[6] = normRowMatrix_tmp;
      k += n;
      tempR[7] = k;
      n = v[2] * v[2] * (1.0 - cth) + cth;
      tempR[8] = n;
      R[0] = tempR_tmp;
      R[1] = normRowMatrix_idx_1;
      R[2] = d_tempR_tmp;
      R[3] = f_tempR_tmp;
      R[4] = g_tempR_tmp;
      R[5] = sth;
      R[6] = normRowMatrix_tmp;
      R[7] = k;
      R[8] = n;
      for (jtilecol = 0; jtilecol < 3; jtilecol++) {
        R[jtilecol] = tempR[3 * jtilecol];
        R[jtilecol + 3] = tempR[3 * jtilecol + 1];
        R[jtilecol + 6] = tempR[3 * jtilecol + 2];
      }
      memset(&b[0], 0, 16U * sizeof(double));
      for (jtilecol = 0; jtilecol < 3; jtilecol++) {
        b_index = jtilecol << 2;
        b[b_index] = R[3 * jtilecol];
        b[b_index + 1] = R[3 * jtilecol + 1];
        b[b_index + 2] = R[3 * jtilecol + 2];
      }
      b[15] = 1.0;
    } break;
    case 1: {
      double v[3];
      rigidBodyJoint_get_JointAxis(b_obj, v);
      memset(&tempR[0], 0, 9U * sizeof(double));
      tempR[0] = 1.0;
      tempR[4] = 1.0;
      tempR[8] = 1.0;
      for (jtilecol = 0; jtilecol < 3; jtilecol++) {
        b_index = jtilecol << 2;
        b[b_index] = tempR[3 * jtilecol];
        b[b_index + 1] = tempR[3 * jtilecol + 1];
        b[b_index + 2] = tempR[3 * jtilecol + 2];
        b[jtilecol + 12] = v[jtilecol] * qvec[i2 + 1];
      }
      b[3] = 0.0;
      b[7] = 0.0;
      b[11] = 0.0;
      b[15] = 1.0;
    } break;
    case 2: {
      double R[9];
      double b_tempR_tmp;
      double c_b;
      double c_tempR_tmp;
      double cth;
      double d_tempR_tmp;
      double e_tempR_tmp;
      double f_tempR_tmp;
      double g_tempR_tmp;
      double h_tempR_tmp;
      double normRowMatrix_idx_0;
      double normRowMatrix_idx_1;
      double normRowMatrix_tmp;
      double sth;
      double tempR_tmp;
      memset(&b_I[0], 0, 16U * sizeof(double));
      b_I[0] = 1.0;
      b_I[5] = 1.0;
      b_I[10] = 1.0;
      b_I[15] = 1.0;
      b_I[12] = qvec[i2 + 5];
      b_I[13] = qvec[i2 + 6];
      b_I[14] = qvec[i2 + 7];
      n = qvec[i2 + 1];
      k = qvec[i2 + 2];
      sth = qvec[i2 + 3];
      normRowMatrix_tmp = qvec[i2 + 4];
      c_b = 1.0 / sqrt(((n * n + k * k) + sth * sth) +
                       normRowMatrix_tmp * normRowMatrix_tmp);
      normRowMatrix_idx_0 = n * c_b;
      normRowMatrix_idx_1 = k * c_b;
      sth *= c_b;
      c_b *= normRowMatrix_tmp;
      normRowMatrix_tmp = c_b * c_b;
      b_tempR_tmp = sth * sth;
      c_tempR_tmp = 1.0 - 2.0 * (b_tempR_tmp + normRowMatrix_tmp);
      tempR[0] = c_tempR_tmp;
      n = normRowMatrix_idx_1 * sth;
      k = normRowMatrix_idx_0 * c_b;
      e_tempR_tmp = 2.0 * (n - k);
      tempR[1] = e_tempR_tmp;
      f_tempR_tmp = normRowMatrix_idx_1 * c_b;
      g_tempR_tmp = normRowMatrix_idx_0 * sth;
      h_tempR_tmp = 2.0 * (f_tempR_tmp + g_tempR_tmp);
      tempR[2] = h_tempR_tmp;
      d_tempR_tmp = 2.0 * (n + k);
      tempR[3] = d_tempR_tmp;
      cth = normRowMatrix_idx_1 * normRowMatrix_idx_1;
      tempR_tmp = 1.0 - 2.0 * (cth + normRowMatrix_tmp);
      tempR[4] = tempR_tmp;
      k = sth * c_b;
      n = normRowMatrix_idx_0 * normRowMatrix_idx_1;
      c_b = 2.0 * (k - n);
      tempR[5] = c_b;
      normRowMatrix_tmp = 2.0 * (f_tempR_tmp - g_tempR_tmp);
      tempR[6] = normRowMatrix_tmp;
      k = 2.0 * (k + n);
      tempR[7] = k;
      n = 1.0 - 2.0 * (cth + b_tempR_tmp);
      tempR[8] = n;
      R[0] = c_tempR_tmp;
      R[1] = e_tempR_tmp;
      R[2] = h_tempR_tmp;
      R[3] = d_tempR_tmp;
      R[4] = tempR_tmp;
      R[5] = c_b;
      R[6] = normRowMatrix_tmp;
      R[7] = k;
      R[8] = n;
      for (jtilecol = 0; jtilecol < 3; jtilecol++) {
        R[jtilecol] = tempR[3 * jtilecol];
        R[jtilecol + 3] = tempR[3 * jtilecol + 1];
        R[jtilecol + 6] = tempR[3 * jtilecol + 2];
      }
      memset(&b_b[0], 0, 16U * sizeof(double));
      for (jtilecol = 0; jtilecol < 3; jtilecol++) {
        b_index = jtilecol << 2;
        b_b[b_index] = R[3 * jtilecol];
        b_b[b_index + 1] = R[3 * jtilecol + 1];
        b_b[b_index + 2] = R[3 * jtilecol + 2];
      }
      b_b[15] = 1.0;
      memset(&b[0], 0, sizeof(double) << 4);
      for (jtilecol = 0; jtilecol < 4; jtilecol++) {
        b_index = jtilecol << 2;
        for (i1 = 0; i1 < 4; i1++) {
          n = b_b[i1 + b_index];
          b_tmp = i1 << 2;
          b[b_index] += b_I[b_tmp] * n;
          b[b_index + 1] += b_I[b_tmp + 1] * n;
          b[b_index + 2] += b_I[b_tmp + 2] * n;
          b[b_index + 3] += b_I[b_tmp + 3] * n;
        }
      }
    } break;
    default:
      memset(&b[0], 0, 16U * sizeof(double));
      b[0] = 1.0;
      b[5] = 1.0;
      b[10] = 1.0;
      b[15] = 1.0;
      break;
    }
    for (jtilecol = 0; jtilecol < 16; jtilecol++) {
      b_b[jtilecol] = b_obj->ChildToJointTransform[jtilecol];
    }
    memset(&b_I[0], 0, sizeof(double) << 4);
    for (jtilecol = 0; jtilecol < 4; jtilecol++) {
      b_index = jtilecol << 2;
      for (i1 = 0; i1 < 4; i1++) {
        n = b[i1 + b_index];
        b_tmp = i1 << 2;
        b_I[b_index] += b_a[b_tmp] * n;
        b_I[b_index + 1] += b_a[b_tmp + 1] * n;
        b_I[b_index + 2] += b_a[b_tmp + 2] * n;
        b_I[b_index + 3] += b_a[b_tmp + 3] * n;
      }
    }
    memset(&b_a[0], 0, sizeof(double) << 4);
    for (i1 = 0; i1 < 4; i1++) {
      b_index = i1 << 2;
      for (jtilecol = 0; jtilecol < 4; jtilecol++) {
        b_tmp = jtilecol + b_index;
        n = b_b[b_tmp];
        a_tmp = jtilecol << 2;
        b_a[b_index] += b_I[a_tmp] * n;
        b_a[b_index + 1] += b_I[a_tmp + 1] * n;
        b_a[b_index + 2] += b_I[a_tmp + 2] * n;
        b_a[b_index + 3] += b_I[a_tmp + 3] * n;
        Ttree_data[b_i].f1[b_tmp] = 0.0;
      }
      b_index = i1 << 2;
      for (jtilecol = 0; jtilecol < 4; jtilecol++) {
        n = b_a[jtilecol + b_index];
        b_tmp = jtilecol << 2;
        Ttree_data[b_i].f1[b_index] += a[b_tmp] * n;
        Ttree_data[b_i].f1[b_index + 1] += a[b_tmp + 1] * n;
        Ttree_data[b_i].f1[b_index + 2] += a[b_tmp + 2] * n;
        Ttree_data[b_i].f1[b_index + 3] += a[b_tmp + 3] * n;
      }
    }
    k = d;
    if (body->ParentIndex > 0.0) {
      for (jtilecol = 0; jtilecol < 16; jtilecol++) {
        a[jtilecol] = Ttree_data[(int)body->ParentIndex - 1].f1[jtilecol];
      }
      memset(&b_a[0], 0, sizeof(double) << 4);
      for (jtilecol = 0; jtilecol < 4; jtilecol++) {
        b_index = jtilecol << 2;
        for (i1 = 0; i1 < 4; i1++) {
          n = Ttree_data[b_i].f1[i1 + b_index];
          b_tmp = i1 << 2;
          b_a[b_index] += a[b_tmp] * n;
          b_a[b_index + 1] += a[b_tmp + 1] * n;
          b_a[b_index + 2] += a[b_tmp + 2] * n;
          b_a[b_index + 3] += a[b_tmp + 3] * n;
        }
      }
      memcpy(&Ttree_data[b_i].f1[0], &b_a[0], 16U * sizeof(double));
    }
  }
  c_emxFreeStruct_robotics_manip_(&expl_temp);
}

/*
 * Arguments    : f_robotics_manip_internal_Rigid *obj
 * Return Type  : double
 */
double c_RigidBodyTree_findBodyIndexBy(f_robotics_manip_internal_Rigid *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double bid;
  double obj_Length;
  int exitg1;
  int i;
  int kstr;
  char obj_Vector[200];
  bool b_bool;
  bid = -1.0;
  obj_Length = obj->Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)obj_Length;
  }
  b_bool = false;
  if (kstr == 9) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 9) {
        if (obj_Vector[kstr] != cv2[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    bid = 0.0;
  } else {
    double d;
    int b_i;
    bool exitg2;
    d = obj->NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)d - 1)) {
      b_obj = obj->Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        kstr = 0;
      } else {
        kstr = (int)obj_Length;
      }
      b_bool = false;
      if (kstr == 9) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 9) {
            if (obj_Vector[kstr] != cv2[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        bid = (double)b_i + 1.0;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  return bid;
}

/*
 * Arguments    : f_robotics_manip_internal_Rigid *obj
 *                const char bodyname_data[]
 *                const int bodyname_size[2]
 * Return Type  : double
 */
double d_RigidBodyTree_findBodyIndexBy(f_robotics_manip_internal_Rigid *obj,
                                       const char bodyname_data[],
                                       const int bodyname_size[2])
{
  c_robotics_manip_internal_Rigid *b_obj;
  double bid;
  double obj_Length;
  int obj_Vector_size[2];
  int i;
  int loop_ub;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bid = -1.0;
  obj_Length = obj->Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  if (b_strcmp(obj_Vector_data, obj_Vector_size, bodyname_data,
               bodyname_size)) {
    bid = 0.0;
  } else {
    double d;
    int b_i;
    bool exitg1;
    d = obj->NumBodies;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= (int)d - 1)) {
      b_obj = obj->Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      obj_Vector_size[0] = 1;
      obj_Vector_size[1] = loop_ub;
      if (loop_ub - 1 >= 0) {
        memcpy(&obj_Vector_data[0], &obj_Vector[0],
               (unsigned int)loop_ub * sizeof(char));
      }
      if (b_strcmp(obj_Vector_data, obj_Vector_size, bodyname_data,
                   bodyname_size)) {
        bid = (double)b_i + 1.0;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
  return bid;
}

/*
 * Arguments    : f_robotics_manip_internal_Rigid *obj
 *                const char jointname_data[]
 *                const int jointname_size[2]
 * Return Type  : double
 */
double e_RigidBodyTree_findBodyIndexBy(f_robotics_manip_internal_Rigid *obj,
                                       const char jointname_data[],
                                       const int jointname_size[2])
{
  c_robotics_manip_internal_Rigid *b_obj;
  rigidBodyJoint *jnt;
  double bid;
  double d;
  int obj_Vector_size[2];
  int b_i;
  int i;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool exitg1;
  bid = -1.0;
  d = obj->NumBodies;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= (int)d - 1)) {
    double obj_Length;
    int loop_ub;
    b_obj = obj->Bodies[i];
    jnt = b_obj->JointInternal;
    obj_Length = jnt->NameInternal.Length;
    for (b_i = 0; b_i < 200; b_i++) {
      obj_Vector[b_i] = jnt->NameInternal.Vector[b_i];
    }
    if (obj_Length < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)obj_Length;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    if (b_strcmp(obj_Vector_data, obj_Vector_size, jointname_data,
                 jointname_size)) {
      bid = (double)i + 1.0;
      exitg1 = true;
    } else {
      i++;
    }
  }
  return bid;
}

/*
 * File trailer for RigidBodyTree1.c
 *
 * [EOF]
 */
