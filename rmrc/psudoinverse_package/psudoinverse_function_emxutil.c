/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function_emxutil.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

/* Include Files */
#include "psudoinverse_function_emxutil.h"
#include "psudoinverse_function_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : c_robotics_manip_internal_Frame *dst
 *                const c_robotics_manip_internal_Frame *src
 * Return Type  : void
 */
void c_emxCopyStruct_robotics_manip_(c_robotics_manip_internal_Frame *dst,
                                     const c_robotics_manip_internal_Frame *src)
{
  emxCopy_real_T(&dst->FrameParents, &src->FrameParents);
  emxCopy_real_T(&dst->FrameRigidTransforms, &src->FrameRigidTransforms);
  emxCopy_uint8_T(&dst->FrameNames, &src->FrameNames);
  dst->NumFrames = src->NumFrames;
}

/*
 * Arguments    : c_emxArray_robotics_manip_inter *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void c_emxEnsureCapacity_robotics_ma(c_emxArray_robotics_manip_inter *emxArray,
                                     int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity *
                     sizeof(c_robotics_manip_internal_Colli));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(c_robotics_manip_internal_Colli) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (c_robotics_manip_internal_Colli *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : c_robotics_manip_internal_Rigid pMatrix[8]
 * Return Type  : void
 */
void c_emxFreeMatrix_robotics_manip_(c_robotics_manip_internal_Rigid pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    d_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : c_robotics_manip_internal_Frame *pStruct
 * Return Type  : void
 */
void c_emxFreeStruct_robotics_manip_(c_robotics_manip_internal_Frame *pStruct)
{
  emxFree_real_T(&pStruct->FrameParents);
  emxFree_real_T(&pStruct->FrameRigidTransforms);
  emxFree_uint8_T(&pStruct->FrameNames);
}

/*
 * Arguments    : c_emxArray_robotics_manip_inter **pEmxArray
 * Return Type  : void
 */
void c_emxFree_robotics_manip_intern(
    c_emxArray_robotics_manip_inter **pEmxArray)
{
  if (*pEmxArray != (c_emxArray_robotics_manip_inter *)NULL) {
    if (((*pEmxArray)->data != (c_robotics_manip_internal_Colli *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (c_emxArray_robotics_manip_inter *)NULL;
  }
}

/*
 * Arguments    : c_robotics_manip_internal_Rigid pMatrix[8]
 * Return Type  : void
 */
void c_emxInitMatrix_robotics_manip_(c_robotics_manip_internal_Rigid pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    d_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : f_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void c_emxInitStruct_robotics_manip_(f_robotics_manip_internal_Rigid *pStruct)
{
  d_emxInitStruct_robotics_manip_(&pStruct->Base);
  c_emxInitMatrix_robotics_manip_(pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : c_emxArray_robotics_manip_inter **pEmxArray
 * Return Type  : void
 */
void c_emxInit_robotics_manip_intern(
    c_emxArray_robotics_manip_inter **pEmxArray)
{
  c_emxArray_robotics_manip_inter *emxArray;
  int i;
  *pEmxArray = (c_emxArray_robotics_manip_inter *)malloc(
      sizeof(c_emxArray_robotics_manip_inter));
  emxArray = *pEmxArray;
  emxArray->data = (c_robotics_manip_internal_Colli *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : d_robotics_manip_internal_Colli pMatrix[16]
 * Return Type  : void
 */
void d_emxFreeMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[16])
{
  int i;
  for (i = 0; i < 16; i++) {
    e_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : c_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void d_emxFreeStruct_robotics_manip_(c_robotics_manip_internal_Rigid *pStruct)
{
  c_emxFreeStruct_robotics_manip_(&pStruct->FramesInternal);
  emxFree_real_T(&pStruct->CollisionFrameIndices);
  e_emxFreeStruct_robotics_manip_(&pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : d_robotics_manip_internal_Colli pMatrix[16]
 * Return Type  : void
 */
void d_emxInitMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[16])
{
  int i;
  for (i = 0; i < 16; i++) {
    f_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : c_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void d_emxInitStruct_robotics_manip_(c_robotics_manip_internal_Rigid *pStruct)
{
  e_emxInitStruct_robotics_manip_(&pStruct->FramesInternal);
  emxInit_real_T(&pStruct->CollisionFrameIndices, 1);
  f_emxInitStruct_robotics_manip_(&pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : e_robotics_manip_internal_Rigid pMatrix[8]
 * Return Type  : void
 */
void e_emxFreeMatrix_robotics_manip_(e_robotics_manip_internal_Rigid pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    h_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : d_robotics_manip_internal_Colli *pStruct
 * Return Type  : void
 */
void e_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct)
{
  c_emxFree_robotics_manip_intern(&pStruct->CollisionGeometries);
}

/*
 * Arguments    : e_robotics_manip_internal_Rigid pMatrix[8]
 * Return Type  : void
 */
void e_emxInitMatrix_robotics_manip_(e_robotics_manip_internal_Rigid pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    g_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : c_robotics_manip_internal_Frame *pStruct
 * Return Type  : void
 */
void e_emxInitStruct_robotics_manip_(c_robotics_manip_internal_Frame *pStruct)
{
  emxInit_real_T(&pStruct->FrameParents, 1);
  emxInit_real_T(&pStruct->FrameRigidTransforms, 3);
  emxInit_uint8_T(&pStruct->FrameNames);
}

/*
 * Arguments    : emxArray_real_T **dst
 *                emxArray_real_T * const *src
 * Return Type  : void
 */
void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_uint8_T **dst
 *                emxArray_uint8_T * const *src
 * Return Type  : void
 */
void emxCopy_uint8_T(emxArray_uint8_T **dst, emxArray_uint8_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_uint8_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_int8_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(signed char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(signed char) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (signed char *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_uint8_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(unsigned char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(unsigned char) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (unsigned char *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : rigidBodyTree *pStruct
 * Return Type  : void
 */
void emxFreeStruct_rigidBodyTree(rigidBodyTree *pStruct)
{
  f_emxFreeStruct_robotics_manip_(&pStruct->TreeInternal);
  e_emxFreeStruct_robotics_manip_(&pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : emxArray_int8_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (signed char *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_uint8_T **pEmxArray
 * Return Type  : void
 */
void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

/*
 * Arguments    : rigidBodyTree *pStruct
 * Return Type  : void
 */
void emxInitStruct_rigidBodyTree(rigidBodyTree *pStruct)
{
  c_emxInitStruct_robotics_manip_(&pStruct->TreeInternal);
  f_emxInitStruct_robotics_manip_(&pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : emxArray_int8_T **pEmxArray
 * Return Type  : void
 */
void emxInit_int8_T(emxArray_int8_T **pEmxArray)
{
  emxArray_int8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int8_T *)malloc(sizeof(emxArray_int8_T));
  emxArray = *pEmxArray;
  emxArray->data = (signed char *)NULL;
  emxArray->numDimensions = 3;
  emxArray->size = (int *)malloc(sizeof(int) * 3U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 3; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_uint8_T **pEmxArray
 * Return Type  : void
 */
void emxInit_uint8_T(emxArray_uint8_T **pEmxArray)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : d_robotics_manip_internal_Colli pMatrix[13]
 * Return Type  : void
 */
void f_emxFreeMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[13])
{
  int i;
  for (i = 0; i < 13; i++) {
    e_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : f_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void f_emxFreeStruct_robotics_manip_(f_robotics_manip_internal_Rigid *pStruct)
{
  d_emxFreeStruct_robotics_manip_(&pStruct->Base);
  c_emxFreeMatrix_robotics_manip_(pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : d_robotics_manip_internal_Colli pMatrix[13]
 * Return Type  : void
 */
void f_emxInitMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[13])
{
  int i;
  for (i = 0; i < 13; i++) {
    f_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

/*
 * Arguments    : d_robotics_manip_internal_Colli *pStruct
 * Return Type  : void
 */
void f_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct)
{
  c_emxInit_robotics_manip_intern(&pStruct->CollisionGeometries);
}

/*
 * Arguments    : d_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void g_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct)
{
  e_emxFreeStruct_robotics_manip_(&pStruct->CollisionsInternal);
}

/*
 * Arguments    : e_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void g_emxInitStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct)
{
  h_emxInitStruct_robotics_manip_(&pStruct->Base);
  h_emxInitStruct_robotics_manip_(&pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : e_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void h_emxFreeStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct)
{
  g_emxFreeStruct_robotics_manip_(&pStruct->Base);
  g_emxFreeStruct_robotics_manip_(&pStruct->coder_buffer_pobj0);
}

/*
 * Arguments    : d_robotics_manip_internal_Rigid *pStruct
 * Return Type  : void
 */
void h_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct)
{
  f_emxInitStruct_robotics_manip_(&pStruct->CollisionsInternal);
}

/*
 * File trailer for psudoinverse_function_emxutil.c
 *
 * [EOF]
 */
