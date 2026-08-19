// 600def9c  FUN_600def9c  size=68 bytes
// --- callers ---
//   6005c8a0 FUN_6005c8a0
//   600defe0 FUN_600defe0
// --- callees ---
//   600d3618 FUN_600d3618
//   6013d2a0 thunk_EXT_FUN_00007a2c


undefined4 FUN_600def9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(char *)(param_1 + 0x158) == '\0') || (*(int *)(param_1 + 0x14c) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_600d3618();
    *(undefined4 *)(param_1 + 0x154) = uVar1;
    if (*(int *)(param_1 + 0x150) == 0) {
      uVar1 = 3;
    }
    else {
      iVar2 = thunk_EXT_FUN_00007a2c
                        (*(undefined4 *)(param_1 + 0x80),4,*(int *)(param_1 + 0x150),0,10,param_2,
                         param_3);
      if (iVar2 == 0) {
        uVar1 = 4;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


