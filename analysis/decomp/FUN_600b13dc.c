// 600b13dc  FUN_600b13dc  size=216 bytes
// --- callers ---
//   6009afd4 FUN_6009afd4
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b13dc(undefined2 param_1,int param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x27,DAT_600b14b4,0x27f);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x1f;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x19;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0x1c;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    local_14 = (undefined1 *)(iVar1 + 0xd);
    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + param_2);
      local_14 = local_14 + 1;
    }
    *local_14 = (char)param_3;
    local_14[1] = (char)((ushort)param_3 >> 8);
    local_14 = local_14 + 2;
    for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + param_4);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


