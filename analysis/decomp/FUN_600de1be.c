// 600de1be  FUN_600de1be  size=184 bytes
// --- callers ---
// --- callees ---
//   6013d340 thunk_EXT_FUN_00009b30


void FUN_600de1be(float param_1,float param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint in_fpscr;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr8;
  float fVar2;
  
  if ((param_5 == 0) || (param_4 != 0)) {
    uVar1 = *(uint *)(param_3 + 0x10);
  }
  else {
    uVar1 = *(int *)(param_3 + 0x20) - 1;
    uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  }
  *(uint *)(param_3 + 0x20) = uVar1;
  if (0 < *(int *)(param_3 + 0x20)) {
    param_1 = *(float *)(param_3 + 0xc) / param_1;
    fVar2 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(param_3 + 0x1c),(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = fVar2 * *(float *)(param_3 + 8);
    if (fVar2 < param_1 * param_2 * param_1) {
      thunk_EXT_FUN_00009b30(fVar2 / param_2);
    }
  }
  fVar2 = *(float *)(param_3 + 4);
  coprocessor_function2(10,3,0,in_cr8,in_cr8,in_cr7);
  coprocessor_function2(10,3,0,in_cr0,in_cr0,in_cr8);
  if ((int)((uint)(fVar2 < 1.0) << 0x1f) < 0) {
    fVar2 = 1.0;
  }
  *(float *)(param_3 + 0x18) = fVar2;
  return;
}


