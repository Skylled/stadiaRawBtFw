// 600e8b7a  FUN_600e8b7a  size=1328 bytes
// --- callers ---
//   600e91e6 FUN_600e91e6
//   600e957c FUN_600e957c
//   600e9680 FUN_600e9680
// --- callees ---


void FUN_600e8b7a(undefined4 *param_1,uint *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
  *param_1 = (int)uVar1;
  lVar2 = (ulonglong)param_2[1] * (ulonglong)*param_2;
  lVar3 = lVar2 + (uVar1 >> 0x20);
  param_1[1] = (int)(lVar3 + lVar2);
  uVar5 = (uint)CARRY4((uint)((ulonglong)lVar3 >> 0x20),
                       (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4((uint)lVar2,(uint)lVar3));
  uVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1] + ((ulonglong)(lVar3 + lVar2) >> 0x20);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[2] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[2] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[2] = (int)lVar2;
  if (CARRY4(uVar5,uVar4)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[3] * (ulonglong)*param_2 + (ulonglong)(uVar5 + uVar4);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[3] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[3] = (int)lVar2;
  uVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[2] + (ulonglong)(uVar4 + uVar6);
  uVar5 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar4 = uVar7 + uVar5;
  uVar6 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[4] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  lVar2 = (ulonglong)param_2[4] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  param_1[4] = (int)lVar2;
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  if (CARRY4(uVar5,uVar4)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)*param_2 + (ulonglong)(uVar5 + uVar4);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar6 + uVar5;
  uVar7 = (uint)CARRY4(uVar6,uVar5);
  uVar1 = (ulonglong)param_2[5] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[5] = (int)lVar2;
  uVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[3] + (ulonglong)(uVar4 + uVar6);
  uVar5 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar6 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar6 + uVar5;
  if (CARRY4(uVar6,uVar5)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[6] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[6] = (int)lVar2;
  if (CARRY4(uVar4,uVar5)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[7] * (ulonglong)*param_2 + (ulonglong)(uVar4 + uVar5);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[7] * (ulonglong)*param_2 + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[7] = (int)lVar2;
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[4] + (ulonglong)(uVar4 + uVar6);
  uVar5 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar6 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar6 + uVar5;
  if (CARRY4(uVar6,uVar5)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[1] + (uVar1 & 0xffffffff);
  uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[8] = (int)lVar2;
  if (CARRY4(uVar4,uVar5)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[2] + (ulonglong)(uVar4 + uVar5);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar7 + uVar5;
  uVar6 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[2] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  lVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[9] = (int)lVar2;
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[5] + (ulonglong)(uVar4 + uVar7);
  uVar5 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar7 = uVar6 + uVar5;
  uVar6 = (uint)CARRY4(uVar6,uVar5);
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar7 + uVar5;
  if (CARRY4(uVar7,uVar5)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar7;
  if (CARRY4(uVar4,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  uVar7 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7)) {
    uVar6 = uVar6 + 1;
  }
  lVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[3] + (uVar1 & 0xffffffff);
  param_1[10] = (int)lVar2;
  uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
  if (CARRY4(uVar4,uVar5)) {
    uVar6 = uVar6 + 1;
  }
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[4] + (ulonglong)(uVar4 + uVar5);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar6 + uVar5;
  uVar7 = (uint)CARRY4(uVar6,uVar5);
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[4] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar5 + uVar6;
  if (CARRY4(uVar5,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[0xb] = (int)lVar2;
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[6] + (ulonglong)(uVar4 + uVar6);
  uVar5 = (uint)(uVar1 >> 0x20);
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  uVar4 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar5 = uVar4 + uVar6;
  if (CARRY4(uVar4,uVar6)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[5] + (uVar1 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[0xc] = (int)lVar2;
  if (CARRY4(uVar5,uVar4)) {
    uVar7 = uVar7 + 1;
  }
  uVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[6] + (ulonglong)(uVar5 + uVar4);
  uVar5 = (uint)(uVar1 >> 0x20);
  uVar4 = uVar7 + uVar5;
  uVar7 = (uint)CARRY4(uVar7,uVar5);
  lVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[6] + (uVar1 & 0xffffffff);
  uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
  param_1[0xd] = (int)lVar2;
  if (CARRY4(uVar4,uVar5)) {
    uVar7 = uVar7 + 1;
  }
  lVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[7] + (ulonglong)(uVar4 + uVar5);
  param_1[0xe] = (int)lVar2;
  param_1[0xf] = uVar7 + (int)((ulonglong)lVar2 >> 0x20);
  return;
}


