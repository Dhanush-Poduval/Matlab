/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "psudoinverse_function.h"
#include "handle.h"
#include "mldivide.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_initialize.h"
#include "psudoinverse_function_internal_types.h"
#include "psudoinverse_function_types.h"
#include "rigidBody.h"
#include "rigidBodyJoint.h"
#include "rigidBodyTree.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static c_robotics_manip_internal_Rigid gobj_3[8];

static d_robotics_manip_internal_Colli gobj_1[16];

static rigidBodyTree robot;

static bool robot_not_empty;

/* Function Declarations */
static void binary_expand_op(double in1[6], const double in2[6],
                             const double in3_data[], const int in3_size[2],
                             const double in4[3]);

/* Function Definitions */
/*
 * Arguments    : double in1[6]
 *                const double in2[6]
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4[3]
 * Return Type  : void
 */
static void binary_expand_op(double in1[6], const double in2[6],
                             const double in3_data[], const int in3_size[2],
                             const double in4[3])
{
  double b_in3_data[56];
  double tmp_data[56];
  int i;
  int i1;
  int loop_ub;
  loop_ub = in3_size[1];
  if (loop_ub - 1 >= 0) {
    memset(&tmp_data[0], 0, (unsigned int)loop_ub * sizeof(double));
  }
  for (i = 0; i < 3; i++) {
    double d;
    d = in4[i];
    for (i1 = 0; i1 < loop_ub; i1++) {
      tmp_data[i1] += in3_data[i + 6 * i1] * d;
    }
  }
  if (loop_ub - 1 >= 0) {
    memcpy(&b_in3_data[0], &tmp_data[0],
           (unsigned int)loop_ub * sizeof(double));
  }
  loop_ub = (loop_ub != 1);
  for (i = 0; i < 6; i++) {
    in1[i] = in2[i] + b_in3_data[i * loop_ub] * 0.1;
  }
}

/*
 * Arguments    : const char endEffector[5]
 *                const double velocities[6]
 *                const double config[6]
 *                double x[6]
 *                double *y
 * Return Type  : void
 */
void psudoinverse_function(const char endEffector[5],
                           const double velocities[6], const double config[6],
                           double x[6], double *y)
{
  static rigidBodyJoint gobj_2[16];
  static const double b_y[9] = {0.0025000000000000005, 0.0, 0.0, 0.0,
                                0.0025000000000000005, 0.0, 0.0, 0.0,
                                0.0025000000000000005};
  c_robotics_manip_internal_Rigid lobj_19[8];
  c_robotics_manip_internal_Rigid *iobj_2;
  d_robotics_manip_internal_Colli lobj_16[13];
  d_robotics_manip_internal_Colli *iobj_0;
  d_robotics_manip_internal_Rigid *b_obj;
  e_robotics_manip_internal_Rigid lobj_18[8];
  e_robotics_manip_internal_Rigid *obj;
  rigidBody b_body;
  rigidBody body;
  rigidBody c_body;
  rigidBody d_body;
  rigidBody e_body;
  rigidBody f_body;
  rigidBody g_body;
  rigidBody h_body;
  rigidBodyJoint lobj_17[15];
  rigidBodyJoint b_joint;
  rigidBodyJoint c_joint;
  rigidBodyJoint d_joint;
  rigidBodyJoint e_joint;
  rigidBodyJoint f_joint;
  rigidBodyJoint g_joint;
  rigidBodyJoint h_joint;
  rigidBodyJoint joint;
  rigidBodyJoint *iobj_1;
  rigidBodyTree *b_robot;
  double J_data[336];
  double J[9];
  double dv[3];
  int J_size[2];
  int i;
  int i1;
  int i2;
  int loop_ub;
  if (!isInitialized_psudoinverse_function) {
    psudoinverse_function_initialize();
  }
  c_emxInitMatrix_robotics_manip_(lobj_19);
  e_emxInitMatrix_robotics_manip_(lobj_18);
  f_emxInitMatrix_robotics_manip_(lobj_16);
  if (!robot_not_empty) {
    iobj_0 = &gobj_1[0];
    iobj_1 = &gobj_2[0];
    iobj_2 = &gobj_3[0];
    /* rmrcRobot Create rigidBodyTree for the robot model */
    /*    ROBOT = rmrcRobot(DATAFORMAT) constructs a rigidBodyTree, ROBOT, and
     * sets the */
    /*    data format to DATAFORMAT. The possible values of DATAFORMAT are  */
    /*    'struct', 'column' and 'row'. The default value is 'row', which  */
    /*    matches the data format of the rigidbodytree object used to generate
     */
    /*    this function. */
    for (i2 = 0; i2 < 8; i2++) {
      lobj_19[i2].coder_buffer_pobj0.matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      lobj_18[i2].coder_buffer_pobj0.CollisionsInternal.matlabCodegenIsDeleted =
          true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      lobj_18[i2].Base.CollisionsInternal.matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 13; i2++) {
      lobj_16[i2].matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      lobj_19[i2].matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      lobj_18[i2].coder_buffer_pobj0.matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      lobj_18[i2].Base.matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      lobj_18[i2].matlabCodegenIsDeleted = true;
    }
    body.matlabCodegenIsDeleted = true;
    b_body.matlabCodegenIsDeleted = true;
    c_body.matlabCodegenIsDeleted = true;
    d_body.matlabCodegenIsDeleted = true;
    e_body.matlabCodegenIsDeleted = true;
    f_body.matlabCodegenIsDeleted = true;
    g_body.matlabCodegenIsDeleted = true;
    h_body.matlabCodegenIsDeleted = true;
    /*    Auto-generated by MATLAB on 07-Mar-2026 02:10:04 */
    b_robot = rigidBodyTree_rigidBodyTree(&robot);
    rigidBodyTree_set_BaseName(b_robot);
    /*  Add body, 'base', and joint, 'base_link-base' */
    c_rigidBodyJoint_rigidBodyJoint(&joint);
    c_rigidBodyJoint_setFixedTransf(&joint);
    rigidBody_rigidBody(&h_body, &lobj_18[0], &lobj_19[0]);
    h_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&joint, &lobj_17[0]);
    rigidBody_set_Mass(&h_body);
    rigidBody_set_CenterOfMass(&h_body);
    rigidBody_set_Inertia(&h_body);
    rigidBodyTree_addBody(b_robot, &h_body, &iobj_0[0], &iobj_1[0], &iobj_2[0]);
    /*  Add body, 'link_1', and joint, 'joint_1' */
    d_rigidBodyJoint_rigidBodyJoint(&b_joint);
    c_rigidBodyJoint_setFixedTransf(&b_joint);
    c_rigidBodyJoint_set_PositionLi(&b_joint);
    rigidBodyJoint_set_JointAxis(&b_joint);
    rigidBodyJoint_set_HomePosition(&b_joint);
    b_rigidBody_rigidBody(&g_body, &lobj_18[1], &lobj_16[0], &lobj_17[1],
                          &lobj_19[1]);
    g_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&b_joint, &lobj_17[2]);
    b_rigidBody_set_Mass(&g_body);
    b_rigidBody_set_CenterOfMass(&g_body);
    b_rigidBody_set_Inertia(&g_body);
    rigidBodyTree_addBody(b_robot, &g_body, &iobj_0[2], &iobj_1[2], &iobj_2[1]);
    /*  Add body, 'link_2', and joint, 'joint_2' */
    e_rigidBodyJoint_rigidBodyJoint(&c_joint);
    d_rigidBodyJoint_setFixedTransf(&c_joint);
    d_rigidBodyJoint_set_PositionLi(&c_joint);
    b_rigidBodyJoint_set_JointAxis(&c_joint);
    rigidBodyJoint_set_HomePosition(&c_joint);
    c_rigidBody_rigidBody(&f_body, &lobj_18[2], &lobj_16[2], &lobj_17[3],
                          &lobj_19[2]);
    f_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&c_joint, &lobj_17[4]);
    c_rigidBody_set_Mass(&f_body);
    c_rigidBody_set_CenterOfMass(&f_body);
    c_rigidBody_set_Inertia(&f_body);
    b_rigidBodyTree_addBody(b_robot, &f_body, &iobj_0[4], &iobj_1[4],
                            &iobj_2[2]);
    /*  Add body, 'link_3', and joint, 'joint_3' */
    f_rigidBodyJoint_rigidBodyJoint(&d_joint);
    e_rigidBodyJoint_setFixedTransf(&d_joint);
    e_rigidBodyJoint_set_PositionLi(&d_joint);
    b_rigidBodyJoint_set_JointAxis(&d_joint);
    rigidBodyJoint_set_HomePosition(&d_joint);
    d_rigidBody_rigidBody(&e_body, &lobj_18[3], &lobj_16[4], &lobj_17[5],
                          &lobj_19[3]);
    e_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&d_joint, &lobj_17[6]);
    d_rigidBody_set_Mass(&e_body);
    d_rigidBody_set_CenterOfMass(&e_body);
    d_rigidBody_set_Inertia(&e_body);
    c_rigidBodyTree_addBody(b_robot, &e_body, &iobj_0[6], &iobj_1[6],
                            &iobj_2[3]);
    /*  Add body, 'link_4', and joint, 'joint_4' */
    g_rigidBodyJoint_rigidBodyJoint(&e_joint);
    f_rigidBodyJoint_setFixedTransf(&e_joint);
    f_rigidBodyJoint_set_PositionLi(&e_joint);
    c_rigidBodyJoint_set_JointAxis(&e_joint);
    rigidBodyJoint_set_HomePosition(&e_joint);
    e_rigidBody_rigidBody(&d_body, &lobj_18[4], &lobj_16[6], &lobj_17[7],
                          &lobj_19[4]);
    d_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&e_joint, &lobj_17[8]);
    e_rigidBody_set_Mass(&d_body);
    e_rigidBody_set_CenterOfMass(&d_body);
    e_rigidBody_set_Inertia(&d_body);
    d_rigidBodyTree_addBody(b_robot, &d_body, &iobj_0[8], &iobj_1[8],
                            &iobj_2[4]);
    /*  Add body, 'link_5', and joint, 'joint_5' */
    h_rigidBodyJoint_rigidBodyJoint(&f_joint);
    g_rigidBodyJoint_setFixedTransf(&f_joint);
    g_rigidBodyJoint_set_PositionLi(&f_joint);
    b_rigidBodyJoint_set_JointAxis(&f_joint);
    rigidBodyJoint_set_HomePosition(&f_joint);
    f_rigidBody_rigidBody(&c_body, &lobj_18[5], &lobj_16[8], &lobj_17[9],
                          &lobj_19[5]);
    c_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&f_joint, &lobj_17[10]);
    f_rigidBody_set_Mass(&c_body);
    f_rigidBody_set_CenterOfMass(&c_body);
    f_rigidBody_set_Inertia(&c_body);
    e_rigidBodyTree_addBody(b_robot, &c_body, &iobj_0[10], &iobj_1[10],
                            &iobj_2[5]);
    /*  Add body, 'link_6', and joint, 'joint_6' */
    i_rigidBodyJoint_rigidBodyJoint(&g_joint);
    h_rigidBodyJoint_setFixedTransf(&g_joint);
    h_rigidBodyJoint_set_PositionLi(&g_joint);
    c_rigidBodyJoint_set_JointAxis(&g_joint);
    rigidBodyJoint_set_HomePosition(&g_joint);
    g_rigidBody_rigidBody(&b_body, &lobj_18[6], &lobj_16[10], &lobj_17[11],
                          &lobj_19[6]);
    b_body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&g_joint, &lobj_17[12]);
    g_rigidBody_set_Mass(&b_body);
    g_rigidBody_set_CenterOfMass(&b_body);
    g_rigidBody_set_Inertia(&b_body);
    f_rigidBodyTree_addBody(b_robot, &b_body, &iobj_0[12], &iobj_1[12],
                            &iobj_2[6]);
    /*  Add body, 'tool0', and joint, 'joint6-tool0' */
    j_rigidBodyJoint_rigidBodyJoint(&h_joint);
    c_rigidBodyJoint_setFixedTransf(&h_joint);
    h_rigidBody_rigidBody(&body, &lobj_18[7], &lobj_16[12], &lobj_17[13],
                          &lobj_19[7]);
    body.BodyInternal->JointInternal =
        rigidBodyJoint_copy(&h_joint, &lobj_17[14]);
    rigidBody_set_Mass(&body);
    rigidBody_set_CenterOfMass(&body);
    rigidBody_set_Inertia(&body);
    g_rigidBodyTree_addBody(b_robot, &body, &iobj_0[14], &iobj_1[14],
                            &iobj_2[7]);
    if (!h_body.matlabCodegenIsDeleted) {
      h_body.matlabCodegenIsDeleted = true;
    }
    if (!g_body.matlabCodegenIsDeleted) {
      g_body.matlabCodegenIsDeleted = true;
    }
    if (!f_body.matlabCodegenIsDeleted) {
      f_body.matlabCodegenIsDeleted = true;
    }
    if (!e_body.matlabCodegenIsDeleted) {
      e_body.matlabCodegenIsDeleted = true;
    }
    if (!d_body.matlabCodegenIsDeleted) {
      d_body.matlabCodegenIsDeleted = true;
    }
    if (!c_body.matlabCodegenIsDeleted) {
      c_body.matlabCodegenIsDeleted = true;
    }
    if (!b_body.matlabCodegenIsDeleted) {
      b_body.matlabCodegenIsDeleted = true;
    }
    if (!body.matlabCodegenIsDeleted) {
      body.matlabCodegenIsDeleted = true;
    }
    for (i2 = 0; i2 < 8; i2++) {
      obj = &lobj_18[i2];
      if (!obj->matlabCodegenIsDeleted) {
        obj->matlabCodegenIsDeleted = true;
      }
    }
    for (i2 = 0; i2 < 8; i2++) {
      b_obj = &lobj_18[i2].Base;
      if (!b_obj->matlabCodegenIsDeleted) {
        b_obj->matlabCodegenIsDeleted = true;
      }
    }
    for (i2 = 0; i2 < 8; i2++) {
      b_obj = &lobj_18[i2].coder_buffer_pobj0;
      if (!b_obj->matlabCodegenIsDeleted) {
        b_obj->matlabCodegenIsDeleted = true;
      }
    }
    for (i2 = 0; i2 < 8; i2++) {
      iobj_2 = &lobj_19[i2];
      if (!iobj_2->matlabCodegenIsDeleted) {
        iobj_2->matlabCodegenIsDeleted = true;
      }
    }
    for (i2 = 0; i2 < 13; i2++) {
      handle_matlabCodegenDestructor(&lobj_16[i2]);
    }
    for (i2 = 0; i2 < 8; i2++) {
      handle_matlabCodegenDestructor(&lobj_18[i2].Base.CollisionsInternal);
    }
    for (i2 = 0; i2 < 8; i2++) {
      handle_matlabCodegenDestructor(
          &lobj_18[i2].coder_buffer_pobj0.CollisionsInternal);
    }
    for (i2 = 0; i2 < 8; i2++) {
      handle_matlabCodegenDestructor(&lobj_19[i2].coder_buffer_pobj0);
    }
    robot_not_empty = true;
  }
  rigidBodyTree_geometricJacobian(&robot, config, endEffector, J_data, J_size);
  loop_ub = J_size[1];
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      double d;
      d = 0.0;
      for (i2 = 0; i2 < loop_ub; i2++) {
        d += J_data[i + 6 * i2] * J_data[i1 + 6 * i2];
      }
      int J_tmp;
      J_tmp = i + 3 * i1;
      J[J_tmp] = d + b_y[J_tmp];
    }
  }
  mldivide(J, &velocities[0], dv);
  if (J_size[1] == 6) {
    double tmp_data[56];
    for (i2 = 0; i2 < 6; i2++) {
      tmp_data[i2] = 0.0;
    }
    for (i2 = 0; i2 < 3; i2++) {
      for (i = 0; i < 6; i++) {
        tmp_data[i] += J_data[i2 + 6 * i] * dv[i2];
      }
    }
    for (i2 = 0; i2 < 6; i2++) {
      x[i2] = config[i2] + tmp_data[i2] * 0.1;
    }
  } else {
    binary_expand_op(x, config, J_data, J_size, dv);
  }
  *y = 0.0;
  f_emxFreeMatrix_robotics_manip_(lobj_16);
  e_emxFreeMatrix_robotics_manip_(lobj_18);
  c_emxFreeMatrix_robotics_manip_(lobj_19);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void psudoinverse_function_delete(void)
{
  c_robotics_manip_internal_Rigid *obj;
  int i;
  if (!robot.matlabCodegenIsDeleted) {
    robot.matlabCodegenIsDeleted = true;
  }
  if (!robot.TreeInternal.matlabCodegenIsDeleted) {
    robot.TreeInternal.matlabCodegenIsDeleted = true;
  }
  if (!robot.TreeInternal.Base.matlabCodegenIsDeleted) {
    robot.TreeInternal.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 8; i++) {
    obj = &robot.TreeInternal.coder_buffer_pobj0[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  for (i = 0; i < 8; i++) {
    obj = &gobj_3[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  handle_matlabCodegenDestructor(&robot.TreeInternal.Base.coder_buffer_pobj0);
  for (i = 0; i < 8; i++) {
    handle_matlabCodegenDestructor(
        &robot.TreeInternal.coder_buffer_pobj0[i].coder_buffer_pobj0);
  }
  handle_matlabCodegenDestructor(&robot.coder_buffer_pobj0);
  for (i = 0; i < 16; i++) {
    handle_matlabCodegenDestructor(&gobj_1[i]);
  }
  for (i = 0; i < 8; i++) {
    handle_matlabCodegenDestructor(&gobj_3[i].coder_buffer_pobj0);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void psudoinverse_function_emx_free(void)
{
  emxFreeStruct_rigidBodyTree(&robot);
  d_emxFreeMatrix_robotics_manip_(gobj_1);
  c_emxFreeMatrix_robotics_manip_(gobj_3);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void psudoinverse_function_emx_init(void)
{
  emxInitStruct_rigidBodyTree(&robot);
  d_emxInitMatrix_robotics_manip_(gobj_1);
  c_emxInitMatrix_robotics_manip_(gobj_3);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void psudoinverse_function_init(void)
{
  robot_not_empty = false;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void psudoinverse_function_new(void)
{
  int i;
  for (i = 0; i < 8; i++) {
    gobj_3[i].coder_buffer_pobj0.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 16; i++) {
    gobj_1[i].matlabCodegenIsDeleted = true;
  }
  robot.coder_buffer_pobj0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 8; i++) {
    robot.TreeInternal.coder_buffer_pobj0[i]
        .coder_buffer_pobj0.matlabCodegenIsDeleted = true;
  }
  robot.TreeInternal.Base.coder_buffer_pobj0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 8; i++) {
    gobj_3[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 8; i++) {
    robot.TreeInternal.coder_buffer_pobj0[i].matlabCodegenIsDeleted = true;
  }
  robot.TreeInternal.Base.matlabCodegenIsDeleted = true;
  robot.TreeInternal.matlabCodegenIsDeleted = true;
  robot.matlabCodegenIsDeleted = true;
}

/*
 * File trailer for psudoinverse_function.c
 *
 * [EOF]
 */
