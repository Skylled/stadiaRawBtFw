// 600866c4  pem_oth__600866c4  size=88 bytes
// src: pem_oth.c
// --- callers ---
//   60086720 FUN_60086720
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e0552 FUN_600e0552
//   60086508 FUN_60086508


/* src: pem_oth.c */

int pem_oth__600866c4(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [2];
  
  local_1c = 0;
  local_18 = 0;
  iVar1 = FUN_60086508(&local_18,local_14,0,param_2,param_3,param_5,param_6);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    local_1c = local_18;
    iVar1 = (*param_1)(param_4,&local_1c,local_14[0]);
    if (iVar1 == 0) {
      FUN_600e0552(9,0,0xc,DAT_6008671c,0x54);
    }
    thunk_EXT_FUN_0000ac5e(local_18);
  }
  return iVar1;
}


