// 600ea008  FUN_600ea008  size=42 bytes
// --- callers ---
// --- callees ---
//   6008c9e0 FUN_6008c9e0


undefined4 FUN_600ea008(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  FUN_6008c9e0(param_2,iVar1,param_3,param_4,param_4);
  FUN_6008c9e0(param_2 + 8,iVar1 + 0x80);
  FUN_6008c9e0(param_2 + 0x10,iVar1 + 0x100);
  return 1;
}


