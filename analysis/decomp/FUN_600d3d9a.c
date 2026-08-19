// 600d3d9a  FUN_600d3d9a  size=62 bytes
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   600dffe8 FUN_600dffe8


undefined4 FUN_600d3d9a(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 + 8;
  iVar1 = FUN_600dffe8(param_1,2);
  if ((((iVar1 == 0) && (iVar1 = FUN_600dffe8(param_1,8), iVar1 == 0)) &&
      (iVar1 = FUN_600dffe8(param_1,10), iVar1 == 0)) &&
     (iVar1 = FUN_600dffe8(param_1,9), iVar1 == 0)) {
    uVar2 = FUN_600dffe8(param_1,1);
    return uVar2;
  }
  return 1;
}


