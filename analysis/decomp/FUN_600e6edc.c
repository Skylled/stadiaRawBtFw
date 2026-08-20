// 600e6edc  FUN_600e6edc  size=158 bytes
// --- callers ---
//   600e7548 FUN_600e7548
//   600e7588 FUN_600e7588
// --- callees ---
//   600e1e54 FUN_600e1e54


uint FUN_600e6edc(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  int extraout_r2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint *puVar3;
  
  uVar6 = 0;
  uVar1 = param_4;
  if (param_2 <= param_4) {
    uVar1 = param_2;
  }
  uVar4 = 0;
  for (; uVar6 != uVar1; uVar6 = uVar6 + 1) {
    uVar7 = *(uint *)(param_1 + uVar6 * 4);
    uVar5 = *(uint *)(param_3 + uVar6 * 4);
    uVar8 = uVar7 ^ uVar5;
    uVar9 = FUN_600e1e54(uVar8);
    param_2 = (uint)((ulonglong)uVar9 >> 0x20);
    uVar5 = (int)((uVar7 - uVar5 ^ uVar7 | uVar8) ^ uVar7) >> 0x1f | 1;
    uVar4 = (uVar4 ^ uVar5) & (uint)uVar9 ^ uVar5;
    param_3 = extraout_r2;
  }
  if (param_2 < param_4) {
    uVar1 = 0;
    puVar2 = (uint *)(param_3 + param_2 * 4);
    do {
      puVar3 = puVar2 + 1;
      uVar1 = uVar1 | *puVar2;
      puVar2 = puVar3;
    } while ((uint *)(param_3 + param_4 * 4) != puVar3);
    uVar1 = FUN_600e1e54(uVar1);
    uVar4 = uVar4 | ~uVar1;
  }
  else if (param_4 < param_2) {
    uVar1 = 0;
    puVar2 = (uint *)(param_1 + param_4 * 4);
    do {
      puVar3 = puVar2 + 1;
      uVar1 = uVar1 | *puVar2;
      puVar2 = puVar3;
    } while ((uint *)(param_1 + param_2 * 4) != puVar3);
    uVar1 = FUN_600e1e54(uVar1);
    uVar4 = (uVar4 ^ 1) & uVar1 ^ 1;
  }
  return uVar4;
}


