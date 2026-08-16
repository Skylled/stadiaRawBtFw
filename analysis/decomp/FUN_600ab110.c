// 600ab110  FUN_600ab110  size=502 bytes
// --- callers ---
//   600ff09c FUN_600ff09c
//   600aac04 FUN_600aac04
// --- callees ---
//   600af444 FUN_600af444
//   600af4d4 FUN_600af4d4
//   600d9290 FUN_600d9290
//   600afd28 FUN_600afd28
//   600f4e88 FUN_600f4e88
//   600af390 FUN_600af390
//   600af314 FUN_600af314
//   600f67b2 FUN_600f67b2
//   600f686a FUN_600f686a
//   6006ddd8 FUN_6006ddd8


ushort FUN_600ab110(undefined1 param_1,short *param_2,undefined2 param_3,ushort param_4,
                   undefined1 param_5)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_1c;
  ushort local_16;
  int local_14;
  
  piVar2 = DAT_600ab308;
  local_16 = 0;
  bVar1 = false;
  local_1c = 0;
  puVar3 = (undefined4 *)FUN_600afd28(param_1);
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  local_14 = FUN_600af444(puVar3,param_2,param_3);
  if (local_14 == 0) {
    if ((*param_2 == 2) && (param_2[2] == 0x1801)) {
      local_16 = *(ushort *)(DAT_600ab30c + 0x155c);
    }
    else if ((*param_2 == 2) && (param_2[2] == 0x1800)) {
      local_16 = *(ushort *)(DAT_600ab30c + 0x155e);
    }
    else {
      if (*piVar2 != 0) {
        local_16 = *(short *)(*piVar2 + 0x34) + 1;
      }
      if (local_16 < *(ushort *)(DAT_600ab30c + 0x1560)) {
        local_16 = *(ushort *)(DAT_600ab30c + 0x1560);
      }
      bVar1 = true;
    }
    if ((int)(0x10000 - (uint)local_16) < (int)(uint)param_4) {
      return 0;
    }
    local_14 = FUN_600af390();
    if (local_14 == 0) {
      return 0;
    }
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    uVar7 = puVar3[3];
    *(undefined4 *)(local_14 + 8) = *puVar3;
    *(undefined4 *)(local_14 + 0xc) = uVar5;
    *(undefined4 *)(local_14 + 0x10) = uVar6;
    *(undefined4 *)(local_14 + 0x14) = uVar7;
    *(undefined4 *)(local_14 + 0x18) = puVar3[4];
    uVar5 = *(undefined4 *)(param_2 + 2);
    uVar6 = *(undefined4 *)(param_2 + 4);
    uVar7 = *(undefined4 *)(param_2 + 6);
    *(undefined4 *)(local_14 + 0x1c) = *(undefined4 *)param_2;
    *(undefined4 *)(local_14 + 0x20) = uVar5;
    *(undefined4 *)(local_14 + 0x24) = uVar6;
    *(undefined4 *)(local_14 + 0x28) = uVar7;
    *(undefined4 *)(local_14 + 0x2c) = *(undefined4 *)(param_2 + 8);
    *(undefined2 *)(local_14 + 0x30) = param_3;
    *(ushort *)(local_14 + 0x32) = local_16;
    *(ushort *)(local_14 + 0x34) = param_4 + local_16 + -1;
    *(undefined1 *)(local_14 + 0x36) = param_5;
    FUN_600f67b2(piVar2,local_14);
    if (bVar1) {
      if (*(int *)(DAT_600ab30c + 0x1554) != 0) {
        (**(code **)(DAT_600ab30c + 0x1554))(1,local_14 + 8);
      }
      local_1c = FUN_600af314(local_14 + 8);
      if (local_1c == 0) {
        if (local_14 != 0) {
          FUN_600f686a(piVar2,local_14);
          FUN_600af4d4(local_14);
        }
        return 0;
      }
    }
  }
  else {
    local_16 = *(ushort *)(local_14 + 0x32);
  }
  iVar4 = FUN_600f4e88(local_14 + 0x38,param_2,param_5,local_16,param_4);
  if (iVar4 == 0) {
    if (local_14 != 0) {
      FUN_600f686a(piVar2,local_14);
      FUN_600af4d4(local_14);
    }
    if (local_1c != 0) {
      uVar5 = FUN_600d9290(DAT_600ab310,local_1c);
      FUN_6006ddd8(uVar5,DAT_600ab314,0xf6);
    }
    local_16 = 0;
  }
  return local_16;
}


