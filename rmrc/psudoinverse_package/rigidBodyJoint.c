/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: rigidBodyJoint.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "rigidBodyJoint.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_types.h"
#include "rt_nonfinite.h"
#include "validatestring.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void c_rigidBodyJoint_resetHomePosit(rigidBodyJoint *obj);

static void d_rigidBodyJoint_set_MotionSubs(rigidBodyJoint *obj,
                                            const double msubspace[6]);

/* Function Definitions */
/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
static void c_rigidBodyJoint_resetHomePosit(rigidBodyJoint *obj)
{
  double ub_data[7];
  double d;
  int i;
  int loop_ub;
  d = obj->PositionNumber;
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)d;
  }
  if (loop_ub - 1 >= 0) {
    memcpy(&ub_data[0], &obj->PositionLimitsInternal[7],
           (unsigned int)loop_ub * sizeof(double));
  }
  if (obj->PositionNumber == 1.0) {
    int ix;
    bool b_data[7];
    bool x_data[7];
    bool exitg1;
    bool guard1;
    bool guard2;
    bool guard3;
    bool y;
    for (i = 0; i < loop_ub; i++) {
      d = obj->PositionLimitsInternal[i];
      b_data[i] = ((!rtIsInf(d)) && (!rtIsNaN(d)));
    }
    y = true;
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= loop_ub)) {
      if (!b_data[ix - 1]) {
        y = false;
        exitg1 = true;
      } else {
        ix++;
      }
    }
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (y) {
      bool b_y;
      for (i = 0; i < loop_ub; i++) {
        d = obj->PositionLimitsInternal[i + 7];
        x_data[i] = ((!rtIsInf(d)) && (!rtIsNaN(d)));
      }
      b_y = true;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= loop_ub)) {
        if (!x_data[ix - 1]) {
          b_y = false;
          exitg1 = true;
        } else {
          ix++;
        }
      }
      if (b_y) {
        for (i = 0; i < loop_ub; i++) {
          ub_data[i] = 0.5 * (obj->PositionLimitsInternal[i] +
                              obj->PositionLimitsInternal[i + 7]);
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
    if (guard3) {
      if (y) {
        for (i = 0; i < loop_ub; i++) {
          d = obj->PositionLimitsInternal[i + 7];
          x_data[i] = (rtIsInf(d) || rtIsNaN(d));
        }
        y = false;
        ix = 1;
        exitg1 = false;
        while ((!exitg1) && (ix <= loop_ub)) {
          if (x_data[ix - 1]) {
            y = true;
            exitg1 = true;
          } else {
            ix++;
          }
        }
        if (y) {
          if (loop_ub - 1 >= 0) {
            memcpy(&ub_data[0], &obj->PositionLimitsInternal[0],
                   (unsigned int)loop_ub * sizeof(double));
          }
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    }
    if (guard2) {
      for (i = 0; i < loop_ub; i++) {
        b_data[i] = !b_data[i];
      }
      y = false;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= loop_ub)) {
        if (b_data[ix - 1]) {
          y = true;
          exitg1 = true;
        } else {
          ix++;
        }
      }
      if (y) {
        for (i = 0; i < loop_ub; i++) {
          d = obj->PositionLimitsInternal[i + 7];
          x_data[i] = ((!rtIsInf(d)) && (!rtIsNaN(d)));
        }
        y = true;
        ix = 1;
        exitg1 = false;
        while ((!exitg1) && (ix <= loop_ub)) {
          if (!x_data[ix - 1]) {
            y = false;
            exitg1 = true;
          } else {
            ix++;
          }
        }
        if (!y) {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
    if (guard1) {
      ix = (signed char)loop_ub;
      if (ix - 1 >= 0) {
        memset(&ub_data[0], 0, (unsigned int)ix * sizeof(double));
      }
    }
    if (loop_ub - 1 >= 0) {
      memcpy(&obj->HomePositionInternal[0], &ub_data[0],
             (unsigned int)loop_ub * sizeof(double));
    }
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 *                const double msubspace[6]
 * Return Type  : void
 */
static void d_rigidBodyJoint_set_MotionSubs(rigidBodyJoint *obj,
                                            const double msubspace[6])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  int i;
  int i1;
  int loop_ub;
  bool b_bool;
  if (obj->TypeInternal.Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj->TypeInternal.Vector[loop_ub] != b_cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    double d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int i2;
        i2 = i1 + 6 * i;
        obj->MotionSubspaceInternal[i2] = msubspace[i2];
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      obj->MotionSubspaceInternal[i] = 0.0;
    }
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 *                const char jname[14]
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *b_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj,
                                                const char jname[14])
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 14.0;
  for (k = 0; k < 14; k++) {
    s.Vector[k] = jname[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv1[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv2[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv3[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void b_rigidBodyJoint_set_JointAxis(rigidBodyJoint *obj)
{
  static const double dv[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
  static const double dv1[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  int kstr;
  bool result;
  obj->JointAxisInternal[0] = 0.0;
  obj->JointAxisInternal[1] = 1.0;
  obj->JointAxisInternal[2] = 0.0;
  if (obj->TypeInternal.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)obj->TypeInternal.Length;
  }
  result = false;
  if (kstr == 8) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (b_cv[kstr] != obj->TypeInternal.Vector[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    kstr = 0;
  } else {
    kstr = -1;
  }
  if (kstr == 0) {
    d_rigidBodyJoint_set_MotionSubs(obj, dv1);
  } else {
    d_rigidBodyJoint_set_MotionSubs(obj, dv);
  }
}

/*
 * Arguments    : const rigidBodyJoint *obj
 *                double msubspace_data[]
 *                int msubspace_size[2]
 * Return Type  : void
 */
void c_rigidBodyJoint_get_MotionSubs(const rigidBodyJoint *obj,
                                     double msubspace_data[],
                                     int msubspace_size[2])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  int i;
  int i1;
  int loop_ub;
  bool b_bool;
  if (obj->TypeInternal.Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj->TypeInternal.Vector[loop_ub] != b_cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    double d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    msubspace_size[0] = 6;
    msubspace_size[1] = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int msubspace_data_tmp;
        msubspace_data_tmp = i1 + 6 * i;
        msubspace_data[msubspace_data_tmp] =
            obj->MotionSubspaceInternal[msubspace_data_tmp];
      }
    }
  } else {
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *c_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv[14] = {'b', 'a', 's', 'e', '_', 'l', 'i',
                                'n', 'k', '-', 'b', 'a', 's', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 14.0;
  for (k = 0; k < 14; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void c_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj)
{
  int i;
  for (i = 0; i < 16; i++) {
    obj->JointToParentTransform[i] = iv[i];
    obj->ChildToJointTransform[i] = 0.0;
  }
  obj->ChildToJointTransform[0] = 1.0;
  obj->ChildToJointTransform[5] = 1.0;
  obj->ChildToJointTransform[10] = 1.0;
  obj->ChildToJointTransform[15] = 1.0;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void c_rigidBodyJoint_set_JointAxis(rigidBodyJoint *obj)
{
  static const double dv[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  static const double dv1[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  int kstr;
  bool result;
  obj->JointAxisInternal[0] = 1.0;
  obj->JointAxisInternal[1] = 0.0;
  obj->JointAxisInternal[2] = 0.0;
  if (obj->TypeInternal.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)obj->TypeInternal.Length;
  }
  result = false;
  if (kstr == 8) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (b_cv[kstr] != obj->TypeInternal.Vector[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    kstr = 0;
  } else {
    kstr = -1;
  }
  if (kstr == 0) {
    d_rigidBodyJoint_set_MotionSubs(obj, dv1);
  } else {
    d_rigidBodyJoint_set_MotionSubs(obj, dv);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 *                const double msubspace_data[]
 * Return Type  : void
 */
void c_rigidBodyJoint_set_MotionSubs(rigidBodyJoint *obj,
                                     const double msubspace_data[])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  int i;
  int i1;
  int loop_ub;
  bool b_bool;
  if (obj->TypeInternal.Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj->TypeInternal.Vector[loop_ub] != b_cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    double d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int i2;
        i2 = i1 + 6 * i;
        obj->MotionSubspaceInternal[i2] = msubspace_data[i2];
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      obj->MotionSubspaceInternal[i] = 0.0;
    }
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void c_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj)
{
  double dv[2];
  double d;
  int b_loop_ub;
  int i;
  int i1;
  bool resetHome;
  resetHome = false;
  switch ((int)obj->PositionNumber) {
  case 0:
  case 7:
    break;
  default: {
    int loop_ub;
    bool x_data[7];
    bool exitg1;
    bool y;
    d = obj->PositionNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (obj->HomePositionInternal[i] > 2.87979);
    }
    y = false;
    b_loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub <= loop_ub)) {
      if (x_data[b_loop_ub - 1]) {
        y = true;
        exitg1 = true;
      } else {
        b_loop_ub++;
      }
    }
    if (y) {
      resetHome = true;
    } else {
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (obj->HomePositionInternal[i] < -2.87979);
      }
      y = false;
      b_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= loop_ub)) {
        if (x_data[b_loop_ub - 1]) {
          y = true;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (y) {
        resetHome = true;
      }
    }
  } break;
  }
  d = obj->PositionNumber;
  dv[0] = -2.87979;
  dv[1] = 2.87979;
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      obj->PositionLimitsInternal[i1 + 7 * i] = dv[i1 + b_loop_ub * i];
    }
  }
  if (resetHome) {
    c_rigidBodyJoint_resetHomePosit(obj);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *d_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[7] = {'j', 'o', 'i', 'n', 't', '_', '1'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 7.0;
  for (k = 0; k < 7; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void d_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj)
{
  static const double inputTform[16] = {1.0, 0.0, 0.0,  0.0, 0.0, 1.0,
                                        0.0, 0.0, 0.0,  0.0, 1.0, 0.0,
                                        0.0, 0.0, 0.29, 1.0};
  int i;
  for (i = 0; i < 16; i++) {
    obj->JointToParentTransform[i] = inputTform[i];
    obj->ChildToJointTransform[i] = 0.0;
  }
  obj->ChildToJointTransform[0] = 1.0;
  obj->ChildToJointTransform[5] = 1.0;
  obj->ChildToJointTransform[10] = 1.0;
  obj->ChildToJointTransform[15] = 1.0;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void d_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj)
{
  double dv[2];
  double d;
  int b_loop_ub;
  int i;
  int i1;
  bool resetHome;
  resetHome = false;
  switch ((int)obj->PositionNumber) {
  case 0:
  case 7:
    break;
  default: {
    int loop_ub;
    bool x_data[7];
    bool exitg1;
    bool y;
    d = obj->PositionNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (obj->HomePositionInternal[i] > 1.91986);
    }
    y = false;
    b_loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub <= loop_ub)) {
      if (x_data[b_loop_ub - 1]) {
        y = true;
        exitg1 = true;
      } else {
        b_loop_ub++;
      }
    }
    if (y) {
      resetHome = true;
    } else {
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (obj->HomePositionInternal[i] < -1.91986);
      }
      y = false;
      b_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= loop_ub)) {
        if (x_data[b_loop_ub - 1]) {
          y = true;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (y) {
        resetHome = true;
      }
    }
  } break;
  }
  d = obj->PositionNumber;
  dv[0] = -1.91986;
  dv[1] = 1.91986;
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      obj->PositionLimitsInternal[i1 + 7 * i] = dv[i1 + b_loop_ub * i];
    }
  }
  if (resetHome) {
    c_rigidBodyJoint_resetHomePosit(obj);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *e_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[7] = {'j', 'o', 'i', 'n', 't', '_', '2'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 7.0;
  for (k = 0; k < 7; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void e_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj)
{
  static const double inputTform[16] = {1.0, 0.0, 0.0,  0.0, 0.0, 1.0,
                                        0.0, 0.0, 0.0,  0.0, 1.0, 0.0,
                                        0.0, 0.0, 0.27, 1.0};
  int i;
  for (i = 0; i < 16; i++) {
    obj->JointToParentTransform[i] = inputTform[i];
    obj->ChildToJointTransform[i] = 0.0;
  }
  obj->ChildToJointTransform[0] = 1.0;
  obj->ChildToJointTransform[5] = 1.0;
  obj->ChildToJointTransform[10] = 1.0;
  obj->ChildToJointTransform[15] = 1.0;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void e_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj)
{
  double dv[2];
  double d;
  int b_loop_ub;
  int i;
  int i1;
  bool resetHome;
  resetHome = false;
  switch ((int)obj->PositionNumber) {
  case 0:
  case 7:
    break;
  default: {
    int loop_ub;
    bool x_data[7];
    bool exitg1;
    bool y;
    d = obj->PositionNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (obj->HomePositionInternal[i] > 1.22173);
    }
    y = false;
    b_loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub <= loop_ub)) {
      if (x_data[b_loop_ub - 1]) {
        y = true;
        exitg1 = true;
      } else {
        b_loop_ub++;
      }
    }
    if (y) {
      resetHome = true;
    } else {
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (obj->HomePositionInternal[i] < -1.91986);
      }
      y = false;
      b_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= loop_ub)) {
        if (x_data[b_loop_ub - 1]) {
          y = true;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (y) {
        resetHome = true;
      }
    }
  } break;
  }
  d = obj->PositionNumber;
  dv[0] = -1.91986;
  dv[1] = 1.22173;
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      obj->PositionLimitsInternal[i1 + 7 * i] = dv[i1 + b_loop_ub * i];
    }
  }
  if (resetHome) {
    c_rigidBodyJoint_resetHomePosit(obj);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *f_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[7] = {'j', 'o', 'i', 'n', 't', '_', '3'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 7.0;
  for (k = 0; k < 7; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void f_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj)
{
  static const double inputTform[16] = {1.0, 0.0, 0.0,  0.0, 0.0, 1.0,
                                        0.0, 0.0, 0.0,  0.0, 1.0, 0.0,
                                        0.0, 0.0, 0.07, 1.0};
  int i;
  for (i = 0; i < 16; i++) {
    obj->JointToParentTransform[i] = inputTform[i];
    obj->ChildToJointTransform[i] = 0.0;
  }
  obj->ChildToJointTransform[0] = 1.0;
  obj->ChildToJointTransform[5] = 1.0;
  obj->ChildToJointTransform[10] = 1.0;
  obj->ChildToJointTransform[15] = 1.0;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void f_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj)
{
  double dv[2];
  double d;
  int b_loop_ub;
  int i;
  int i1;
  bool resetHome;
  resetHome = false;
  switch ((int)obj->PositionNumber) {
  case 0:
  case 7:
    break;
  default: {
    int loop_ub;
    bool x_data[7];
    bool exitg1;
    bool y;
    d = obj->PositionNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (obj->HomePositionInternal[i] > 2.79253);
    }
    y = false;
    b_loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub <= loop_ub)) {
      if (x_data[b_loop_ub - 1]) {
        y = true;
        exitg1 = true;
      } else {
        b_loop_ub++;
      }
    }
    if (y) {
      resetHome = true;
    } else {
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (obj->HomePositionInternal[i] < -2.79253);
      }
      y = false;
      b_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= loop_ub)) {
        if (x_data[b_loop_ub - 1]) {
          y = true;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (y) {
        resetHome = true;
      }
    }
  } break;
  }
  d = obj->PositionNumber;
  dv[0] = -2.79253;
  dv[1] = 2.79253;
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      obj->PositionLimitsInternal[i1 + 7 * i] = dv[i1 + b_loop_ub * i];
    }
  }
  if (resetHome) {
    c_rigidBodyJoint_resetHomePosit(obj);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *g_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[7] = {'j', 'o', 'i', 'n', 't', '_', '4'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 7.0;
  for (k = 0; k < 7; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void g_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj)
{
  static const double inputTform[16] = {1.0,   0.0, 0.0, 0.0, 0.0, 1.0,
                                        0.0,   0.0, 0.0, 0.0, 1.0, 0.0,
                                        0.302, 0.0, 0.0, 1.0};
  int i;
  for (i = 0; i < 16; i++) {
    obj->JointToParentTransform[i] = inputTform[i];
    obj->ChildToJointTransform[i] = 0.0;
  }
  obj->ChildToJointTransform[0] = 1.0;
  obj->ChildToJointTransform[5] = 1.0;
  obj->ChildToJointTransform[10] = 1.0;
  obj->ChildToJointTransform[15] = 1.0;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void g_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj)
{
  double dv[2];
  double d;
  int b_loop_ub;
  int i;
  int i1;
  bool resetHome;
  resetHome = false;
  switch ((int)obj->PositionNumber) {
  case 0:
  case 7:
    break;
  default: {
    int loop_ub;
    bool x_data[7];
    bool exitg1;
    bool y;
    d = obj->PositionNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (obj->HomePositionInternal[i] > 2.094395);
    }
    y = false;
    b_loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub <= loop_ub)) {
      if (x_data[b_loop_ub - 1]) {
        y = true;
        exitg1 = true;
      } else {
        b_loop_ub++;
      }
    }
    if (y) {
      resetHome = true;
    } else {
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (obj->HomePositionInternal[i] < -2.094395);
      }
      y = false;
      b_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= loop_ub)) {
        if (x_data[b_loop_ub - 1]) {
          y = true;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (y) {
        resetHome = true;
      }
    }
  } break;
  }
  d = obj->PositionNumber;
  dv[0] = -2.094395;
  dv[1] = 2.094395;
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      obj->PositionLimitsInternal[i1 + 7 * i] = dv[i1 + b_loop_ub * i];
    }
  }
  if (resetHome) {
    c_rigidBodyJoint_resetHomePosit(obj);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *h_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[7] = {'j', 'o', 'i', 'n', 't', '_', '5'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 7.0;
  for (k = 0; k < 7; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void h_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj)
{
  static const double inputTform[16] = {1.0,   0.0, 0.0, 0.0, 0.0, 1.0,
                                        0.0,   0.0, 0.0, 0.0, 1.0, 0.0,
                                        0.072, 0.0, 0.0, 1.0};
  int i;
  for (i = 0; i < 16; i++) {
    obj->JointToParentTransform[i] = inputTform[i];
    obj->ChildToJointTransform[i] = 0.0;
  }
  obj->ChildToJointTransform[0] = 1.0;
  obj->ChildToJointTransform[5] = 1.0;
  obj->ChildToJointTransform[10] = 1.0;
  obj->ChildToJointTransform[15] = 1.0;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void h_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj)
{
  double dv[2];
  double d;
  int b_loop_ub;
  int i;
  int i1;
  bool resetHome;
  resetHome = false;
  switch ((int)obj->PositionNumber) {
  case 0:
  case 7:
    break;
  default: {
    int loop_ub;
    bool x_data[7];
    bool exitg1;
    bool y;
    d = obj->PositionNumber;
    if (d < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)d;
    }
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (obj->HomePositionInternal[i] > 6.98132);
    }
    y = false;
    b_loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub <= loop_ub)) {
      if (x_data[b_loop_ub - 1]) {
        y = true;
        exitg1 = true;
      } else {
        b_loop_ub++;
      }
    }
    if (y) {
      resetHome = true;
    } else {
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (obj->HomePositionInternal[i] < -6.98132);
      }
      y = false;
      b_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= loop_ub)) {
        if (x_data[b_loop_ub - 1]) {
          y = true;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (y) {
        resetHome = true;
      }
    }
  } break;
  }
  d = obj->PositionNumber;
  dv[0] = -6.98132;
  dv[1] = 6.98132;
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      obj->PositionLimitsInternal[i1 + 7 * i] = dv[i1 + b_loop_ub * i];
    }
  }
  if (resetHome) {
    c_rigidBodyJoint_resetHomePosit(obj);
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *i_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[7] = {'j', 'o', 'i', 'n', 't', '_', '6'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 7.0;
  for (k = 0; k < 7; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *j_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv[12] = {'j', 'o', 'i', 'n', 't', '6',
                                '-', 't', 'o', 'o', 'l', '0'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 12.0;
  for (k = 0; k < 12; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : const rigidBodyJoint *obj
 *                rigidBodyJoint *iobj_0
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *rigidBodyJoint_copy(const rigidBodyJoint *obj,
                                    rigidBodyJoint *iobj_0)
{
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv1[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara b_obj;
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *newjoint;
  double msubspace_data[36];
  double d_obj[16];
  double poslim_data[14];
  double c_obj[7];
  double obj_Length;
  int obj_Vector_size[2];
  int vec_size[2];
  int b_loop_ub;
  int exitg1;
  int i;
  int ibmat;
  int k;
  int loop_ub;
  int poslim_size_idx_0;
  char vec_data[204];
  char obj_Vector[200];
  char obj_Vector_data[200];
  signed char homepos_data[7];
  bool result;
  obj_Length = obj->TypeInternal.Length;
  for (k = 0; k < 200; k++) {
    obj_Vector[k] = obj->TypeInternal.Vector[k];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_obj = obj->NameInternal;
  if (b_obj.Length < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)b_obj.Length;
  }
  iobj_0->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_0->JointToParentTransform[k] = ibmat;
    iobj_0->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_0->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_0->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_0->MotionSubspaceInternal[k] = 0.0;
  }
  newjoint = iobj_0;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_0->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_0->TypeInternal = s;
  s = iobj_0->NameInternal;
  s.Length = b_loop_ub;
  if (b_loop_ub < 1) {
    b_loop_ub = 0;
  }
  if (b_loop_ub - 1 >= 0) {
    memcpy(&s.Vector[0], &b_obj.Vector[0],
           (unsigned int)b_loop_ub * sizeof(char));
  }
  iobj_0->NameInternal = s;
  b_obj = iobj_0->TypeInternal;
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  validatestring(obj_Vector_data, obj_Vector_size, vec_data, vec_size);
  b_obj.Length = vec_size[1];
  ibmat = vec_size[1];
  if (ibmat - 1 >= 0) {
    memcpy(&b_obj.Vector[0], &vec_data[0], (unsigned int)ibmat * sizeof(char));
  }
  iobj_0->TypeInternal = b_obj;
  obj_Length = iobj_0->TypeInternal.Length;
  for (k = 0; k < 200; k++) {
    obj_Vector[k] = iobj_0->TypeInternal.Vector[k];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  result = false;
  if (loop_ub == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv[ibmat] != obj_Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (loop_ub == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != obj_Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (loop_ub == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv1[ibmat] != obj_Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    b_loop_ub = 1;
    homepos_data[0] = 0;
    iobj_0->VelocityNumber = 1.0;
    iobj_0->PositionNumber = 1.0;
    iobj_0->JointAxisInternal[0] = 0.0;
    iobj_0->JointAxisInternal[1] = 0.0;
    iobj_0->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    b_loop_ub = 1;
    homepos_data[0] = 0;
    iobj_0->VelocityNumber = 1.0;
    iobj_0->PositionNumber = 1.0;
    iobj_0->JointAxisInternal[0] = 0.0;
    iobj_0->JointAxisInternal[1] = 0.0;
    iobj_0->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    b_loop_ub = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    iobj_0->VelocityNumber = 6.0;
    iobj_0->PositionNumber = 7.0;
    iobj_0->JointAxisInternal[0] = rtNaN;
    iobj_0->JointAxisInternal[1] = rtNaN;
    iobj_0->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    b_loop_ub = 1;
    homepos_data[0] = 0;
    iobj_0->VelocityNumber = 0.0;
    iobj_0->PositionNumber = 0.0;
    iobj_0->JointAxisInternal[0] = 0.0;
    iobj_0->JointAxisInternal[1] = 0.0;
    iobj_0->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_0, msubspace_data);
  obj_Length = iobj_0->TypeInternal.Length;
  for (k = 0; k < 200; k++) {
    obj_Vector[k] = iobj_0->TypeInternal.Vector[k];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  result = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv2[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    obj_Length = iobj_0->PositionNumber;
    if (obj_Length < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)obj_Length;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_0->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < b_loop_ub; k++) {
      iobj_0->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_0->PositionLimitsInternal[0] = poslim_data[0];
    iobj_0->PositionLimitsInternal[7] = poslim_data[1];
    iobj_0->HomePositionInternal[0] = homepos_data[0];
  }
  obj_Length = obj->NameInternal.Length;
  if (obj_Length < 1.0) {
    ibmat = 0;
  } else {
    ibmat = (int)obj_Length;
  }
  if (ibmat != 0) {
    obj_Length = obj->NameInternal.Length;
    for (k = 0; k < 200; k++) {
      obj_Vector[k] = obj->NameInternal.Vector[k];
    }
    if (obj_Length < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)obj_Length;
    }
    if (!iobj_0->InTree) {
      b_obj = iobj_0->NameInternal;
      b_obj.Length = ibmat;
      if (ibmat < 1) {
        ibmat = 0;
      }
      if (ibmat - 1 >= 0) {
        memcpy(&b_obj.Vector[0], &obj_Vector[0],
               (unsigned int)ibmat * sizeof(char));
      }
      iobj_0->NameInternal = b_obj;
    }
  }
  for (k = 0; k < 14; k++) {
    poslim_data[k] = obj->PositionLimitsInternal[k];
  }
  for (k = 0; k < 14; k++) {
    iobj_0->PositionLimitsInternal[k] = poslim_data[k];
  }
  for (k = 0; k < 7; k++) {
    c_obj[k] = obj->HomePositionInternal[k];
  }
  for (k = 0; k < 7; k++) {
    iobj_0->HomePositionInternal[k] = c_obj[k];
  }
  double obj_idx_1;
  double obj_idx_2;
  obj_Length = obj->JointAxisInternal[0];
  obj_idx_1 = obj->JointAxisInternal[1];
  obj_idx_2 = obj->JointAxisInternal[2];
  iobj_0->JointAxisInternal[0] = obj_Length;
  iobj_0->JointAxisInternal[1] = obj_idx_1;
  iobj_0->JointAxisInternal[2] = obj_idx_2;
  c_rigidBodyJoint_get_MotionSubs(obj, msubspace_data, obj_Vector_size);
  c_rigidBodyJoint_set_MotionSubs(iobj_0, msubspace_data);
  for (k = 0; k < 16; k++) {
    d_obj[k] = obj->JointToParentTransform[k];
  }
  for (k = 0; k < 16; k++) {
    iobj_0->JointToParentTransform[k] = d_obj[k];
  }
  for (k = 0; k < 16; k++) {
    d_obj[k] = obj->ChildToJointTransform[k];
  }
  for (k = 0; k < 16; k++) {
    iobj_0->ChildToJointTransform[k] = d_obj[k];
  }
  return newjoint;
}

/*
 * Arguments    : const rigidBodyJoint *obj
 *                double ax[3]
 * Return Type  : void
 */
void rigidBodyJoint_get_JointAxis(const rigidBodyJoint *obj, double ax[3])
{
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  int exitg1;
  int kstr;
  bool b_bool;
  bool guard1;
  if (obj->TypeInternal.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (kstr == 8) {
    int b_kstr;
    b_kstr = 0;
    do {
      exitg1 = 0;
      if (b_kstr < 8) {
        if (obj->TypeInternal.Vector[b_kstr] != b_cv[b_kstr]) {
          exitg1 = 1;
        } else {
          b_kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  guard1 = false;
  if (b_bool) {
    guard1 = true;
  } else {
    b_bool = false;
    if (kstr == 9) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 9) {
          if (obj->TypeInternal.Vector[kstr] != cv1[kstr]) {
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
      guard1 = true;
    } else {
      ax[0] = rtNaN;
      ax[1] = rtNaN;
      ax[2] = rtNaN;
    }
  }
  if (guard1) {
    ax[0] = obj->JointAxisInternal[0];
    ax[1] = obj->JointAxisInternal[1];
    ax[2] = obj->JointAxisInternal[2];
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : rigidBodyJoint *
 */
rigidBodyJoint *rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj)
{
  static const char b_cv[8] = {'b', 'a', 's', 'e', '_', 'j', 'n', 't'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  bool result;
  b_obj = obj;
  b_obj->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    b_obj->JointToParentTransform[k] = ibmat;
    b_obj->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    b_obj->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    b_obj->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    b_obj->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = 8.0;
  for (k = 0; k < 8; k++) {
    s.Vector[k] = b_cv[k];
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv1[k];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (kstr == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv1[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (kstr == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = b_iv1[k];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (k = 0; k < 36; k++) {
      b_I[k] = 0;
    }
    for (k = 0; k < 6; k++) {
      b_I[k + 6 * k] = 1;
    }
    for (k = 0; k < 36; k++) {
      msubspace_data[k] = b_I[k];
    }
    poslim_size_idx_0 = 7;
    for (k = 0; k < 2; k++) {
      signed char b_tmp;
      ibmat = k * 3;
      b_tmp = (signed char)(10 * k - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * k] = rtNaN;
      poslim_data[7 * k + 1] = rtNaN;
      poslim_data[7 * k + 2] = rtNaN;
      poslim_data[7 * k + 3] = rtNaN;
    }
    for (k = 0; k < 2; k++) {
      poslim_data[7 * k + 4] = b[3 * k];
      poslim_data[7 * k + 5] = b[3 * k + 1];
      poslim_data[7 * k + 6] = b[3 * k + 2];
    }
    homepos_size_idx_1 = 7;
    for (k = 0; k < 7; k++) {
      homepos_data[k] = iv2[k];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (k = 0; k < 6; k++) {
      msubspace_data[k] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)s.Length;
  }
  result = false;
  if (kstr == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (s.Vector[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        b_obj->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      b_obj->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void rigidBodyJoint_set_HomePosition(rigidBodyJoint *obj)
{
  double d;
  int loop_ub;
  d = obj->PositionNumber;
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)d;
  }
  if (loop_ub - 1 >= 0) {
    memset(&obj->HomePositionInternal[0], 0,
           (unsigned int)loop_ub * sizeof(double));
  }
}

/*
 * Arguments    : rigidBodyJoint *obj
 * Return Type  : void
 */
void rigidBodyJoint_set_JointAxis(rigidBodyJoint *obj)
{
  static const double dv[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  static const double dv1[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  int kstr;
  bool result;
  obj->JointAxisInternal[0] = 0.0;
  obj->JointAxisInternal[1] = 0.0;
  obj->JointAxisInternal[2] = 1.0;
  if (obj->TypeInternal.Length < 1.0) {
    kstr = 0;
  } else {
    kstr = (int)obj->TypeInternal.Length;
  }
  result = false;
  if (kstr == 8) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (b_cv[kstr] != obj->TypeInternal.Vector[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    kstr = 0;
  } else {
    kstr = -1;
  }
  if (kstr == 0) {
    d_rigidBodyJoint_set_MotionSubs(obj, dv1);
  } else {
    d_rigidBodyJoint_set_MotionSubs(obj, dv);
  }
}

/*
 * File trailer for rigidBodyJoint.c
 *
 * [EOF]
 */
