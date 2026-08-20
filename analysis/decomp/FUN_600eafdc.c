// 600eafdc  FUN_600eafdc  size=362 bytes
// --- callers ---
// --- callees ---
//   600e7450 FUN_600e7450
//   600eaf8e FUN_600eaf8e
//   600eab8c FUN_600eab8c
//   600eafb4 FUN_600eafb4
//   600ea8d8 FUN_600ea8d8
//   6013cee8 thunk_EXT_FUN_0000af90
//   600eaba4 FUN_600eaba4
//   600e9ba8 FUN_600e9ba8
//   600e1e54 FUN_600e1e54


void FUN_600eafdc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_1a74 [68];
  undefined1 auStack_1a30 [68];
  undefined1 auStack_19ec [68];
  undefined1 auStack_19a8 [68];
  undefined1 auStack_1964 [136];
  undefined1 auStack_18dc [6328];
  
  FUN_600eaf8e(auStack_19a8);
  uVar6 = 2;
  FUN_600eafb4(auStack_18dc,param_3);
  do {
    if ((int)(uVar6 << 0x1f) < 0) {
      FUN_600eaba4(param_1,auStack_19a8 + uVar6 * 0xcc,auStack_18dc,auStack_1a74 + uVar6 * 0xcc);
    }
    else {
      FUN_600ea8d8(param_1,auStack_19a8 + uVar6 * 0xcc,auStack_19a8 + (uVar6 >> 1) * 0xcc);
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 != 0x20);
  uVar2 = FUN_600e7450(param_1 + 8);
  bVar1 = true;
  uVar6 = uVar2;
  while (uVar7 = uVar6, uVar6 = uVar7 - 1, uVar6 < uVar2) {
    if (!bVar1) {
      FUN_600ea8d8(param_1,param_2,param_2);
    }
    if (uVar6 % 5 == 0) {
      puVar8 = auStack_1964;
      uVar9 = FUN_600e9ba8(param_4,*(undefined4 *)(param_1 + 0xc),uVar7 + 3);
      uVar10 = FUN_600e9ba8(param_4,(int)((ulonglong)uVar9 >> 0x20),uVar7 + 2);
      uVar11 = FUN_600e9ba8(param_4,(int)((ulonglong)uVar10 >> 0x20),uVar7 + 1);
      uVar12 = FUN_600e9ba8(param_4,(int)((ulonglong)uVar11 >> 0x20),uVar7);
      uVar3 = FUN_600e9ba8(param_4,(int)((ulonglong)uVar12 >> 0x20),uVar6);
      thunk_EXT_FUN_0000af90(auStack_1a74,0,0xcc);
      uVar7 = 0;
      do {
        uVar4 = (uVar3 | (int)(char)((byte)((int)uVar11 << 2) | (byte)((int)uVar10 << 3)) |
                 (int)uVar12 << 1 | (int)uVar9 << 4) & 0xff ^ uVar7;
        uVar7 = uVar7 + 1;
        uVar5 = FUN_600e1e54(uVar4);
        FUN_600eab8c(param_1,auStack_1a74,uVar5,puVar8 + -0x44,auStack_1a74);
        FUN_600eab8c(param_1,auStack_1a30,uVar5,puVar8,auStack_1a30);
        FUN_600eab8c(param_1,auStack_19ec,uVar5,puVar8 + 0x44,auStack_19ec);
        puVar8 = puVar8 + 0xcc;
      } while (uVar7 != 0x20);
      if (bVar1) {
        FUN_600eafb4(param_2,auStack_1a74);
      }
      else {
        FUN_600eaba4(param_1,param_2,param_2,auStack_1a74);
      }
      bVar1 = false;
    }
  }
  if (bVar1) {
    FUN_600eaf8e(param_2);
  }
  return;
}


