// 600c24d0  FUN_600c24d0  size=216 bytes
// --- callers ---
//   600fcbfa FUN_600fcbfa
// --- callees ---


undefined1 FUN_600c24d0(int param_1)

{
  undefined1 local_11;
  
  local_11 = 9;
  if ((*(char *)(param_1 + 399) == '\x01') || (*(char *)(param_1 + 400) == '\x01')) {
    local_11 = 8;
  }
  else if (((*(byte *)(param_1 + 0x191) & 4) == 0) && ((*(byte *)(param_1 + 0x192) & 4) == 0)) {
    local_11 = 4;
  }
  else if ((*(byte *)(param_1 + 0x18d) < 5) && (*(byte *)(param_1 + 0x18e) < 5)) {
    if (*(char *)(param_1 + 0x26) == '\0') {
      local_11 = *(undefined1 *)
                  ((uint)*(byte *)(param_1 + 0x26) * 0x19 + (uint)*(byte *)(param_1 + 0x18d) * 5 +
                   DAT_600c25a8 + (uint)*(byte *)(param_1 + 0x18e));
    }
    else {
      local_11 = *(undefined1 *)
                  ((uint)*(byte *)(param_1 + 0x26) * 0x19 + (uint)*(byte *)(param_1 + 0x18e) * 5 +
                   DAT_600c25a8 + (uint)*(byte *)(param_1 + 0x18d));
    }
  }
  return local_11;
}


