// 600d10a4  FUN_600d10a4  size=20 bytes
// --- callers ---
//   600d0624 FUN_600d0624
//   600d4f84 FUN_600d4f84
// --- callees ---


undefined4 FUN_600d10a4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 3;
  }
  if (param_1[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x600d10ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1[1] + 0x10))(*param_1);
    return uVar1;
  }
  return 6;
}


