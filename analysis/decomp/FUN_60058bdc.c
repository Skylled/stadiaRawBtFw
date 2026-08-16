// 60058bdc  FUN_60058bdc  size=34 bytes
// --- callers ---
//   6005ad74 application_state__6005ad74
// --- callees ---
//   600d543c FUN_600d543c


undefined4 FUN_60058bdc(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar1 = DAT_60058c04;
  local_10 = DAT_60058c00;
  uStack_c = param_1;
  FUN_600d543c(DAT_60058c04,&local_10);
  *(undefined4 *)(iVar1 + 0x10) = DAT_60058c08;
  *(undefined4 *)(iVar1 + 0x14) = DAT_60058c0c;
  return 0;
}


