// 600a12e0  FUN_600a12e0  size=88 bytes
// --- callers ---
//   600a1900 FUN_600a1900
//   600c269c FUN_600c269c
//   600a0bc4 FUN_600a0bc4
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b3878 FUN_600b3878


undefined4 FUN_600a12e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = thunk_EXT_FUN_0000b554(DAT_600a1338,param_1,3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    thunk_EXT_FUN_0000b572(DAT_600a1338,param_1,3);
    if ((*(char *)(DAT_600a133c + 0x881) == '\0') || (*(char *)(DAT_600a133c + 0x881) == '\x01')) {
      uVar2 = 0xc;
    }
    else {
      iVar1 = FUN_600b3878(param_1);
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


