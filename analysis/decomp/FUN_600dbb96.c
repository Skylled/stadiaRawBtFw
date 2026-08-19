// 600dbb96  FUN_600dbb96  size=58 bytes
// --- callers ---
//   600dbbd0 FUN_600dbbd0
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


undefined4 FUN_600dbb96(int *param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar1 = 3;
  }
  else {
    uVar2 = param_1[1];
    if (param_3 <= (uint)param_1[1]) {
      uVar2 = param_3;
    }
    if (*param_1 != 0) {
      if (uVar2 != 0) {
        thunk_EXT_FUN_0000b588(param_2,*param_1,uVar2);
      }
      *param_1 = *param_1 + uVar2;
    }
    param_1[1] = param_1[1] - uVar2;
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar2;
    }
    uVar1 = 0;
  }
  return uVar1;
}


