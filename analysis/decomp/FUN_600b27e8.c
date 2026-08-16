// 600b27e8  FUN_600b27e8  size=194 bytes
// --- callers ---
//   600a7870 FUN_600a7870
//   600a3014 FUN_600a3014
//   600a74dc FUN_600a74dc
// --- callees ---
//   6006dbac FUN_6006dbac
//   6009a82c FUN_6009a82c


undefined4 FUN_600b27e8(int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x15,DAT_600b28ac,0x217);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0xd;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x19;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 10;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = param_2;
    local_14[1] = param_3;
    local_14[2] = (char)param_4;
    local_14[3] = (char)((ushort)param_4 >> 8);
    FUN_6009a82c(iVar1,param_1);
    uVar2 = 1;
  }
  return uVar2;
}


