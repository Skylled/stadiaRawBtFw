// 600668dc  keys__600668dc  size=90 bytes
// src: keys.cc
// --- callers ---
//   600db5a8 FUN_600db5a8
// --- callees ---
//   60065eb8 keys__60065eb8
//   60065ccc FUN_60065ccc
//   600d74b0 FUN_600d74b0
//   60101740 FUN_60101740
//   600ce2a0 FUN_600ce2a0


/* src: keys.cc */

undefined4 keys__600668dc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined1 auStack_b0 [156];
  
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    uVar2 = 5;
  }
  else {
    puVar3 = (undefined *)FUN_60065ccc();
    if (puVar3 == PTR_DAT_60066938) {
      FUN_600ce2a0(auStack_b0,PTR_s_CHECK_failed_60122ce9_9_60066940,PTR_s_keys_cc_6006693c,0x3d1);
      FUN_60101740(auStack_b0);
    }
    if (puVar3[0xc] == '\0') {
      if (puVar3[0xd] == '\0') {
        uVar2 = keys__60065eb8(iVar1,param_2,param_3);
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


