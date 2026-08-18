// 600ced30  FUN_600ced30  size=146 bytes
// --- callers ---
//   60052ef0 FUN_60052ef0
//   60052e80 FUN_60052e80
//   600530b0 FUN_600530b0
//   60053078 FUN_60053078
//   60052eb8 FUN_60052eb8
//   60052fd0 FUN_60052fd0
//   60052e10 FUN_60052e10
//   60052e48 FUN_60052e48
//   60053040 FUN_60053040
//   60052dd8 FUN_60052dd8
//   60052f60 FUN_60052f60
//   60052f28 FUN_60052f28
//   60052f98 FUN_60052f98
//   600530e8 FUN_600530e8
//   60053120 FUN_60053120
//   60053008 FUN_60053008
// --- callees ---


void FUN_600ced30(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar4 = param_1[2];
  bVar1 = *(byte *)(param_1 + 4);
  *(byte *)(iVar4 + 0x1f) = bVar1;
  *(byte *)(iVar4 + 0x1c) = bVar1;
  UNRECOVERED_JUMPTABLE = (code *)*param_1;
  if ((param_1[3] == 0) && (UNRECOVERED_JUMPTABLE != (code *)0x0)) {
    uVar5 = 1;
    uVar2 = param_1[1];
  }
  else {
    iVar4 = iVar4 + (uint)bVar1 * 0x20;
    uVar3 = (uint)(*(int *)(iVar4 + 0x1018) - param_1[3]) >> 5;
    if ((*(ushort *)(iVar4 + 0x101c) & 0x80) == 0) {
      uVar5 = 0;
      if (uVar3 == 0) {
        uVar3 = *(byte *)(param_1 + 5) - 1;
      }
      else {
        uVar3 = uVar3 - 1;
      }
    }
    else {
      uVar5 = 1;
    }
    if ((uVar3 & 0xff) == (int)*(char *)((int)param_1 + 0x11)) {
      if (*(char *)(param_1 + 5) == *(char *)((int)param_1 + 0x13)) {
        iVar4 = (int)*(char *)((int)param_1 + 0x13);
      }
      else {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = (uVar3 & 0xff) - (int)*(char *)((int)param_1 + 0x11);
      if (iVar4 < 0) {
        iVar4 = *(char *)(param_1 + 5) + iVar4;
      }
    }
    *(char *)((int)param_1 + 0x11) = (char)uVar3;
    *(char *)((int)param_1 + 0x13) = *(char *)((int)param_1 + 0x13) - (char)iVar4;
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return;
    }
    uVar2 = param_1[1];
  }
                    /* WARNING: Could not recover jumptable at 0x600ced4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar2,uVar5);
  return;
}


