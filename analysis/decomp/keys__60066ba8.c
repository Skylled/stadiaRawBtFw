// 60066ba8  keys__60066ba8  size=114 bytes
// src: keys.cc
// --- callers ---
//   60078e00 FUN_60078e00
// --- callees ---
//   60101198 FUN_60101198
//   60065ccc FUN_60065ccc
//   60065db0 FUN_60065db0
//   600d74b0 FUN_600d74b0
//   60101740 FUN_60101740
//   60065dd8 FUN_60065dd8
//   600ce2a0 FUN_600ce2a0


/* src: keys.cc */

undefined4 keys__60066ba8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 local_a8 [38];
  
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    uVar2 = 5;
  }
  else {
    puVar3 = (undefined *)FUN_60065ccc();
    if (puVar3 == PTR_DAT_60066c1c) {
      FUN_600ce2a0(local_a8,PTR_s_CHECK_failed_60122ce9_9_60066c24,PTR_s_keys_cc_60066c20,0x458);
      FUN_60101740(local_a8);
    }
    if (puVar3[0xc] == '\x01') {
      if (puVar3[0xf] == '\x01') {
        local_a8[0] = param_2;
        uVar2 = FUN_60065db0(iVar1);
        uVar4 = FUN_60065dd8(iVar1);
        uVar2 = FUN_60101198(uVar2,uVar4,local_a8,4);
      }
      else {
        uVar2 = 7;
      }
    }
    else {
      uVar2 = 3;
    }
  }
  return uVar2;
}


