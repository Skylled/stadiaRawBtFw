// 600f800a  FUN_600f800a  size=130 bytes
// --- callers ---
//   600f80c4 FUN_600f80c4
// --- callees ---
//   6009ac8c FUN_6009ac8c


void FUN_600f800a(int param_1)

{
  undefined2 local_c;
  undefined2 local_a;
  
  local_a = 0;
  if (param_1 != 0) {
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if (((local_c != 1) && (*(int *)(param_1 + (local_c + 0x24) * 4) != 0)) &&
         ((uint)local_a < *(ushort *)(*(int *)(param_1 + (local_c + 0x24) * 4) + 0x122) + 4)) {
        local_a = *(short *)(*(int *)(param_1 + (local_c + 0x24) * 4) + 0x122) + 4;
      }
    }
    if (0xfb < local_a) {
      local_a = 0xfb;
    }
    FUN_6009ac8c(param_1 + 4,local_a);
  }
  return;
}


