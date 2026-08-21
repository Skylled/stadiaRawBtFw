// 600ed10a  FUN_600ed10a  size=32 bytes
// --- callers ---
//   600eda9c FUN_600eda9c
//   600ece3c FUN_600ece3c
// --- callees ---
//   600ecfae FUN_600ecfae
//   600ecef4 FUN_600ecef4


undefined4 FUN_600ed10a(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ecfae();
  uVar2 = 0;
  if ((iVar1 != 0) && (iVar1 = FUN_600ecef4(*param_1,param_2,param_3), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


