// 600b2eec  FUN_600b2eec  size=142 bytes
// --- callers ---
//   60099584 FUN_60099584
//   6009a5b0 FUN_6009a5b0
//   6009931c FUN_6009931c
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b2eec(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x12,DAT_600b2f7c,0x3bc);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 10;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xb;
    *(undefined1 *)(iVar1 + 9) = 8;
    *(undefined1 *)(iVar1 + 10) = 7;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = param_2;
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


