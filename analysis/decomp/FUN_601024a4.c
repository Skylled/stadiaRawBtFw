// 601024a4  FUN_601024a4  size=16 bytes
// --- callers ---
//   6006d5a8 FUN_6006d5a8
//   6005a1b0 device_info__6005a1b0
//   60061964 FUN_60061964
//   600cae68 FUN_600cae68
//   6006c340 remote_device_db__6006c340
//   6006dbac FUN_6006dbac
//   6006dcdc FUN_6006dcdc
// --- callees ---


void FUN_601024a4(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_2;
    *param_1 = cVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}


