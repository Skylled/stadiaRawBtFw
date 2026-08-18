// 600971a0  FUN_600971a0  size=92 bytes
// --- callers ---
// --- callees ---
//   6006edb4 FUN_6006edb4


void FUN_600971a0(int param_1)

{
  undefined1 local_c [4];
  
  if (**(char **)(param_1 + 4) == '\0') {
    local_c[0] = *(undefined1 *)(DAT_600971fc + 0x98);
    FUN_6006edb4(0,6,local_c);
    if (*(int *)(DAT_600971fc + 0x9c) != 0) {
      (**(code **)(DAT_600971fc + 0x9c))(0);
    }
  }
  else if (*(int *)(DAT_600971fc + 0x9c) != 0) {
    (**(code **)(DAT_600971fc + 0x9c))(1);
  }
  return;
}


