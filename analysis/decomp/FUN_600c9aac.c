// 600c9aac  FUN_600c9aac  size=536 bytes
// --- callers ---
//   600c8798 FUN_600c8798
// --- callees ---
//   601004b2 FUN_601004b2
//   6010027c FUN_6010027c
//   60100424 FUN_60100424
//   60100246 FUN_60100246
//   60100544 FUN_60100544
//   601002bc FUN_601002bc
//   600c8acc FUN_600c8acc
//   60100324 FUN_60100324


void FUN_600c9aac(undefined4 param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint local_74 [9];
  uint local_50 [9];
  uint local_2c [8];
  undefined4 local_c;
  
  if (param_3 == 8) {
    local_c = DAT_600c9cc4;
  }
  else {
    local_c = DAT_600c9cc8;
  }
  FUN_6010027c(local_2c,local_c,param_3);
  FUN_60100246(local_50,param_3);
  FUN_60100246(local_74,param_3);
  local_50[0] = 1;
  while (iVar2 = FUN_60100324(param_2,param_3), iVar2 == 0) {
    while ((*param_2 & 1) == 0) {
      FUN_60100544(param_2,param_2,param_3);
      if ((local_50[0] & 1) == 0) {
        FUN_60100544(local_50,local_50,param_3);
      }
      else {
        uVar1 = FUN_60100424(local_50,local_50,local_c,param_3);
        local_50[param_3] = uVar1;
        FUN_60100544(local_50,local_50,param_3);
        local_50[param_3 + -1] = local_50[param_3] << 0x1f | local_50[param_3 + -1];
      }
    }
    while ((local_2c[0] & 1) == 0) {
      FUN_60100544(local_2c,local_2c,param_3);
      if ((local_74[0] & 1) == 0) {
        FUN_60100544(local_74,local_74,param_3);
      }
      else {
        uVar1 = FUN_60100424(local_74,local_74,local_c,param_3);
        local_74[param_3] = uVar1;
        FUN_60100544(local_74,local_74,param_3);
        local_74[param_3 + -1] = local_74[param_3] << 0x1f | local_74[param_3 + -1];
      }
    }
    iVar2 = FUN_601002bc(param_2,local_2c,param_3);
    if (iVar2 < 0) {
      FUN_601004b2(local_2c,local_2c,param_2,param_3);
      FUN_600c8acc(local_74,local_74,local_50,param_3);
    }
    else {
      FUN_601004b2(param_2,param_2,local_2c,param_3);
      FUN_600c8acc(local_50,local_50,local_74,param_3);
    }
  }
  iVar2 = FUN_601002bc(local_74,local_c,param_3);
  if (iVar2 < 0) {
    FUN_6010027c(param_1,local_74,param_3);
  }
  else {
    FUN_601004b2(param_1,local_74,local_c,param_3);
  }
  return;
}


