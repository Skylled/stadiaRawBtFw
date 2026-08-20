// 600ea6b6  FUN_600ea6b6  size=46 bytes
// --- callers ---
// --- callees ---
//   600ea438 FUN_600ea438


undefined4 FUN_600ea6b6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  FUN_600ea438(param_3,param_2,param_4,iVar1,iVar1 + 0x80,iVar1 + 0x100,param_1 + 0x28,
               *(undefined4 *)(param_1 + 0x10));
  return 1;
}


