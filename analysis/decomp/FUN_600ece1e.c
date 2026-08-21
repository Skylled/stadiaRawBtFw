// 600ece1e  FUN_600ece1e  size=30 bytes
// --- callers ---
//   600861c0 pem_lib__600861c0
// --- callees ---


undefined4 FUN_600ece1e(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = 0;
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    return 0xffffffff;
  }
  if (*param_1 == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


