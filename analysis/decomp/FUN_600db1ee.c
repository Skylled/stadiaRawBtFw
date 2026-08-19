// 600db1ee  FUN_600db1ee  size=88 bytes
// --- callers ---
// --- callees ---
//   60101818 FUN_60101818
//   60101822 FUN_60101822
//   6013d318 thunk_EXT_FUN_00000fac
//   600d4f6c FUN_600d4f6c
//   600d4f84 FUN_600d4f84


uint FUN_600db1ee(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  thunk_EXT_FUN_00000fac(param_1,0x100,param_3,param_4,param_4);
  uVar1 = FUN_600d4f6c(param_2,param_1,*(undefined4 *)(param_1 + 0x100));
  if ((uVar1 & 0xff) == 0) {
    iVar3 = param_1 + 0x108;
    if (param_3 == 0) {
      FUN_60101818(iVar3);
    }
    else {
      iVar2 = FUN_60101822(iVar3,param_3);
      if (iVar2 == 0) {
        FUN_600d4f84(param_2);
        FUN_60101818(iVar3);
        *(undefined4 *)(param_1 + 0x100) = 0;
        return 4;
      }
    }
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  return uVar1;
}


