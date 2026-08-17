// 60098d2c  FUN_60098d2c  size=90 bytes
// --- callers ---
//   60098d8c FUN_60098d8c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a1394 FUN_600a1394


char FUN_60098d2c(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_1c [7];
  char local_15;
  undefined1 *local_14;
  
  local_14 = local_1c;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(param_1 + (5 - iVar2));
    local_14 = puVar1;
  }
  local_15 = FUN_600a1394(0xfc01,6,local_1c,*(undefined4 *)(param_1 + 8));
  if (local_15 != '\x03') {
    thunk_EXT_FUN_0000b572(DAT_60098d88,param_1,6);
  }
  return local_15;
}


