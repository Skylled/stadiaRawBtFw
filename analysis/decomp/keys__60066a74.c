// 60066a74  keys__60066a74  size=186 bytes
// src: keys.cc
// --- callers ---
//   600db5a8 FUN_600db5a8
// --- callees ---
//   600d382e FUN_600d382e
//   600d7032 FUN_600d7032
//   600d39ba FUN_600d39ba
//   60065ccc FUN_60065ccc
//   600d74b0 FUN_600d74b0
//   600d708c FUN_600d708c
//   60101740 FUN_60101740
//   600ce2a0 FUN_600ce2a0
//   600d70e6 FUN_600d70e6


/* src: keys.cc */

uint keys__60066a74(undefined4 param_1,uint *param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint local_a8;
  uint uStack_a4;
  
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    return 5;
  }
  puVar2 = (undefined *)FUN_60065ccc();
  if (puVar2 == PTR_DAT_60066b34) {
    FUN_600ce2a0(&local_a8,PTR_s_CHECK_failed_60122ce9_9_60066b3c,PTR_s_keys_cc_60066b38,0x41a);
    FUN_60101740(&local_a8);
  }
  if (puVar2[0xd] != '\0') {
    return 7;
  }
  switch(puVar2[0xc]) {
  case 2:
    uVar3 = FUN_600d7032(iVar1,&local_a8);
    break;
  default:
    return 3;
  case 4:
    uVar3 = FUN_600d70e6(iVar1,&local_a8);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    goto LAB_60066af6;
  case 5:
    uVar3 = FUN_600d382e(iVar1,&local_a8);
    break;
  case 6:
    uVar3 = FUN_600d708c(iVar1,&local_a8);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    local_a8 = local_a8 & 0xffff;
    goto LAB_60066af4;
  case 7:
    uVar3 = FUN_600d39ba(iVar1,&local_a8);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    local_a8 = local_a8 & 0xff;
LAB_60066af4:
    uStack_a4 = 0;
LAB_60066af6:
    *param_2 = local_a8;
    param_2[1] = uStack_a4;
    goto LAB_60066adc;
  }
  if ((uVar3 & 0xff) == 0) {
    *param_2 = local_a8;
    param_2[1] = 0;
LAB_60066adc:
    uVar3 = 0;
  }
  return uVar3;
}


