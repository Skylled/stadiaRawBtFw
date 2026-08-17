// 6009f57c  FUN_6009f57c  size=80 bytes
// --- callers ---
//   6009f93c FUN_6009f93c
//   6009f644 FUN_6009f644
// --- callees ---
//   6009e84c FUN_6009e84c
//   6009c71c FUN_6009c71c
//   6009e6c0 FUN_6009e6c0


void FUN_6009f57c(void)

{
  int iVar1;
  
  iVar1 = DAT_6009f5cc;
  if ((*(byte *)(DAT_6009f5cc + 0x19d) & 4) != 0) {
    FUN_6009e84c();
  }
  if ((*(byte *)(iVar1 + 0x19d) & 2) != 0) {
    FUN_6009e6c0();
  }
  if ((*(byte *)(iVar1 + 0x19d) & 1) != 0) {
    FUN_6009c71c();
  }
  *(undefined1 *)(iVar1 + 0x19d) = 0;
  return;
}


