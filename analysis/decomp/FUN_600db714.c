// 600db714  FUN_600db714  size=28 bytes
// --- callers ---
//   6007991c http_flash_writer__6007991c
//   600db730 FUN_600db730
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cf40 thunk_EXT_FUN_00007d10


void FUN_600db714(int param_1,undefined4 param_2)

{
  thunk_EXT_FUN_0000b4c2(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0x24) = param_2;
  thunk_EXT_FUN_00007d10(param_1 + 0xb4);
  return;
}


