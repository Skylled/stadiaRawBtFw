// 600b20a0  FUN_600b20a0  size=232 bytes
// --- callers ---
//   600bc5c4 FUN_600bc5c4
// --- callees ---
//   6006dbac FUN_6006dbac
//   6009a82c FUN_6009a82c


undefined4
FUN_600b20a0(int param_1,undefined2 param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5
            ,undefined1 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x18,DAT_600b2188,0xa5);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x10;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 5;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 0xd;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = (char)param_2;
    local_14[1] = (char)((ushort)param_2 >> 8);
    local_14[2] = param_3;
    local_14[3] = param_4;
    local_14[4] = (char)param_5;
    local_14[5] = (char)((ushort)param_5 >> 8);
    local_14[6] = param_6;
    FUN_6009a82c(iVar1,param_1);
    uVar2 = 1;
  }
  return uVar2;
}


