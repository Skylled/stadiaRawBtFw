// 600b3ec0  FUN_600b3ec0  size=326 bytes
// --- callers ---
//   600ff6d0 FUN_600ff6d0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b3ec0(undefined1 param_1,undefined2 *param_2)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  byte local_d;
  undefined1 *local_c;
  
  sVar1 = (ushort)*(byte *)(param_2 + 3) * 3;
  iVar2 = FUN_6006dbac(sVar1 + 0x12,DAT_600b4008,0x9c4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    *(short *)(iVar2 + 2) = sVar1 + 10;
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined1 *)(iVar2 + 8) = 0x6f;
    *(undefined1 *)(iVar2 + 9) = 0xc;
    *(char *)(iVar2 + 10) = (char)sVar1 + '\a';
    *(char *)(iVar2 + 0xb) = (char)*param_2;
    *(char *)(iVar2 + 0xc) = (char)((ushort)*param_2 >> 8);
    *(char *)(iVar2 + 0xd) = (char)param_2[1];
    *(char *)(iVar2 + 0xe) = (char)((ushort)param_2[1] >> 8);
    *(char *)(iVar2 + 0xf) = (char)param_2[2];
    *(char *)(iVar2 + 0x10) = (char)((ushort)param_2[2] >> 8);
    local_c = (undefined1 *)(iVar2 + 0x12);
    *(undefined1 *)(iVar2 + 0x11) = *(undefined1 *)(param_2 + 3);
    for (local_d = 0; local_d < *(byte *)(param_2 + 3); local_d = local_d + 1) {
      *local_c = (char)param_2[local_d + 4];
      puVar3 = local_c + 2;
      local_c[1] = (char)((ushort)param_2[local_d + 4] >> 8);
      local_c = local_c + 3;
      *puVar3 = *(undefined1 *)((int)param_2 + local_d + 0x48);
    }
    FUN_600a9234(param_1,iVar2);
    uVar4 = 1;
  }
  return uVar4;
}


