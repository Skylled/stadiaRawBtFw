// 600c03d8  FUN_600c03d8  size=82 bytes
// --- callers ---
//   600f0c84 FUN_600f0c84
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600c1a34 FUN_600c1a34
//   600f096a FUN_600f096a


void FUN_600c03d8(undefined4 param_1,char param_2)

{
  int iVar1;
  char local_15;
  undefined4 local_14;
  int local_c;
  
  local_c = DAT_600c042c;
  local_15 = param_2;
  local_14 = param_1;
  iVar1 = thunk_EXT_FUN_0000b554(DAT_600c0430,param_1,6);
  if (iVar1 == 0) {
    if ((*(char *)(local_c + 0x1b1) != '\0') && (local_15 != '\0')) {
      FUN_600f096a(local_14,*(undefined1 *)(local_c + 0x1b1));
    }
    FUN_600c1a34(DAT_600c042c,0x11,&local_15);
  }
  return;
}


