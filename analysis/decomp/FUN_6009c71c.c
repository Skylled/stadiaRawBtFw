// 6009c71c  FUN_6009c71c  size=82 bytes
// --- callers ---
//   6009f57c FUN_6009f57c
//   6009ed00 FUN_6009ed00
//   600f1376 FUN_600f1376
// --- callees ---
//   6009c59c FUN_6009c59c
//   6009c444 FUN_6009c444


undefined1 FUN_6009c71c(void)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = DAT_6009c770;
  local_9 = 0;
  if (*(char *)(DAT_6009c770 + 0xe8) != '\0') {
    if (*(char *)(DAT_6009c770 + 0xe8) == '\x01') {
      local_9 = FUN_6009c444(1);
    }
    if (*(char *)(iVar1 + 0xe8) == '\x02') {
      local_9 = FUN_6009c59c(1,*(undefined4 *)(DAT_6009c774 + 0x9c0));
    }
  }
  return local_9;
}


