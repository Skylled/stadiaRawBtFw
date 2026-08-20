// 600e77d4  FUN_600e77d4  size=206 bytes
// --- callers ---
//   600e7930 FUN_600e7930
//   6008b6a8 bcm__6008b6a8
//   600e7b96 FUN_600e7b96
// --- callees ---


uint FUN_600e77d4(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    while( true ) {
      if ((param_3 & 0xfffffffc) == 0) break;
      param_3 = param_3 - 4;
      uVar1 = (ulonglong)*param_2 * (ulonglong)param_4 +
              (ulonglong)CONCAT14(CARRY4(uVar3,*param_1),uVar3 + *param_1);
      *param_1 = (uint)uVar1;
      uVar1 = (ulonglong)param_2[1] * (ulonglong)param_4 + (ulonglong)param_1[1] + (uVar1 >> 0x20);
      param_1[1] = (uint)uVar1;
      uVar1 = (ulonglong)param_2[2] * (ulonglong)param_4 + (ulonglong)param_1[2] + (uVar1 >> 0x20);
      param_1[2] = (uint)uVar1;
      lVar2 = (ulonglong)param_2[3] * (ulonglong)param_4 + (ulonglong)param_1[3] + (uVar1 >> 0x20);
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      param_1[3] = (uint)lVar2;
      param_2 = param_2 + 4;
      param_1 = param_1 + 4;
    }
    param_2 = param_2 + -1;
    puVar4 = param_1 + param_3;
    for (; param_1 != puVar4; param_1 = param_1 + 1) {
      param_2 = param_2 + 1;
      lVar2 = (ulonglong)*param_2 * (ulonglong)param_4 + (ulonglong)uVar3 + (ulonglong)*param_1;
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      *param_1 = (uint)lVar2;
    }
  }
  return uVar3;
}


