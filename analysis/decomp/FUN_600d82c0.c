// 600d82c0  FUN_600d82c0  size=24 bytes
// --- callers ---
//   6006820c i2c_device__6006820c
//   600d82f6 FUN_600d82f6
// --- callees ---
//   600d8282 FUN_600d8282


uint FUN_600d82c0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((int)param_1 + 6);
  if (uVar1 == 0) {
    uVar1 = FUN_600d8282(*param_1,*(undefined1 *)(param_1 + 1),*(undefined1 *)((int)param_1 + 5),200
                         ,param_4);
  }
  return uVar1;
}


