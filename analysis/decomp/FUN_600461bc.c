// 600461bc  FUN_600461bc  size=136 bytes
// --- callers ---
//   6004ae32 FUN_6004ae32
// --- callees ---
//   6004bda4 FUN_6004bda4
//   6004aee0 FUN_6004aee0
//   6004af1a FUN_6004af1a


void FUN_600461bc(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  float local_210 [64];
  float afStack_110 [64];
  float fStack_10;
  
  pfVar1 = local_210;
  FUN_6004af1a(param_1,*(int *)(param_1 + 0x38) * 0x208 + *(int *)(param_1 + 0x20),local_210);
  do {
    *pfVar1 = *pfVar1 * DAT_60046244;
    pfVar1 = pfVar1 + 1;
  } while (pfVar1 != afStack_110);
  do {
    pfVar2 = pfVar1 + 1;
    *pfVar1 = 0.0;
    pfVar1 = pfVar2;
  } while (pfVar2 != &fStack_10);
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_6004bda4(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x38) * 0x100,local_210,0x100);
  }
  FUN_6004aee0(param_1,local_210,*(int *)(param_1 + 0x38) * 0x208 + *(int *)(param_1 + 0x20));
  if (*(uint *)(param_1 + 0x38) <
      (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 3) * DAT_60046248 - 1U) {
    iVar3 = *(uint *)(param_1 + 0x38) + 1;
  }
  else {
    iVar3 = 0;
  }
  *(int *)(param_1 + 0x38) = iVar3;
  return;
}


