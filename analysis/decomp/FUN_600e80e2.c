// 600e80e2  FUN_600e80e2  size=1370 bytes
// --- callers ---
//   600e89f8 FUN_600e89f8
//   600e863c FUN_600e863c
//   600e87fa FUN_600e87fa
//   600e9542 FUN_600e9542
// --- callees ---


void FUN_600e80e2(undefined4 *param_1,uint *param_2,uint *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = *param_3;
  uVar4 = *param_2;
  *param_1 = (int)((ulonglong)uVar4 * (ulonglong)uVar3);
  uVar1 = (ulonglong)param_3[1] * (ulonglong)*param_2 +
          ((ulonglong)uVar4 * (ulonglong)uVar3 >> 0x20);
  uVar6 = (uint)(uVar1 >> 0x20);
  lVar2 = (ulonglong)*param_3 * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[1] = (int)lVar2;
  uVar3 = (uint)CARRY4(uVar6,uVar4);
  uVar1 = (ulonglong)*param_3 * (ulonglong)param_2[2] + (ulonglong)(uVar6 + uVar4);
  uVar4 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar4 + uVar3;
  uVar4 = (uint)CARRY4(uVar4,uVar3);
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  lVar2 = (ulonglong)param_3[2] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[2] = (int)lVar2;
  uVar3 = *param_2;
  if (CARRY4(uVar7,uVar6)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)uVar3 + (ulonglong)(uVar7 + uVar6);
  uVar6 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar6)) {
    uVar3 = 1;
  }
  uVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  if (!CARRY4(uVar4,uVar6)) {
    uVar3 = 0;
  }
  uVar5 = uVar4 + uVar6 + uVar7;
  if (CARRY4(uVar4 + uVar6,uVar7)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar3 = uVar3 + 1;
  }
  lVar2 = (ulonglong)*param_3 * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[3] = (int)lVar2;
  if (CARRY4(uVar4,uVar6)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)*param_3 * (ulonglong)param_2[4] + (ulonglong)(uVar4 + uVar6);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  uVar7 = (uint)CARRY4(uVar3,uVar6);
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_3[4] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[4] = (int)lVar2;
  uVar4 = *param_2;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)uVar4 + (ulonglong)(uVar3 + uVar6);
  uVar3 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar7,uVar3)) {
    uVar4 = 1;
  }
  uVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  if (!CARRY4(uVar7,uVar3)) {
    uVar4 = 0;
  }
  uVar5 = uVar7 + uVar3 + uVar6;
  if (CARRY4(uVar7 + uVar3,uVar6)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar7 + uVar3;
  if (CARRY4(uVar7,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  lVar2 = (ulonglong)*param_3 * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[5] = (int)lVar2;
  uVar3 = param_2[6];
  if (CARRY4(uVar6,uVar7)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = (ulonglong)*param_3 * (ulonglong)uVar3 + (ulonglong)(uVar6 + uVar7);
  uVar6 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar6)) {
    uVar3 = 1;
  }
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  if (!CARRY4(uVar4,uVar6)) {
    uVar3 = 0;
  }
  uVar5 = uVar4 + uVar6 + uVar7;
  if (CARRY4(uVar4 + uVar6,uVar7)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar6 + uVar7;
  if (CARRY4(uVar6,uVar7)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar3 = uVar3 + 1;
  }
  lVar2 = (ulonglong)param_3[6] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[6] = (int)lVar2;
  if (CARRY4(uVar6,uVar4)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (ulonglong)param_3[7] * (ulonglong)*param_2 + (ulonglong)(uVar6 + uVar4);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  uVar7 = (uint)CARRY4(uVar3,uVar6);
  uVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)*param_3 * (ulonglong)param_2[7] + (uVar1 & 0xffffffff);
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[7] = (int)lVar2;
  if (CARRY4(uVar4,uVar3)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[1] * (ulonglong)param_2[7] + (ulonglong)(uVar4 + uVar3);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar7 + uVar3;
  uVar7 = (uint)CARRY4(uVar7,uVar3);
  uVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar4 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar6 + uVar4;
  if (CARRY4(uVar6,uVar4)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_3[7] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[8] = (int)lVar2;
  if (CARRY4(uVar3,uVar4)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_3[7] * (ulonglong)param_2[2] + (ulonglong)(uVar3 + uVar4);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar7 + uVar3;
  uVar6 = (uint)CARRY4(uVar7,uVar3);
  uVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar4 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar7;
  if (CARRY4(uVar3,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar7;
  if (CARRY4(uVar3,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  lVar2 = (ulonglong)param_3[2] * (ulonglong)param_2[7] + (uVar1 & 0xffffffff);
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[9] = (int)lVar2;
  if (CARRY4(uVar4,uVar3)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[7] + (ulonglong)(uVar4 + uVar3);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar7 = uVar6 + uVar3;
  uVar6 = (uint)CARRY4(uVar6,uVar3);
  uVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar4 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar7;
  if (CARRY4(uVar3,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  lVar2 = (ulonglong)param_3[7] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[10] = (int)lVar2;
  if (CARRY4(uVar3,uVar4)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[7] * (ulonglong)param_2[4] + (ulonglong)(uVar3 + uVar4);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar7 = uVar6 + uVar3;
  uVar6 = (uint)CARRY4(uVar6,uVar3);
  uVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar4 = (uint)(uVar1 >> 0x20);
  uVar3 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar3 + uVar7;
  if (CARRY4(uVar3,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  lVar2 = (ulonglong)param_3[4] * (ulonglong)param_2[7] + (uVar1 & 0xffffffff);
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[0xb] = (int)lVar2;
  if (CARRY4(uVar4,uVar3)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_3[5] * (ulonglong)param_2[7] + (ulonglong)(uVar4 + uVar3);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar7 = uVar6 + uVar3;
  uVar4 = (uint)CARRY4(uVar6,uVar3);
  uVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar7 + uVar3;
  if (CARRY4(uVar7,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  lVar2 = (ulonglong)param_3[7] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[0xc] = (int)lVar2;
  if (CARRY4(uVar6,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = (ulonglong)param_3[7] * (ulonglong)param_2[6] + (ulonglong)(uVar6 + uVar3);
  uVar3 = (uint)(uVar1 >> 0x20);
  uVar6 = uVar4 + uVar3;
  uVar4 = (uint)CARRY4(uVar4,uVar3);
  lVar2 = (ulonglong)param_3[6] * (ulonglong)param_2[7] + (uVar1 & 0xffffffff);
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[0xd] = (int)lVar2;
  if (CARRY4(uVar6,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  lVar2 = (ulonglong)param_3[7] * (ulonglong)param_2[7] + (ulonglong)(uVar6 + uVar3);
  param_1[0xe] = (int)lVar2;
  param_1[0xf] = uVar4 + (int)((ulonglong)lVar2 >> 0x20);
  return;
}


