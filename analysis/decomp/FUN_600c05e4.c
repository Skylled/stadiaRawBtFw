// 600c05e4  FUN_600c05e4  size=86 bytes
// --- callers ---
//   600a4820 FUN_600a4820
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600c1a34 FUN_600c1a34


undefined1 FUN_600c05e4(undefined4 param_1)

{
  int iVar1;
  undefined1 local_11;
  int local_10;
  undefined1 local_9;
  
  local_10 = DAT_600c063c;
  local_11 = 8;
  local_9 = 0;
  if ((*(char *)(DAT_600c063c + 0x23) != '\0') &&
     (iVar1 = thunk_EXT_FUN_0000b554(DAT_600c063c + 0x1d,param_1,6), iVar1 == 0)) {
    *(undefined1 *)(local_10 + 0x1fa) = 1;
    FUN_600c1a34(local_10,0x17,&local_11);
    local_9 = 1;
  }
  return local_9;
}


