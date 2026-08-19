// 600dba6a  FUN_600dba6a  size=250 bytes
// --- callers ---
//   600dbb64 FUN_600dbb64
// --- callees ---
//   6007a450 linear_interpolation_source__6007a450


uint FUN_600dba6a(int *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_30;
  uint local_2c;
  int local_28 [3];
  undefined4 local_1c;
  
  local_28[0] = *param_4;
  local_28[2] = *param_2;
  local_1c = *param_3;
  local_28[1] = 0;
  if (local_28[0] == 0) {
    return 0;
  }
  uVar5 = param_1[3];
  local_30 = 0;
  uVar6 = uVar5 - param_1[1];
  if (uVar6 == 0) goto LAB_600dbac2;
  uVar4 = param_1[1] + *param_1;
  iVar3 = uVar4 - uVar5 * (uVar4 / uVar5);
  if ((*param_1 == 0) || (uVar5 <= uVar4)) {
    bVar1 = linear_interpolation_source__6007a450(local_28,iVar3 + param_1[2],uVar6,&local_30);
    iVar3 = param_1[1] + local_30;
LAB_600dbabc:
    local_2c = (uint)bVar1;
    param_1[1] = iVar3;
  }
  else {
    uVar5 = uVar5 - iVar3;
    if (uVar5 == 0) {
      local_2c = 0;
    }
    else {
      bVar1 = linear_interpolation_source__6007a450(local_28,iVar3 + param_1[2],uVar5,&local_30);
      local_2c = (uint)bVar1;
    }
    param_1[1] = param_1[1] + local_30;
    if (local_30 == uVar5) {
      if (local_2c != 0) {
        return local_2c;
      }
      if ((local_28[0] == 0) || (*param_1 == 0)) goto LAB_600dbac2;
      bVar1 = linear_interpolation_source__6007a450(local_28,param_1[2],*param_1,&local_2c);
      local_30 = local_30 + local_2c;
      iVar3 = param_1[1] + local_2c;
      goto LAB_600dbabc;
    }
  }
  if (local_2c != 0) {
    return local_2c;
  }
LAB_600dbac2:
  if ((uVar6 <= local_30) && (local_28[0] != 0)) {
    while( true ) {
      local_2c = 0;
      if (local_28[0] == 0) {
        return 0xf;
      }
      uVar6 = param_1[3];
      uVar5 = uVar6 - *param_1;
      if (uVar6 <= uVar5) {
        uVar5 = uVar6;
      }
      cVar2 = linear_interpolation_source__6007a450(local_28,*param_1 + param_1[2],uVar5,&local_2c);
      *param_1 = (*param_1 + local_2c) - param_1[3] * ((*param_1 + local_2c) / (uint)param_1[3]);
      if ((uVar5 != 0) && (local_2c == 0)) break;
      if (cVar2 != '\0') {
        return 0xf;
      }
    }
    return 0xf;
  }
  return 0;
}


