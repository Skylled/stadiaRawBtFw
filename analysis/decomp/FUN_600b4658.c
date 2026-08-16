// 600b4658  FUN_600b4658  size=184 bytes
// --- callers ---
//   600a4a20 FUN_600a4a20
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b4658(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x15,DAT_600b4710,0xac3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0xd;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x2e;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 10;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = (char)param_2;
    local_14[1] = (char)((uint)param_2 >> 8);
    local_14[2] = (char)((uint)param_2 >> 0x10);
    local_14[3] = (char)((uint)param_2 >> 0x18);
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


