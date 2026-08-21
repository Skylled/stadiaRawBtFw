// 600ecef4  FUN_600ecef4  size=22 bytes
// --- callers ---
//   600ed10a FUN_600ed10a
//   600ecfae FUN_600ecfae
//   600ecf0a FUN_600ecf0a
//   600ed0de FUN_600ed0de
// --- callees ---
//   600ecea6 FUN_600ecea6


bool FUN_600ecef4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_600ecea6();
  if (iVar1 != 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_3;
  }
  return iVar1 != 0;
}


