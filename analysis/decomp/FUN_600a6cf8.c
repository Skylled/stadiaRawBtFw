// 600a6cf8  FUN_600a6cf8  size=114 bytes
// --- callers ---
// --- callees ---
//   600a5964 FUN_600a5964
//   600a8108 FUN_600a8108


void FUN_600a6cf8(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_600a6d6c + 0x114c);
  *(undefined4 *)(DAT_600a6d6c + 0x1160) = 0;
  *(undefined4 *)(DAT_600a6d6c + 0x114c) = 0;
  iVar1 = FUN_600a5964(iVar2);
  if ((iVar1 != 1) && (FUN_600a8108(0), *(int *)(DAT_600a6d6c + 0x1128) != 0)) {
    (**(code **)(DAT_600a6d6c + 0x1128))(iVar2 + 0x10,iVar2 + 0x16,iVar2 + 0x2c,7);
  }
  return;
}


