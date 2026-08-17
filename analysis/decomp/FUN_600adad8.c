// 600adad8  FUN_600adad8  size=118 bytes
// --- callers ---
//   600adbfc FUN_600adbfc
//   600f60ee FUN_600f60ee
// --- callees ---
//   600abbc4 FUN_600abbc4
//   600f367e FUN_600f367e


void FUN_600adad8(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 local_14 [6];
  short local_e;
  undefined1 *local_c;
  
  local_c = local_14;
  if (*(short *)(DAT_600adb50 + 0x1550) != 0) {
    local_e = FUN_600abbc4(param_1);
    if (local_e != -1) {
      puVar1 = local_c + 1;
      *local_c = 1;
      local_c = puVar1;
      puVar1 = local_c + 1;
      *local_c = 0;
      local_c = puVar1;
      puVar1 = local_c + 1;
      *local_c = 0xff;
      local_c = puVar1;
      puVar1 = local_c + 1;
      *local_c = 0xff;
      local_c = puVar1;
      FUN_600f367e(local_e,*(undefined2 *)(DAT_600adb50 + 0x1550),4,local_14);
    }
  }
  return;
}


