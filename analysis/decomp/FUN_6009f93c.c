// 6009f93c  FUN_6009f93c  size=78 bytes
// --- callers ---
//   6009f8c8 FUN_6009f8c8
//   6009f6c0 FUN_6009f6c0
//   600b59ec FUN_600b59ec
//   600979e4 FUN_600979e4
//   6009cad8 FUN_6009cad8
//   6009f990 FUN_6009f990
// --- callees ---
//   6009f57c FUN_6009f57c
//   6009f60c FUN_6009f60c


void FUN_6009f93c(byte param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_6009f98c + 0xa80);
  *(byte *)(DAT_6009f98c + 0xa80) = param_1 | *(byte *)(DAT_6009f98c + 0xa80);
  if (((cVar1 == '\0') && (*(char *)(DAT_6009f98c + 0xa80) != '\0')) &&
     (*(char *)(DAT_6009f98c + 0xa6b) != '\0')) {
    FUN_6009f60c();
    FUN_6009f57c();
  }
  return;
}


