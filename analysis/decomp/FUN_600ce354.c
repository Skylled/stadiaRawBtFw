// 600ce354  FUN_600ce354  size=236 bytes
// --- callers ---
//   6005183c FUN_6005183c
//   60051a50 FUN_60051a50
// --- callees ---


void FUN_600ce354(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = param_2;
  while (iVar7 < (param_3 + -1) / 2) {
    iVar6 = iVar7 + 1;
    puVar5 = (undefined4 *)(iVar7 * 0x24 + param_1);
    iVar7 = iVar6 * 2;
    iVar6 = iVar6 * 0x48 + param_1;
    if (*(uint *)(iVar6 + 8) < *(uint *)(iVar6 + -0x1c)) {
      iVar7 = iVar7 + -1;
    }
    puVar4 = (undefined4 *)(iVar7 * 0x24 + param_1);
    uVar1 = puVar4[1];
    uVar2 = puVar4[2];
    uVar3 = puVar4[3];
    *puVar5 = *puVar4;
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    uVar1 = puVar4[5];
    uVar2 = puVar4[6];
    uVar3 = puVar4[7];
    puVar5[4] = puVar4[4];
    puVar5[5] = uVar1;
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
    puVar5[8] = puVar4[8];
  }
  if ((-1 < param_3 << 0x1f) && (iVar7 == (param_3 + -2) / 2)) {
    puVar5 = (undefined4 *)(iVar7 * 0x24 + param_1);
    iVar6 = (iVar7 + 1) * 0x48 + param_1;
    uVar1 = *(undefined4 *)(iVar6 + -0x20);
    uVar2 = *(undefined4 *)(iVar6 + -0x1c);
    uVar3 = *(undefined4 *)(iVar6 + -0x18);
    *puVar5 = *(undefined4 *)(iVar6 + -0x24);
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    uVar1 = *(undefined4 *)(iVar6 + -0x10);
    uVar2 = *(undefined4 *)(iVar6 + -0xc);
    uVar3 = *(undefined4 *)(iVar6 + -8);
    puVar5[4] = *(undefined4 *)(iVar6 + -0x14);
    puVar5[5] = uVar1;
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
    puVar5[8] = *(undefined4 *)(iVar6 + -4);
    iVar7 = (iVar7 + 1) * 2 + -1;
  }
  while( true ) {
    iVar6 = (iVar7 + -1) / 2;
    puVar5 = (undefined4 *)(iVar7 * 0x24 + param_1);
    if ((iVar7 <= param_2) ||
       (puVar4 = (undefined4 *)(iVar6 * 0x24 + param_1), param_6 <= (uint)puVar4[2])) break;
    uVar1 = puVar4[1];
    uVar2 = puVar4[2];
    uVar3 = puVar4[3];
    *puVar5 = *puVar4;
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    uVar1 = puVar4[5];
    uVar2 = puVar4[6];
    uVar3 = puVar4[7];
    puVar5[4] = puVar4[4];
    puVar5[5] = uVar1;
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
    puVar5[8] = puVar4[8];
    iVar7 = iVar6;
  }
  *puVar5 = param_4;
  puVar5[1] = param_5;
  puVar5[2] = param_6;
  puVar5[3] = param_7;
  puVar5[4] = param_8;
  puVar5[5] = param_9;
  puVar5[6] = param_10;
  puVar5[7] = param_11;
  puVar5[8] = param_12;
  return;
}


