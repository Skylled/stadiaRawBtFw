// 600d0c6a  FUN_600d0c6a  size=384 bytes
// --- callers ---
//   6005505c FUN_6005505c
// --- callees ---
//   60055224 FUN_60055224
//   600d1156 FUN_600d1156
//   600d0c3c FUN_600d0c3c
//   600d1134 FUN_600d1134


undefined4 FUN_600d0c6a(undefined4 *param_1,undefined4 param_2,ushort *param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  byte *pbVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_1c;
  ushort *local_18;
  undefined4 local_14;
  
  puVar6 = &local_1c;
  if ((param_3 == (ushort *)0x0) || (param_1 == (undefined4 *)0x0)) {
    return 3;
  }
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_4;
  switch(param_2) {
  case 1:
    pbVar3 = *(byte **)param_3;
    if ((*pbVar3 & 0x1f) != 1) {
      return 1;
    }
    if (*(byte *)((int)param_1 + 0xd) != pbVar3[4]) {
      return 1;
    }
    local_14._2_2_ = (undefined2)((uint)param_4 >> 0x10);
    switch(pbVar3[1]) {
    case 1:
      uVar2 = 3;
      local_14 = CONCAT31(CONCAT21(local_14._2_2_,(char)*(undefined2 *)(pbVar3 + 2)),
                          (char)((ushort)*(undefined2 *)(pbVar3 + 2) >> 8));
      pcVar4 = *(code **)param_1[1];
      break;
    case 2:
      puVar6 = (undefined4 *)((int)param_1 + 0xf);
      goto LAB_600d0d8e;
    case 3:
      puVar6 = param_1 + 4;
LAB_600d0d8e:
      uVar2 = (**(code **)param_1[1])(param_1,4,puVar6);
      *(undefined4 **)(param_3 + 2) = puVar6;
      return uVar2;
    default:
      return 5;
    case 9:
      local_14 = CONCAT31(CONCAT21(local_14._2_2_,(char)*(undefined2 *)(pbVar3 + 2)),
                          (char)((ushort)*(undefined2 *)(pbVar3 + 2) >> 8));
      local_18 = *(ushort **)(param_3 + 4);
      pcVar4 = *(code **)param_1[1];
      if ((char)param_3[6] == '\0') {
        local_1c = *(undefined4 *)(param_3 + 2);
        uVar2 = 6;
        goto LAB_600d0dcc;
      }
      uVar2 = 9;
      break;
    case 10:
      uVar2 = 7;
      puVar6 = (undefined4 *)((int)param_1 + 0xf);
      *(char *)puVar6 = (char)((ushort)*(undefined2 *)(pbVar3 + 2) >> 8);
      pcVar4 = *(code **)param_1[1];
      goto LAB_600d0dcc;
    case 0xb:
      uVar2 = 8;
      puVar6 = param_1 + 4;
      *(char *)puVar6 = (char)*(undefined2 *)(pbVar3 + 2);
      pcVar4 = *(code **)param_1[1];
LAB_600d0dcc:
      uVar2 = (*pcVar4)(param_1,uVar2,puVar6,pcVar4,param_1);
      return uVar2;
    }
    uVar2 = (*pcVar4)(param_1,uVar2,puVar6);
    *(undefined4 *)(param_3 + 2) = local_1c;
    *(ushort **)(param_3 + 4) = local_18;
    return uVar2;
  case 2:
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 0x11) = 0;
    *(undefined1 *)((int)param_1 + 0x12) = 0;
    param_1[2] = 0;
    break;
  case 3:
    if ((param_1[1] != 0) && ((char)*param_3 != *(char *)(param_1 + 3))) {
      if (*(char *)(param_1 + 3) != '\0') {
        FUN_600d0c3c();
      }
      *(char *)(param_1 + 3) = (char)*param_3;
      *(undefined1 *)((int)param_1 + 0xe) = 0;
LAB_600d0cb6:
      uVar2 = FUN_60055224(param_1);
      return uVar2;
    }
    break;
  case 4:
    if (((param_1[1] != 0) && ((ushort)*(byte *)((int)param_1 + 0xd) == *param_3 >> 8)) &&
       (cVar1 = (char)*param_3, *(char *)((int)param_1 + 0xe) != cVar1)) {
      FUN_600d0c3c();
      *(char *)((int)param_1 + 0xe) = cVar1;
      goto LAB_600d0cb6;
    }
    break;
  case 5:
    if ((param_1[1] != 0) && (param_1[2] != 0)) {
      uVar2 = 1;
      for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)(param_1[2] + 4); iVar5 = iVar5 + 1) {
        if (*(char *)(*(int *)(param_1[2] + 8) + iVar5 * 4) == (char)*param_3) {
          uVar2 = FUN_600d1134(*param_1);
        }
      }
      return uVar2;
    }
    break;
  case 6:
    if ((param_1[1] != 0) && (param_1[2] != 0)) {
      uVar2 = 1;
      for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)(param_1[2] + 4); iVar5 = iVar5 + 1) {
        if (*(char *)(*(int *)(param_1[2] + 8) + iVar5 * 4) == (char)*param_3) {
          uVar2 = FUN_600d1156(*param_1);
        }
      }
      return uVar2;
    }
  }
  return 1;
}


