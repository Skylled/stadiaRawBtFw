// 600d9076  FUN_600d9076  size=24 bytes
// --- callers ---
//   6006b85c FUN_6006b85c
// --- callees ---
//   600d8fa6 FUN_600d8fa6


uint FUN_600d9076(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 2);
  if (uVar1 == 0) {
    uVar1 = FUN_600d8fa6(*param_1,*(undefined1 *)(param_1 + 1),*(undefined2 *)((int)param_1 + 6),200
                         ,param_4);
  }
  return uVar1;
}


