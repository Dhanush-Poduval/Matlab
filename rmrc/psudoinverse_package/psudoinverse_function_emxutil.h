/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function_emxutil.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef PSUDOINVERSE_FUNCTION_EMXUTIL_H
#define PSUDOINVERSE_FUNCTION_EMXUTIL_H

/* Include Files */
#include "psudoinverse_function_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
c_emxCopyStruct_robotics_manip_(c_robotics_manip_internal_Frame *dst,
                                const c_robotics_manip_internal_Frame *src);

extern void
c_emxEnsureCapacity_robotics_ma(c_emxArray_robotics_manip_inter *emxArray,
                                int oldNumel);

extern void
c_emxFreeMatrix_robotics_manip_(c_robotics_manip_internal_Rigid pMatrix[8]);

extern void
c_emxFreeStruct_robotics_manip_(c_robotics_manip_internal_Frame *pStruct);

extern void
c_emxFree_robotics_manip_intern(c_emxArray_robotics_manip_inter **pEmxArray);

extern void
c_emxInitMatrix_robotics_manip_(c_robotics_manip_internal_Rigid pMatrix[8]);

extern void
c_emxInitStruct_robotics_manip_(f_robotics_manip_internal_Rigid *pStruct);

extern void
c_emxInit_robotics_manip_intern(c_emxArray_robotics_manip_inter **pEmxArray);

extern void
d_emxFreeMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[16]);

extern void
d_emxFreeStruct_robotics_manip_(c_robotics_manip_internal_Rigid *pStruct);

extern void
d_emxInitMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[16]);

extern void
d_emxInitStruct_robotics_manip_(c_robotics_manip_internal_Rigid *pStruct);

extern void
e_emxFreeMatrix_robotics_manip_(e_robotics_manip_internal_Rigid pMatrix[8]);

extern void
e_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct);

extern void
e_emxInitMatrix_robotics_manip_(e_robotics_manip_internal_Rigid pMatrix[8]);

extern void
e_emxInitStruct_robotics_manip_(c_robotics_manip_internal_Frame *pStruct);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

extern void emxCopy_uint8_T(emxArray_uint8_T **dst,
                            emxArray_uint8_T *const *src);

extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxFreeStruct_rigidBodyTree(rigidBodyTree *pStruct);

extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInitStruct_rigidBodyTree(rigidBodyTree *pStruct);

extern void emxInit_int8_T(emxArray_int8_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray);

extern void
f_emxFreeMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[13]);

extern void
f_emxFreeStruct_robotics_manip_(f_robotics_manip_internal_Rigid *pStruct);

extern void
f_emxInitMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[13]);

extern void
f_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct);

extern void
g_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct);

extern void
g_emxInitStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct);

extern void
h_emxFreeStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct);

extern void
h_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for psudoinverse_function_emxutil.h
 *
 * [EOF]
 */
