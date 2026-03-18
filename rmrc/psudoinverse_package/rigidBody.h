/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: rigidBody.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

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
rigidBody *b_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

void b_rigidBody_set_CenterOfMass(rigidBody *obj);

void b_rigidBody_set_Inertia(rigidBody *obj);

void b_rigidBody_set_Mass(rigidBody *obj);

rigidBody *c_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

void c_rigidBody_set_CenterOfMass(rigidBody *obj);

void c_rigidBody_set_Inertia(rigidBody *obj);

void c_rigidBody_set_Mass(rigidBody *obj);

rigidBody *d_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

void d_rigidBody_set_CenterOfMass(rigidBody *obj);

void d_rigidBody_set_Inertia(rigidBody *obj);

void d_rigidBody_set_Mass(rigidBody *obj);

rigidBody *e_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

void e_rigidBody_set_CenterOfMass(rigidBody *obj);

void e_rigidBody_set_Inertia(rigidBody *obj);

void e_rigidBody_set_Mass(rigidBody *obj);

rigidBody *f_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

void f_rigidBody_set_CenterOfMass(rigidBody *obj);

void f_rigidBody_set_Inertia(rigidBody *obj);

void f_rigidBody_set_Mass(rigidBody *obj);

rigidBody *g_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

void g_rigidBody_set_CenterOfMass(rigidBody *obj);

void g_rigidBody_set_Inertia(rigidBody *obj);

void g_rigidBody_set_Mass(rigidBody *obj);

rigidBody *h_rigidBody_rigidBody(rigidBody *obj,
                                 e_robotics_manip_internal_Rigid *iobj_0,
                                 d_robotics_manip_internal_Colli *iobj_1,
                                 rigidBodyJoint *iobj_2,
                                 c_robotics_manip_internal_Rigid *iobj_3);

rigidBody *rigidBody_rigidBody(rigidBody *obj,
                               e_robotics_manip_internal_Rigid *iobj_0,
                               c_robotics_manip_internal_Rigid *iobj_1);

void rigidBody_set_CenterOfMass(rigidBody *obj);

void rigidBody_set_Inertia(rigidBody *obj);

void rigidBody_set_Mass(rigidBody *obj);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for rigidBody.h
 *
 * [EOF]
 */
