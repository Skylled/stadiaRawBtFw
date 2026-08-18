// 600c6a3c  FUN_600c6a3c  size=112 bytes
// --- callers ---
//   600c6ad0 FUN_600c6ad0
// --- callees ---
//   600ab088 FUN_600ab088
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d923a thunk_FUN_6006d1ac
//   600ab0d4 FUN_600ab0d4


void FUN_600c6a3c(char *param_1)

{
  int iVar1;
  undefined1 auStack_3c [51];
  char local_9;
  
  local_9 = '\0';
  if (*param_1 == '\0') {
    thunk_EXT_FUN_0000b5ba(param_1,0,0x25c);
    *param_1 = '\x01';
    while (iVar1 = thunk_FUN_6006d1ac(local_9,auStack_3c), iVar1 != 0) {
      FUN_600ab088(auStack_3c);
      thunk_EXT_FUN_0000b5ba(auStack_3c,0,0x30);
      local_9 = local_9 + '\x01';
    }
    FUN_600ab0d4(DAT_600c6aac);
  }
  return;
}


