// 600b34ac  FUN_600b34ac  size=152 bytes
// --- callers ---
//   600a10e0 FUN_600a10e0
// --- callees ---
//   6004cb28 FUN_6004cb28
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b34ac(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ushort local_16;
  undefined1 *local_14;
  
  sVar1 = FUN_6004cb28(param_1);
  local_16 = sVar1 + 1;
  iVar2 = FUN_6006dbac(0x103,DAT_600b3544,0x56a);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    *(undefined2 *)(iVar2 + 2) = 0xfb;
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined1 *)(iVar2 + 8) = 0x13;
    *(undefined1 *)(iVar2 + 9) = 0xc;
    *(undefined1 *)(iVar2 + 10) = 0xf8;
    if (0xf8 < local_16) {
      local_16 = 0xf8;
    }
    local_14 = (undefined1 *)(iVar2 + 0xb);
    for (iVar4 = 0; iVar4 < (int)(uint)local_16; iVar4 = iVar4 + 1) {
      *local_14 = *(undefined1 *)(iVar4 + param_1);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar2);
    uVar3 = 1;
  }
  return uVar3;
}


