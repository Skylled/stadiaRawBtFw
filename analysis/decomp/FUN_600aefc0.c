// 600aefc0  FUN_600aefc0  size=92 bytes
// --- callers ---
//   600af074 FUN_600af074
// --- callees ---
//   600af718 FUN_600af718
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600aefc0(int param_1)

{
  undefined1 auStack_14 [8];
  int local_c;
  
  local_c = 0;
  local_c = FUN_600af718(param_1 + 0xd);
  if (local_c != 0) {
    *(undefined1 *)(local_c + 6) = 0;
    thunk_EXT_FUN_0000b572(auStack_14,local_c,7);
    if (*(int *)(DAT_600af01c + 0x1558) != 0) {
      (**(code **)(DAT_600af01c + 0x1558))(2,auStack_14,0);
    }
  }
  return;
}


