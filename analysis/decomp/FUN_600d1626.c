// 600d1626  FUN_600d1626  size=60 bytes
// --- callers ---
// --- callees ---
//   6013d3b8 thunk_EXT_FUN_00006820


undefined4
FUN_600d1626(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((param_1 == (undefined4 *)0x0) ||
     (uVar2 = thunk_EXT_FUN_00006820
                        (*param_1,param_2,param_1[1] != 0,param_3,(uint)(param_4 * 1000) / 1000,
                         param_2,param_3), param_5 == (uint *)0x0)) {
    uVar1 = 1;
  }
  else {
    *param_5 = uVar2 & param_2;
    if ((uVar2 & param_2) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


