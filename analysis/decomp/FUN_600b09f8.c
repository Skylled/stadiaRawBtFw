// 600b09f8  FUN_600b09f8  size=260 bytes
// --- callers ---
//   6009daac FUN_6009daac
//   6009dc14 FUN_6009dc14
//   6009cc7c FUN_6009cc7c
//   6009e95c FUN_6009e95c
//   6009c848 FUN_6009c848
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4
FUN_600b09f8(undefined2 param_1,undefined2 param_2,undefined1 param_3,undefined1 param_4,
            undefined1 param_5,int param_6,undefined1 param_7,undefined1 param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x1a,DAT_600b0afc,0x8f);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x12;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 6;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0xf;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2 >> 8);
    *(undefined1 *)(iVar1 + 0xf) = param_3;
    *(undefined1 *)(iVar1 + 0x10) = param_4;
    *(undefined1 *)(iVar1 + 0x11) = param_5;
    local_14 = (undefined1 *)(iVar1 + 0x12);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_6);
      local_14 = local_14 + 1;
    }
    *local_14 = param_7;
    local_14[1] = param_8;
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


