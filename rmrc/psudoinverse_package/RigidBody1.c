/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: RigidBody1.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "RigidBody1.h"
#include "CollisionSet.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_types.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "collisioncodegen_api.hpp"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : c_robotics_manip_internal_Rigid *obj
 * Return Type  : c_robotics_manip_internal_Rigid *
 */
c_robotics_manip_internal_Rigid *
RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj)
{
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  int k;
  int obj_FrameRigidTransforms_tmp;
  signed char c_I[36];
  signed char d_I[16];
  signed char b_I[9];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  obj_FrameRigidTransforms_tmp = b_obj->CollisionFrameIndices->size[0];
  b_obj->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(b_obj->CollisionFrameIndices,
                           obj_FrameRigidTransforms_tmp);
  for (k = 0; k < 100; k++) {
    b_obj->CollisionFrameIndices->data[k] = 0.0;
  }
  s = b_obj->NameInternal;
  s.Length = 4.0;
  s.Vector[0] = 'b';
  s.Vector[1] = 'a';
  s.Vector[2] = 's';
  s.Vector[3] = 'e';
  b_obj->NameInternal = s;
  b_obj->JointInternal =
      rigidBodyJoint_rigidBodyJoint(&b_obj->coder_buffer_pobj1);
  b_obj->JointInternal->InTree = false;
  b_obj->Index = -1.0;
  b_obj->ParentIndex = -1.0;
  b_obj->MassInternal = 1.0;
  b_obj->CenterOfMassInternal[0] = 0.0;
  b_obj->CenterOfMassInternal[1] = 0.0;
  b_obj->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    b_I[k] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (k = 0; k < 9; k++) {
    b_obj->InertiaInternal[k] = b_I[k];
  }
  for (k = 0; k < 36; k++) {
    c_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    c_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    b_obj->SpatialInertia[k] = c_I[k];
  }
  b_obj->CollisionsInternal =
      CollisionSet_CollisionSet(&b_obj->coder_buffer_pobj0, 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  obj_FrameRigidTransforms_tmp = obj_FrameRigidTransforms->size[0] *
                                 obj_FrameRigidTransforms->size[1] *
                                 obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms,
                           obj_FrameRigidTransforms_tmp);
  obj_FrameRigidTransforms_data = obj_FrameRigidTransforms->data;
  for (k = 0; k < 16; k++) {
    obj_FrameRigidTransforms_data[k] = 0;
    d_I[k] = 0;
  }
  d_I[0] = 1;
  d_I[5] = 1;
  d_I[10] = 1;
  d_I[15] = 1;
  for (k = 0; k < 4; k++) {
    obj_FrameRigidTransforms_tmp = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[obj_FrameRigidTransforms_tmp];
    obj_FrameRigidTransforms_data[4 * k + 1] =
        d_I[obj_FrameRigidTransforms_tmp + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] =
        d_I[obj_FrameRigidTransforms_tmp + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] =
        d_I[obj_FrameRigidTransforms_tmp + 3];
  }
  obj_FrameRigidTransforms_tmp =
      obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, obj_FrameRigidTransforms_tmp);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  obj_FrameNames_data[0] = 98U;
  obj_FrameNames_data[obj_FrameNames->size[0]] = 97U;
  obj_FrameNames_data[obj_FrameNames->size[0] * 2] = 115U;
  obj_FrameNames_data[obj_FrameNames->size[0] * 3] = 101U;
  obj_FrameRigidTransforms_tmp = b_obj->FramesInternal.FrameParents->size[0];
  b_obj->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(b_obj->FramesInternal.FrameParents,
                           obj_FrameRigidTransforms_tmp);
  b_obj->FramesInternal.FrameParents->data[0] = 0.0;
  obj_FrameRigidTransforms_tmp =
      b_obj->FramesInternal.FrameRigidTransforms->size[0] *
      b_obj->FramesInternal.FrameRigidTransforms->size[1] *
      b_obj->FramesInternal.FrameRigidTransforms->size[2];
  b_obj->FramesInternal.FrameRigidTransforms->size[0] = 4;
  b_obj->FramesInternal.FrameRigidTransforms->size[1] = 4;
  b_obj->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(b_obj->FramesInternal.FrameRigidTransforms,
                           obj_FrameRigidTransforms_tmp);
  for (k = 0; k < 16; k++) {
    b_obj->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  obj_FrameRigidTransforms_tmp = b_obj->FramesInternal.FrameNames->size[0] *
                                 b_obj->FramesInternal.FrameNames->size[1];
  b_obj->FramesInternal.FrameNames->size[0] = 1;
  b_obj->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(b_obj->FramesInternal.FrameNames,
                            obj_FrameRigidTransforms_tmp);
  for (k = 0; k < 200; k++) {
    b_obj->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  b_obj->FramesInternal.NumFrames = 1.0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : c_robotics_manip_internal_Rigid *obj
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : c_robotics_manip_internal_Rigid *
 */
c_robotics_manip_internal_Rigid *
RigidBody_copy(c_robotics_manip_internal_Rigid *obj,
               d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1,
               c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  void *copyGeometryInternal;
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Colli expl_temp;
  c_robotics_manip_internal_Colli r;
  c_robotics_manip_internal_Frame b_obj;
  c_robotics_manip_internal_Rigid *newbody;
  d_robotics_manip_internal_Colli *d_obj;
  emxArray_real_T *e_obj;
  double msubspace_data[36];
  double poslim_data[14];
  double c_obj[9];
  double obj_Length;
  double *obj_data;
  int b_loop_ub;
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int loop_ub;
  int poslim_size_idx_0;
  char vec_data[204];
  char obj_Vector[200];
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  bool result;
  obj_Length = obj->NameInternal.Length;
  for (k = 0; k < 200; k++) {
    obj_Vector[k] = obj->NameInternal.Vector[k];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  newbody = iobj_2;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  ibmat = iobj_2->CollisionFrameIndices->size[0];
  iobj_2->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_2->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_2->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_2->NameInternal;
  s.Length = loop_ub;
  if (loop_ub < 1) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub - 1 >= 0) {
    memcpy(&s.Vector[0], &obj_Vector[0],
           (unsigned int)b_loop_ub * sizeof(char));
  }
  iobj_2->NameInternal = s;
  iobj_1[0].InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_1[0].JointToParentTransform[k] = ibmat;
    iobj_1[0].ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_1[0].PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_1[0].HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_1[0].MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_1[0].NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_1[0].TypeInternal = s;
  s = iobj_1[0].NameInternal;
  ibmat = loop_ub + 4;
  if (loop_ub - 1 >= 0) {
    memcpy(&vec_data[0], &obj_Vector[0], (unsigned int)loop_ub * sizeof(char));
  }
  vec_data[loop_ub] = '_';
  vec_data[loop_ub + 1] = 'j';
  vec_data[loop_ub + 2] = 'n';
  vec_data[loop_ub + 3] = 't';
  s.Length = loop_ub + 4;
  if (ibmat - 1 >= 0) {
    memcpy(&s.Vector[0], &vec_data[0], (unsigned int)ibmat * sizeof(char));
  }
  iobj_1[0].NameInternal = s;
  s = iobj_1[0].TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_1[0].TypeInternal = s;
  s = iobj_1[0].TypeInternal;
  if (s.Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)s.Length;
  }
  result = false;
  if (loop_ub == 8) {
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
    if (loop_ub == 9) {
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
      if (loop_ub == 8) {
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
    iobj_1[0].VelocityNumber = 1.0;
    iobj_1[0].PositionNumber = 1.0;
    iobj_1[0].JointAxisInternal[0] = 0.0;
    iobj_1[0].JointAxisInternal[1] = 0.0;
    iobj_1[0].JointAxisInternal[2] = 1.0;
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
    iobj_1[0].VelocityNumber = 1.0;
    iobj_1[0].PositionNumber = 1.0;
    iobj_1[0].JointAxisInternal[0] = 0.0;
    iobj_1[0].JointAxisInternal[1] = 0.0;
    iobj_1[0].JointAxisInternal[2] = 1.0;
    break;
  case 2: {
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
    iobj_1[0].VelocityNumber = 6.0;
    iobj_1[0].PositionNumber = 7.0;
    iobj_1[0].JointAxisInternal[0] = rtNaN;
    iobj_1[0].JointAxisInternal[1] = rtNaN;
    iobj_1[0].JointAxisInternal[2] = rtNaN;
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
    iobj_1[0].VelocityNumber = 0.0;
    iobj_1[0].PositionNumber = 0.0;
    iobj_1[0].JointAxisInternal[0] = 0.0;
    iobj_1[0].JointAxisInternal[1] = 0.0;
    iobj_1[0].JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(&iobj_1[0], msubspace_data);
  s = iobj_1[0].TypeInternal;
  if (s.Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)s.Length;
  }
  result = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (s.Vector[loop_ub] != cv3[loop_ub]) {
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
    obj_Length = iobj_1[0].PositionNumber;
    if (obj_Length < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)obj_Length;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_1[0].PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_1[0].HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_1[0].PositionLimitsInternal[0] = poslim_data[0];
    iobj_1[0].PositionLimitsInternal[7] = poslim_data[1];
    iobj_1[0].HomePositionInternal[0] = homepos_data[0];
  }
  iobj_2->JointInternal = &iobj_1[0];
  iobj_2->JointInternal->InTree = false;
  iobj_2->Index = -1.0;
  iobj_2->ParentIndex = -1.0;
  iobj_2->MassInternal = 1.0;
  iobj_2->CenterOfMassInternal[0] = 0.0;
  iobj_2->CenterOfMassInternal[1] = 0.0;
  iobj_2->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_2->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->SpatialInertia[k] = b_I[k];
  }
  iobj_2->CollisionsInternal = CollisionSet_CollisionSet(&iobj_0[0], 0.0);
  e_emxInitStruct_robotics_manip_(&b_obj);
  ibmat = b_obj.FrameParents->size[0];
  b_obj.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(b_obj.FrameParents, ibmat);
  b_obj.FrameParents->data[0] = 0.0;
  ibmat = b_obj.FrameRigidTransforms->size[0] *
          b_obj.FrameRigidTransforms->size[1] *
          b_obj.FrameRigidTransforms->size[2];
  b_obj.FrameRigidTransforms->size[0] = 4;
  b_obj.FrameRigidTransforms->size[1] = 4;
  b_obj.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(b_obj.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    b_obj.FrameRigidTransforms->data[k] = 0.0;
    d_I[k] = 0;
  }
  d_I[0] = 1;
  d_I[5] = 1;
  d_I[10] = 1;
  d_I[15] = 1;
  for (k = 0; k < 4; k++) {
    ibmat = k << 2;
    b_obj.FrameRigidTransforms->data[4 * k] = d_I[ibmat];
    b_obj.FrameRigidTransforms->data[4 * k + 1] = d_I[ibmat + 1];
    b_obj.FrameRigidTransforms->data[4 * k + 2] = d_I[ibmat + 2];
    b_obj.FrameRigidTransforms->data[4 * k + 3] = d_I[ibmat + 3];
  }
  b_obj.NumFrames = 1.0;
  ibmat = b_obj.FrameNames->size[0] * b_obj.FrameNames->size[1];
  b_obj.FrameNames->size[0] = 1;
  b_obj.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(b_obj.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    b_obj.FrameNames->data[k] = 0U;
  }
  for (k = 0; k < b_loop_ub; k++) {
    b_obj.FrameNames->data[b_obj.FrameNames->size[0] * k] =
        (unsigned char)obj_Vector[k];
  }
  double obj_idx_1;
  double obj_idx_2;
  c_emxCopyStruct_robotics_manip_(&iobj_2->FramesInternal, &b_obj);
  iobj_2->matlabCodegenIsDeleted = false;
  iobj_2->JointInternal = rigidBodyJoint_copy(obj->JointInternal, &iobj_1[1]);
  iobj_2->MassInternal = obj->MassInternal;
  obj_Length = obj->CenterOfMassInternal[0];
  obj_idx_1 = obj->CenterOfMassInternal[1];
  obj_idx_2 = obj->CenterOfMassInternal[2];
  iobj_2->CenterOfMassInternal[0] = obj_Length;
  iobj_2->CenterOfMassInternal[1] = obj_idx_1;
  iobj_2->CenterOfMassInternal[2] = obj_idx_2;
  for (k = 0; k < 9; k++) {
    c_obj[k] = obj->InertiaInternal[k];
  }
  for (k = 0; k < 9; k++) {
    iobj_2->InertiaInternal[k] = c_obj[k];
  }
  for (k = 0; k < 36; k++) {
    msubspace_data[k] = obj->SpatialInertia[k];
  }
  for (k = 0; k < 36; k++) {
    iobj_2->SpatialInertia[k] = msubspace_data[k];
  }
  d_obj = obj->CollisionsInternal;
  iobj_0 = CollisionSet_CollisionSet(&iobj_0[1], d_obj->MaxElements);
  iobj_0->Size = d_obj->Size;
  obj_Length = d_obj->Size;
  ibmat = (int)obj_Length;
  for (k = 0; k < ibmat; k++) {
    r = d_obj->CollisionGeometries->data[k];
    copyGeometryInternal = collisioncodegen_copyGeometry(r.CollisionPrimitive);
    expl_temp.CollisionPrimitive = copyGeometryInternal;
    memcpy(&expl_temp.LocalPose[0], &r.LocalPose[0], 16U * sizeof(double));
    memcpy(&expl_temp.WorldPose[0], &r.WorldPose[0], 16U * sizeof(double));
    expl_temp.MeshScale[0] = r.MeshScale[0];
    expl_temp.MeshScale[1] = r.MeshScale[1];
    expl_temp.MeshScale[2] = r.MeshScale[2];
    expl_temp.ColorAlpha[0] = r.ColorAlpha[0];
    expl_temp.ColorAlpha[1] = r.ColorAlpha[1];
    expl_temp.ColorAlpha[2] = r.ColorAlpha[2];
    expl_temp.ColorAlpha[3] = r.ColorAlpha[3];
    iobj_0->CollisionGeometries->data[k] = expl_temp;
  }
  iobj_2->CollisionsInternal = iobj_0;
  c_emxCopyStruct_robotics_manip_(&b_obj, &obj->FramesInternal);
  c_emxCopyStruct_robotics_manip_(&iobj_2->FramesInternal, &b_obj);
  c_emxFreeStruct_robotics_manip_(&b_obj);
  emxInit_real_T(&e_obj, 1);
  loop_ub = obj->CollisionFrameIndices->size[0];
  ibmat = e_obj->size[0];
  e_obj->size[0] = loop_ub;
  emxEnsureCapacity_real_T(e_obj, ibmat);
  obj_data = e_obj->data;
  ibmat = obj->CollisionFrameIndices->size[0];
  for (k = 0; k < ibmat; k++) {
    obj_data[k] = obj->CollisionFrameIndices->data[k];
  }
  ibmat = iobj_2->CollisionFrameIndices->size[0];
  iobj_2->CollisionFrameIndices->size[0] = loop_ub;
  emxEnsureCapacity_real_T(iobj_2->CollisionFrameIndices, ibmat);
  for (k = 0; k < loop_ub; k++) {
    iobj_2->CollisionFrameIndices->data[k] = obj_data[k];
  }
  emxFree_real_T(&e_obj);
  return newbody;
}

/*
 * Arguments    : c_robotics_manip_internal_Rigid *obj
 *                const char bodyInput[10]
 * Return Type  : c_robotics_manip_internal_Rigid *
 */
c_robotics_manip_internal_Rigid *
b_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      const char bodyInput[10])
{
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  int k;
  int obj_FrameRigidTransforms_tmp;
  signed char c_I[36];
  signed char d_I[16];
  char b_bodyInput[14];
  signed char b_I[9];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  b_obj->NameInternal = s;
  obj_FrameRigidTransforms_tmp = b_obj->CollisionFrameIndices->size[0];
  b_obj->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(b_obj->CollisionFrameIndices,
                           obj_FrameRigidTransforms_tmp);
  for (k = 0; k < 100; k++) {
    b_obj->CollisionFrameIndices->data[k] = 0.0;
  }
  s = b_obj->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = bodyInput[k];
  }
  b_obj->NameInternal = s;
  for (k = 0; k < 10; k++) {
    b_bodyInput[k] = bodyInput[k];
  }
  b_bodyInput[10] = '_';
  b_bodyInput[11] = 'j';
  b_bodyInput[12] = 'n';
  b_bodyInput[13] = 't';
  b_obj->JointInternal =
      b_rigidBodyJoint_rigidBodyJoint(&b_obj->coder_buffer_pobj1, b_bodyInput);
  b_obj->JointInternal->InTree = false;
  b_obj->Index = -1.0;
  b_obj->ParentIndex = -1.0;
  b_obj->MassInternal = 1.0;
  b_obj->CenterOfMassInternal[0] = 0.0;
  b_obj->CenterOfMassInternal[1] = 0.0;
  b_obj->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    b_I[k] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (k = 0; k < 9; k++) {
    b_obj->InertiaInternal[k] = b_I[k];
  }
  for (k = 0; k < 36; k++) {
    c_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    c_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    b_obj->SpatialInertia[k] = c_I[k];
  }
  b_obj->CollisionsInternal =
      CollisionSet_CollisionSet(&b_obj->coder_buffer_pobj0, 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  obj_FrameRigidTransforms_tmp = obj_FrameRigidTransforms->size[0] *
                                 obj_FrameRigidTransforms->size[1] *
                                 obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms,
                           obj_FrameRigidTransforms_tmp);
  obj_FrameRigidTransforms_data = obj_FrameRigidTransforms->data;
  for (k = 0; k < 16; k++) {
    obj_FrameRigidTransforms_data[k] = 0;
    d_I[k] = 0;
  }
  d_I[0] = 1;
  d_I[5] = 1;
  d_I[10] = 1;
  d_I[15] = 1;
  for (k = 0; k < 4; k++) {
    obj_FrameRigidTransforms_tmp = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[obj_FrameRigidTransforms_tmp];
    obj_FrameRigidTransforms_data[4 * k + 1] =
        d_I[obj_FrameRigidTransforms_tmp + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] =
        d_I[obj_FrameRigidTransforms_tmp + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] =
        d_I[obj_FrameRigidTransforms_tmp + 3];
  }
  obj_FrameRigidTransforms_tmp =
      obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, obj_FrameRigidTransforms_tmp);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 10; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] =
        (unsigned char)bodyInput[k];
  }
  obj_FrameRigidTransforms_tmp = b_obj->FramesInternal.FrameParents->size[0];
  b_obj->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(b_obj->FramesInternal.FrameParents,
                           obj_FrameRigidTransforms_tmp);
  b_obj->FramesInternal.FrameParents->data[0] = 0.0;
  obj_FrameRigidTransforms_tmp =
      b_obj->FramesInternal.FrameRigidTransforms->size[0] *
      b_obj->FramesInternal.FrameRigidTransforms->size[1] *
      b_obj->FramesInternal.FrameRigidTransforms->size[2];
  b_obj->FramesInternal.FrameRigidTransforms->size[0] = 4;
  b_obj->FramesInternal.FrameRigidTransforms->size[1] = 4;
  b_obj->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(b_obj->FramesInternal.FrameRigidTransforms,
                           obj_FrameRigidTransforms_tmp);
  for (k = 0; k < 16; k++) {
    b_obj->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  obj_FrameRigidTransforms_tmp = b_obj->FramesInternal.FrameNames->size[0] *
                                 b_obj->FramesInternal.FrameNames->size[1];
  b_obj->FramesInternal.FrameNames->size[0] = 1;
  b_obj->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(b_obj->FramesInternal.FrameNames,
                            obj_FrameRigidTransforms_tmp);
  for (k = 0; k < 200; k++) {
    b_obj->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  b_obj->FramesInternal.NumFrames = 1.0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * File trailer for RigidBody1.c
 *
 * [EOF]
 */
