// 600861c0  pem_lib__600861c0  size=824 bytes
// src: pem_lib.c
// --- callers ---
//   60086508 FUN_60086508
// --- callees ---
//   60084c40 bio__60084c40
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6004cb28 FUN_6004cb28
//   600ece78 FUN_600ece78
//   600ece1e FUN_600ece1e
//   60090d24 FUN_60090d24
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600ece1a thunk_FUN_600ece12
//   600ece60 FUN_600ece60
//   600e0552 FUN_600e0552
//   601024b4 FUN_601024b4
//   60090ef4 buf__60090ef4
//   600ecea2 thunk_FUN_600ece78


/* src: pem_lib.c */

undefined4
pem_lib__600861c0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  int local_168;
  int local_164;
  undefined1 auStack_160 [56];
  byte local_128 [9];
  undefined1 auStack_11f [245];
  undefined1 local_2a;
  
  local_164 = 0;
  iVar1 = buf__60090ef4();
  iVar2 = buf__60090ef4();
  iVar3 = buf__60090ef4();
  uVar8 = DAT_60086504;
  uVar14 = DAT_60086500;
  if (((iVar1 == 0) || (iVar2 == 0)) || (iVar3 == 0)) {
    FUN_600ece60(iVar1);
    FUN_600ece60(iVar2);
    FUN_600ece60(iVar3);
    FUN_600e0552(9,0,0x41,DAT_600864f8,0x265);
    return 0;
  }
  local_2a = 0;
  do {
    do {
      iVar4 = bio__60084c40(param_1,local_128,0xfe);
      if (iVar4 < 1) {
        uVar8 = 0x6e;
        uVar14 = 0x26e;
        iVar4 = iVar3;
        iVar5 = iVar2;
        goto LAB_6008623e;
      }
      do {
        if (0x20 < local_128[iVar4]) break;
        bVar12 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar12);
      local_128[iVar4 + 1] = 10;
      local_128[iVar4 + 2] = 0;
      iVar4 = FUN_601024b4(local_128,uVar8,0xb);
    } while (iVar4 != 0);
    iVar4 = FUN_6004cb28(auStack_11f + 2);
    iVar5 = FUN_601024b4(local_128 + iVar4 + 5,uVar14,6);
  } while (iVar5 != 0);
  iVar5 = FUN_600ece78(iVar1,iVar4 + 9);
  if (iVar5 == 0) {
    uVar14 = 0x27d;
LAB_600862aa:
    uVar8 = 0x41;
    iVar4 = iVar3;
    iVar5 = iVar2;
  }
  else {
    if (iVar4 != 6) {
      thunk_EXT_FUN_0000b572(*(undefined4 *)(iVar1 + 4),auStack_11f + 2);
    }
    *(undefined1 *)(*(int *)(iVar1 + 4) + iVar4 + -6) = 0;
    iVar4 = FUN_600ece78(iVar2,0x100);
    if (iVar4 == 0) {
      uVar14 = 0x287;
      goto LAB_600862aa;
    }
    **(undefined1 **)(iVar2 + 4) = 0;
    iVar9 = 0;
    while( true ) {
      iVar4 = bio__60084c40(param_1,local_128,0xfe);
      bVar12 = false;
      if (iVar4 < 1) break;
      do {
        if (0x20 < local_128[iVar4]) break;
        bVar11 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar11);
      iVar5 = iVar4 + 2;
      local_128[iVar4 + 1] = 10;
      local_128[iVar5] = 0;
      if (local_128[0] == 10) break;
      iVar6 = iVar9 + iVar5;
      iVar4 = FUN_600ece78(iVar2,iVar6 + 9);
      if (iVar4 == 0) {
        uVar14 = 0x298;
        goto LAB_600862aa;
      }
      iVar4 = FUN_601024b4(local_128,DAT_600864fc,9);
      if (iVar4 == 0) {
        bVar12 = true;
        break;
      }
      if (iVar5 != 0) {
        thunk_EXT_FUN_0000b572(*(int *)(iVar2 + 4) + iVar9,local_128,iVar5);
      }
      *(undefined1 *)(*(int *)(iVar2 + 4) + iVar6) = 0;
      iVar9 = iVar6;
    }
    local_164 = 0;
    iVar6 = FUN_600ece78(iVar3,0x400);
    if (iVar6 == 0) {
      uVar14 = 0x2a6;
      goto LAB_600862aa;
    }
    **(undefined1 **)(iVar3 + 4) = 0;
    uVar14 = DAT_600864fc;
    iVar4 = iVar2;
    iVar5 = iVar3;
    if (!bVar12) {
      do {
        uVar13 = bio__60084c40(param_1,local_128,0xfe);
        iVar6 = (int)((ulonglong)uVar13 >> 0x20);
        iVar7 = (int)uVar13;
        iVar4 = iVar3;
        iVar5 = iVar2;
        iVar9 = local_164;
        if (iVar7 < 1) goto LAB_6008642c;
        do {
          if (0x20 < local_128[iVar7]) break;
          bVar12 = iVar7 != 0;
          iVar7 = iVar7 + -1;
        } while (bVar12);
        iVar10 = iVar7 + 2;
        local_128[iVar7 + 1] = 10;
        local_128[iVar10] = 0;
        uVar13 = FUN_601024b4(local_128,uVar14,9);
        iVar6 = (int)((ulonglong)uVar13 >> 0x20);
        iVar9 = local_164;
        if (((int)uVar13 == 0) || (0x41 < iVar10)) goto LAB_6008642c;
        iVar4 = thunk_FUN_600ece78(iVar3,local_164 + iVar10 + 9);
        if (iVar4 == 0) {
          uVar14 = 700;
          goto LAB_600862aa;
        }
        thunk_EXT_FUN_0000b572(*(int *)(iVar3 + 4) + local_164,local_128,iVar10);
        *(undefined1 *)(*(int *)(iVar3 + 4) + iVar10 + local_164) = 0;
        local_164 = local_164 + iVar10;
      } while (iVar10 == 0x41);
      local_128[0] = 0;
      uVar13 = bio__60084c40(param_1,local_128,0xfe);
      iVar6 = (int)((ulonglong)uVar13 >> 0x20);
      iVar7 = (int)uVar13;
      iVar4 = iVar3;
      iVar9 = local_164;
      if (0 < iVar7) {
        do {
          if (0x20 < local_128[iVar7]) break;
          bVar12 = iVar7 != 0;
          iVar7 = iVar7 + -1;
        } while (bVar12);
        local_128[iVar7 + 1] = 10;
        local_128[iVar7 + 2] = 0;
      }
    }
LAB_6008642c:
    local_164 = iVar9;
    uVar14 = *(undefined4 *)(iVar1 + 4);
    iVar2 = FUN_6004cb28(uVar14,iVar6);
    iVar3 = FUN_601024b4(local_128,DAT_600864fc,9);
    if (((iVar3 == 0) && (iVar3 = FUN_601024b4(uVar14,auStack_11f,iVar2), iVar3 == 0)) &&
       (iVar2 = FUN_601024b4(auStack_11f + iVar2,DAT_60086500,6), iVar2 == 0)) {
      thunk_FUN_600ece12(auStack_160);
      iVar2 = FUN_60090d24(auStack_160,*(undefined4 *)(iVar4 + 4),&local_164,
                           *(undefined4 *)(iVar4 + 4),local_164);
      if (iVar2 < 0) {
        uVar14 = 0x2e3;
      }
      else {
        iVar2 = FUN_600ece1e(auStack_160,*(int *)(iVar4 + 4) + local_164,&local_168);
        if (-1 < iVar2) {
          local_164 = local_164 + local_168;
          if (local_164 != 0) {
            *param_2 = *(undefined4 *)(iVar1 + 4);
            *param_3 = *(undefined4 *)(iVar5 + 4);
            *param_4 = *(undefined4 *)(iVar4 + 4);
            *param_5 = local_164;
            thunk_EXT_FUN_0000ac5e(iVar1);
            thunk_EXT_FUN_0000ac5e(iVar5);
            thunk_EXT_FUN_0000ac5e(iVar4);
            return 1;
          }
          goto LAB_60086244;
        }
        uVar14 = 0x2e8;
      }
      uVar8 = 100;
    }
    else {
      uVar8 = 0x66;
      uVar14 = 0x2da;
    }
  }
LAB_6008623e:
  FUN_600e0552(9,0,uVar8,DAT_600864f8,uVar14);
LAB_60086244:
  FUN_600ece60(iVar1);
  FUN_600ece60(iVar5);
  FUN_600ece60(iVar4);
  return 0;
}


