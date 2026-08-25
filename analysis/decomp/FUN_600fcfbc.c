// 600fcfbc  FUN_600fcfbc  size=126 bytes
// --- callers ---
// --- callees ---
//   600a42d0 FUN_600a42d0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f1f5c FUN_600f1f5c
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fcfbc(int param_1)

{
  undefined1 auStack_14 [8];
  int local_c;
  
  local_c = FUN_600f1f5c(param_1 + 8);
  if (local_c == 0) {
    thunk_EXT_FUN_0000b5ba(auStack_14,0,8);
  }
  else {
    thunk_EXT_FUN_0000b572(auStack_14,local_c,8);
  }
  if (*(char *)(param_1 + 0xe) == '\0') {
    FUN_600a42d0(param_1 + 8,0xb,0,0,auStack_14);
  }
  else {
    FUN_600a42d0(param_1 + 8,0,*(undefined1 *)(param_1 + 0xf),param_1 + 0x10,auStack_14);
  }
  return;
}


