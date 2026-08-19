// 600e01b4  FUN_600e01b4  size=142 bytes
// --- callers ---
//   600591b4 FUN_600591b4
// --- callees ---
//   60084b90 FUN_60084b90


void FUN_600e01b4(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,int param_9,int param_10,int param_11,
                 char param_12)

{
  uint in_fpscr;
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 extraout_s13;
  
  *(undefined4 *)(param_3 + 0x50) = param_1;
  if (param_12 == '\x02') {
    param_9 = param_9 + param_10;
    fVar2 = (float)VectorUnsignedToFloat(param_5 + param_6,(byte)(in_fpscr >> 0x16) & 3);
  }
  else {
    param_9 = param_8 + param_11;
    fVar2 = (float)VectorUnsignedToFloat(param_4 + param_7,(byte)(in_fpscr >> 0x16) & 3);
  }
  VectorUnsignedToFloat(param_9,(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = VectorUnsignedToFloat(param_7,(byte)(in_fpscr >> 0x16) & 3);
  uVar1 = VectorUnsignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
  FUN_60084b90(uVar1,fVar2 * 0.5,uVar3,param_2,param_3);
  uVar3 = VectorUnsignedToFloat(param_11,(byte)(in_fpscr >> 0x16) & 3);
  uVar1 = VectorUnsignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
  FUN_60084b90(uVar1,extraout_s13,uVar3,param_3 + 0x28);
  return;
}


