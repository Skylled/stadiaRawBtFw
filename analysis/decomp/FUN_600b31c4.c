// 600b31c4  FUN_600b31c4  size=118 bytes
// --- callers ---
//   600a01c4 FUN_600a01c4
// --- callees ---
//   6009a804 FUN_6009a804
//   6006dbac FUN_6006dbac
//   6009a7c0 FUN_6009a7c0
//   600a9234 FUN_600a9234


undefined4 FUN_600b31c4(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b323c,0x472);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 3;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(param_1,iVar1);
    if (param_1 == '\0') {
      FUN_6009a7c0();
      FUN_6009a804(0);
    }
    uVar2 = 1;
  }
  return uVar2;
}


