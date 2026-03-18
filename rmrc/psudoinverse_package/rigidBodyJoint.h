/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: rigidBodyJoint.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef RIGIDBODYJOINT_H
#define RIGIDBODYJOINT_H

/* Include Files */
#include "psudoinverse_function_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
rigidBodyJoint *b_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj,
                                                const char jname[14]);

void b_rigidBodyJoint_set_JointAxis(rigidBodyJoint *obj);

void c_rigidBodyJoint_get_MotionSubs(const rigidBodyJoint *obj,
                                     double msubspace_data[],
                                     int msubspace_size[2]);

rigidBodyJoint *c_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void c_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj);

void c_rigidBodyJoint_set_JointAxis(rigidBodyJoint *obj);

void c_rigidBodyJoint_set_MotionSubs(rigidBodyJoint *obj,
                                     const double msubspace_data[]);

void c_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj);

rigidBodyJoint *d_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void d_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj);

void d_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj);

rigidBodyJoint *e_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void e_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj);

void e_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj);

rigidBodyJoint *f_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void f_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj);

void f_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj);

rigidBodyJoint *g_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void g_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj);

void g_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj);

rigidBodyJoint *h_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void h_rigidBodyJoint_setFixedTransf(rigidBodyJoint *obj);

void h_rigidBodyJoint_set_PositionLi(rigidBodyJoint *obj);

rigidBodyJoint *i_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

rigidBodyJoint *j_rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

rigidBodyJoint *rigidBodyJoint_copy(const rigidBodyJoint *obj,
                                    rigidBodyJoint *iobj_0);

void rigidBodyJoint_get_JointAxis(const rigidBodyJoint *obj, double ax[3]);

rigidBodyJoint *rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj);

void rigidBodyJoint_set_HomePosition(rigidBodyJoint *obj);

void rigidBodyJoint_set_JointAxis(rigidBodyJoint *obj);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for rigidBodyJoint.h
 *
 * [EOF]
 */
