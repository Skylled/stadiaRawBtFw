// 600a4270  FUN_600a4270  size=90 bytes
// --- callers ---
//   600bc00c FUN_600bc00c
// --- callees ---


char FUN_600a4270(short param_1)

{
  undefined4 local_14;
  undefined1 local_d;
  undefined4 local_c;
  
  local_c = DAT_600a42cc;
  local_d = '\0';
  for (local_14 = 0; local_14 < 0xe; local_14 = local_14 + 1) {
    if (((*(ushort *)(local_c + 0xe) & 0x80) != 0) && (param_1 == *(short *)(local_c + 0xc))) {
      *(undefined2 *)(local_c + 0xe) = 0;
      local_d = local_d + '\x01';
    }
    local_c = local_c + 0x14;
  }
  return local_d;
}


