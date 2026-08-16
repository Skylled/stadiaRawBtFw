// 6005e904  FUN_6005e904  size=274 bytes
// --- callers ---
//   6005ea2c FUN_6005ea2c
// --- callees ---
//   600cc8f8 FUN_600cc8f8
//   600cc450 FUN_600cc450
//   600cbb14 FUN_600cbb14
//   600d46fe FUN_600d46fe
//   60101a54 FUN_60101a54
//   6010138c FUN_6010138c
//   600510b0 FUN_600510b0
//   600cc984 FUN_600cc984
//   60101a80 FUN_60101a80
//   600d45b2 FUN_600d45b2
//   600ce1f8 FUN_600ce1f8
//   600cc3b4 FUN_600cc3b4
//   600ce220 FUN_600ce220


uint FUN_6005e904(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  longlong lVar11;
  longlong lVar12;
  undefined4 **local_4c;
  undefined4 *local_48;
  undefined4 **local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  int local_38;
  uint local_34;
  uint uStack_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 local_24;
  
  pbVar1 = DAT_6005ea18;
  DataMemoryBarrier(0x1b);
  if ((-1 < (int)((uint)*DAT_6005ea18 << 0x1f)) && (iVar6 = FUN_600cc8f8(DAT_6005ea18), iVar6 != 0))
  {
    FUN_600d46fe(DAT_6005ea1c);
    FUN_600cc984(pbVar1);
  }
  FUN_600510b0(&local_3c);
  uVar4 = DAT_6005ea28;
  uVar3 = DAT_6005ea24;
  local_28 = local_38;
  local_2c = local_3c;
  local_24 = DAT_6005ea20;
  local_48 = local_3c;
  local_4c = &local_2c;
  FUN_600ce1f8(&local_4c);
  uVar2 = DAT_6005ea1c;
  local_40 = local_2c + local_28;
  local_44 = &local_2c;
  FUN_600ce1f8(&local_44);
  while( true ) {
    if (local_48 == local_40) {
      return 0;
    }
    puVar10 = (undefined4 *)*local_48;
    uVar7 = FUN_60101a80(uVar2);
    FUN_600cc450(uVar7,uVar3,*puVar10);
    uVar8 = FUN_6010138c(param_1,uVar2);
    local_34 = uVar8 & 0xff;
    if (local_34 != 0) break;
    uStack_30 = local_34;
    lVar11 = FUN_600d45b2(&local_34);
    lVar12 = FUN_600d45b2(puVar10 + 1);
    if (lVar11 == lVar12) {
      uVar5 = (*(code *)puVar10[4])(param_1);
    }
    else {
      uVar5 = 0xd;
    }
    local_34 = CONCAT31(local_34._1_3_,uVar5);
    iVar6 = FUN_600cc3b4(*(undefined4 *)(param_1 + 0x14));
    if (iVar6 == 0) {
      uVar8 = FUN_6010138c(param_1,*(undefined4 *)(param_1 + 0x14));
      if ((uVar8 & 0xff) != 0) {
        return uVar8;
      }
      FUN_60101a54(*(undefined4 *)(param_1 + 0x14));
    }
    if ((local_34 & 0xff) != 0) {
      uVar7 = FUN_60101a80(uVar2);
      uVar9 = FUN_600cbb14(&local_34);
      FUN_600cc450(uVar7,uVar4,uVar9);
      uVar8 = FUN_6010138c(param_1,uVar2);
      if ((uVar8 & 0xff) != 0) {
        return uVar8;
      }
    }
    FUN_600ce220(&local_4c);
  }
  return uVar8;
}


