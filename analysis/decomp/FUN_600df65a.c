// 600df65a  FUN_600df65a  size=26 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600df65a(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar2 + param_3;
  for (iVar1 = 0; iVar1 != param_3; iVar1 = iVar1 + 1) {
    *(undefined1 *)(iVar2 + iVar1) = *(undefined1 *)(param_2 + iVar1);
  }
  return 1;
}


