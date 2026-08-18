// 600d3244  FUN_600d3244  size=18 bytes
// --- callers ---
//   600d17ae FUN_600d17ae
//   600d1d8a FUN_600d1d8a
//   600d206c FUN_600d206c
//   600567fc FUN_600567fc
// --- callees ---


undefined4 FUN_600d3244(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (param_3 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x600d3250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1[0xb4] + 8))(*param_1);
    return uVar1;
  }
  return 3;
}


