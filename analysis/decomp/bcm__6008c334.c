// 6008c334  bcm__6008c334  size=706 bytes
// src: bcm.c
// --- callers ---
// --- callees ---
//   600e9b62 FUN_600e9b62
//   600e9dea FUN_600e9dea
//   600e7598 FUN_600e7598
//   6008ba20 bcm__6008ba20
//   600e092c FUN_600e092c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e932c FUN_600e932c
//   600e965c FUN_600e965c
//   600e7706 FUN_600e7706
//   600e0552 FUN_600e0552
//   600e92f0 FUN_600e92f0
//   600e936e FUN_600e936e
//   600e73ac FUN_600e73ac
//   600e7382 FUN_600e7382
//   6008b3d4 bcm__6008b3d4
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6013cfb0 thunk_EXT_FUN_0000ac52
//   600e7548 FUN_600e7548


/* src: bcm.c */

undefined4
bcm__6008c334(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  int local_70;
  uint local_6c;
  int local_64;
  int local_50 [3];
  undefined4 local_44;
  undefined4 local_40;
  int local_3c [3];
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar10 = FUN_600e7706(param_4);
  if ((int)uVar10 == 0) {
    FUN_600e0552(3,0,0x68,DAT_6008c5f8,0x392);
    return 0;
  }
  if (*(int *)(param_4 + 0xc) != 0) {
    uVar3 = 0x6d;
    uVar11 = 0x396;
LAB_6008c374:
    FUN_600e0552(3,0,uVar3,DAT_6008c5f8,uVar11);
    return 0;
  }
  if ((*(int *)((int)((ulonglong)uVar10 >> 0x20) + 0xc) != 0) ||
     (iVar1 = FUN_600e7548(param_2,param_4), -1 < iVar1)) {
    uVar3 = 0x6b;
    uVar11 = 0x39a;
    goto LAB_6008c374;
  }
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 == 0) {
    iVar1 = FUN_600e7598(param_4,1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
      return 1;
    }
    uVar3 = FUN_600e7382(param_1);
    return uVar3;
  }
  if (param_6 == 0) {
    param_6 = FUN_600e9b62(param_4,param_5);
    local_70 = param_6;
    if (param_6 == 0) {
      uVar3 = 0;
      iVar5 = 0;
      local_6c = 0;
      local_64 = 0;
      goto LAB_6008c4e8;
    }
  }
  else {
    local_70 = 0;
  }
  iVar1 = iVar1 * 0x20;
  iVar7 = *(int *)(param_6 + 0x18);
  if (iVar1 < 0x3aa) {
    if (iVar1 < 0x133) {
      if (iVar1 < 0x5a) {
        if (iVar1 < 0x17) {
          iVar8 = 1;
        }
        else {
          iVar8 = 3;
        }
      }
      else {
        iVar8 = 4;
      }
    }
    else {
      iVar8 = 5;
    }
  }
  else {
    iVar8 = 6;
  }
  iVar4 = 1 << iVar8;
  iVar5 = iVar7 * 2;
  if (iVar5 < iVar4) {
    iVar5 = iVar4;
  }
  local_64 = ((iVar7 << iVar8) + iVar5) * 4;
  local_6c = FUN_600e092c(local_64 + 0x40);
  if (local_6c == 0) {
    uVar3 = 0;
    iVar5 = 0;
  }
  else {
    iVar5 = (local_6c & 0xffffffc0) + 0x40;
    iVar6 = iVar5 + (iVar7 << iVar8) * 4;
    thunk_EXT_FUN_0000af90(iVar5,0,local_64);
    local_3c[0] = iVar6 + iVar7 * 4;
    local_3c[1] = 0;
    local_50[1] = 0;
    local_30 = 0;
    local_44 = 0;
    local_2c = 2;
    local_40 = 2;
    local_50[0] = iVar6;
    local_50[2] = iVar7;
    local_3c[2] = iVar7;
    iVar6 = FUN_600e936e(local_50,param_6,param_5);
    uVar3 = 0;
    if (iVar6 != 0) {
      iVar6 = FUN_600e965c(local_3c,param_2,param_6,param_5);
      uVar3 = 0;
      if (iVar6 != 0) {
        bcm__6008b3d4(iVar5,iVar7,local_50);
        iVar6 = iVar5 + iVar7 * 4;
        bcm__6008b3d4(iVar6,iVar7,local_3c);
        if (iVar8 != 1) {
          iVar9 = bcm__6008ba20(local_50,local_3c,local_3c,param_6,param_5);
          uVar3 = 0;
          if (iVar9 == 0) goto LAB_6008c4e8;
          iVar6 = iVar6 + iVar7 * 4;
          bcm__6008b3d4(iVar6,iVar7,local_50);
          iVar6 = iVar6 + iVar7 * 4;
          for (iVar9 = 3; iVar9 < iVar4; iVar9 = iVar9 + 1) {
            iVar2 = bcm__6008ba20(local_50,local_3c,local_50,param_6,param_5);
            uVar3 = 0;
            if (iVar2 == 0) goto LAB_6008c4e8;
            bcm__6008b3d4(iVar6,iVar7,local_50);
            iVar6 = iVar6 + iVar7 * 4;
          }
        }
        iVar1 = iVar1 + -1;
        iVar4 = 0;
        for (iVar6 = iVar1 - iVar8 * (iVar1 / iVar8); -1 < iVar6; iVar6 = iVar6 + -1) {
          iVar9 = FUN_600e9dea(param_3,iVar1);
          iVar1 = iVar1 + -1;
          iVar4 = iVar4 * 2 + iVar9;
        }
        iVar4 = FUN_600e73ac(local_50,iVar7,iVar5,iVar4,iVar8);
        while (uVar3 = 0, iVar4 != 0) {
          if (iVar1 < 0) {
            iVar1 = FUN_600e932c(param_1,local_50,param_6,param_5);
            uVar3 = 0;
            if (iVar1 != 0) {
              uVar3 = 1;
            }
            break;
          }
          iVar9 = iVar1 - iVar8;
          iVar6 = 0;
          iVar4 = iVar1;
          do {
            iVar1 = bcm__6008ba20(local_50,local_50,local_50,param_6,param_5);
            uVar3 = 0;
            if (iVar1 == 0) goto LAB_6008c4e8;
            iVar1 = iVar4 + -1;
            iVar4 = FUN_600e9dea(param_3,iVar4);
            iVar6 = iVar6 * 2 + iVar4;
            iVar4 = iVar1;
          } while (iVar1 != iVar9);
          iVar4 = FUN_600e73ac(local_3c,iVar7,iVar5,iVar6,iVar8);
          uVar3 = 0;
          if (iVar4 == 0) break;
          iVar4 = bcm__6008ba20(local_50,local_50,local_3c,param_6,param_5);
        }
      }
    }
  }
LAB_6008c4e8:
  FUN_600e92f0(local_70);
  if ((iVar5 != 0) && (local_6c == 0)) {
    thunk_EXT_FUN_0000ac52(iVar5,local_64);
  }
  thunk_EXT_FUN_0000ac5e(local_6c);
  return uVar3;
}


