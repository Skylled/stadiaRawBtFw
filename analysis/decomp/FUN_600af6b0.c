// 600af6b0  FUN_600af6b0  size=98 bytes
// --- callers ---
//   600adbfc FUN_600adbfc
// --- callees ---
//   600d92f8 FUN_600d92f8
//   600d92fc FUN_600d92fc


undefined1 FUN_600af6b0(int param_1)

{
  undefined1 local_d;
  int local_c;
  
  local_c = FUN_600d92f8(param_1 + 0x68);
  local_d = 0;
  if (*(short *)(param_1 + 100) == *(short *)(DAT_600af714 + 0x1550)) {
    local_d = 1;
  }
  else {
    for (; local_c != 0; local_c = FUN_600d92fc(local_c)) {
      if (*(short *)(local_c + 2) == *(short *)(DAT_600af714 + 0x1550)) {
        return 1;
      }
    }
  }
  return local_d;
}


