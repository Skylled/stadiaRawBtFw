// 600f1a0e  FUN_600f1a0e  size=198 bytes
// --- callers ---
//   600c2e9c FUN_600c2e9c
// --- callees ---
//   6009ff18 FUN_6009ff18
//   600f1f82 FUN_600f1f82
//   600a7b44 FUN_600a7b44


void FUN_600f1a0e(undefined4 param_1,char param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint local_c;
  
  iVar2 = FUN_6009ff18(param_1);
  if (iVar2 != 0) {
    if (param_2 == '\0') {
      *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) | 1;
      if (param_3 != 0) {
        for (local_c = 0; local_c < 2; local_c = local_c + 1) {
          *(undefined4 *)(local_c * 4 + iVar2 + 4) = *(undefined4 *)(param_3 + local_c * 4);
        }
      }
      if (*(char *)(iVar2 + 0x51) == '\0') {
        *(undefined1 *)(iVar2 + 0xef) = *(undefined1 *)(*(int *)(iVar2 + 0xf0) + 0x10);
      }
    }
    if (*(char *)(iVar2 + 0x50) == '\x04') {
      *(undefined1 *)(iVar2 + 0x50) = 0;
      if (param_2 == '\0') {
        cVar1 = FUN_600a7b44(iVar2);
        if (cVar1 != '\x01') {
          FUN_600f1f82(iVar2,cVar1,0);
        }
      }
      else {
        FUN_600f1f82(iVar2,param_2,0);
      }
    }
  }
  return;
}


