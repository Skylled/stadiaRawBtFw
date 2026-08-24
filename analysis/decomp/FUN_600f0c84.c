// 600f0c84  FUN_600f0c84  size=170 bytes
// --- callers ---
//   600a6b20 FUN_600a6b20
// --- callees ---
//   600f1f82 FUN_600f1f82
//   600c03d8 FUN_600c03d8
//   600ac22c FUN_600ac22c
//   6009ff18 FUN_6009ff18


void FUN_600f0c84(undefined4 param_1,char param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    bVar2 = *(char *)(iVar1 + 0x50) == '\x02';
    FUN_600c03d8(param_1,param_2);
    if (bVar2) {
      *(undefined1 *)(iVar1 + 0x50) = 0;
    }
    if ((param_2 != '\0') && (*(char *)(iVar1 + 0x61) == '\0')) {
      *(undefined1 *)(iVar1 + 0x61) = *(undefined1 *)(iVar1 + 0xd9);
    }
    if ((*(int *)(iVar1 + 0xf4) != 0) && (bVar2)) {
      if (param_2 == '\0') {
        if (*(char *)(iVar1 + 0x52) != '\0') {
          FUN_600f1f82(iVar1,10,1);
        }
      }
      else {
        FUN_600f1f82(iVar1,0,1);
      }
    }
    FUN_600ac22c(iVar1 + 100);
  }
  return;
}


