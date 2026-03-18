/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: rigidBodyTree.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef RIGIDBODYTREE_H
#define RIGIDBODYTREE_H

/* Include Files */
#include "psudoinverse_function_internal_types.h"
#include "psudoinverse_function_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2);

void c_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2);

void d_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2);

void e_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2);

void f_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2);

void g_rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                             d_robotics_manip_internal_Colli *iobj_0,
                             rigidBodyJoint *iobj_1,
                             c_robotics_manip_internal_Rigid *iobj_2);

void rigidBodyTree_addBody(rigidBodyTree *obj, rigidBody *bodyin,
                           d_robotics_manip_internal_Colli *iobj_0,
                           rigidBodyJoint *iobj_1,
                           c_robotics_manip_internal_Rigid *iobj_2);

void rigidBodyTree_geometricJacobian(rigidBodyTree *obj, const double Q[6],
                                     const char endeffectorname[5],
                                     double Jac_data[], int Jac_size[2]);

rigidBodyTree *rigidBodyTree_rigidBodyTree(rigidBodyTree *obj);

void rigidBodyTree_set_BaseName(rigidBodyTree *obj);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for rigidBodyTree.h
 *
 * [EOF]
 */
