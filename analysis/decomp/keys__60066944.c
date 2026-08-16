// 60066944  keys__60066944  size=88 bytes
// src: keys.cc
// --- callers ---
//   600db5a8 FUN_600db5a8
// --- callees ---
//   60065ccc FUN_60065ccc
//   600d74b0 FUN_600d74b0
//   60101740 FUN_60101740
//   600d72ec FUN_600d72ec
//   600ce2a0 FUN_600ce2a0


/* src: keys.cc */

undefined4 keys__60066944(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined1 auStack_a8 [152];
  
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    uVar2 = 5;
  }
  else {
    puVar3 = (undefined *)FUN_60065ccc();
    if (puVar3 == PTR_DAT_6006699c) {
      FUN_600ce2a0(auStack_a8,PTR_s_CHECK_failed_60122ce9_9_600669a4,PTR_s_keys_cc_600669a0,0x3de);
      FUN_60101740(auStack_a8);
    }
    if (puVar3[0xc] == '\x01') {
      if (puVar3[0xd] == '\0') {
        uVar2 = FUN_600d72ec(iVar1,param_2);
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


