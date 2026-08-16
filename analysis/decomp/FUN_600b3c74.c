// 600b3c74  FUN_600b3c74  size=176 bytes
// --- callers ---
//   600a5ec8 FUN_600a5ec8
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b3c74(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x14,DAT_600b3d24,0x96f);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0xc;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x2b;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 9;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = param_2;
    local_14[1] = param_3;
    local_14[2] = param_4;
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


