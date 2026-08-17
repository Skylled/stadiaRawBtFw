// 6009ab40  FUN_6009ab40  size=80 bytes
// --- callers ---
//   600c269c FUN_600c269c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_6009ab40(char param_1,int param_2)

{
  if (param_2 != 0) {
    if (param_1 == '\x01') {
      thunk_EXT_FUN_0000b572(DAT_6009ab90 + 0x151,param_2,0x30);
    }
    else if (param_1 == '\x02') {
      thunk_EXT_FUN_0000b572(DAT_6009ab90 + 0x181,param_2,0x10);
    }
  }
  return;
}


