// 600c073c  FUN_600c073c  size=114 bytes
// --- callers ---
//   600f06dc FUN_600f06dc
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600c1a34 FUN_600c1a34
//   6009ff18 FUN_6009ff18


void FUN_600c073c(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined1 local_d;
  int local_c;
  
  local_c = DAT_600c07b0;
  local_d = 0xc;
  if (((*(char *)(DAT_600c07b0 + 0x2a) == '\x06') &&
      (iVar1 = thunk_EXT_FUN_0000b554(param_1,DAT_600c07b0 + 0x1d,6), iVar1 == 0)) &&
     (iVar1 = FUN_6009ff18(param_1), iVar1 != 0)) {
    if (param_2 == '\0') {
      FUN_600c1a34(local_c,0x23,0);
    }
    else {
      FUN_600c1a34(local_c,0x17,&local_d);
    }
  }
  return;
}


