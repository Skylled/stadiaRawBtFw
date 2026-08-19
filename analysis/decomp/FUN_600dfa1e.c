// 600dfa1e  FUN_600dfa1e  size=36 bytes
// --- callers ---
//   6008261c FUN_6008261c
//   600829d4 FUN_600829d4
// --- callees ---
//   60082270 FUN_60082270


undefined4 FUN_600dfa1e(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_2 + 8) == 0) ||
     (iVar2 = FUN_60082270(param_2,0,*(int *)(param_2 + 8),param_4,param_4), iVar2 != 0)) {
    uVar1 = 1;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


