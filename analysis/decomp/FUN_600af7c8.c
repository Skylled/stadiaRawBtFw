// 600af7c8  FUN_600af7c8  size=72 bytes
// --- callers ---
//   600f3b78 FUN_600f3b78
//   600f395a FUN_600f395a
//   600f37d2 FUN_600f37d2
//   600ab778 FUN_600ab778
//   600f3da6 FUN_600f3da6
//   600f3ade FUN_600f3ade
//   600afdf8 FUN_600afdf8
//   600f3e00 FUN_600f3e00
//   600f38d0 FUN_600f38d0
//   600f39fc FUN_600f39fc
//   600f367e FUN_600f367e
//   600ab620 FUN_600ab620
// --- callees ---


int FUN_600af7c8(byte param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((param_1 < 10) && (*(char *)((uint)param_1 * 0x10c + DAT_600af810 + 0xfa) != '\0')) {
    local_c = (uint)param_1 * 0x10c + DAT_600af810;
  }
  return local_c;
}


