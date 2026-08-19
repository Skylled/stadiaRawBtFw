// 600de77c  FUN_600de77c  size=186 bytes
// --- callers ---
// --- callees ---


void FUN_600de77c(int param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  if (0 < *(int *)(param_1 + 0x15c)) {
    iVar1 = *(int *)(param_1 + 0x15c) + -1;
    *(int *)(param_1 + 0x15c) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x38);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x44);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x48);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x4c);
    }
    else {
      fVar3 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
      fVar3 = fVar3 * *(float *)(param_1 + 4);
      fVar2 = 1.0 - fVar3;
      *(float *)(param_1 + 0xc) =
           fVar2 * *(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x3c) * fVar3;
      *(float *)(param_1 + 0x10) =
           fVar2 * *(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x40) * fVar3;
      *(float *)(param_1 + 0x14) =
           fVar2 * *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x44) * fVar3;
      *(float *)(param_1 + 0x18) =
           fVar2 * *(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x48) * fVar3;
      *(float *)(param_1 + 0x1c) =
           fVar2 * *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x4c) * fVar3;
    }
  }
  return;
}


