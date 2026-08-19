// 600db3a2  FUN_600db3a2  size=20 bytes
// --- callers ---
//   60078e00 FUN_60078e00
//   60078340 firmware_image_upload__60078340
//   60078da8 FUN_60078da8
// --- callees ---
//   600d37ac FUN_600d37ac


int * FUN_600db3a2(int *param_1)

{
  *(undefined1 *)(*param_1 + 0x18) = 1;
  FUN_600d37ac(param_1 + 1);
  return param_1;
}


