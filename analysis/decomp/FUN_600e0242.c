// 600e0242  FUN_600e0242  size=50 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   60067d14 gotham__60067d14
//   600d3b02 FUN_600d3b02
// --- callees ---
//   600867c8 FUN_600867c8
//   6013d208 thunk_EXT_FUN_0000ac5e


undefined4 FUN_600e0242(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  
  while( true ) {
    if (param_1 == (int *)0x0) {
      return 1;
    }
    iVar1 = FUN_600867c8(param_1 + 6);
    if (iVar1 == 0) break;
    piVar3 = (int *)param_1[8];
    param_1[8] = 0;
    if ((*param_1 != 0) && (pcVar2 = *(code **)(*param_1 + 0x20), pcVar2 != (code *)0x0)) {
      (*pcVar2)(param_1);
    }
    thunk_EXT_FUN_0000ac5e(param_1);
    param_1 = piVar3;
  }
  return 0;
}


