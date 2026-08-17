// 600a58f0  FUN_600a58f0  size=110 bytes
// --- callers ---
//   600b6378 FUN_600b6378
//   600b61c4 FUN_600b61c4
// --- callees ---
//   6009ff18 FUN_6009ff18


void FUN_600a58f0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    if (*(int *)(DAT_600a5960 + 0x112c) != 0) {
      (**(code **)(DAT_600a5960 + 0x112c))(param_1,iVar1 + 0x16,iVar1 + 0x2c);
    }
    if ((*(char *)(iVar1 + 0x50) == '\x04') || (*(char *)(iVar1 + 0x50) == '\x01')) {
      *(undefined1 *)(iVar1 + 0x50) = 0;
      *(undefined4 *)(iVar1 + 0xf4) = 0;
    }
  }
  return;
}


