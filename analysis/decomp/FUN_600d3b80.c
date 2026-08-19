// 600d3b80  FUN_600d3b80  size=24 bytes
// --- callers ---
//   60079618 FUN_60079618
//   60080f2c FUN_60080f2c
//   6005db20 FUN_6005db20
//   6005a9fc FUN_6005a9fc
//   6007991c http_flash_writer__6007991c
//   60075044 FUN_60075044
//   600667fc FUN_600667fc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600d3b80(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  if (param_3 == 1) {
    *param_1 = *param_2;
  }
  else if (param_3 != 0) {
    thunk_EXT_FUN_0000b572();
    return;
  }
  return;
}


