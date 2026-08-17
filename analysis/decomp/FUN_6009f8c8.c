// 6009f8c8  FUN_6009f8c8  size=112 bytes
// --- callers ---
//   600f2080 FUN_600f2080
// --- callees ---
//   6009ee8c FUN_6009ee8c
//   6009f08c FUN_6009f08c
//   6009f2ec FUN_6009f2ec
//   6009f644 FUN_6009f644
//   6009f93c FUN_6009f93c


void FUN_6009f8c8(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(DAT_6009f938 + 0xa80);
  if ((cVar1 == '\0') || (iVar2 = FUN_6009f644(cVar1,0), iVar2 != 0)) {
    if (((*(byte *)(param_1 + 0x72) & 2) != 0) &&
       (iVar2 = FUN_6009ee8c(param_1 + 0x10,3), iVar2 == 0)) {
      FUN_6009f08c(param_1 + 0x10,0);
      FUN_6009f2ec(param_1);
    }
    if (cVar1 != '\0') {
      FUN_6009f93c(cVar1);
    }
  }
  return;
}


