// 600de400  FUN_600de400  size=78 bytes
// --- callers ---
// --- callees ---
//   6007df4c FUN_6007df4c


void FUN_600de400(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar1 = *(int *)(param_1 + 0x1c) + -1;
    *(int *)(param_1 + 0x1c) = iVar1;
    fVar4 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = fVar4 * *(float *)(param_1 + 0xc);
    fVar3 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(param_1 + 0x18),(byte)(in_fpscr >> 0x16) & 3);
    fVar5 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    uVar2 = VectorFloatToUnsigned(fVar5 * (1.0 - fVar4) + fVar3 * fVar4,3);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    FUN_6007df4c();
    return;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  return;
}


