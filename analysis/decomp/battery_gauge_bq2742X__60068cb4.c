// 60068cb4  battery_gauge_bq2742X__60068cb4  size=444 bytes
// src: battery_gauge_bq2742X.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   600d866a FUN_600d866a
//   600d87f4 FUN_600d87f4
//   60068970 FUN_60068970
//   600d8636 FUN_600d8636
//   6010165c FUN_6010165c
//   60068a00 battery_gauge_bq2742X__60068a00
//   600d4330 FUN_600d4330
//   600d87c0 FUN_600d87c0


/* src: battery_gauge_bq2742X.cc */

uint battery_gauge_bq2742X__60068cb4(int param_1,int param_2,uint param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*(char *)(param_1 + 0x1a) == '\0') {
    iVar6 = param_1;
    iVar7 = param_2;
    local_18 = param_3;
    local_14 = param_4;
    FUN_60068970();
    if (param_2 == 1) {
      uVar4 = 300;
    }
    else {
      uVar4 = 4000;
    }
    cVar1 = FUN_600d866a(param_1,0x80,0x80,uVar4,iVar6,iVar7);
    if (cVar1 != '\0') {
      if (param_2 == 1) {
        FUN_6010165c(0x1e,DAT_60068e74,0x142,DAT_60068e70);
        return 0;
      }
      FUN_6010165c(0x1e,DAT_60068e74,0x145,DAT_60068e78);
      uVar2 = battery_gauge_bq2742X__60068a00(param_1);
      if ((uVar2 & 0xff) != 0) {
        return uVar2;
      }
      uVar2 = FUN_600d866a(param_1,0x80,0x80,4000,iVar6,iVar7);
      if ((uVar2 & 0xff) != 0) {
        return uVar2;
      }
      FUN_6010165c(0x14,DAT_60068e74,0x14b,DAT_60068e7c);
    }
    uVar2 = FUN_600d8636(param_1,1,&local_18);
    if ((uVar2 & 0xff) != 0) {
      return uVar2;
    }
    uVar5 = local_18 & 0xffff;
    if (uVar5 == 0x421) {
      uVar3 = 1;
    }
    else {
      if (uVar5 != 0x426) {
        *(char *)(param_1 + 0x1b) = (char)uVar2;
        FUN_6010165c(0x28,DAT_60068e74,0x152,DAT_60068e90,uVar5);
        return 5;
      }
      uVar3 = 2;
    }
    *(undefined1 *)(param_1 + 0x1b) = uVar3;
    FUN_6010165c(10,DAT_60068e74,0x155,DAT_60068e80,uVar5);
    local_18 = local_18 & 0xffff;
    uVar2 = FUN_600d8636(param_1,2,(int)&local_18 + 2);
    if ((uVar2 & 0xff) != 0) {
      return uVar2;
    }
    uVar2 = local_18 >> 0x10;
    FUN_6010165c(10,DAT_60068e74,0x159,DAT_60068e84,uVar2);
    local_14 = local_14 & 0xffff0000;
    uVar5 = FUN_600d8636(param_1,8,&local_14);
    if ((uVar5 & 0xff) != 0) {
      return uVar5;
    }
    local_14 = local_14 & 0xffff;
    uVar5 = FUN_600d4330(param_1,6,(int)&local_14 + 2,200);
    if ((uVar5 & 0xff) != 0) {
      return uVar5;
    }
    if (((int)((local_14 >> 0x10) << 0x1a) < 0) || (*(short *)(param_1 + 0x18) != (short)local_14))
    {
      if ((*(int *)(param_1 + 0x14) != 0) && (uVar5 = FUN_600d87f4(param_1), (uVar5 & 0xff) != 0)) {
        return uVar5;
      }
      FUN_6010165c(10,DAT_60068e74,0x165,DAT_60068e88,uVar2);
      uVar2 = FUN_600d87c0(param_1);
      if ((uVar2 & 0xff) != 0) {
        return uVar2;
      }
      uVar2 = FUN_600d8636(param_1,8,&local_14);
      if ((uVar2 & 0xff) != 0) {
        return uVar2;
      }
      if ((uint)*(ushort *)(param_1 + 0x18) != (local_14 & 0xffff)) {
        FUN_6010165c(0x28,DAT_60068e74,0x16a,DAT_60068e8c,local_14 & 0xffff,
                     (uint)*(ushort *)(param_1 + 0x18));
        return 2;
      }
    }
    FUN_6010165c(10,DAT_60068e74,0x16f,DAT_60068e94,local_14 & 0xffff);
    *(undefined1 *)(param_1 + 0x1a) = 1;
  }
  return 0;
}


