// 60100eaa  FUN_60100eaa  size=46 bytes
// --- callers ---
//   60100ed8 FUN_60100ed8
// --- callees ---


void FUN_60100eaa(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  
  bVar5 = *(char *)(param_1 + 0xab8) - 1;
  iVar1 = param_2 * 0x18 + param_1;
  *(byte *)(param_1 + 0xab8) = bVar5;
  param_1 = (uint)bVar5 * 0x18 + param_1;
  uVar2 = *(undefined4 *)(param_1 + 0x15c);
  uVar3 = *(undefined4 *)(param_1 + 0x160);
  uVar4 = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(iVar1 + 0x158) = *(undefined4 *)(param_1 + 0x158);
  *(undefined4 *)(iVar1 + 0x15c) = uVar2;
  *(undefined4 *)(iVar1 + 0x160) = uVar3;
  *(undefined4 *)(iVar1 + 0x164) = uVar4;
  uVar2 = *(undefined4 *)(param_1 + 0x16c);
  *(undefined4 *)(iVar1 + 0x168) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(iVar1 + 0x16c) = uVar2;
  return;
}


