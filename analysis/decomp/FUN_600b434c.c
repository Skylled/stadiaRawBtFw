// 600b434c  FUN_600b434c  size=256 bytes
// --- callers ---
//   600ff79e FUN_600ff79e
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b434c(undefined1 param_1,byte *param_2)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  byte local_d;
  undefined1 *local_c;
  
  sVar1 = (ushort)*param_2 * 4;
  iVar2 = FUN_6006dbac(sVar1 + 0xc,DAT_600b444c,0xa26);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    *(short *)(iVar2 + 2) = sVar1 + 4;
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined1 *)(iVar2 + 8) = 0x72;
    *(undefined1 *)(iVar2 + 9) = 0xc;
    *(char *)(iVar2 + 10) = (char)sVar1 + '\x01';
    local_c = (undefined1 *)(iVar2 + 0xc);
    *(byte *)(iVar2 + 0xb) = *param_2;
    for (local_d = 0; local_d < *param_2; local_d = local_d + 1) {
      *local_c = (char)*(undefined2 *)(param_2 + (uint)local_d * 2 + 2);
      local_c[1] = (char)((ushort)*(undefined2 *)(param_2 + (uint)local_d * 2 + 2) >> 8);
      puVar3 = local_c + 3;
      local_c[2] = (char)*(undefined2 *)(param_2 + (local_d + 8) * 2 + 2);
      local_c = local_c + 4;
      *puVar3 = (char)((ushort)*(undefined2 *)(param_2 + (local_d + 8) * 2 + 2) >> 8);
    }
    FUN_600a9234(param_1,iVar2);
    uVar4 = 1;
  }
  return uVar4;
}


