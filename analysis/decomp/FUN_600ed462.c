// 600ed462  FUN_600ed462  size=230 bytes
// --- callers ---
//   600ed548 FUN_600ed548
// --- callees ---
//   60090f78 FUN_60090f78
//   600ed3ba FUN_600ed3ba
//   600ed2e6 FUN_600ed2e6
//   600ed444 FUN_600ed444


undefined4
FUN_600ed462(undefined4 *param_1,undefined1 *param_2,int *param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte local_3d;
  int local_3c;
  uint local_38;
  uint uStack_34;
  undefined4 local_30;
  int local_2c;
  undefined1 auStack_28 [12];
  
  local_30 = *param_1;
  local_2c = param_1[1];
  if (param_2 == (undefined1 *)0x0) {
    param_2 = auStack_28;
  }
  iVar1 = FUN_60090f78(&local_30,&local_3c);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_3c;
  }
  iVar1 = FUN_600ed3ba(&local_30,&local_3d);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = param_1[1] - local_2c;
  if ((local_3d & 0x80) == 0) {
    iVar4 = (uint)local_3d + iVar1;
    iVar3 = iVar1;
  }
  else {
    uVar5 = local_3d & 0x7f;
    if (((param_5 != 0) && (local_3c << 2 < 0)) && ((local_3d & 0x7f) == 0)) {
      if (param_4 != (int *)0x0) {
        *param_4 = iVar1;
      }
      goto LAB_600ed4dc;
    }
    if (3 < uVar5 - 1) {
      return 0;
    }
    iVar3 = FUN_600ed2e6(&local_30,&local_38,uVar5);
    if (iVar3 == 0) {
      return 0;
    }
    if (uStack_34 == 0 && local_38 < 0x80) {
      return 0;
    }
    uVar6 = (uVar5 + 0x1fffffff) * 8;
    if (uStack_34 >> (uVar6 & 0xff) == 0 &&
        ((local_38 >> (uVar6 & 0xff) == 0 &&
         uStack_34 << ((uVar5 + 0x1fffffff) * -8 + 0x20 & 0xff) == 0) &&
        uStack_34 >> (uVar6 - 0x20 & 0xff) == 0)) {
      return 0;
    }
    if (uVar5 + local_38 + iVar1 < local_38) {
      return 0;
    }
    iVar3 = iVar1 + uVar5;
    iVar4 = local_38 + iVar3;
  }
  iVar1 = iVar4;
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
  }
LAB_600ed4dc:
  uVar2 = FUN_600ed444(param_1,param_2,iVar1);
  return uVar2;
}


