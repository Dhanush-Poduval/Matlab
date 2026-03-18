/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: RigidBody1.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef RIGIDBODY1_H
#define RIGIDBODY1_H

/* Include Files */
#include "psudoinverse_function_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
c_robotics_manip_internal_Rigid *
RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj);

c_robotics_manip_internal_Rigid *
RigidBody_copy(c_robotics_manip_internal_Rigid *obj,
               d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1,
               c_robotics_manip_internal_Rigid *iobj_2);

c_robotics_manip_internal_Rigid *
b_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      const char bodyInput[10]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for RigidBody1.h
 *
 * [EOF]
 */
