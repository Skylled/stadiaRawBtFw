// 600ab318  FUN_600ab318  size=252 bytes
// --- callers ---
//   600c6e20 FUN_600c6e20
// --- callees ---
//   600af444 FUN_600af444
//   600d9290 FUN_600d9290
//   600af4d4 FUN_600af4d4
//   600afd28 FUN_600afd28
//   600adbfc FUN_600adbfc
//   600afbd0 FUN_600afbd0
//   600ab564 FUN_600ab564
//   6006ddd8 FUN_6006ddd8
//   600f686a FUN_600f686a
//   600af240 FUN_600af240


undefined4 FUN_600ab318(undefined1 param_1,undefined4 param_2,undefined2 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = DAT_600ab414;
  iVar2 = FUN_600afd28(param_1);
  if (iVar2 == 0) {
    uVar6 = 0;
  }
  else {
    iVar3 = FUN_600af444(iVar2,param_2,param_3);
    if (iVar3 == 0) {
      uVar6 = 0;
    }
    else {
      iVar4 = FUN_600af240(iVar3 + 8,iVar3 + 0x1c,*(undefined2 *)(iVar3 + 0x30));
      if (iVar4 == 0) {
        FUN_600adbfc();
      }
      else {
        uVar5 = FUN_600d9290(DAT_600ab418,iVar4);
        FUN_6006ddd8(uVar5,DAT_600ab41c,0x1a7);
      }
      bVar1 = FUN_600afbd0(iVar2,param_2,param_3);
      if (bVar1 != 10) {
        FUN_600ab564(*(undefined2 *)((uint)bVar1 * 0x28 + DAT_600ab420 + 0xaa4));
      }
      if ((*(ushort *)(DAT_600ab420 + 0x1560) <= *(ushort *)(iVar3 + 0x32)) &&
         (*(int *)(DAT_600ab420 + 0x1554) != 0)) {
        (**(code **)(DAT_600ab420 + 0x1554))(0,iVar3 + 8);
      }
      FUN_600f686a(uVar6,iVar3);
      FUN_600af4d4(iVar3);
      uVar6 = 1;
    }
  }
  return uVar6;
}


