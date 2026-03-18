/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: FrameTree.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef FRAMETREE_H
#define FRAMETREE_H

/* Include Files */
#include "psudoinverse_function_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double FrameTree_getFrameIdx(const emxArray_uint8_T *obj_FrameNames,
                             double obj_NumFrames);

bool FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                             double obj_NumFrames, double *fidx);

void FrameTree_transformUsingFrameID(
    const emxArray_real_T *obj_FrameParents,
    const emxArray_real_T *obj_FrameRigidTransforms, double fid1,
    double tform[16]);

bool b_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx);

bool c_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx);

bool d_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx);

bool e_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx);

bool f_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx);

bool g_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, const char name[5],
                               double *fidx);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for FrameTree.h
 *
 * [EOF]
 */
