// 6009f08c  FUN_6009f08c  size=148 bytes
// --- callers ---
//   6009f8c8 FUN_6009f8c8
//   6009f6c0 FUN_6009f6c0
// --- callees ---
//   6009efa0 FUN_6009efa0
//   6009ff18 FUN_6009ff18
//   6009f004 FUN_6009f004


void FUN_6009f08c(undefined4 param_1,char param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_6009ff18(param_1);
  if (iVar2 != 0) {
    if (param_2 == '\0') {
      *(byte *)(iVar2 + 0x72) = *(byte *)(iVar2 + 0x72) & 0xfd;
      if ((*(byte *)(DAT_6009f120 + 0x831) & 0x40) == 0) {
        FUN_6009efa0(*(undefined1 *)(iVar2 + 0x73));
        *(undefined1 *)(iVar2 + 0x73) = 0;
      }
    }
    else {
      *(byte *)(iVar2 + 0x72) = *(byte *)(iVar2 + 0x72) | 2;
      if ((*(byte *)(DAT_6009f120 + 0x831) & 0x40) == 0) {
        uVar1 = FUN_6009f004();
        *(undefined1 *)(iVar2 + 0x73) = uVar1;
      }
    }
  }
  return;
}


