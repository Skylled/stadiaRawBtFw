// 600ecc0e  FUN_600ecc0e  size=50 bytes
// --- callers ---
//   60090940 FUN_60090940
// --- callees ---
//   600ecb94 FUN_600ecb94
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600ecc0e(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_600ecb94(param_1,param_2 + 0x10);
  if (piVar1 != (int *)0x0) {
    if ((*piVar1 != 0) && (-1 < (int)((uint)*(byte *)(piVar1 + 3) << 0x1f))) {
      thunk_EXT_FUN_0000ac5e();
    }
    *(byte *)(piVar1 + 3) = *(byte *)(piVar1 + 3) & 0xfc;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 1;
  }
  return;
}


