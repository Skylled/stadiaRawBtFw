// 60080ba4  FUN_60080ba4  size=36 bytes
// --- callers ---
//   60080bcc gatt_manager_task__60080bcc
// --- callees ---
//   60081c6c FUN_60081c6c


uint FUN_60080ba4(int param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x2135) == '\0') {
    uVar1 = FUN_60081c6c(DAT_60080bc8);
    if ((uVar1 & 0xff) == 0) {
      *(undefined1 *)(param_1 + 0x2135) = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


