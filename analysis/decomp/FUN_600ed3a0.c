// 600ed3a0  FUN_600ed3a0  size=26 bytes
// --- callers ---
//   600eda1c FUN_600eda1c
// --- callees ---
//   600e0976 FUN_600e0976


bool FUN_600ed3a0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  
  if (param_1[1] == param_3) {
    iVar2 = FUN_600e0976(*param_1);
    bVar1 = iVar2 == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


