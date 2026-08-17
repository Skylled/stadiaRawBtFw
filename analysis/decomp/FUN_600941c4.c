// 600941c4  FUN_600941c4  size=60 bytes
// --- callers ---
//   60093d20 FUN_60093d20
// --- callees ---
//   600a3424 FUN_600a3424
//   600a35e4 FUN_600a35e4


undefined4 FUN_600941c4(undefined4 param_1)

{
  char local_9;
  
  local_9 = '\0';
  FUN_600a35e4(param_1,&local_9);
  if (local_9 != '\x03') {
    FUN_600a3424(*(undefined1 *)(DAT_60094200 + 0x124),param_1,*DAT_60094204 + 0x32);
  }
  return 1;
}


