// 6009f644  FUN_6009f644  size=120 bytes
// --- callers ---
//   6009dc14 FUN_6009dc14
//   6009f8c8 FUN_6009f8c8
//   6009f990 FUN_6009f990
//   600b59ec FUN_600b59ec
//   600979e4 FUN_600979e4
//   6009daac FUN_6009daac
//   6009cad8 FUN_6009cad8
//   6009b368 FUN_6009b368
//   6009f6c0 FUN_6009f6c0
//   600b5720 FUN_600b5720
//   600b56aa FUN_600b56aa
// --- callees ---
//   6009f57c FUN_6009f57c
//   6009f5d0 FUN_6009f5d0


undefined4 FUN_6009f644(byte param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = *(char *)(DAT_6009f6bc + 0xa80);
  if (*(char *)(DAT_6009f6bc + 0xa6b) == '\0') {
    uVar3 = 0;
  }
  else {
    *(byte *)(DAT_6009f6bc + 0xa80) = ~param_1 & *(byte *)(DAT_6009f6bc + 0xa80);
    if ((cVar1 == '\0') || (*(char *)(DAT_6009f6bc + 0xa80) != '\0')) {
      uVar3 = 1;
    }
    else {
      iVar2 = FUN_6009f5d0();
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        if (param_2 != '\0') {
          FUN_6009f57c();
        }
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}


