// 6008eb24  bcm__6008eb24  size=560 bytes
// src: bcm.c
// --- callers ---
//   600868fc FUN_600868fc
// --- callees ---
//   6008b50c bcm__6008b50c
//   600e6a22 FUN_600e6a22
//   6008b9f0 bcm__6008b9f0
//   6008b544 FUN_6008b544
//   600e94ca FUN_600e94ca
//   600e721a FUN_600e721a
//   6008b60c bcm__6008b60c
//   600e0552 FUN_600e0552
//   6008b3b8 FUN_6008b3b8
//   600e7554 FUN_600e7554
//   600ebf58 FUN_600ebf58
//   600e99a2 FUN_600e99a2


/* src: bcm.c */

undefined4 bcm__6008eb24(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  undefined1 auStack_a4 [20];
  undefined1 auStack_90 [20];
  undefined1 auStack_7c [20];
  undefined1 auStack_68 [20];
  undefined1 auStack_54 [20];
  undefined1 auStack_40 [20];
  undefined1 auStack_2c [20];
  
  iVar1 = FUN_600ebf58();
  if (iVar1 != 0) {
    return 1;
  }
  if ((*(int *)(param_1 + 0x10) != 0) != (*(int *)(param_1 + 0x14) != 0)) {
    uVar3 = 0x86;
    uVar5 = 0x29d;
LAB_6008eb56:
    FUN_600e0552(4,0,uVar3,DAT_6008ed54,uVar5);
    return 0;
  }
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 8) == 0)) {
    uVar3 = 0x90;
    uVar5 = 0x2a2;
    goto LAB_6008eb56;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    return 1;
  }
  iVar1 = bcm__6008b50c();
  if (iVar1 == 0) {
    uVar3 = 0x41;
    uVar5 = 0x2ae;
    goto LAB_6008eb56;
  }
  FUN_600e721a(auStack_a4);
  FUN_600e721a(auStack_90);
  FUN_600e721a(auStack_7c);
  FUN_600e721a(auStack_68);
  FUN_600e721a(auStack_54);
  FUN_600e721a(auStack_40);
  FUN_600e721a(auStack_2c);
  iVar2 = bcm__6008b9f0(auStack_a4,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                        iVar1);
  if (iVar2 == 0) {
LAB_6008ebd4:
    uVar5 = 3;
    uVar6 = 0x2c4;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0x10);
    uVar3 = FUN_6008b3b8();
    iVar2 = bcm__6008b60c(auStack_90,uVar5,uVar3);
    if (iVar2 == 0) goto LAB_6008ebd4;
    uVar5 = *(undefined4 *)(param_1 + 0x14);
    uVar3 = FUN_6008b3b8();
    iVar2 = bcm__6008b60c(auStack_7c,uVar5,uVar3);
    if (((iVar2 == 0) || (iVar2 = FUN_600e99a2(auStack_68,auStack_90,auStack_7c,iVar1), iVar2 == 0))
       || (iVar2 = FUN_600e94ca(&local_b4,*(undefined4 *)(param_1 + 8),
                                *(undefined4 *)(param_1 + 0xc),auStack_68,0,iVar1), iVar2 == 0))
    goto LAB_6008ebd4;
    uVar3 = *(undefined4 *)(param_1 + 4);
    iVar2 = FUN_600e7554(auStack_a4,uVar3);
    if (iVar2 == 0) {
      if (local_b4 == 0) {
        uVar3 = 0x77;
        uVar5 = 0x2ce;
      }
      else if ((*(int *)(*(int *)(param_1 + 0xc) + 0xc) == 0) &&
              (iVar2 = FUN_600e7554(*(int *)(param_1 + 0xc),uVar3), iVar2 < 0)) {
        iVar2 = *(int *)(param_1 + 0x18);
        bVar4 = *(int *)(param_1 + 0x1c) != 0;
        if ((bVar4 == (iVar2 != 0)) && ((*(int *)(param_1 + 0x20) != 0) == bVar4)) {
          if (iVar2 == 0) {
            uVar3 = 1;
            goto LAB_6008ebe8;
          }
          iVar2 = FUN_600e94ca(&local_b0,*(undefined4 *)(param_1 + 8),iVar2,auStack_90,1,iVar1);
          if (((iVar2 == 0) ||
              (iVar2 = FUN_600e94ca(&local_ac,*(undefined4 *)(param_1 + 8),
                                    *(undefined4 *)(param_1 + 0x1c),auStack_7c,1,iVar1), iVar2 == 0)
              ) || (iVar2 = FUN_600e94ca(&local_a8,*(undefined4 *)(param_1 + 0x14),
                                         *(undefined4 *)(param_1 + 0x20),
                                         *(undefined4 *)(param_1 + 0x10),1,iVar1), iVar2 == 0)) {
            uVar3 = 3;
            uVar5 = 0x2e6;
          }
          else {
            if (((local_b0 != 0) && (local_ac != 0)) && (local_a8 != 0)) {
              uVar3 = 1;
              goto LAB_6008ebe8;
            }
            uVar3 = 0x6f;
            uVar5 = 0x2eb;
          }
        }
        else {
          uVar3 = 0x7b;
          uVar5 = 0x2da;
        }
      }
      else {
        uVar3 = 0x93;
        uVar5 = 0x2d3;
      }
      FUN_600e0552(4,0,uVar3,DAT_6008ed54,uVar5);
      uVar3 = 0;
      goto LAB_6008ebe8;
    }
    uVar5 = 0x84;
    uVar6 = 0x2c9;
  }
  uVar3 = 0;
  FUN_600e0552(4,0,uVar5,DAT_6008ed54,uVar6);
LAB_6008ebe8:
  FUN_600e6a22(auStack_a4);
  FUN_600e6a22(auStack_90);
  FUN_600e6a22(auStack_7c);
  FUN_600e6a22(auStack_68);
  FUN_600e6a22(auStack_54);
  FUN_600e6a22(auStack_40);
  FUN_600e6a22(auStack_2c);
  FUN_6008b544(iVar1);
  return uVar3;
}


