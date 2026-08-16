// 600b4bf0  FUN_600b4bf0  size=124 bytes
// --- callers ---
//   600c6fe4 FUN_600c6fe4
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b4bf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x15,DAT_600b4c6c,0xdd0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0xd;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x3f;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 10;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + param_1);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


