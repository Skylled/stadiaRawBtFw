// 600f05da  FUN_600f05da  size=64 bytes
// --- callers ---
//   600fbf8a FUN_600fbf8a
//   600fcd40 FUN_600fcd40
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60098ec8 FUN_60098ec8


void FUN_600f05da(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_60098ec8(param_1,2);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b572(param_2,iVar1 + 0x12f,6);
    *param_3 = *(undefined1 *)(iVar1 + 0x135);
  }
  return;
}


