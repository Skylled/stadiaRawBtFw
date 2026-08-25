// 600fd48e  FUN_600fd48e  size=82 bytes
// --- callers ---
// --- callees ---
//   60095d9c FUN_60095d9c
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600fd48e(int param_1)

{
  undefined1 auStack_18 [6];
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined4 local_c;
  
  thunk_EXT_FUN_0000b572(auStack_18,param_1 + 8,6);
  local_12 = *(undefined1 *)(param_1 + 0xe);
  local_11 = *(undefined1 *)(param_1 + 0xf);
  local_10 = *(undefined1 *)(param_1 + 0x10);
  local_f = *(undefined1 *)(param_1 + 0x11);
  local_c = *(undefined4 *)(param_1 + 0x14);
  FUN_60095d9c(6,auStack_18);
  return;
}


