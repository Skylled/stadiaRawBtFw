// 600df8fa  FUN_600df8fa  size=30 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600df8fa(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar2 + param_3;
  if (param_2 != 0) {
    for (iVar1 = 0; iVar1 != param_3; iVar1 = iVar1 + 1) {
      *(undefined1 *)(param_2 + iVar1) = *(undefined1 *)(iVar2 + iVar1);
    }
  }
  return 1;
}


