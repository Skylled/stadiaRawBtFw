// 600db36c  FUN_600db36c  size=40 bytes
// --- callers ---
//   60078e00 FUN_60078e00
//   60078340 firmware_image_upload__60078340
//   60078da8 FUN_60078da8
// --- callees ---


void FUN_600db36c(int *param_1,int param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_2 + 0x19;
  param_1[2] = 0x100;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined4 *)(param_2 + 8) = 2;
  *(undefined1 *)(param_2 + 0x19) = 0;
  *(undefined1 *)(param_2 + 0x10) = 1;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined1 *)(param_2 + 0x18) = 0;
  return;
}


