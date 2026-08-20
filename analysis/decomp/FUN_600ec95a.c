// 600ec95a  FUN_600ec95a  size=106 bytes
// --- callers ---
// --- callees ---
//   600902e4 FUN_600902e4
//   600e092c FUN_600e092c


int FUN_600ec95a(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_2c [2];
  int local_24 [2];
  
  local_2c[0] = param_1;
  if ((param_2 == (int *)0x0) || (*param_2 != 0)) {
    iVar1 = FUN_600902e4(local_2c,param_2,param_3,0xffffffff,param_4);
  }
  else {
    iVar1 = FUN_600902e4(local_2c,0,param_3,0xffffffff,param_4);
    if (0 < iVar1) {
      iVar2 = FUN_600e092c();
      if (iVar2 == 0) {
        iVar1 = -1;
      }
      else {
        local_24[0] = iVar2;
        FUN_600902e4(local_2c,local_24,param_3,0xffffffff,param_4);
        *param_2 = iVar2;
      }
    }
  }
  return iVar1;
}


