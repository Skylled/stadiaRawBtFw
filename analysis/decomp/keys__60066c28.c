// 60066c28  keys__60066c28  size=162 bytes
// src: keys.cc
// --- callers ---
//   60078e00 FUN_60078e00
// --- callees ---
//   600d7162 FUN_600d7162
//   600d6ea8 FUN_600d6ea8
//   600d71a6 FUN_600d71a6
//   600d7184 FUN_600d7184
//   60065ccc FUN_60065ccc
//   600d74b0 FUN_600d74b0
//   600d7140 FUN_600d7140
//   60101740 FUN_60101740
//   600ce2a0 FUN_600ce2a0


/* src: keys.cc */

undefined4
keys__60066c28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
    if (puVar3 == PTR_DAT_60066cd4) {
      FUN_600ce2a0(local_a8,PTR_s_CHECK_failed_60122ce9_9_60066cdc,PTR_s_keys_cc_60066cd8,0x465);
      FUN_60101740(local_a8);
    }
    if (puVar3[0xf] == '\x01') {
      switch(puVar3[0xc]) {
      case 3:
        local_a8[0] = local_b0;
        uVar2 = FUN_600d6ea8(iVar1,local_a8);
        break;
      default:
        uVar2 = 3;
        break;
      case 8:
        uVar2 = FUN_600d71a6(iVar1,&local_b0);
        break;
      case 9:
        local_a8[0] = local_b0;
        uVar2 = FUN_600d7184(iVar1,local_a8);
        break;
      case 10:
        local_a8[0] = CONCAT22(local_a8[0]._2_2_,(short)local_b0);
        uVar2 = FUN_600d7162(iVar1,local_a8);
        break;
      case 0xb:
        local_a8[0] = CONCAT31(local_a8[0]._1_3_,(char)local_b0);
        uVar2 = FUN_600d7140(iVar1,local_a8);
      }
    }
    else {
      uVar2 = 7;
    }
  }
  return uVar2;
}


