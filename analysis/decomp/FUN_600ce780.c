// 600ce780  FUN_600ce780  size=312 bytes
// --- callers ---
// --- callees ---
//   600cf38e FUN_600cf38e
//   600cf292 FUN_600cf292
//   6005368c FUN_6005368c
//   6005382c FUN_6005382c
//   600cf200 FUN_600cf200


undefined4 FUN_600ce780(uint param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2d;
  undefined1 local_24;
  undefined1 local_23;
  
  if (-1 < (int)((uint)*(byte *)(param_3 + 3) << 0x1e)) {
    return 0xffffffff;
  }
  if ((param_1 & 0xf0000) != 0) {
    return 0xfffffffc;
  }
  uVar4 = param_1 & 0xff;
  piVar3 = (int *)*param_3;
  if (uVar4 == 0x18) {
    FUN_600cf292(*piVar3,param_3[1]);
    return 0;
  }
  if (uVar4 == 0x19) {
    FUN_600cf38e(*piVar3,param_3[1]);
    return 0;
  }
  FUN_600cf200(&local_34);
  if (uVar4 == 0x15) {
    iVar2 = *piVar3;
    if (param_2 != 0) {
      uVar4 = *(uint *)(iVar2 + 0x18) | 0x80000;
      goto LAB_600ce7fe;
    }
    uVar4 = *(uint *)(iVar2 + 0x18) & 0xfff7ffff;
  }
  else {
    if (uVar4 != 0x16) {
      if (uVar4 != 1) {
        return 0xfffffffc;
      }
      if ((param_1 & 0x700) == 0) {
        local_2f = 0;
      }
      else {
        if ((param_1 & 0x700) != 0x700) {
          return 0xfffffff7;
        }
        local_2f = (undefined1)param_1;
      }
      uVar4 = param_1 & 0x3000;
      if (uVar4 == 0x1000) {
        local_30 = 2;
      }
      else if (uVar4 == 0x2000) {
        local_30 = 3;
      }
      else {
        local_30 = 0;
        if (uVar4 != 0) {
          return 0xfffffff6;
        }
      }
      if ((param_1 & 0xc000) != 0) {
        if ((param_1 & 0xc000) != 0x4000) {
          return 0xfffffff5;
        }
        local_2d = 1;
      }
      local_34 = param_2;
      if ((int)((uint)*(byte *)(param_3 + 3) << 0x1d) < 0) {
        FUN_6005382c(*piVar3);
        *(byte *)(param_3 + 3) = *(byte *)(param_3 + 3) & 0xfb;
      }
      local_24 = 1;
      local_23 = 1;
      iVar2 = *piVar3;
      uVar1 = (*(code *)piVar3[1])();
      iVar2 = FUN_6005368c(iVar2,&local_34,uVar1);
      if (iVar2 != 0x521) {
        *(byte *)(param_3 + 3) = *(byte *)(param_3 + 3) | 4;
        return 0;
      }
      return 0xfffffff8;
    }
    iVar2 = *piVar3;
    if (param_2 != 0) {
      uVar4 = *(uint *)(iVar2 + 0x18) | 0x40000;
LAB_600ce7fe:
      *(uint *)(iVar2 + 0x18) = uVar4;
      return 0;
    }
    uVar4 = *(uint *)(iVar2 + 0x18) & 0xfffbffff;
  }
  *(uint *)(iVar2 + 0x18) = uVar4;
  return 0;
}


