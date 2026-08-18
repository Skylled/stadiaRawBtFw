// 600ceff2  FUN_600ceff2  size=216 bytes
// --- callers ---
//   600534c0 FUN_600534c0
// --- callees ---


void FUN_600ceff2(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = *(uint *)(param_1 + 0x10);
  uVar2 = 1;
  uVar7 = 0;
  uVar3 = 0;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  uVar1 = 1;
  uVar4 = 0xffffffff;
  do {
    do {
      if (uVar1 != 1) {
        uVar6 = uVar1 * 3 + 2 / uVar2;
      }
      else {
        uVar6 = 2 / uVar2 + 6;
      }
      if (uVar1 != 1) {
        uVar6 = uVar6 + 2;
      }
      uVar6 = (uint)(((ulonglong)param_2 / (ulonglong)uVar2) / (ulonglong)uVar6);
      if (param_3 <= uVar6) {
        uVar6 = uVar6 - param_3;
        if (uVar4 <= uVar6) goto LAB_600cf046;
        uVar7 = uVar1;
        uVar3 = uVar2;
        if (uVar6 != 0) goto LAB_600cf042;
        break;
      }
      uVar6 = param_3 - uVar6;
      if (uVar6 < uVar4) {
LAB_600cf042:
        uVar3 = uVar2;
        uVar4 = uVar6;
        uVar7 = uVar1;
      }
LAB_600cf046:
      uVar6 = uVar4;
      uVar1 = uVar1 + 1;
      uVar4 = uVar6;
    } while (uVar1 != 0x20);
    uVar2 = uVar2 * 2;
    if ((0x80 < uVar2) || (uVar6 == 0)) break;
    uVar1 = 1;
    uVar4 = uVar6;
  } while( true );
  if (uVar7 < 2) {
    uVar7 = uVar7 << 8 | 0x1020003;
  }
  else {
    uVar7 = (uVar7 & 0x1f) << 1 | uVar7 << 8 | uVar7 << 0x10 | (uVar7 >> 1) << 0x18;
  }
  *(uint *)(param_1 + 0x48) = uVar7;
  uVar7 = 0;
  do {
    uVar4 = uVar7;
    if (1 << (uVar7 & 0xff) == uVar3) break;
    uVar7 = uVar7 + 1;
    uVar4 = uVar3;
  } while (uVar7 != 8);
  *(uint *)(param_1 + 0x24) = uVar4 & 7 | *(uint *)(param_1 + 0x24) & 0xfffffff8;
  if ((uVar5 & 1) != 0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 1;
  }
  return;
}


