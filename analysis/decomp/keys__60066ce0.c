// 60066ce0  keys__60066ce0  size=162 bytes
// src: keys.cc
// --- callers ---
//   60078e00 FUN_60078e00
// --- callees ---
//   600d7250 FUN_600d7250
//   600d71c8 FUN_600d71c8
//   60065ccc FUN_60065ccc
//   600d74b0 FUN_600d74b0
//   600d722e FUN_600d722e
//   600d720c FUN_600d720c
//   60101740 FUN_60101740
//   600ce2a0 FUN_600ce2a0
//   600d71ea FUN_600d71ea


/* src: keys.cc */

undefined4
keys__60066ce0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8 [39];
  
  local_b0 = param_3;
  uStack_ac = param_4;
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    uVar2 = 5;
  }
  else {
    puVar3 = (undefined *)FUN_60065ccc();
    if (puVar3 == PTR_DAT_60066d88) {
      FUN_600ce2a0(local_a8,PTR_s_CHECK_failed_60122ce9_9_60066d90,PTR_s_keys_cc_60066d8c,0x47e);
      FUN_60101740(local_a8);
    }
    if (puVar3[0xf] == '\x01') {
      switch(puVar3[0xc]) {
      case 2:
        local_a8[0] = local_b0;
        uVar2 = FUN_600d71c8(iVar1,local_a8);
        break;
      default:
        uVar2 = 3;
        break;
      case 4:
        uVar2 = FUN_600d7250(iVar1,&local_b0);
        break;
      case 5:
        local_a8[0] = local_b0;
        uVar2 = FUN_600d722e(iVar1,local_a8);
        break;
      case 6:
        local_a8[0] = CONCAT22(local_a8[0]._2_2_,(short)local_b0);
        uVar2 = FUN_600d720c(iVar1,local_a8);
        break;
      case 7:
        local_a8[0] = CONCAT31(local_a8[0]._1_3_,(char)local_b0);
        uVar2 = FUN_600d71ea(iVar1,local_a8);
      }
    }
    else {
      uVar2 = 7;
    }
  }
  return uVar2;
}


