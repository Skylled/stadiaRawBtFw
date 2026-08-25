// 600f41d0  FUN_600f41d0  size=150 bytes
// --- callers ---
//   600ad9d8 FUN_600ad9d8
// --- callees ---
//   600f0e98 FUN_600f0e98
//   600f6516 FUN_600f6516


void FUN_600f41d0(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  
  puVar3 = (undefined1 *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  uVar1 = *(short *)(param_2 + 2) - 8;
  pbVar4 = puVar3 + (uVar1 - 4);
  iVar2 = FUN_600f0e98(param_1 + 0xd,puVar3,uVar1,
                       (uint)pbVar4[3] * 0x1000000 +
                       (uint)*pbVar4 + (uint)pbVar4[1] * 0x100 + (uint)pbVar4[2] * 0x10000,
                       pbVar4 + 4);
  if (iVar2 != 0) {
    FUN_600f6516(param_1,*puVar3,*(short *)(param_2 + 2) + -1,puVar3 + 1);
  }
  return;
}


