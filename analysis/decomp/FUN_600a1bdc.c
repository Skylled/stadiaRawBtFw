// 600a1bdc  FUN_600a1bdc  size=110 bytes
// --- callers ---
//   600a08c4 FUN_600a08c4
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600b4d58 FUN_600b4d58


undefined4 FUN_600a1bdc(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_1 == 1)) {
    if ((*(byte *)(DAT_600a1c4c + 0x816) & 0x20) == 0) {
      uVar2 = 4;
    }
    else {
      if (param_1 != *(short *)(DAT_600a1c4c + 0xb1e)) {
        iVar1 = FUN_600a01a0();
        if (iVar1 == 0) {
          return 6;
        }
        iVar1 = FUN_600b4d58((char)param_1);
        if (iVar1 == 0) {
          return 3;
        }
        *(short *)(DAT_600a1c4c + 0xb1e) = param_1;
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}


