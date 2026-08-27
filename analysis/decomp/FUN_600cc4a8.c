// 600cc4a8  FUN_600cc4a8  size=96 bytes
// --- callers ---
//   600da67e FUN_600da67e
//   600ce55c FUN_600ce55c
//   6006222c FUN_6006222c
// --- callees ---
//   600ccb10 FUN_600ccb10
//   600cdcc4 FUN_600cdcc4


void FUN_600cc4a8(float param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float local_1c [2];
  
  fVar2 = (float)FUN_600ccb10(local_1c);
  uVar1 = DAT_600cc510;
  if ((int)((uint)(param_1 < 0.0) << 0x1f) < 0) {
    uVar1 = DAT_600cc50c;
  }
  uVar3 = VectorFloatToUnsigned(ABS(fVar2) * DAT_600cc508 + 0.5,3);
  uVar4 = VectorFloatToUnsigned(ABS(local_1c[0]),3);
  FUN_600cdcc4(param_2,param_3,DAT_600cc514,uVar1,uVar4,uVar3);
  return;
}


