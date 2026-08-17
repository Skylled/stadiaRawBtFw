// 60099f4c  FUN_60099f4c  size=136 bytes
// --- callers ---
//   600bc5c4 FUN_600bc5c4
//   60099c0c FUN_60099c0c
// --- callees ---


ushort FUN_60099f4c(ushort param_1)

{
  undefined2 local_a;
  
  local_a = (ushort)DAT_60099fd8 & *(ushort *)(DAT_60099fd4 + 0xaf0);
  if (param_1 != 0xffff) {
    local_a = param_1 & local_a;
  }
  if (*(byte *)(DAT_60099fd4 + 0x806) < 3) {
    local_a = local_a & 0xccf9;
  }
  else {
    local_a = local_a | *(ushort *)(DAT_60099fd4 + 0xaf0) & 0x3306;
    if (param_1 != 0xffff) {
      local_a = local_a | param_1 & 0x3306;
    }
  }
  return local_a;
}


