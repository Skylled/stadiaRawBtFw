// 600ec9c4  FUN_600ec9c4  size=6 bytes
// --- callers ---
// --- callees ---


int FUN_600ec9c4(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 auStack_2c [2];
  int aiStack_24 [2];
  
  auStack_2c[0] = param_1;
  if ((param_2 == (int *)0x0) || (*param_2 != 0)) {
    iVar1 = FUN_600902e4(auStack_2c,param_2,param_3,0xffffffff,0);
  }
  else {
    iVar1 = FUN_600902e4(auStack_2c,0,param_3,0xffffffff,0);
    if (0 < iVar1) {
      iVar2 = FUN_600e092c();
      if (iVar2 == 0) {
        iVar1 = -1;
      }
      else {
        aiStack_24[0] = iVar2;
        FUN_600902e4(auStack_2c,aiStack_24,param_3,0xffffffff,0);
        *param_2 = iVar2;
      }
    }
  }
  return iVar1;
}


