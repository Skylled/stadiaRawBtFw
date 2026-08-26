// 600d82d8  FUN_600d82d8  size=30 bytes
// --- callers ---
//   6006820c i2c_device__6006820c
//   600d82f6 FUN_600d82f6
// --- callees ---
//   600d81f8 FUN_600d81f8


undefined4 * FUN_600d82d8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  *(char *)(param_1 + 1) = (char)param_3;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *param_1 = param_2;
  uVar1 = FUN_600d81f8(param_2,param_3,(int)param_1 + 5,200);
  *(undefined1 *)((int)param_1 + 6) = uVar1;
  return param_1;
}


