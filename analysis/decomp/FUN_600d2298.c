// 600d2298  FUN_600d2298  size=48 bytes
// --- callers ---
//   600d25f4 FUN_600d25f4
// --- callees ---
//   600d16ae FUN_600d16ae
//   600d1692 FUN_600d1692


void FUN_600d2298(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  FUN_600d1692(*(undefined4 *)(param_1 + 8));
  iVar2 = param_1 + (param_2 - 1U >> 3);
  uVar1 = (uint)*(byte *)(iVar2 + 0x2d8) & ~(1 << (param_2 - 1U & 7));
  *(char *)(iVar2 + 0x2d8) = (char)uVar1;
  FUN_600d16ae(*(undefined4 *)(param_1 + 8),uVar1,iVar2,param_4);
  return;
}


