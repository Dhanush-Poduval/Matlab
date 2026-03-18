/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: psudoinverse_function_types.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 07-Mar-2026 20:10:01
 */

#ifndef PSUDOINVERSE_FUNCTION_TYPES_H
#define PSUDOINVERSE_FUNCTION_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef c_typedef_c_robotics_manip_inte
#define c_typedef_c_robotics_manip_inte
typedef struct {
  double Length;
  char Vector[200];
} c_robotics_manip_internal_Chara;
#endif /* c_typedef_c_robotics_manip_inte */

#ifndef typedef_rigidBodyJoint
#define typedef_rigidBodyJoint
typedef struct {
  double VelocityNumber;
  double PositionNumber;
  bool InTree;
  double JointToParentTransform[16];
  double ChildToJointTransform[16];
  c_robotics_manip_internal_Chara NameInternal;
  double PositionLimitsInternal[14];
  double HomePositionInternal[7];
  double JointAxisInternal[3];
  double MotionSubspaceInternal[36];
  c_robotics_manip_internal_Chara TypeInternal;
} rigidBodyJoint;
#endif /* typedef_rigidBodyJoint */

#ifndef d_typedef_c_robotics_manip_inte
#define d_typedef_c_robotics_manip_inte
typedef struct {
  void *CollisionPrimitive;
  double LocalPose[16];
  double WorldPose[16];
  double MeshScale[3];
  double ColorAlpha[4];
} c_robotics_manip_internal_Colli;
#endif /* d_typedef_c_robotics_manip_inte */

#ifndef c_typedef_c_emxArray_robotics_m
#define c_typedef_c_emxArray_robotics_m
typedef struct {
  c_robotics_manip_internal_Colli *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
} c_emxArray_robotics_manip_inter;
#endif /* c_typedef_c_emxArray_robotics_m */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

#ifndef e_typedef_c_robotics_manip_inte
#define e_typedef_c_robotics_manip_inte
typedef struct {
  emxArray_real_T *FrameParents;
  emxArray_real_T *FrameRigidTransforms;
  emxArray_uint8_T *FrameNames;
  double NumFrames;
} c_robotics_manip_internal_Frame;
#endif /* e_typedef_c_robotics_manip_inte */

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T
struct emxArray_int8_T {
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};
#endif /* struct_emxArray_int8_T */
#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T
typedef struct emxArray_int8_T emxArray_int8_T;
#endif /* typedef_emxArray_int8_T */

#ifndef c_typedef_d_robotics_manip_inte
#define c_typedef_d_robotics_manip_inte
typedef struct {
  bool matlabCodegenIsDeleted;
  c_emxArray_robotics_manip_inter *CollisionGeometries;
  double MaxElements;
  double Size;
} d_robotics_manip_internal_Colli;
#endif /* c_typedef_d_robotics_manip_inte */

#ifndef f_typedef_c_robotics_manip_inte
#define f_typedef_c_robotics_manip_inte
typedef struct {
  bool matlabCodegenIsDeleted;
  c_robotics_manip_internal_Chara NameInternal;
  double Index;
  rigidBodyJoint *JointInternal;
  double ParentIndex;
  double MassInternal;
  double CenterOfMassInternal[3];
  double InertiaInternal[9];
  double SpatialInertia[36];
  d_robotics_manip_internal_Colli *CollisionsInternal;
  c_robotics_manip_internal_Frame FramesInternal;
  emxArray_real_T *CollisionFrameIndices;
  d_robotics_manip_internal_Colli coder_buffer_pobj0;
  rigidBodyJoint coder_buffer_pobj1;
} c_robotics_manip_internal_Rigid;
#endif /* f_typedef_c_robotics_manip_inte */

#ifndef d_typedef_d_robotics_manip_inte
#define d_typedef_d_robotics_manip_inte
typedef struct {
  bool matlabCodegenIsDeleted;
  c_robotics_manip_internal_Chara NameInternal;
  rigidBodyJoint JointInternal;
  d_robotics_manip_internal_Colli CollisionsInternal;
} d_robotics_manip_internal_Rigid;
#endif /* d_typedef_d_robotics_manip_inte */

#ifndef c_typedef_e_robotics_manip_inte
#define c_typedef_e_robotics_manip_inte
typedef struct {
  bool matlabCodegenIsDeleted;
  d_robotics_manip_internal_Rigid Base;
  d_robotics_manip_internal_Rigid *Bodies[1];
  d_robotics_manip_internal_Rigid coder_buffer_pobj0;
} e_robotics_manip_internal_Rigid;
#endif /* c_typedef_e_robotics_manip_inte */

#ifndef c_typedef_f_robotics_manip_inte
#define c_typedef_f_robotics_manip_inte
typedef struct {
  bool matlabCodegenIsDeleted;
  double NumBodies;
  c_robotics_manip_internal_Rigid Base;
  c_robotics_manip_internal_Rigid *Bodies[8];
  double NumNonFixedBodies;
  double PositionNumber;
  double VelocityNumber;
  double VelocityDoFMap[16];
  double BodyParentFrameIdx[8];
  c_robotics_manip_internal_Rigid coder_buffer_pobj0[8];
} f_robotics_manip_internal_Rigid;
#endif /* c_typedef_f_robotics_manip_inte */

#ifndef typedef_rigidBodyTree
#define typedef_rigidBodyTree
typedef struct {
  bool matlabCodegenIsDeleted;
  f_robotics_manip_internal_Rigid TreeInternal;
  d_robotics_manip_internal_Colli coder_buffer_pobj0;
} rigidBodyTree;
#endif /* typedef_rigidBodyTree */

#endif
/*
 * File trailer for psudoinverse_function_types.h
 *
 * [EOF]
 */
