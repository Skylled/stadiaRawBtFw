// 600eadee  FUN_600eadee  size=232 bytes
// --- callers ---
// --- callees ---
//   600eadd0 FUN_600eadd0


bool FUN_600eadee(int *param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  code *pcVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puStack_140;
  undefined1 auStack_138 [68];
  undefined1 auStack_f4 [68];
  undefined1 auStack_b0 [68];
  undefined1 auStack_6c [72];
  
  puVar9 = param_2 + 0x88;
  puVar8 = param_3 + 0x88;
  iVar1 = FUN_600eadd0(param_1,puVar9,param_1 + 0x45);
  iVar2 = FUN_600eadd0(param_1,puVar8,param_1 + 0x45);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    pcVar6 = *(code **)(*param_1 + 0x24);
    pcVar5 = *(code **)(*param_1 + 0x28);
    puVar7 = param_2;
    if (iVar2 == 0) {
      puVar7 = auStack_138;
      (*pcVar5)(param_1,auStack_6c,puVar8);
      (*pcVar6)(param_1,auStack_138,param_2,auStack_6c);
    }
    puStack_140 = param_3;
    if (iVar1 == 0) {
      (*pcVar5)(param_1,auStack_b0,puVar9);
      (*pcVar6)(param_1,auStack_f4,param_3,auStack_b0);
      puStack_140 = auStack_f4;
    }
    iVar3 = FUN_600eadd0(param_1,puVar7,puStack_140);
    if (iVar3 != 0) {
      puVar4 = param_2 + 0x44;
      if (iVar2 == 0) {
        (*pcVar6)(param_1,auStack_6c,auStack_6c,puVar8);
        (*pcVar6)(param_1,auStack_138,param_2 + 0x44,auStack_6c);
        puVar4 = puVar7;
      }
      puVar8 = param_3 + 0x44;
      if (iVar1 == 0) {
        (*pcVar6)(param_1,auStack_b0,auStack_b0,puVar9);
        (*pcVar6)(param_1,auStack_f4,param_3 + 0x44,auStack_b0);
        puVar8 = puStack_140;
      }
      goto LAB_600eae42;
    }
  }
  else {
    iVar1 = FUN_600eadd0(param_1,param_2,param_3);
    if (iVar1 != 0) {
      puVar4 = param_2 + 0x44;
      puVar8 = param_3 + 0x44;
LAB_600eae42:
      iVar1 = FUN_600eadd0(param_1,puVar4,puVar8);
      return iVar1 == 0;
    }
  }
  return true;
}


