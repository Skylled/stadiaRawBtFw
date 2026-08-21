// 600ecc40  FUN_600ecc40  size=88 bytes
// --- callers ---
//   6008fa18 tasn_dec__6008fa18
// --- callees ---
//   600e092c FUN_600e092c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ecb94 FUN_600ecb94
//   6013d208 thunk_EXT_FUN_0000ac5e


undefined4 FUN_600ecc40(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)FUN_600ecb94(param_1,param_4 + 0x10);
  if (piVar1 != (int *)0x0) {
    if (-1 < (int)((uint)*(byte *)(piVar1 + 3) << 0x1f)) {
      thunk_EXT_FUN_0000ac5e(*piVar1);
    }
    uVar3 = (*(byte *)(piVar1 + 3) & 3) >> 1;
    *(byte *)(piVar1 + 3) = *(byte *)(piVar1 + 3) & 0xfc | (byte)uVar3;
    if ((int)(uVar3 << 0x1f) < 0) {
      *piVar1 = param_2;
    }
    else {
      iVar2 = FUN_600e092c(param_3);
      *piVar1 = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
      if (param_3 != 0) {
        thunk_EXT_FUN_0000b572(iVar2,param_2,param_3);
      }
    }
    piVar1[1] = param_3;
    piVar1[2] = 0;
  }
  return 1;
}


