// 600d10f6  FUN_600d10f6  size=62 bytes
// --- callers ---
//   600cfe6a FUN_600cfe6a
//   60054f30 FUN_60054f30
//   600d0c3c FUN_600d0c3c
//   600cfc8e FUN_600cfc8e
//   600d06d6 FUN_600d06d6
// --- callees ---
//   600d0ede FUN_600d0ede


undefined4 FUN_600d10f6(int param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_11;
  
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = FUN_600d0ede(param_1,3,&local_11,param_4,param_1);
    if ((param_2 & 0xf) < 8) {
      param_1 = ((uint)(param_2 >> 7) | (param_2 & 0xf) << 1) * 0xc + param_1;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined1 *)(param_1 + 0x14) = 0;
    }
    else {
      uVar1 = 4;
    }
  }
  return uVar1;
}


