// 600e6bea  FUN_600e6bea  size=158 bytes
// --- callers ---
//   6008af3c FUN_6008af3c
//   600e6c88 FUN_600e6c88
// --- callees ---
//   600e6bc4 FUN_600e6bc4


void FUN_600e6bea(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  uint *extraout_r2_02;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  
  puVar6 = param_2;
  puVar8 = param_1;
  do {
    puVar7 = puVar6 + 2;
    uVar4 = puVar6[1];
    *puVar8 = *puVar6;
    puVar8[1] = uVar4;
    puVar8 = puVar8 + 2;
    puVar6 = puVar7;
  } while (puVar7 != param_2 + 4);
  uVar1 = FUN_600e6bc4(*param_1);
  uVar2 = FUN_600e6bc4(*(undefined4 *)(extraout_r2 + 4));
  uVar4 = FUN_600e6bc4(*(undefined4 *)(extraout_r2_00 + 8));
  uVar9 = FUN_600e6bc4(*(undefined4 *)(extraout_r2_01 + 0xc),uVar4);
  uVar5 = (uint)((ulonglong)uVar9 >> 0x20);
  uVar3 = (uint)uVar9;
  *extraout_r2_02 = uVar1 & 0xff | uVar3 << 0x18 | (uVar2 & 0xff) << 8 | (uVar5 & 0xff) << 0x10;
  extraout_r2_02[1] =
       (uVar1 & 0xffff) >> 8 | (uVar3 >> 8) << 0x18 | uVar2 & 0xff00 | (uVar5 & 0xff00) << 8;
  extraout_r2_02[2] =
       (uVar1 & 0xffffff) >> 0x10 | (uVar3 >> 0x10) << 0x18 | uVar5 & 0xff0000 | uVar2 >> 8 & 0xff00
  ;
  extraout_r2_02[3] =
       uVar3 & 0xff000000 | uVar1 >> 0x18 | (uVar2 >> 0x18) << 8 | (uVar5 >> 0x18) << 0x10;
  return;
}


