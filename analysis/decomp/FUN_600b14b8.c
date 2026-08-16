// 600b14b8  FUN_600b14b8  size=156 bytes
// --- callers ---
//   6009b0a8 FUN_6009b0a8
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b14b8(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x1d,DAT_600b1554,0x298);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x15;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x1a;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0x12;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    local_14 = (undefined1 *)(iVar1 + 0xd);
    for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + param_2);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


