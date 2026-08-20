// 600e957c  FUN_600e957c  size=224 bytes
// --- callers ---
//   600e966c FUN_600e966c
//   6008ba20 bcm__6008ba20
// --- callees ---
//   600e8b7a FUN_600e8b7a
//   600e7718 FUN_600e7718
//   6008b43c bcm__6008b43c
//   600e90aa FUN_600e90aa
//   600e77c0 FUN_600e77c0
//   600e72fc FUN_600e72fc
//   600e91e6 FUN_600e91e6
//   6008b570 bcm__6008b570
//   600e7b96 FUN_600e7b96


undefined4 FUN_600e957c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined1 auStack_a0 [128];
  
  uVar5 = param_2[1];
  puVar4 = auStack_a0;
  if ((int)uVar5 < 1) {
    param_1[1] = 0;
    param_1[3] = 0;
    return 1;
  }
  FUN_600e7718(param_3);
  puVar1 = param_1;
  if (param_2 == param_1) {
    puVar1 = (undefined4 *)bcm__6008b570(param_3);
  }
  puVar2 = (undefined4 *)bcm__6008b570(param_3);
  if ((puVar1 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
    iVar6 = uVar5 << 1;
    iVar3 = bcm__6008b43c(puVar1,iVar6);
    if (iVar3 != 0) {
      if (uVar5 == 4) {
        FUN_600e90aa(*puVar1,*param_2);
      }
      else if (uVar5 == 8) {
        FUN_600e8b7a(*puVar1,*param_2);
      }
      else {
        if (0xf < (int)uVar5) {
          if ((uVar5 - 1 & uVar5) == 0) {
            iVar3 = bcm__6008b43c(puVar2,uVar5 << 2);
            if (iVar3 != 0) {
              FUN_600e91e6(*puVar1,*param_2,uVar5,*puVar2);
              goto LAB_600e95e8;
            }
          }
          else {
            iVar3 = bcm__6008b43c(puVar2,iVar6);
            if (iVar3 != 0) {
              puVar4 = (undefined1 *)*puVar2;
              goto LAB_600e9618;
            }
          }
          goto LAB_600e95ba;
        }
LAB_600e9618:
        FUN_600e7b96(*puVar1,*param_2,uVar5,puVar4);
      }
LAB_600e95e8:
      puVar1[1] = iVar6;
      puVar1[3] = 0;
      if (puVar1 == param_1) {
        bVar7 = true;
      }
      else {
        iVar3 = FUN_600e72fc(param_1,puVar1);
        bVar7 = iVar3 != 0;
      }
      goto LAB_600e95bc;
    }
  }
LAB_600e95ba:
  bVar7 = false;
LAB_600e95bc:
  FUN_600e77c0(param_3,bVar7);
  return extraout_r1;
}


