// 6009fa34  FUN_6009fa34  size=160 bytes
// --- callers ---
//   6009f124 FUN_6009f124
//   600a0600 FUN_600a0600
//   600973f8 FUN_600973f8
// --- callees ---
//   6006dbac FUN_6006dbac
//   6009f3c0 FUN_6009f3c0


void FUN_6009fa34(byte param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  byte bVar3;
  
  puVar1 = DAT_6009fad4;
  if ((param_1 & 7) == 0) {
    bVar3 = param_1 >> 3;
  }
  else {
    bVar3 = (param_1 >> 3) + 1;
  }
  if (param_1 != 0) {
    uVar2 = FUN_6006dbac((uint)param_1 * 6,DAT_6009fad8,0x3da);
    *puVar1 = uVar2;
    uVar2 = FUN_6006dbac(param_1,DAT_6009fad8,0x3db);
    puVar1[1] = uVar2;
    if (*(int *)(DAT_6009fadc + 0xa70) == 0) {
      uVar2 = FUN_6006dbac(bVar3,DAT_6009fad8,0x3df);
      *(undefined4 *)(DAT_6009fadc + 0xa70) = uVar2;
    }
  }
  *(byte *)(DAT_6009fadc + 0xa6b) = param_1;
  FUN_6009f3c0();
  return;
}


