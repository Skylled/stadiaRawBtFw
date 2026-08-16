// 600b24f8  FUN_600b24f8  size=204 bytes
// --- callers ---
//   600a7870 FUN_600a7870
//   600a42d0 FUN_600a42d0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b24f8(int param_1,byte param_2,byte *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte *local_2c;
  int local_18;
  byte *local_14;
  
  iVar1 = FUN_6006dbac(0x22,DAT_600b25c4,0x172);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x1a;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xd;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 0x17;
    local_14 = (byte *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(byte *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = param_2;
    local_2c = param_3;
    for (local_18 = 0; local_14 = local_14 + 1, local_18 < (int)(uint)param_2;
        local_18 = local_18 + 1) {
      *local_14 = *local_2c;
      local_2c = local_2c + 1;
    }
    for (; local_18 < 0x10; local_18 = local_18 + 1) {
      *local_14 = 0;
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


