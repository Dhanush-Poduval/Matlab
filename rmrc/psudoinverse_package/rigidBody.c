/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: rigidBody.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "rigidBody.h"
#include "CollisionSet.h"
#include "RigidBody1.h"
#include "RigidBodyTree1.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_internal_types.h"
#include "psudoinverse_function_types.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const signed char iv1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};

/* Function Definitions */
/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *b_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[10] = {'l', 'i', 'n', 'k', '_',
                                 '1', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '1'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 49U};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 6.0;
  for (k = 0; k < 6; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[0], 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 6; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[1], 1.0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void b_rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = 9.77E-5;
  b_obj->CenterOfMassInternal[1] = -0.00012;
  b_obj->CenterOfMassInternal[2] = 0.23841;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void b_rigidBody_set_Inertia(rigidBody *obj)
{
  static const double inertiaInternal[9] = {
      0.1885437634475,  -1.2821942492E-5,   -9.4574979019E-5,
      -1.2821942492E-5, 0.1887303485581045, 0.0001070848164,
      -9.4574979019E-5, 0.0001070848164,    0.01045337344020443};
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = inertiaInternal[i];
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void b_rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 3.067;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *c_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[10] = {'l', 'i', 'n', 'k', '_',
                                 '2', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '2'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 50U};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 6.0;
  for (k = 0; k < 6; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[0], 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 6; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[1], 1.0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void c_rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = 0.00078;
  b_obj->CenterOfMassInternal[1] = -0.00212;
  b_obj->CenterOfMassInternal[2] = 0.10124;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void c_rigidBody_set_Inertia(rigidBody *obj)
{
  static const double inertiaInternal[9] = {
      0.100394111088,   1.62982324E-5,          -0.0002514420848,
      1.62982324E-5,    0.081636820714,         0.00033401397919999992,
      -0.0002514420848, 0.00033401397919999992, 0.0259747468452};
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = inertiaInternal[i];
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void c_rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 3.909;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *d_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[10] = {'l', 'i', 'n', 'k', '_',
                                 '3', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '3'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 51U};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 6.0;
  for (k = 0; k < 6; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[0], 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 6; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[1], 1.0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void d_rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = 0.02281;
  b_obj->CenterOfMassInternal[1] = 0.00106;
  b_obj->CenterOfMassInternal[2] = 0.05791;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void d_rigidBody_set_Inertia(rigidBody *obj)
{
  static const double inertiaInternal[9] = {
      0.0182322723648,        -0.0001513362984, -0.0024599693824000012,
      -0.0001513362984,       0.0281176562048,  -0.0003629432624,
      -0.0024599693824000012, -0.0003629432624, 0.0142334595968};
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = inertiaInternal[i];
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void d_rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 2.944;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *e_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[10] = {'l', 'i', 'n', 'k', '_',
                                 '4', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '4'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 52U};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 6.0;
  for (k = 0; k < 6; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[0], 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 6; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[1], 1.0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void e_rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = 0.2247;
  b_obj->CenterOfMassInternal[1] = 0.00015;
  b_obj->CenterOfMassInternal[2] = 0.00041;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void e_rigidBody_set_Inertia(rigidBody *obj)
{
  static const double inertiaInternal[9] = {
      0.0028468631168, -6.603674E-5,         -0.000138779656,
      -6.603674E-5,    0.071064522756800017, 1.3051928E-5,
      -0.000138779656, 1.3051928E-5,         0.072304369400000013};
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = inertiaInternal[i];
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void e_rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 1.328;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *f_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[10] = {'l', 'i', 'n', 'k', '_',
                                 '5', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '5'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 53U};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 6.0;
  for (k = 0; k < 6; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[0], 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 6; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[1], 1.0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void f_rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = -0.00109;
  b_obj->CenterOfMassInternal[1] = 3.68E-5;
  b_obj->CenterOfMassInternal[2] = 6.22E-5;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void f_rigidBody_set_Inertia(rigidBody *obj)
{
  static const double inertiaInternal[9] = {
      0.00040489385180168, 1.641331152E-6,         8.83822708E-7,
      1.641331152E-6,      0.00089347581498663993, -1.642897216E-8,
      8.83822708E-7,       -1.642897216E-8,        0.00081611744201504};
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = inertiaInternal[i];
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void f_rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 0.546;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *g_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[10] = {'l', 'i', 'n', 'k', '_',
                                 '6', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '6'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 54U};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 6.0;
  for (k = 0; k < 6; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 10.0;
  for (k = 0; k < 10; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[0], 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 6; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(&iobj_1[1], 1.0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void g_rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = -0.00706;
  b_obj->CenterOfMassInternal[1] = -0.00017;
  b_obj->CenterOfMassInternal[2] = -1.32E-6;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void g_rigidBody_set_Inertia(rigidBody *obj)
{
  static const double inertiaInternal[9] = {
      0.0010000039595387091, -1.644274E-7,         -1.2767304E-9,
      -1.644274E-7,          0.001006828573438709, -3.07428E-11,
      -1.2767304E-9,         -3.07428E-11,         0.0010068325325};
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = inertiaInternal[i];
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void g_rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 0.137;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                d_robotics_manip_internal_Colli *iobj_1
 *                rigidBodyJoint *iobj_2
 *                c_robotics_manip_internal_Rigid *iobj_3
 * Return Type  : rigidBody *
 */
rigidBody *h_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3)
{
  static const char b_cv1[9] = {'t', 'o', 'o', 'l', '0', '_', 'j', 'n', 't'};
  static const char cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char b_iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv[5] = {'t', 'o', 'o', 'l', '0'};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const unsigned char b_uv[5] = {116U, 111U, 111U, 108U, 48U};
  static const char cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  emxArray_int8_T *obj_FrameRigidTransforms;
  emxArray_uint8_T *obj_FrameNames;
  rigidBody *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int ibmat;
  int k;
  int kstr;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char d_I[16];
  signed char c_I[9];
  signed char homepos_data[7];
  unsigned char *obj_FrameNames_data;
  signed char *obj_FrameRigidTransforms_data;
  bool result;
  b_obj = obj;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_3->NameInternal = s;
  ibmat = iobj_3->CollisionFrameIndices->size[0];
  iobj_3->CollisionFrameIndices->size[0] = 100;
  emxEnsureCapacity_real_T(iobj_3->CollisionFrameIndices, ibmat);
  for (k = 0; k < 100; k++) {
    iobj_3->CollisionFrameIndices->data[k] = 0.0;
  }
  s = iobj_3->NameInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv[k];
  }
  iobj_3->NameInternal = s;
  iobj_2->InTree = false;
  for (k = 0; k < 16; k++) {
    ibmat = iv[k];
    iobj_2->JointToParentTransform[k] = ibmat;
    iobj_2->ChildToJointTransform[k] = ibmat;
  }
  for (k = 0; k < 14; k++) {
    iobj_2->PositionLimitsInternal[k] = 0.0;
  }
  for (k = 0; k < 7; k++) {
    iobj_2->HomePositionInternal[k] = 0.0;
  }
  for (k = 0; k < 36; k++) {
    iobj_2->MotionSubspaceInternal[k] = 0.0;
  }
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->NameInternal = s;
  s.Length = 200.0;
  for (k = 0; k < 200; k++) {
    s.Vector[k] = ' ';
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->NameInternal;
  s.Length = 9.0;
  for (k = 0; k < 9; k++) {
    s.Vector[k] = b_cv1[k];
  }
  iobj_2->NameInternal = s;
  s = iobj_2->TypeInternal;
  s.Length = 5.0;
  for (k = 0; k < 5; k++) {
    s.Vector[k] = b_cv2[k];
  }
  iobj_2->TypeInternal = s;
  s = iobj_2->TypeInternal;
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
            if (cv4[ibmat] != s.Vector[ibmat]) {
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 1.0;
    iobj_2->PositionNumber = 1.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 1.0;
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
    iobj_2->VelocityNumber = 6.0;
    iobj_2->PositionNumber = 7.0;
    iobj_2->JointAxisInternal[0] = rtNaN;
    iobj_2->JointAxisInternal[1] = rtNaN;
    iobj_2->JointAxisInternal[2] = rtNaN;
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
    iobj_2->VelocityNumber = 0.0;
    iobj_2->PositionNumber = 0.0;
    iobj_2->JointAxisInternal[0] = 0.0;
    iobj_2->JointAxisInternal[1] = 0.0;
    iobj_2->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_2, msubspace_data);
  s = iobj_2->TypeInternal;
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
        if (s.Vector[kstr] != cv5[kstr]) {
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
    d = iobj_2->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (k = 0; k < 2; k++) {
      for (i = 0; i < ibmat; i++) {
        iobj_2->PositionLimitsInternal[i + 7 * k] =
            poslim_data[i + poslim_size_idx_0 * k];
      }
    }
    for (k = 0; k < homepos_size_idx_1; k++) {
      iobj_2->HomePositionInternal[k] = homepos_data[k];
    }
  } else {
    iobj_2->PositionLimitsInternal[0] = poslim_data[0];
    iobj_2->PositionLimitsInternal[7] = poslim_data[1];
    iobj_2->HomePositionInternal[0] = homepos_data[0];
  }
  iobj_3->JointInternal = iobj_2;
  iobj_3->JointInternal->InTree = false;
  iobj_3->Index = -1.0;
  iobj_3->ParentIndex = -1.0;
  iobj_3->MassInternal = 1.0;
  iobj_3->CenterOfMassInternal[0] = 0.0;
  iobj_3->CenterOfMassInternal[1] = 0.0;
  iobj_3->CenterOfMassInternal[2] = 0.0;
  for (k = 0; k < 9; k++) {
    c_I[k] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (k = 0; k < 9; k++) {
    iobj_3->InertiaInternal[k] = c_I[k];
  }
  for (k = 0; k < 36; k++) {
    b_I[k] = 0;
  }
  for (k = 0; k < 6; k++) {
    b_I[k + 6 * k] = 1;
  }
  for (k = 0; k < 36; k++) {
    iobj_3->SpatialInertia[k] = b_I[k];
  }
  iobj_3->CollisionsInternal = CollisionSet_CollisionSet(iobj_1, 0.0);
  emxInit_uint8_T(&obj_FrameNames);
  emxInit_int8_T(&obj_FrameRigidTransforms);
  ibmat = obj_FrameRigidTransforms->size[0] *
          obj_FrameRigidTransforms->size[1] * obj_FrameRigidTransforms->size[2];
  obj_FrameRigidTransforms->size[0] = 4;
  obj_FrameRigidTransforms->size[1] = 4;
  obj_FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_int8_T(obj_FrameRigidTransforms, ibmat);
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
    ibmat = k << 2;
    obj_FrameRigidTransforms_data[4 * k] = d_I[ibmat];
    obj_FrameRigidTransforms_data[4 * k + 1] = d_I[ibmat + 1];
    obj_FrameRigidTransforms_data[4 * k + 2] = d_I[ibmat + 2];
    obj_FrameRigidTransforms_data[4 * k + 3] = d_I[ibmat + 3];
  }
  ibmat = obj_FrameNames->size[0] * obj_FrameNames->size[1];
  obj_FrameNames->size[0] = 1;
  obj_FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(obj_FrameNames, ibmat);
  obj_FrameNames_data = obj_FrameNames->data;
  for (k = 0; k < 200; k++) {
    obj_FrameNames_data[k] = 0U;
  }
  for (k = 0; k < 5; k++) {
    obj_FrameNames_data[obj_FrameNames->size[0] * k] = b_uv[k];
  }
  ibmat = iobj_3->FramesInternal.FrameParents->size[0];
  iobj_3->FramesInternal.FrameParents->size[0] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameParents, ibmat);
  iobj_3->FramesInternal.FrameParents->data[0] = 0.0;
  ibmat = iobj_3->FramesInternal.FrameRigidTransforms->size[0] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[1] *
          iobj_3->FramesInternal.FrameRigidTransforms->size[2];
  iobj_3->FramesInternal.FrameRigidTransforms->size[0] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[1] = 4;
  iobj_3->FramesInternal.FrameRigidTransforms->size[2] = 1;
  emxEnsureCapacity_real_T(iobj_3->FramesInternal.FrameRigidTransforms, ibmat);
  for (k = 0; k < 16; k++) {
    iobj_3->FramesInternal.FrameRigidTransforms->data[k] =
        obj_FrameRigidTransforms_data[k];
  }
  emxFree_int8_T(&obj_FrameRigidTransforms);
  ibmat = iobj_3->FramesInternal.FrameNames->size[0] *
          iobj_3->FramesInternal.FrameNames->size[1];
  iobj_3->FramesInternal.FrameNames->size[0] = 1;
  iobj_3->FramesInternal.FrameNames->size[1] = 200;
  emxEnsureCapacity_uint8_T(iobj_3->FramesInternal.FrameNames, ibmat);
  for (k = 0; k < 200; k++) {
    iobj_3->FramesInternal.FrameNames->data[k] = obj_FrameNames_data[k];
  }
  emxFree_uint8_T(&obj_FrameNames);
  iobj_3->FramesInternal.NumFrames = 1.0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  b_obj->BodyInternal = iobj_3;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 *                e_robotics_manip_internal_Rigid *iobj_0
 *                c_robotics_manip_internal_Rigid *iobj_1
 * Return Type  : rigidBody *
 */
rigidBody *rigidBody_rigidBody(rigidBody *obj,
                               e_robotics_manip_internal_Rigid *iobj_0,
                               c_robotics_manip_internal_Rigid *iobj_1)
{
  rigidBody *b_obj;
  b_obj = obj;
  iobj_1 = RigidBody_RigidBody(iobj_1);
  iobj_0 = RigidBodyTree_RigidBodyTree(iobj_0);
  b_obj->BodyInternal = iobj_1;
  b_obj->TreeInternal = iobj_0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void rigidBody_set_CenterOfMass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->CenterOfMassInternal[0] = 0.0;
  b_obj->CenterOfMassInternal[1] = 0.0;
  b_obj->CenterOfMassInternal[2] = 0.0;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void rigidBody_set_Inertia(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = 0.0;
  }
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * Arguments    : rigidBody *obj
 * Return Type  : void
 */
void rigidBody_set_Mass(rigidBody *obj)
{
  c_robotics_manip_internal_Rigid *b_obj;
  double inertia[9];
  double sc[9];
  double com_idx_0;
  double com_idx_1;
  double com_idx_2;
  double mass;
  int i;
  int i1;
  b_obj = obj->BodyInternal;
  b_obj->MassInternal = 0.0;
  mass = b_obj->MassInternal;
  com_idx_0 = b_obj->CenterOfMassInternal[0];
  com_idx_1 = b_obj->CenterOfMassInternal[1];
  com_idx_2 = b_obj->CenterOfMassInternal[2];
  for (i = 0; i < 9; i++) {
    inertia[i] = b_obj->InertiaInternal[i];
  }
  sc[0] = 0.0;
  sc[3] = -com_idx_2;
  sc[6] = com_idx_1;
  sc[1] = com_idx_2;
  sc[4] = 0.0;
  sc[7] = -com_idx_0;
  sc[2] = -com_idx_1;
  sc[5] = com_idx_0;
  sc[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i] = inertia[3 * i];
    b_obj->SpatialInertia[6 * i + 1] = inertia[3 * i + 1];
    b_obj->SpatialInertia[6 * i + 2] = inertia[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1] = mass * sc[3 * i];
    b_obj->SpatialInertia[i1 + 1] = mass * sc[3 * i + 1];
    b_obj->SpatialInertia[i1 + 2] = mass * sc[3 * i + 2];
  }
  for (i = 0; i < 3; i++) {
    b_obj->SpatialInertia[6 * i + 3] = mass * sc[i];
    b_obj->SpatialInertia[6 * i + 4] = mass * sc[i + 3];
    b_obj->SpatialInertia[6 * i + 5] = mass * sc[i + 6];
  }
  for (i = 0; i < 3; i++) {
    i1 = 6 * (i + 3);
    b_obj->SpatialInertia[i1 + 3] = mass * (double)iv1[3 * i];
    b_obj->SpatialInertia[i1 + 4] = mass * (double)iv1[3 * i + 1];
    b_obj->SpatialInertia[i1 + 5] = mass * (double)iv1[3 * i + 2];
  }
}

/*
 * File trailer for rigidBody.c
 *
 * [EOF]
 */
