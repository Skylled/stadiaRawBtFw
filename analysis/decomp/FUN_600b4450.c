// 600b4450  FUN_600b4450  size=242 bytes
// --- callers ---
//   600ff800 FUN_600ff800
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b4450(undefined1 param_1,undefined1 *param_2)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  byte local_d;
  undefined1 *local_c;
  
  sVar1 = (ushort)(byte)param_2[1] * 3;
  iVar2 = FUN_6006dbac(sVar1 + 0xd,DAT_600b4544,0xa47);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    *(short *)(iVar2 + 2) = sVar1 + 5;
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined1 *)(iVar2 + 8) = 0x73;
    *(undefined1 *)(iVar2 + 9) = 0xc;
    *(char *)(iVar2 + 10) = (char)sVar1 + '\x02';
    *(undefined1 *)(iVar2 + 0xb) = *param_2;
    local_c = (undefined1 *)(iVar2 + 0xd);
    *(undefined1 *)(iVar2 + 0xc) = param_2[1];
    for (local_d = 0; local_d < (byte)param_2[1]; local_d = local_d + 1) {
      *local_c = (char)*(undefined2 *)(param_2 + (uint)local_d * 2 + 2);
      puVar3 = local_c + 2;
      local_c[1] = (char)((ushort)*(undefined2 *)(param_2 + (uint)local_d * 2 + 2) >> 8);
      local_c = local_c + 3;
      *puVar3 = param_2[local_d + 0x22];
    }
    FUN_600a9234(param_1,iVar2);
    uVar4 = 1;
  }
  return uVar4;
}


