// 600a1c50  FUN_600a1c50  size=86 bytes
// --- callers ---
//   600a08c4 FUN_600a08c4
// --- callees ---
//   600b4ce4 FUN_600b4ce4
//   600a01a0 FUN_600a01a0


undefined4 FUN_600a1c50(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != '\0') {
    if (param_1 != '\x01') {
      return 5;
    }
    if ((*(byte *)(DAT_600a1ca8 + 0x816) & 0x40) == 0) {
      return 4;
    }
  }
  iVar1 = FUN_600a01a0();
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    iVar1 = FUN_600b4ce4(param_1);
    if (iVar1 == 0) {
      uVar2 = 3;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


