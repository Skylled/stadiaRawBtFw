// 600faac2  FUN_600faac2  size=74 bytes
// --- callers ---
// --- callees ---
//   600c1b74 FUN_600c1b74


void FUN_600faac2(int param_1,undefined1 *param_2)

{
  *(undefined1 *)(param_1 + 0x25) = *param_2;
  *(undefined1 *)(param_1 + 0x24) = *param_2;
  if ((*(byte *)(param_1 + 0x25) < 0xf) && (*(char *)(param_1 + 0x25) != '\0')) {
    FUN_600c1b74(5,param_1);
    *(undefined1 *)(param_1 + 0x200) = 1;
  }
  return;
}


