// 600a1b68  FUN_600a1b68  size=110 bytes
// --- callers ---
//   600a08c4 FUN_600a08c4
// --- callees ---
//   600b4c70 FUN_600b4c70
//   600a01a0 FUN_600a01a0


undefined4 FUN_600a1b68(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_1 == 1)) {
    if ((*(byte *)(DAT_600a1bd8 + 0x816) & 0x10) == 0) {
      uVar2 = 4;
    }
    else {
      if (param_1 != *(short *)(DAT_600a1bd8 + 0xb1c)) {
        iVar1 = FUN_600a01a0();
        if (iVar1 == 0) {
          return 6;
        }
        iVar1 = FUN_600b4c70((char)param_1);
        if (iVar1 == 0) {
          return 3;
        }
        *(short *)(DAT_600a1bd8 + 0xb1c) = param_1;
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}


