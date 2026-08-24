// 600f061a  FUN_600f061a  size=72 bytes
// --- callers ---
//   600fbf8a FUN_600fbf8a
//   600fc04a FUN_600fc04a
//   600fcd96 FUN_600fcd96
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60098ec8 FUN_60098ec8


bool FUN_600f061a(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_60098ec8(param_1,2);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b572(param_2,iVar1 + 0x136,6);
    *param_3 = *(undefined1 *)(iVar1 + 0x13c);
  }
  return iVar1 != 0;
}


