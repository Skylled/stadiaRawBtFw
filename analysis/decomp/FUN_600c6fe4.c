// 600c6fe4  FUN_600c6fe4  size=94 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
//   600c7048 FUN_600c7048
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600b4bf0 FUN_600b4bf0


undefined4 FUN_600c6fe4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((*(byte *)(DAT_600c7044 + 0x818) & 8) == 0) &&
      ((*(byte *)(DAT_600c7044 + 0x817) & 0x10) == 0)) &&
     ((*(byte *)(DAT_600c7044 + 0x818) & 0x10) == 0)) {
    uVar2 = 4;
  }
  else {
    iVar1 = FUN_600a01a0();
    if (iVar1 == 0) {
      uVar2 = 6;
    }
    else {
      iVar1 = FUN_600b4bf0(param_1);
      if (iVar1 == 0) {
        uVar2 = 3;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


