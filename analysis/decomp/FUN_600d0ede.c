// 600d0ede  FUN_600d0ede  size=20 bytes
// --- callers ---
//   600d10f6 FUN_600d10f6
//   600d0fb6 FUN_600d0fb6
//   600d1178 FUN_600d1178
//   600d1156 FUN_600d1156
//   600d1134 FUN_600d1134
//   600d1066 FUN_600d1066
//   600d11ba FUN_600d11ba
//   600d105e FUN_600d105e
//   600d10b8 FUN_600d10b8
// --- callees ---


undefined4 FUN_600d0ede(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 3;
  }
  if (param_1[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x600d0ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1[1] + 0x14))(*param_1);
    return uVar1;
  }
  return 6;
}


