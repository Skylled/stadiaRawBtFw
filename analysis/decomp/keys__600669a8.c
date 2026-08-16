// 600669a8  keys__600669a8  size=182 bytes
// src: keys.cc
// --- callers ---
//   600db5a8 FUN_600db5a8
// --- callees ---
//   600d6f24 FUN_600d6f24
//   600d6f7e FUN_600d6f7e
//   600d72b8 FUN_600d72b8
//   60065ccc FUN_60065ccc
//   600d6eca FUN_600d6eca
//   600d74b0 FUN_600d74b0
//   60101740 FUN_60101740
//   600d6fd8 FUN_600d6fd8
//   600ce2a0 FUN_600ce2a0


/* src: keys.cc */

uint keys__600669a8(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  int local_a8;
  int iStack_a4;
  
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    return 5;
  }
  puVar2 = (undefined *)FUN_60065ccc();
  if (puVar2 == PTR_DAT_60066a68) {
    FUN_600ce2a0(&local_a8,PTR_s_CHECK_failed_60122ce9_9_60066a70,PTR_s_keys_cc_60066a6c,0x3eb);
    FUN_60101740(&local_a8);
  }
  if (puVar2[0xd] != '\0') {
    return 7;
  }
  switch(puVar2[0xc]) {
  case 3:
    uVar3 = FUN_600d72b8(iVar1,&local_a8);
    goto LAB_60066a08;
  default:
    return 3;
  case 8:
    uVar3 = FUN_600d6fd8(iVar1,&local_a8);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    goto LAB_60066a26;
  case 9:
    uVar3 = FUN_600d6f7e(iVar1,&local_a8);
LAB_60066a08:
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    break;
  case 10:
    uVar3 = FUN_600d6f24(iVar1,&local_a8);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    local_a8 = (int)(short)local_a8;
    break;
  case 0xb:
    uVar3 = FUN_600d6eca(iVar1,&local_a8);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    local_a8 = (int)(char)local_a8;
  }
  iStack_a4 = local_a8 >> 0x1f;
LAB_60066a26:
  *param_2 = local_a8;
  param_2[1] = iStack_a4;
  return 0;
}


