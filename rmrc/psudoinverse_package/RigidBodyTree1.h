/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: RigidBodyTree1.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef RIGIDBODYTREE1_H
#define RIGIDBODYTREE1_H

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
e_robotics_manip_internal_Rigid *
RigidBodyTree_RigidBodyTree(e_robotics_manip_internal_Rigid *obj);

void RigidBodyTree_forwardKinematics(f_robotics_manip_internal_Rigid *obj,
                                     const double qvec[6],
                                     cell_wrap_30 Ttree_data[],
                                     int Ttree_size[2]);

double c_RigidBodyTree_findBodyIndexBy(f_robotics_manip_internal_Rigid *obj);

double d_RigidBodyTree_findBodyIndexBy(f_robotics_manip_internal_Rigid *obj,
                                       const char bodyname_data[],
                                       const int bodyname_size[2]);

double e_RigidBodyTree_findBodyIndexBy(f_robotics_manip_internal_Rigid *obj,
                                       const char jointname_data[],
                                       const int jointname_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for RigidBodyTree1.h
 *
 * [EOF]
 */
