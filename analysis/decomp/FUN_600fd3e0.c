// 600fd3e0  FUN_600fd3e0  size=98 bytes
// --- callers ---
// --- callees ---
//   6009cec8 FUN_6009cec8
//   6009ce30 FUN_6009ce30


void FUN_600fd3e0(int param_1)

{
  undefined1 local_9;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    local_9 = FUN_6009cec8(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  }
  else {
    local_9 = FUN_6009ce30(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  }
  if (local_9 == '\0') {
    local_9 = '\0';
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    (**(code **)(param_1 + 0x10))(local_9);
  }
  return;
}


