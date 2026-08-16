// 60054a54  usb_device_cdc_acm__60054a54  size=532 bytes
// src: usb_device_cdc_acm.c
// --- callers ---
//   6005505c FUN_6005505c
// --- callees ---
//   600d1134 FUN_600d1134
//   600d1156 FUN_600d1156
//   6010165c FUN_6010165c
//   600d06d6 FUN_600d06d6
//   600548c4 FUN_600548c4


/* src: usb_device_cdc_acm.c */

int usb_device_cdc_acm__60054a54(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  ushort *local_28;
  ushort *local_24;
  undefined2 local_20;
  undefined2 local_1e;
  char local_1c;
  
  if ((param_3 == (ushort *)0x0) || (param_1 == (undefined4 *)0x0)) {
    return 3;
  }
  switch(param_2) {
  case 1:
    pbVar5 = *(byte **)param_3;
    local_20 = *(undefined2 *)(pbVar5 + 4);
    if ((*(char *)((int)param_1 + 0x29) == (char)local_20) && ((*pbVar5 & 0x60) == 0x20)) {
      local_28 = param_3 + 2;
      local_24 = param_3 + 4;
      local_1e = *(undefined2 *)(pbVar5 + 2);
      local_1c = (char)param_3[6];
      bVar1 = pbVar5[1];
      if (bVar1 == 4) {
        uVar3 = 8;
        pcVar6 = *(code **)param_1[1];
      }
      else if (bVar1 < 5) {
        if (bVar1 == 1) {
          uVar3 = 5;
          pcVar6 = *(code **)param_1[1];
        }
        else if (bVar1 == 0) {
          uVar3 = 4;
          pcVar6 = *(code **)param_1[1];
        }
        else if (bVar1 == 2) {
          uVar3 = 6;
          pcVar6 = *(code **)param_1[1];
        }
        else {
          if (bVar1 != 3) {
            return 5;
          }
          uVar3 = 7;
          pcVar6 = *(code **)param_1[1];
        }
      }
      else if (bVar1 == 0x21) {
        uVar3 = 9;
        pcVar6 = *(code **)param_1[1];
      }
      else if (bVar1 < 0x22) {
        if (bVar1 != 0x20) {
          return 5;
        }
        uVar3 = 10;
        pcVar6 = *(code **)param_1[1];
      }
      else if (bVar1 == 0x22) {
        uVar3 = 0xb;
        pcVar6 = *(code **)param_1[1];
      }
      else {
        if (bVar1 != 0x23) {
          return 5;
        }
        uVar3 = 0xc;
        pcVar6 = *(code **)param_1[1];
      }
      iVar7 = (*pcVar6)(param_1,uVar3,&local_28);
      return iVar7;
    }
    break;
  case 2:
    *(undefined1 *)(param_1 + 10) = 0;
    break;
  case 3:
    if ((param_1[1] != 0) && ((char)*param_3 != *(char *)(param_1 + 10))) {
      FUN_600d06d6();
      *(char *)(param_1 + 10) = (char)*param_3;
      *(undefined1 *)((int)param_1 + 0x2a) = 0;
      iVar7 = FUN_600548c4(param_1);
      if (iVar7 == 0) {
        return 0;
      }
      uVar3 = 0x19d;
      uVar4 = DAT_60054c70;
LAB_60054ab2:
      FUN_6010165c(0x28,DAT_60054c74,uVar3,uVar4);
      return iVar7;
    }
    break;
  case 4:
    if (((param_1[1] != 0) && ((ushort)*(byte *)((int)param_1 + 0x29) == *param_3 >> 8)) &&
       (cVar2 = (char)*param_3, *(char *)((int)param_1 + 0x2a) != cVar2)) {
      FUN_600d06d6();
      *(char *)((int)param_1 + 0x2a) = cVar2;
      iVar7 = FUN_600548c4(param_1);
      if (iVar7 == 0) {
        return 0;
      }
      uVar3 = 0x1b6;
      uVar4 = DAT_60054c78;
      goto LAB_60054ab2;
    }
    break;
  case 5:
    if (((param_1[1] != 0) && (param_1[2] != 0)) && (param_1[3] != 0)) {
      iVar7 = 1;
      for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(param_1[2] + 4); iVar8 = iVar8 + 1) {
        if (*(char *)(*(int *)(param_1[2] + 8) + iVar8 * 4) == (char)*param_3) {
          iVar7 = FUN_600d1134(*param_1);
        }
      }
      for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(param_1[3] + 4); iVar8 = iVar8 + 1) {
        if (*(char *)(*(int *)(param_1[3] + 8) + iVar8 * 4) == (char)*param_3) {
          iVar7 = FUN_600d1134(*param_1);
        }
      }
      return iVar7;
    }
    break;
  case 6:
    if (((param_1[1] != 0) && (param_1[2] != 0)) && (param_1[3] != 0)) {
      iVar7 = 1;
      for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(param_1[2] + 4); iVar8 = iVar8 + 1) {
        if (*(char *)(*(int *)(param_1[2] + 8) + iVar8 * 4) == (char)*param_3) {
          iVar7 = FUN_600d1156(*param_1);
        }
      }
      for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(param_1[3] + 4); iVar8 = iVar8 + 1) {
        if (*(char *)(*(int *)(param_1[3] + 8) + iVar8 * 4) == (char)*param_3) {
          iVar7 = FUN_600d1156(*param_1);
        }
      }
      return iVar7;
    }
  }
  return 1;
}


