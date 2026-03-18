/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: rigidBodyTree.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "rigidBodyTree.h"
#include "CollisionSet.h"
#include "FrameTree.h"
#include "RigidBody1.h"
#include "RigidBodyTree1.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_internal_types.h"
#include "psudoinverse_function_types.h"
#include "rand.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void b_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '1'};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_obj;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double obj_Length;
  double parentfid;
  int obj_Vector_size[2];
  int exitg1;
  int i;
  int loop_ub;
  int pid;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool b_bool;
  bool exitg2;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = -1;
  obj_Length = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
  if (b_bool) {
    pid = 0;
  } else {
    int b_i;
    b_index = obj->TreeInternal.NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)b_index - 1)) {
      b_obj = obj->TreeInternal.Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      b_bool = false;
      if (loop_ub == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if (b_bool) {
        pid = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  if (pid == -1) {
    b_bool = FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, &parentfid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      pid = 0;
    } else {
      b_index = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)b_index - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = FrameTree_isFrameInTree(expl_temp.FrameNames,
                                         expl_temp.NumFrames, &parentfid);
        if (b_bool) {
          pid = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    parentfid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv1[loop_ub]) {
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
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = parentfid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void c_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '2'};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_obj;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double obj_Length;
  double parentfid;
  int obj_Vector_size[2];
  int exitg1;
  int i;
  int loop_ub;
  int pid;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool b_bool;
  bool exitg2;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = -1;
  obj_Length = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
  if (b_bool) {
    pid = 0;
  } else {
    int b_i;
    b_index = obj->TreeInternal.NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)b_index - 1)) {
      b_obj = obj->TreeInternal.Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      b_bool = false;
      if (loop_ub == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if (b_bool) {
        pid = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  if (pid == -1) {
    b_bool = b_FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, &parentfid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      pid = 0;
    } else {
      b_index = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)b_index - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = b_FrameTree_isFrameInTree(expl_temp.FrameNames,
                                           expl_temp.NumFrames, &parentfid);
        if (b_bool) {
          pid = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    parentfid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv1[loop_ub]) {
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
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = parentfid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void d_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '3'};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_obj;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double obj_Length;
  double parentfid;
  int obj_Vector_size[2];
  int exitg1;
  int i;
  int loop_ub;
  int pid;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool b_bool;
  bool exitg2;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = -1;
  obj_Length = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
  if (b_bool) {
    pid = 0;
  } else {
    int b_i;
    b_index = obj->TreeInternal.NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)b_index - 1)) {
      b_obj = obj->TreeInternal.Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      b_bool = false;
      if (loop_ub == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if (b_bool) {
        pid = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  if (pid == -1) {
    b_bool = c_FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, &parentfid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      pid = 0;
    } else {
      b_index = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)b_index - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = c_FrameTree_isFrameInTree(expl_temp.FrameNames,
                                           expl_temp.NumFrames, &parentfid);
        if (b_bool) {
          pid = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    parentfid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv1[loop_ub]) {
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
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = parentfid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void e_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '4'};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_obj;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double obj_Length;
  double parentfid;
  int obj_Vector_size[2];
  int exitg1;
  int i;
  int loop_ub;
  int pid;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool b_bool;
  bool exitg2;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = -1;
  obj_Length = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
  if (b_bool) {
    pid = 0;
  } else {
    int b_i;
    b_index = obj->TreeInternal.NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)b_index - 1)) {
      b_obj = obj->TreeInternal.Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      b_bool = false;
      if (loop_ub == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if (b_bool) {
        pid = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  if (pid == -1) {
    b_bool = d_FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, &parentfid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      pid = 0;
    } else {
      b_index = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)b_index - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = d_FrameTree_isFrameInTree(expl_temp.FrameNames,
                                           expl_temp.NumFrames, &parentfid);
        if (b_bool) {
          pid = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    parentfid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv1[loop_ub]) {
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
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = parentfid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void f_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '5'};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_obj;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double obj_Length;
  double parentfid;
  int obj_Vector_size[2];
  int exitg1;
  int i;
  int loop_ub;
  int pid;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool b_bool;
  bool exitg2;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = -1;
  obj_Length = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
  if (b_bool) {
    pid = 0;
  } else {
    int b_i;
    b_index = obj->TreeInternal.NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)b_index - 1)) {
      b_obj = obj->TreeInternal.Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      b_bool = false;
      if (loop_ub == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if (b_bool) {
        pid = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  if (pid == -1) {
    b_bool = e_FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, &parentfid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      pid = 0;
    } else {
      b_index = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)b_index - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = e_FrameTree_isFrameInTree(expl_temp.FrameNames,
                                           expl_temp.NumFrames, &parentfid);
        if (b_bool) {
          pid = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    parentfid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv1[loop_ub]) {
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
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = parentfid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void g_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[6] = {'l', 'i', 'n', 'k', '_', '6'};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_obj;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double obj_Length;
  double parentfid;
  int obj_Vector_size[2];
  int exitg1;
  int i;
  int loop_ub;
  int pid;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool b_bool;
  bool exitg2;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = -1;
  obj_Length = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
  if (b_bool) {
    pid = 0;
  } else {
    int b_i;
    b_index = obj->TreeInternal.NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)b_index - 1)) {
      b_obj = obj->TreeInternal.Bodies[b_i];
      obj_Length = b_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->NameInternal.Vector[i];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      b_bool = false;
      if (loop_ub == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if (b_bool) {
        pid = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  if (pid == -1) {
    b_bool = f_FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, &parentfid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      pid = 0;
    } else {
      b_index = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)b_index - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = f_FrameTree_isFrameInTree(expl_temp.FrameNames,
                                           expl_temp.NumFrames, &parentfid);
        if (b_bool) {
          pid = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    parentfid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv1[loop_ub]) {
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
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = parentfid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                rigidBody *bodyin
 *                d_robotics_manip_internal_Colli *iobj_0
 *                rigidBodyJoint *iobj_1
 *                c_robotics_manip_internal_Rigid *iobj_2
 * Return Type  : void
 */
void rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                           d_robotics_manip_internal_Colli *iobj_0,
                           rigidBodyJoint *iobj_1,
                           c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double fid;
  double obj_Length;
  double pid;
  int obj_Vector_size[2];
  int i;
  int loop_ub;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bool isFrameInBase;
  body = bodyin->BodyInternal;
  obj_Length = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
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
  d_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  pid = c_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal);
  if (pid == -1.0) {
    e_emxInitStruct_robotics_manip_(&expl_temp);
    loop_ub = expl_temp.FrameNames->size[0] * expl_temp.FrameNames->size[1];
    expl_temp.FrameNames->size[0] =
        obj->TreeInternal.Base.FramesInternal.FrameNames->size[0];
    expl_temp.FrameNames->size[1] = 200;
    emxEnsureCapacity_uint8_T(expl_temp.FrameNames, loop_ub);
    loop_ub = obj->TreeInternal.Base.FramesInternal.FrameNames->size[0] * 200;
    for (i = 0; i < loop_ub; i++) {
      expl_temp.FrameNames->data[i] =
          obj->TreeInternal.Base.FramesInternal.FrameNames->data[i];
    }
    obj_Length = obj->TreeInternal.Base.FramesInternal.NumFrames;
    fid = FrameTree_getFrameIdx(expl_temp.FrameNames, obj_Length);
    isFrameInBase = (fid > 0.0);
    if (isFrameInBase) {
      pid = 0.0;
    } else {
      bool exitg1;
      obj_Length = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (int)obj_Length - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        fid = FrameTree_getFrameIdx(expl_temp.FrameNames, expl_temp.NumFrames);
        if (fid > 0.0) {
          pid = (double)loop_ub + 1.0;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    fid = 1.0;
  }
  jnt = body->JointInternal;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
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
  e_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal, obj_Vector_data,
                                  obj_Vector_size);
  b_index = obj->TreeInternal.NumBodies + 1.0;
  body = RigidBody_copy(body, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->TreeInternal.Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->TreeInternal.NumBodies++;
  jnt = body->JointInternal;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  isFrameInBase = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    int exitg2;
    do {
      exitg2 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
          exitg2 = 1;
        } else {
          loop_ub++;
        }
      } else {
        isFrameInBase = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  if (!isFrameInBase) {
    obj->TreeInternal.NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->TreeInternal.VelocityDoFMap[loop_ub] =
        obj->TreeInternal.VelocityNumber + 1.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 8] =
        obj->TreeInternal.VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->TreeInternal.VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->TreeInternal.VelocityDoFMap[loop_ub + 7] = -1.0;
  }
  jnt = body->JointInternal;
  obj->TreeInternal.PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->TreeInternal.VelocityNumber += jnt->VelocityNumber;
  obj->TreeInternal.BodyParentFrameIdx[(int)b_index - 1] = fid;
}

/*
 * Arguments    : rigidBodyTree *obj
 *                const double Q[6]
 *                const char endeffectorname[5]
 *                double Jac_data[]
 *                int Jac_size[2]
 * Return Type  : void
 */
void rigidBodyTree_geometricJacobian(rigidBodyTree *obj, const double Q[6],
                                     const char endeffectorname[5],
                                     double Jac_data[], int Jac_size[2])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const signed char b_iv[4] = {0, 0, 0, 1};
  c_robotics_manip_internal_Frame expl_temp;
  c_robotics_manip_internal_Rigid *b_body;
  c_robotics_manip_internal_Rigid *body;
  cell_wrap_30 bodyTtree_data[8];
  rigidBodyJoint *b_obj;
  double b_data[336];
  double T1[16];
  double T2[16];
  double Tdh[16];
  double b_T2inv[16];
  double b_R[9];
  double c_R[3];
  double frid;
  double idx_idx_0;
  double idx_idx_1;
  double velnum;
  int b_obj_Vector_size[2];
  int obj_Vector_size[2];
  int b_i;
  int b_loop_ub;
  int bidx;
  int c_loop_ub;
  int exitg1;
  int i;
  int i1;
  int i2;
  int i4;
  int loop_ub;
  char b_obj_Vector[200];
  char obj_Vector[200];
  char obj_Vector_data[200];
  signed char chainmask[8];
  bool b_bool;
  bool exitg2;
  bidx = -1;
  idx_idx_1 = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (idx_idx_1 < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)idx_idx_1;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != endeffectorname[loop_ub]) {
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
  if (b_bool) {
    bidx = 0;
  } else {
    idx_idx_0 = obj->TreeInternal.NumBodies;
    b_loop_ub = 0;
    exitg2 = false;
    while ((!exitg2) && (b_loop_ub <= (int)idx_idx_0 - 1)) {
      body = obj->TreeInternal.Bodies[b_loop_ub];
      idx_idx_1 = body->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = body->NameInternal.Vector[i];
      }
      if (idx_idx_1 < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)idx_idx_1;
      }
      b_bool = false;
      if (loop_ub == 5) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 5) {
            if (obj_Vector[loop_ub] != endeffectorname[loop_ub]) {
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
      if (b_bool) {
        bidx = b_loop_ub + 1;
        exitg2 = true;
      } else {
        b_loop_ub++;
      }
    }
  }
  if (bidx == -1) {
    b_bool = g_FrameTree_isFrameInTree(
        obj->TreeInternal.Base.FramesInternal.FrameNames,
        obj->TreeInternal.Base.FramesInternal.NumFrames, endeffectorname,
        &frid);
    e_emxInitStruct_robotics_manip_(&expl_temp);
    if (b_bool) {
      bidx = 0;
    } else {
      idx_idx_0 = obj->TreeInternal.NumBodies;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= (int)idx_idx_0 - 1)) {
        c_emxCopyStruct_robotics_manip_(
            &expl_temp, &obj->TreeInternal.Bodies[loop_ub]->FramesInternal);
        b_bool = g_FrameTree_isFrameInTree(
            expl_temp.FrameNames, expl_temp.NumFrames, endeffectorname, &frid);
        if (b_bool) {
          bidx = loop_ub + 1;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    c_emxFreeStruct_robotics_manip_(&expl_temp);
  } else {
    frid = 1.0;
  }
  velnum = obj->TreeInternal.VelocityNumber;
  Jac_size[0] = 6;
  i1 = (int)velnum;
  Jac_size[1] = (int)velnum;
  c_loop_ub = 6 * (int)velnum;
  if (c_loop_ub - 1 >= 0) {
    memset(&Jac_data[0], 0, (unsigned int)c_loop_ub * sizeof(double));
  }
  for (i = 0; i < 8; i++) {
    chainmask[i] = 0;
  }
  if (bidx == 0) {
    body = &obj->TreeInternal.Base;
  } else {
    body = obj->TreeInternal.Bodies[bidx - 1];
  }
  idx_idx_1 = body->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = body->NameInternal.Vector[i];
  }
  if (idx_idx_1 < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)idx_idx_1;
  }
  idx_idx_0 = obj->TreeInternal.Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    b_obj_Vector[i] = obj->TreeInternal.Base.NameInternal.Vector[i];
  }
  if (idx_idx_0 < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)idx_idx_0;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = b_loop_ub;
  if (b_loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)b_loop_ub * sizeof(char));
  }
  b_obj_Vector_size[0] = 1;
  b_obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector[0], &b_obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  if (!b_strcmp(obj_Vector_data, obj_Vector_size, obj_Vector,
                b_obj_Vector_size)) {
    double T[36];
    double T2inv[16];
    double R[9];
    double R_tmp;
    int i3;
    RigidBodyTree_forwardKinematics(&obj->TreeInternal, Q, bodyTtree_data,
                                    obj_Vector_size);
    if ((bidx == 0) && (frid == 1.0)) {
      memset(&T2[0], 0, 16U * sizeof(double));
      T2[0] = 1.0;
      T2[5] = 1.0;
      T2[10] = 1.0;
      T2[15] = 1.0;
    } else {
      if (bidx == 0) {
        b_body = &obj->TreeInternal.Base;
      } else {
        b_body = obj->TreeInternal.Bodies[bidx - 1];
      }
      FrameTree_transformUsingFrameID(
          b_body->FramesInternal.FrameParents,
          b_body->FramesInternal.FrameRigidTransforms, frid, T2);
      if (bidx > 0) {
        memset(&Tdh[0], 0, sizeof(double) << 4);
        for (i = 0; i < 4; i++) {
          loop_ub = i << 2;
          for (i2 = 0; i2 < 4; i2++) {
            idx_idx_0 = T2[i2 + loop_ub];
            b_loop_ub = i2 << 2;
            Tdh[loop_ub] += bodyTtree_data[bidx - 1].f1[b_loop_ub] * idx_idx_0;
            Tdh[loop_ub + 1] +=
                bodyTtree_data[bidx - 1].f1[b_loop_ub + 1] * idx_idx_0;
            Tdh[loop_ub + 2] +=
                bodyTtree_data[bidx - 1].f1[b_loop_ub + 2] * idx_idx_0;
            Tdh[loop_ub + 3] +=
                bodyTtree_data[bidx - 1].f1[b_loop_ub + 3] * idx_idx_0;
          }
        }
        memcpy(&T2[0], &Tdh[0], 16U * sizeof(double));
      }
    }
    for (i = 0; i < 3; i++) {
      R[3 * i] = T2[i];
      R[3 * i + 1] = T2[i + 4];
      R[3 * i + 2] = T2[i + 8];
    }
    for (i = 0; i < 9; i++) {
      b_R[i] = -R[i];
    }
    memset(&c_R[0], 0, 3U * sizeof(double));
    idx_idx_0 = c_R[0];
    idx_idx_1 = c_R[1];
    frid = c_R[2];
    for (i = 0; i < 3; i++) {
      R_tmp = T2[i + 12];
      idx_idx_0 += b_R[3 * i] * R_tmp;
      b_loop_ub = i << 2;
      T2inv[b_loop_ub] = R[3 * i];
      loop_ub = 3 * i + 1;
      idx_idx_1 += b_R[loop_ub] * R_tmp;
      T2inv[b_loop_ub + 1] = R[loop_ub];
      loop_ub = 3 * i + 2;
      frid += b_R[loop_ub] * R_tmp;
      T2inv[b_loop_ub + 2] = R[loop_ub];
    }
    T2inv[12] = idx_idx_0;
    T2inv[13] = idx_idx_1;
    T2inv[14] = frid;
    T2inv[3] = 0.0;
    T2inv[7] = 0.0;
    T2inv[11] = 0.0;
    T2inv[15] = 1.0;
    chainmask[(int)body->Index - 1] = 1;
    while (body->ParentIndex > 0.0) {
      body = obj->TreeInternal.Bodies[(int)body->ParentIndex - 1];
      chainmask[(int)body->Index - 1] = 1;
    }
    idx_idx_0 = obj->TreeInternal.NumBodies;
    i3 = (int)idx_idx_0;
    for (b_i = 0; b_i < i3; b_i++) {
      body = obj->TreeInternal.Bodies[b_i];
      b_obj = body->JointInternal;
      idx_idx_1 = b_obj->TypeInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = b_obj->TypeInternal.Vector[i];
      }
      if (idx_idx_1 < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)idx_idx_1;
      }
      b_bool = false;
      if (loop_ub == 5) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 5) {
            if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
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
      if ((!b_bool) && (chainmask[b_i] != 0)) {
        double T_data[336];
        int i5;
        for (i = 0; i < 16; i++) {
          T1[i] = bodyTtree_data[(int)body->Index - 1].f1[i];
        }
        b_obj = body->JointInternal;
        for (i = 0; i < 16; i++) {
          Tdh[i] = b_obj->ChildToJointTransform[i];
        }
        for (i = 0; i < 3; i++) {
          R[3 * i] = Tdh[i];
          R[3 * i + 1] = Tdh[i + 4];
          R[3 * i + 2] = Tdh[i + 8];
        }
        for (i = 0; i < 9; i++) {
          b_R[i] = -R[i];
        }
        memset(&c_R[0], 0, 3U * sizeof(double));
        idx_idx_0 = c_R[0];
        idx_idx_1 = c_R[1];
        frid = c_R[2];
        for (i = 0; i < 3; i++) {
          R_tmp = Tdh[i + 12];
          idx_idx_0 += b_R[3 * i] * R_tmp;
          idx_idx_1 += b_R[3 * i + 1] * R_tmp;
          frid += b_R[3 * i + 2] * R_tmp;
        }
        c_R[2] = frid;
        c_R[1] = idx_idx_1;
        c_R[0] = idx_idx_0;
        memset(&b_T2inv[0], 0, sizeof(double) << 4);
        for (i = 0; i < 4; i++) {
          loop_ub = i << 2;
          for (i2 = 0; i2 < 4; i2++) {
            idx_idx_0 = T1[i2 + loop_ub];
            b_loop_ub = i2 << 2;
            b_T2inv[loop_ub] += T2inv[b_loop_ub] * idx_idx_0;
            b_T2inv[loop_ub + 1] += T2inv[b_loop_ub + 1] * idx_idx_0;
            b_T2inv[loop_ub + 2] += T2inv[b_loop_ub + 2] * idx_idx_0;
            b_T2inv[loop_ub + 3] += T2inv[b_loop_ub + 3] * idx_idx_0;
          }
        }
        for (i = 0; i < 3; i++) {
          loop_ub = i << 2;
          Tdh[loop_ub] = R[3 * i];
          Tdh[loop_ub + 1] = R[3 * i + 1];
          Tdh[loop_ub + 2] = R[3 * i + 2];
          Tdh[i + 12] = c_R[i];
        }
        memset(&T1[0], 0, sizeof(double) << 4);
        for (i = 0; i < 4; i++) {
          loop_ub = i << 2;
          Tdh[loop_ub + 3] = b_iv[i];
          idx_idx_0 = T1[loop_ub];
          idx_idx_1 = T1[loop_ub + 1];
          frid = T1[loop_ub + 2];
          R_tmp = T1[loop_ub + 3];
          for (i4 = 0; i4 < 4; i4++) {
            double d;
            d = Tdh[i4 + loop_ub];
            b_loop_ub = i4 << 2;
            idx_idx_0 += b_T2inv[b_loop_ub] * d;
            idx_idx_1 += b_T2inv[b_loop_ub + 1] * d;
            frid += b_T2inv[b_loop_ub + 2] * d;
            R_tmp += b_T2inv[b_loop_ub + 3] * d;
          }
          T1[loop_ub + 3] = R_tmp;
          T1[loop_ub + 2] = frid;
          T1[loop_ub + 1] = idx_idx_1;
          T1[loop_ub] = idx_idx_0;
        }
        idx_idx_0 = obj->TreeInternal.VelocityDoFMap[b_i];
        idx_idx_1 = obj->TreeInternal.VelocityDoFMap[b_i + 8];
        b_obj = body->JointInternal;
        c_rigidBodyJoint_get_MotionSubs(b_obj, b_data, obj_Vector_size);
        if (idx_idx_0 > idx_idx_1) {
          i5 = 0;
          bidx = 0;
        } else {
          i5 = (int)idx_idx_0 - 1;
          bidx = (int)idx_idx_1;
        }
        R[0] = 0.0;
        R[3] = -T1[14];
        R[6] = T1[13];
        R[1] = T1[14];
        R[4] = 0.0;
        R[7] = -T1[12];
        R[2] = -T1[13];
        R[5] = T1[12];
        R[8] = 0.0;
        memset(&b_R[0], 0, 9U * sizeof(double));
        for (i2 = 0; i2 < 3; i2++) {
          idx_idx_0 = b_R[3 * i2];
          loop_ub = 3 * i2 + 1;
          b_loop_ub = 3 * i2 + 2;
          for (i = 0; i < 3; i++) {
            idx_idx_1 = T1[i + (i2 << 2)];
            idx_idx_0 += R[3 * i] * idx_idx_1;
            b_R[loop_ub] += R[3 * i + 1] * idx_idx_1;
            b_R[b_loop_ub] += R[3 * i + 2] * idx_idx_1;
            T[i + 6 * i2] = idx_idx_1;
            T[i + 6 * (i2 + 3)] = 0.0;
          }
          b_R[3 * i2] = idx_idx_0;
          T[6 * i2 + 3] = idx_idx_0;
          loop_ub = i2 << 2;
          b_loop_ub = 6 * (i2 + 3);
          T[b_loop_ub + 3] = T1[loop_ub];
          T[6 * i2 + 4] = b_R[3 * i2 + 1];
          T[b_loop_ub + 4] = T1[loop_ub + 1];
          T[6 * i2 + 5] = b_R[3 * i2 + 2];
          T[b_loop_ub + 5] = T1[loop_ub + 2];
        }
        b_loop_ub = obj_Vector_size[1];
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          for (i = 0; i < 6; i++) {
            T_data[i + 6 * i4] = 0.0;
          }
          for (i = 0; i < 6; i++) {
            idx_idx_0 = b_data[i + 6 * i4];
            for (i2 = 0; i2 < 6; i2++) {
              loop_ub = i2 + 6 * i4;
              T_data[loop_ub] += T[i2 + 6 * i] * idx_idx_0;
            }
          }
        }
        loop_ub = bidx - i5;
        for (i = 0; i < loop_ub; i++) {
          for (i2 = 0; i2 < 6; i2++) {
            Jac_data[i2 + 6 * (i5 + i)] = T_data[i2 + 6 * i];
          }
        }
      }
    }
    for (i = 0; i < 3; i++) {
      loop_ub = i << 2;
      idx_idx_0 = T2[loop_ub];
      T[6 * i] = idx_idx_0;
      b_loop_ub = 6 * (i + 3);
      T[b_loop_ub] = 0.0;
      T[6 * i + 3] = 0.0;
      T[b_loop_ub + 3] = idx_idx_0;
      idx_idx_0 = T2[loop_ub + 1];
      T[6 * i + 1] = idx_idx_0;
      T[b_loop_ub + 1] = 0.0;
      T[6 * i + 4] = 0.0;
      T[b_loop_ub + 4] = idx_idx_0;
      idx_idx_0 = T2[loop_ub + 2];
      T[6 * i + 2] = idx_idx_0;
      T[b_loop_ub + 2] = 0.0;
      T[6 * i + 5] = 0.0;
      T[b_loop_ub + 5] = idx_idx_0;
    }
    for (i4 = 0; i4 < i1; i4++) {
      for (i = 0; i < 6; i++) {
        b_data[i + 6 * i4] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        idx_idx_0 = Jac_data[i + 6 * i4];
        for (i2 = 0; i2 < 6; i2++) {
          loop_ub = i2 + 6 * i4;
          b_data[loop_ub] += T[i2 + 6 * i] * idx_idx_0;
        }
      }
    }
    Jac_size[0] = 6;
    Jac_size[1] = (int)velnum;
    if (c_loop_ub - 1 >= 0) {
      memcpy(&Jac_data[0], &b_data[0],
             (unsigned int)c_loop_ub * sizeof(double));
    }
  }
}

/*
 * Arguments    : rigidBodyTree *obj
 * Return Type  : rigidBodyTree *
 */
rigidBodyTree *rigidBodyTree_rigidBodyTree(rigidBodyTree *obj)
{
  static const signed char b_iv[16] = {0,  0,  0,  0,  0,  0,  0,  0,
                                       -1, -1, -1, -1, -1, -1, -1, -1};
  static const char b_cv[10] = {'d', 'u', 'm', 'm', 'y',
                                'b', 'o', 'd', 'y', '2'};
  static const char b_cv1[10] = {'d', 'u', 'm', 'm', 'y',
                                 'b', 'o', 'd', 'y', '3'};
  static const char b_cv2[10] = {'d', 'u', 'm', 'm', 'y',
                                 'b', 'o', 'd', 'y', '4'};
  static const char cv3[10] = {'d', 'u', 'm', 'm', 'y',
                               'b', 'o', 'd', 'y', '5'};
  static const char cv4[10] = {'d', 'u', 'm', 'm', 'y',
                               'b', 'o', 'd', 'y', '6'};
  static const char cv5[10] = {'d', 'u', 'm', 'm', 'y',
                               'b', 'o', 'd', 'y', '7'};
  static const char cv6[10] = {'d', 'u', 'm', 'm', 'y',
                               'b', 'o', 'd', 'y', '8'};
  rigidBodyTree *b_obj;
  double unusedExpr[5];
  int i;
  b_obj = obj;
  b_rand(unusedExpr);
  for (i = 0; i < 8; i++) {
    b_obj->TreeInternal.BodyParentFrameIdx[i] = 1.0;
  }
  RigidBody_RigidBody(&b_obj->TreeInternal.Base);
  b_obj->TreeInternal.Base.Index = 0.0;
  b_obj->TreeInternal.Bodies[0] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[0], cv);
  b_obj->TreeInternal.Bodies[1] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[1], b_cv);
  b_obj->TreeInternal.Bodies[2] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[2], b_cv1);
  b_obj->TreeInternal.Bodies[3] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[3], b_cv2);
  b_obj->TreeInternal.Bodies[4] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[4], cv3);
  b_obj->TreeInternal.Bodies[5] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[5], cv4);
  b_obj->TreeInternal.Bodies[6] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[6], cv5);
  b_obj->TreeInternal.Bodies[7] =
      b_RigidBody_RigidBody(&b_obj->TreeInternal.coder_buffer_pobj0[7], cv6);
  b_obj->TreeInternal.NumBodies = 0.0;
  b_obj->TreeInternal.NumNonFixedBodies = 0.0;
  b_obj->TreeInternal.PositionNumber = 0.0;
  b_obj->TreeInternal.VelocityNumber = 0.0;
  b_rand(unusedExpr);
  for (i = 0; i < 16; i++) {
    b_obj->TreeInternal.VelocityDoFMap[i] = b_iv[i];
  }
  for (i = 0; i < 8; i++) {
    b_obj->TreeInternal.BodyParentFrameIdx[i] = 1.0;
  }
  b_obj->TreeInternal.matlabCodegenIsDeleted = false;
  b_obj->TreeInternal.Base.CollisionsInternal =
      CollisionSet_CollisionSet(&b_obj->coder_buffer_pobj0, 10.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : rigidBodyTree *obj
 * Return Type  : void
 */
void rigidBodyTree_set_BaseName(rigidBodyTree *obj)
{
  double bid;
  int i;
  unsigned char name[200];
  bid = c_RigidBodyTree_findBodyIndexBy(&obj->TreeInternal);
  if ((!(bid == 0.0)) && (bid < 0.0)) {
    obj->TreeInternal.Base.NameInternal.Length = 9.0;
    for (i = 0; i < 9; i++) {
      obj->TreeInternal.Base.NameInternal.Vector[i] = cv2[i];
    }
    memset(&name[0], 0, 200U * sizeof(unsigned char));
    for (i = 0; i < 9; i++) {
      name[i] = uv[i];
    }
    for (i = 0; i < 200; i++) {
      obj->TreeInternal.Base.FramesInternal.FrameNames
          ->data[obj->TreeInternal.Base.FramesInternal.FrameNames->size[0] *
                 i] = name[i];
    }
  }
}

/*
 * File trailer for rigidBodyTree.c
 *
 * [EOF]
 */
