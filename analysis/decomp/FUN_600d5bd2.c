// 600d5bd2  FUN_600d5bd2  size=20 bytes
// --- callers ---
//   600d5e6c FUN_600d5e6c
//   600d6698 FUN_600d6698
//   600d5ee6 FUN_600d5ee6
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   60101fcc FUN_60101fcc


void FUN_600d5bd2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined8 uVar1;
  
  uVar1 = CONCAT44(param_2,param_1);
  if (param_1 < 0) {
    uVar1 = FUN_60101fcc();
    param_3 = extraout_r2;
  }
  thunk_EXT_FUN_0000b532((int)uVar1 << 1,(int)((ulonglong)uVar1 >> 0x20),param_3,param_4);
  return;
}


