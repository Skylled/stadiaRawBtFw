// 600dfcf2  FUN_600dfcf2  size=50 bytes
// --- callers ---
//   600dfd24 FUN_600dfd24
// --- callees ---
//   60092128 util__60092128


uint FUN_600dfcf2(undefined4 *param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[4];
  if (uVar2 <= (uint)param_1[3]) {
    uVar1 = util__60092128(param_1[2],uVar2,*param_1,param_2,param_3,param_2,param_3);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    if (*param_3 <= uVar2) {
      return 0;
    }
  }
  return 9;
}


