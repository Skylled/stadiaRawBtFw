// 600db394  FUN_600db394  size=14 bytes
// --- callers ---
//   60078e00 FUN_60078e00
//   60078340 firmware_image_upload__60078340
//   60078da8 FUN_60078da8
// --- callees ---


void FUN_600db394(int *param_1)

{
  *(bool *)(*param_1 + 0x18) = param_1[3] != 0;
  return;
}


