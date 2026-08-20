// 600e6cf2  FUN_600e6cf2  size=210 bytes
// --- callers ---
//   600e7124 FUN_600e7124
//   600e70ba FUN_600e70ba
//   600e6e26 FUN_600e6e26
//   6008deac FUN_6008deac
//   600e6dfe FUN_600e6dfe
// --- callees ---
//   600e6ccc FUN_600e6ccc
//   600e6ac2 FUN_600e6ac2


void FUN_600e6cf2(undefined4 *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *extraout_r2;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uStack_44;
  uint local_40 [9];
  
  local_40[0] = *param_3;
  local_40[1] = param_3[1];
  local_40[2] = param_3[2];
  local_40[3] = param_3[3];
  local_40[4] = param_3[4];
  local_40[5] = param_3[5];
  local_40[6] = param_3[6];
  local_40[7] = param_3[7];
  FUN_600e6ac2(local_40);
  puVar5 = param_1 + param_2 * 4;
  puVar8 = &uStack_44;
  while (puVar5 != param_1) {
    uVar6 = puVar8[1];
    uVar9 = puVar8[7];
    uVar1 = puVar8[3];
    uVar7 = puVar8[5];
    uVar2 = FUN_600e6ccc((uVar7 & 0xff) << 0x10 | uVar6 & 0xff | uVar9 << 0x18 | (uVar1 & 0xff) << 8
                        );
    uVar3 = FUN_600e6ccc((uVar6 & 0xffff) >> 8 | (uVar9 >> 8) << 0x18 | uVar1 & 0xff00 |
                         (uVar7 & 0xff00) << 8);
    uVar4 = FUN_600e6ccc((uVar6 & 0xffffff) >> 0x10 | (uVar9 >> 0x10) << 0x18 | uVar7 & 0xff0000 |
                         uVar1 >> 8 & 0xff00);
    uVar10 = FUN_600e6ccc(uVar9 & 0xff000000 | uVar6 >> 0x18 | (uVar1 >> 0x18) << 8 |
                          (uVar7 >> 0x18) << 0x10);
    *extraout_r2 = uVar2;
    extraout_r2[1] = uVar3;
    param_1 = extraout_r2 + 4;
    extraout_r2[2] = uVar4;
    extraout_r2[3] = (int)uVar10;
    puVar8 = puVar8 + 1;
    puVar5 = (undefined4 *)((ulonglong)uVar10 >> 0x20);
  }
  return;
}


