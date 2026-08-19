// 600db14c  FUN_600db14c  size=60 bytes
// --- callers ---
//   60077750 FUN_60077750
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d238 thunk_EXT_FUN_0000b588


uint FUN_600db14c(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x100);
  if (param_3 <= *(uint *)(param_1 + 0x100)) {
    uVar1 = param_3;
  }
  if (uVar1 != 0) {
    if (param_2 != 0) {
      thunk_EXT_FUN_0000b572(param_2,param_1,uVar1,param_4,param_4);
    }
    if (uVar1 < *(uint *)(param_1 + 0x100)) {
      thunk_EXT_FUN_0000b588(param_1,param_1 + uVar1,*(uint *)(param_1 + 0x100) - uVar1);
    }
    *(uint *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) - uVar1;
  }
  return uVar1;
}


