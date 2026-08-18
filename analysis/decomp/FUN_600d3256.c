// 600d3256  FUN_600d3256  size=18 bytes
// --- callers ---
//   600d25f4 FUN_600d25f4
//   600d194a FUN_600d194a
//   600d17ae FUN_600d17ae
//   600d2140 FUN_600d2140
//   600d1ee0 FUN_600d1ee0
//   600d1d8a FUN_600d1d8a
//   600d206c FUN_600d206c
// --- callees ---


undefined4 FUN_600d3256(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x600d3262. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1[0xb4] + 0xc))(*param_1);
    return uVar1;
  }
  return 3;
}


