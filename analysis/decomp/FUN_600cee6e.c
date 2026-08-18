// 600cee6e  FUN_600cee6e  size=66 bytes
// --- callers ---
//   600ceeb0 FUN_600ceeb0
// --- callees ---


undefined4 FUN_600cee6e(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 0x3c00) == 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(param_2 << 0x12) < 0) {
      uVar1 = 0x38a;
    }
    else if ((int)(param_2 << 0x14) < 0) {
      uVar1 = 0x389;
    }
    else if ((int)(param_2 << 0x15) < 0) {
      uVar1 = 0x386;
    }
    else {
      uVar1 = 0x387;
      if ((param_2 & 0x1000) == 0) {
        uVar1 = 0;
      }
    }
    *(uint *)(param_1 + 0x14) = param_2 & 0x3c00;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x300;
  }
  return uVar1;
}


