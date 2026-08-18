// 600c2e9c  FUN_600c2e9c  size=198 bytes
// --- callers ---
// --- callees ---
//   600f1f5c FUN_600f1f5c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f1a0e FUN_600f1a0e
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c2e9c(int param_1)

{
  uint uVar1;
  uint auStack_18 [3];
  undefined1 local_9;
  
  local_9 = 0;
  auStack_18[2] = FUN_600f1f5c(param_1 + 8);
  if (auStack_18[2] == 0) {
    thunk_EXT_FUN_0000b5ba(auStack_18,0,8);
  }
  else {
    thunk_EXT_FUN_0000b572(auStack_18,auStack_18[2],8);
  }
  if (*(char *)(param_1 + 0xf) == '\x02') {
    FUN_600f1a0e(param_1 + 8,0xb,auStack_18);
  }
  else {
    if ((*(char *)(param_1 + 0xf) == '\0') && (*(byte *)(param_1 + 0xe) < 0x1f)) {
      uVar1 = *(uint *)(DAT_600c2f64 + (uint)*(byte *)(param_1 + 0xe) * 4) >> 5;
      local_9 = (char)uVar1;
      auStack_18[uVar1 & 0xff] =
           auStack_18[uVar1 & 0xff] |
           1 << (*(int *)(DAT_600c2f64 + (uint)*(byte *)(param_1 + 0xe) * 4) +
                 (uVar1 & 0xff) * -0x20 & 0xff);
    }
    FUN_600f1a0e(param_1 + 8,0,auStack_18);
  }
  return;
}


