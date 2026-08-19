// 600dbda6  FUN_600dbda6  size=250 bytes
// --- callers ---
//   600dbea0 FUN_600dbea0
// --- callees ---
//   600dbd64 FUN_600dbd64


uint FUN_600dbda6(int *param_1,undefined4 *param_2,int *param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  int local_1c;
  
  local_20 = *param_2;
  local_1c = *param_3;
  if (local_1c == 0) {
    return 0;
  }
  uVar5 = param_1[3];
  local_28 = 0;
  uVar6 = uVar5 - param_1[1];
  if (uVar6 == 0) goto LAB_600dbdfa;
  uVar4 = param_1[1] + *param_1;
  iVar3 = uVar4 - uVar5 * (uVar4 / uVar5);
  if ((*param_1 == 0) || (uVar5 <= uVar4)) {
    bVar1 = FUN_600dbd64(&local_20,param_1[2] + iVar3 * 2,uVar6,&local_28);
    iVar3 = param_1[1] + local_28;
LAB_600dbdf4:
    local_24 = (uint)bVar1;
    param_1[1] = iVar3;
  }
  else {
    uVar5 = uVar5 - iVar3;
    if (uVar5 == 0) {
      local_24 = 0;
    }
    else {
      bVar1 = FUN_600dbd64(&local_20,param_1[2] + iVar3 * 2,uVar5,&local_28);
      local_24 = (uint)bVar1;
    }
    param_1[1] = param_1[1] + local_28;
    if (local_28 == uVar5) {
      if (local_24 != 0) {
        return local_24;
      }
      if ((local_1c == 0) || (*param_1 == 0)) goto LAB_600dbdfa;
      bVar1 = FUN_600dbd64(&local_20,param_1[2],*param_1,&local_24);
      local_28 = local_28 + local_24;
      iVar3 = param_1[1] + local_24;
      goto LAB_600dbdf4;
    }
  }
  if (local_24 != 0) {
    return local_24;
  }
LAB_600dbdfa:
  if ((uVar6 <= local_28) && (local_1c != 0)) {
    while( true ) {
      local_24 = 0;
      if (local_1c == 0) {
        return 0xf;
      }
      uVar6 = param_1[3];
      uVar5 = uVar6 - *param_1;
      if (uVar6 <= uVar5) {
        uVar5 = uVar6;
      }
      cVar2 = FUN_600dbd64(&local_20,param_1[2] + *param_1 * 2,uVar5,&local_24);
      *param_1 = (*param_1 + local_24) - param_1[3] * ((*param_1 + local_24) / (uint)param_1[3]);
      if ((uVar5 != 0) && (local_24 == 0)) break;
      if (cVar2 != '\0') {
        return 0xf;
      }
    }
    return 0xf;
  }
  return 0;
}


