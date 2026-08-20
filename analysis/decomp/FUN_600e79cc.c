// 600e79cc  FUN_600e79cc  size=102 bytes
// --- callers ---
//   600e7b96 FUN_600e7b96
// --- callees ---


void FUN_600e79cc(longlong *param_1,uint *param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    while( true ) {
      uVar2 = 0;
      if ((param_3 & 0xfffffffc) == 0) break;
      param_3 = param_3 - 4;
      *param_1 = (ulonglong)*param_2 * (ulonglong)*param_2;
      param_1[1] = (ulonglong)param_2[1] * (ulonglong)param_2[1];
      param_1[2] = (ulonglong)param_2[2] * (ulonglong)param_2[2];
      param_1[3] = (ulonglong)param_2[3] * (ulonglong)param_2[3];
      param_1 = param_1 + 4;
      param_2 = param_2 + 4;
    }
    for (; param_3 != uVar2; uVar2 = uVar2 + 1) {
      lVar1 = (ulonglong)param_2[uVar2] * (ulonglong)param_2[uVar2];
      *(int *)(param_1 + uVar2) = (int)lVar1;
      *(int *)((int)param_1 + uVar2 * 8 + 4) = (int)((ulonglong)lVar1 >> 0x20);
    }
  }
  return;
}


