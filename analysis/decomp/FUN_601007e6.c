// 601007e6  FUN_601007e6  size=36 bytes
// --- callers ---
//   6006e484 gki_ft__6006e484
//   6006e454 FUN_6006e454
//   60092528 FUN_60092528
//   60092448 FUN_60092448
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   6013d028 thunk_EXT_FUN_00006a20


undefined4 * FUN_601007e6(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)thunk_EXT_FUN_00006a20(1,0,param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    thunk_EXT_FUN_00006a74(puVar1,0,0);
  }
  return puVar1;
}


