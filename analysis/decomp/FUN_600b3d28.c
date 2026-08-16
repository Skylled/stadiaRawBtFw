// 600b3d28  FUN_600b3d28  size=142 bytes
// --- callers ---
//   600a5ec8 FUN_600a5ec8
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b3d28(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x12,DAT_600b3db8,0x98c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 10;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x34;
    *(undefined1 *)(iVar1 + 9) = 4;
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


