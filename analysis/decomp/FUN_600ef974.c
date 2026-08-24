// 600ef974  FUN_600ef974  size=72 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   600ef8c8 FUN_600ef8c8
//   6009506c FUN_6009506c
//   60094ffc FUN_60094ffc


int FUN_600ef974(int param_1)

{
  undefined4 local_c;
  
  FUN_600ef8c8(param_1 + 8);
  local_c = FUN_6009506c(*(undefined2 *)(param_1 + 6));
  if (local_c == 0) {
    local_c = FUN_60094ffc(*(undefined1 *)(param_1 + 0xe),param_1 + 8,
                           *(undefined1 *)(param_1 + 0x10));
  }
  return local_c;
}


