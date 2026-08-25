// 600fcbfa  FUN_600fcbfa  size=142 bytes
// --- callers ---
//   600fb8c4 FUN_600fb8c4
//   600faec4 FUN_600faec4
// --- callees ---
//   600c23f4 FUN_600c23f4
//   600c24d0 FUN_600c24d0


undefined1 FUN_600fcbfa(int param_1)

{
  undefined1 local_9;
  
  *(undefined1 *)(param_1 + 0x195) = 0;
  *(undefined1 *)(param_1 + 0x196) = 0;
  if (((*(byte *)(param_1 + 0x191) & 8) != 0) && ((*(byte *)(param_1 + 0x192) & 8) != 0)) {
    *(undefined1 *)(param_1 + 0x195) = 1;
  }
  if (*(char *)(param_1 + 0x195) == '\0') {
    local_9 = FUN_600c23f4(param_1);
  }
  else {
    if (((*(byte *)(param_1 + 0x191) & 0x10) != 0) && ((*(byte *)(param_1 + 0x192) & 0x10) != 0)) {
      *(undefined1 *)(param_1 + 0x196) = 1;
    }
    local_9 = FUN_600c24d0(param_1);
  }
  return local_9;
}


