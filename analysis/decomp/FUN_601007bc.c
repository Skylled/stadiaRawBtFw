// 601007bc  FUN_601007bc  size=42 bytes
// --- callers ---
//   6006e854 FUN_6006e854
//   601017e8 FUN_601017e8
//   600557e8 FUN_600557e8
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   600c9de4 queue__600c9de4


undefined4 * FUN_601007bc(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)queue__600c9de4(1,0,0,param_2,param_1,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    thunk_EXT_FUN_00006a74(puVar1,0,0);
  }
  return puVar1;
}


