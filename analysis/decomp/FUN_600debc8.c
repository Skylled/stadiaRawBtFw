// 600debc8  FUN_600debc8  size=268 bytes
// --- callers ---
//   6007f1a4 receiver__6007f1a4
// --- callees ---
//   6013d0c0 thunk_EXT_FUN_000064b0


uint FUN_600debc8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 *param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_34;
  uint local_30;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  char local_1c;
  
  local_20 = *param_4;
  local_1c = '\x01';
  uVar5 = param_1[3];
  local_2c[0] = *param_5;
  uVar6 = uVar5 - param_1[1];
  local_34 = 0;
  local_28 = param_2;
  uStack_24 = param_3;
  if (uVar6 == 0) goto LAB_600dec20;
  uVar4 = param_1[1] + *param_1;
  iVar3 = uVar4 - uVar5 * (uVar4 / uVar5);
  if ((*param_1 == 0) || (uVar5 <= uVar4)) {
    bVar1 = thunk_EXT_FUN_000064b0(local_2c,param_1[2] + iVar3 * 4,uVar6,&local_34);
    iVar3 = param_1[1] + local_34;
LAB_600dec1c:
    local_30 = (uint)bVar1;
    param_1[1] = iVar3;
  }
  else {
    uVar5 = uVar5 - iVar3;
    if (uVar5 == 0) {
      local_30 = 0;
    }
    else {
      bVar1 = thunk_EXT_FUN_000064b0(local_2c,param_1[2] + iVar3 * 4,uVar5,&local_34);
      local_30 = (uint)bVar1;
    }
    param_1[1] = param_1[1] + local_34;
    if (local_34 == uVar5) {
      if (local_30 != 0) {
        return local_30;
      }
      if ((local_1c == '\0') || (*param_1 == 0)) goto LAB_600dec20;
      bVar1 = thunk_EXT_FUN_000064b0(local_2c,param_1[2],*param_1,&local_30);
      local_34 = local_34 + local_30;
      iVar3 = param_1[1] + local_30;
      goto LAB_600dec1c;
    }
  }
  if (local_30 != 0) {
    return local_30;
  }
LAB_600dec20:
  if ((local_34 < uVar6) || (local_1c == '\0')) {
    uVar5 = 0;
  }
  else {
    while (local_30 = 0, local_1c != '\0') {
      uVar6 = param_1[3];
      uVar5 = uVar6 - *param_1;
      if (uVar6 <= uVar5) {
        uVar5 = uVar6;
      }
      cVar2 = thunk_EXT_FUN_000064b0(local_2c,param_1[2] + *param_1 * 4,uVar5,&local_30);
      *param_1 = (*param_1 + local_30) - param_1[3] * ((*param_1 + local_30) / (uint)param_1[3]);
      if (((uVar5 != 0) && (local_30 == 0)) || (cVar2 != '\0')) break;
    }
    uVar5 = 0xf;
  }
  return uVar5;
}


