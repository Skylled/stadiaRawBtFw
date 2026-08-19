// 600dc56e  FUN_600dc56e  size=54 bytes
// --- callers ---
// --- callees ---


void FUN_600dc56e(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_3;
  iVar1 = param_3[1];
  for (iVar2 = 0; iVar2 != iVar1 - iVar3 >> 3; iVar2 = iVar2 + 1) {
    *(int *)(iVar3 + iVar2 * 8) = *(int *)(*param_1 + iVar2 * 0xc) + param_2 * 0x140;
    *(undefined4 *)(iVar3 + iVar2 * 8 + 4) = 0x50;
  }
  return;
}


