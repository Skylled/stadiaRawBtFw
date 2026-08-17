// 6009c6d8  FUN_6009c6d8  size=62 bytes
// --- callers ---
//   6009f4e4 FUN_6009f4e4
//   6009abf4 FUN_6009abf4
//   600f7f30 FUN_600f7f30
// --- callees ---
//   6009c59c FUN_6009c59c
//   6009c444 FUN_6009c444


undefined4 FUN_6009c6d8(void)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_6009c718 + 0xe8) == '\x01') {
    uVar1 = FUN_6009c444(0);
  }
  else if (*(char *)(DAT_6009c718 + 0xe8) == '\x02') {
    uVar1 = FUN_6009c59c(0,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


