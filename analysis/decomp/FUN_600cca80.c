// 600cca80  FUN_600cca80  size=134 bytes
// --- callers ---
//   6007d578 FUN_6007d578
//   6007d5fc FUN_6007d5fc
// --- callees ---
//   600cd604 FUN_600cd604
//   600cceb0 FUN_600cceb0
//   600ccc10 FUN_600ccc10


float FUN_600cca80(float param_1)

{
  uint uVar1;
  float fVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_600ccb08 < (int)ABS(param_1)) {
    if ((uint)ABS(param_1) < 0x7f800000) {
      uVar1 = FUN_600ccc10(&local_10);
      uVar1 = uVar1 & 3;
      if (uVar1 == 1) {
        param_1 = (float)FUN_600cd604(local_10,local_c);
        param_1 = -param_1;
      }
      else if (uVar1 == 2) {
        param_1 = (float)FUN_600cceb0(local_10,local_c);
        param_1 = -param_1;
      }
      else if (uVar1 == 0) {
        param_1 = (float)FUN_600cceb0(local_10,local_c);
      }
      else {
        param_1 = (float)FUN_600cd604(local_10,local_c,1);
      }
    }
    else {
      param_1 = param_1 - param_1;
    }
    return param_1;
  }
  fVar2 = (float)FUN_600cceb0(param_1,DAT_600ccb0c);
  return fVar2;
}


