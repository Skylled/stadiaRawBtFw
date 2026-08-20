// 600eab58  FUN_600eab58  size=52 bytes
// --- callers ---
// --- callees ---
//   600e7c2c FUN_600e7c2c
//   600eab3a FUN_600eab3a


void FUN_600eab58(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_600eab3a(param_1,param_3,param_3,param_4,param_4);
  FUN_600e7c2c(param_2,*(undefined4 *)(param_1 + 0x24),param_3,*(undefined4 *)(param_1 + 0x28));
  iVar2 = *(int *)(param_1 + 0x28);
  for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
    *(uint *)(param_2 + iVar3 * 4) = *(uint *)(param_2 + iVar3 * 4) & uVar1;
  }
  return;
}


