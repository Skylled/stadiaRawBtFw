// 600f6158  FUN_600f6158  size=174 bytes
// --- callers ---
//   600f633e FUN_600f633e
//   600af0b4 FUN_600af0b4
//   600adeb4 FUN_600adeb4
//   600ad4f4 FUN_600ad4f4
//   600aeb14 FUN_600aeb14
// --- callees ---


undefined4 FUN_600f6158(int param_1,char param_2,undefined2 param_3)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((*(char *)(param_1 + 0x56) == '\0') || (param_2 == '\x1e')) {
    if ((param_2 == 'R') || (((param_2 == -0x2e || (param_2 == '\x02')) || (param_2 == '\x1e')))) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      local_c = *(undefined4 *)(param_1 + 0x14);
    }
    else {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x14);
      *(char *)(param_1 + 0x56) = param_2;
      *(undefined2 *)(param_1 + 0x54) = param_3;
      *(undefined1 *)(param_1 + 0x57) = 10;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) % 0xfffffff;
      local_c = *(undefined4 *)(param_1 + 0x2c);
    }
  }
  return local_c;
}


