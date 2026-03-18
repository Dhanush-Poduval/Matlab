/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: FrameTree.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "FrameTree.h"
#include "psudoinverse_function_data.h"
#include "psudoinverse_function_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 * Return Type  : double
 */
double FrameTree_getFrameIdx(const emxArray_uint8_T *obj_FrameNames,
                             double obj_NumFrames)
{
  double fidx;
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  obj_FrameNames_data = obj_FrameNames->data;
  fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 9; i++) {
    u8Name[i] = uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    bool y;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    y = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        y = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (y) {
      fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return fidx;
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                double *fidx
 * Return Type  : bool
 */
bool FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                             double obj_NumFrames, double *fidx)
{
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 49U};
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 6; i++) {
    u8Name[i] = b_uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * Arguments    : const emxArray_real_T *obj_FrameParents
 *                const emxArray_real_T *obj_FrameRigidTransforms
 *                double fid1
 *                double tform[16]
 * Return Type  : void
 */
void FrameTree_transformUsingFrameID(
    const emxArray_real_T *obj_FrameParents,
    const emxArray_real_T *obj_FrameRigidTransforms, double fid1,
    double tform[16])
{
  double T1[16];
  double b_R[16];
  double d_R[3];
  const double *obj_FrameParents_data;
  const double *obj_FrameRigidTransforms_data;
  int i;
  int i1;
  obj_FrameRigidTransforms_data = obj_FrameRigidTransforms->data;
  obj_FrameParents_data = obj_FrameParents->data;
  if (fid1 == 1.0) {
    memset(&tform[0], 0, 16U * sizeof(double));
    tform[0] = 1.0;
    tform[5] = 1.0;
    tform[10] = 1.0;
    tform[15] = 1.0;
  } else {
    double R[9];
    double c_R[9];
    double d;
    double d1;
    double fid;
    int T1_tmp;
    int b_T1_tmp;
    fid = fid1;
    for (i = 0; i < 4; i++) {
      T1_tmp = i << 2;
      b_T1_tmp = 4 * i + 16 * ((int)fid1 - 1);
      T1[T1_tmp] = obj_FrameRigidTransforms_data[b_T1_tmp];
      T1[T1_tmp + 1] = obj_FrameRigidTransforms_data[b_T1_tmp + 1];
      T1[T1_tmp + 2] = obj_FrameRigidTransforms_data[b_T1_tmp + 2];
      T1[T1_tmp + 3] = obj_FrameRigidTransforms_data[b_T1_tmp + 3];
    }
    while (fid > 1.0) {
      memset(&b_R[0], 0, sizeof(double) << 4);
      for (i = 0; i < 4; i++) {
        b_T1_tmp = i << 2;
        for (i1 = 0; i1 < 4; i1++) {
          d = T1[i1 + b_T1_tmp];
          T1_tmp = (int)obj_FrameParents_data[(int)fid - 1] - 1;
          T1_tmp = 4 * i1 + 16 * T1_tmp;
          b_R[b_T1_tmp] += obj_FrameRigidTransforms_data[T1_tmp] * d;
          b_R[b_T1_tmp + 1] += obj_FrameRigidTransforms_data[T1_tmp + 1] * d;
          b_R[b_T1_tmp + 2] += obj_FrameRigidTransforms_data[T1_tmp + 2] * d;
          b_R[b_T1_tmp + 3] += obj_FrameRigidTransforms_data[T1_tmp + 3] * d;
        }
      }
      memcpy(&T1[0], &b_R[0], 16U * sizeof(double));
      fid = obj_FrameParents_data[(int)fid - 1];
    }
    for (i = 0; i < 3; i++) {
      R[3 * i] = obj_FrameRigidTransforms_data[i];
      R[3 * i + 1] = obj_FrameRigidTransforms_data[i + 4];
      R[3 * i + 2] = obj_FrameRigidTransforms_data[i + 8];
    }
    for (i = 0; i < 9; i++) {
      c_R[i] = -R[i];
    }
    memset(&d_R[0], 0, 3U * sizeof(double));
    fid = d_R[0];
    d = d_R[1];
    d1 = d_R[2];
    for (i = 0; i < 3; i++) {
      double d2;
      d2 = obj_FrameRigidTransforms_data[i + 12];
      fid += c_R[3 * i] * d2;
      b_T1_tmp = i << 2;
      b_R[b_T1_tmp] = R[3 * i];
      T1_tmp = 3 * i + 1;
      d += c_R[T1_tmp] * d2;
      b_R[b_T1_tmp + 1] = R[T1_tmp];
      T1_tmp = 3 * i + 2;
      d1 += c_R[T1_tmp] * d2;
      b_R[b_T1_tmp + 2] = R[T1_tmp];
    }
    b_R[12] = fid;
    b_R[13] = d;
    b_R[14] = d1;
    b_R[3] = 0.0;
    b_R[7] = 0.0;
    b_R[11] = 0.0;
    b_R[15] = 1.0;
    memset(&tform[0], 0, sizeof(double) << 4);
    for (i = 0; i < 4; i++) {
      T1_tmp = i << 2;
      for (i1 = 0; i1 < 4; i1++) {
        fid = T1[i1 + T1_tmp];
        b_T1_tmp = i1 << 2;
        tform[T1_tmp] += b_R[b_T1_tmp] * fid;
        tform[T1_tmp + 1] += b_R[b_T1_tmp + 1] * fid;
        tform[T1_tmp + 2] += b_R[b_T1_tmp + 2] * fid;
        tform[T1_tmp + 3] += b_R[b_T1_tmp + 3] * fid;
      }
    }
  }
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                double *fidx
 * Return Type  : bool
 */
bool b_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx)
{
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 50U};
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 6; i++) {
    u8Name[i] = b_uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                double *fidx
 * Return Type  : bool
 */
bool c_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx)
{
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 51U};
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 6; i++) {
    u8Name[i] = b_uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                double *fidx
 * Return Type  : bool
 */
bool d_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx)
{
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 52U};
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 6; i++) {
    u8Name[i] = b_uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                double *fidx
 * Return Type  : bool
 */
bool e_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx)
{
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 53U};
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 6; i++) {
    u8Name[i] = b_uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                double *fidx
 * Return Type  : bool
 */
bool f_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, double *fidx)
{
  static const unsigned char b_uv[6] = {108U, 105U, 110U, 107U, 95U, 54U};
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 6; i++) {
    u8Name[i] = b_uv[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * Arguments    : const emxArray_uint8_T *obj_FrameNames
 *                double obj_NumFrames
 *                const char name[5]
 *                double *fidx
 * Return Type  : bool
 */
bool g_FrameTree_isFrameInTree(const emxArray_uint8_T *obj_FrameNames,
                               double obj_NumFrames, const char name[5],
                               double *fidx)
{
  int b_i;
  int i;
  unsigned char u8Name[200];
  const unsigned char *obj_FrameNames_data;
  bool exitg1;
  bool tf;
  obj_FrameNames_data = obj_FrameNames->data;
  *fidx = -1.0;
  memset(&u8Name[0], 0, 200U * sizeof(unsigned char));
  for (i = 0; i < 5; i++) {
    u8Name[i] = (unsigned char)name[i];
  }
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int)obj_NumFrames - 1)) {
    int k;
    bool x[200];
    bool exitg2;
    for (i = 0; i < 200; i++) {
      x[i] =
          (obj_FrameNames_data[b_i + obj_FrameNames->size[0] * i] == u8Name[i]);
    }
    tf = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 200)) {
      if (!x[k]) {
        tf = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
    if (tf) {
      *fidx = (double)b_i + 1.0;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  return *fidx > 0.0;
}

/*
 * File trailer for FrameTree.c
 *
 * [EOF]
 */
