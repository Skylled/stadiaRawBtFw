// 600af1d8  FUN_600af1d8  size=96 bytes
// --- callers ---
//   600adbfc FUN_600adbfc
// --- callees ---
//   600d92f8 FUN_600d92f8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d92fc FUN_600d92fc


void FUN_600af1d8(void)

{
  undefined1 auStack_14 [8];
  int local_c;
  
  for (local_c = FUN_600d92f8(DAT_600af238); local_c != 0; local_c = FUN_600d92fc(local_c)) {
    if (*(char *)(local_c + 6) == '\0') {
      *(undefined1 *)(local_c + 6) = 1;
      thunk_EXT_FUN_0000b572(auStack_14,local_c,7);
      if (*(int *)(DAT_600af23c + 0x1558) != 0) {
        (**(code **)(DAT_600af23c + 0x1558))(2,auStack_14,0);
      }
    }
  }
  return;
}


