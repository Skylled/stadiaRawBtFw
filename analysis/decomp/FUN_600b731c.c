// 600b731c  FUN_600b731c  size=84 bytes
// --- callers ---
//   600b7674 FUN_600b7674
//   600b6900 FUN_600b6900
//   600b7b48 FUN_600b7b48
//   600b85c6 FUN_600b85c6
//   600b74d8 FUN_600b74d8
// --- callees ---
//   600aa438 FUN_600aa438


void FUN_600b731c(int param_1)

{
  ushort uVar1;
  undefined4 local_c;
  
  if (*(char *)(param_1 + 0xba) == '\0') {
    uVar1 = *(ushort *)(param_1 + 0x36);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x38);
  }
  local_c = (uint)uVar1;
  if (*(char *)(param_1 + 0x116) == '\0') {
    FUN_600aa438(param_1 + 0x100,3,
                 (uint)((ulonglong)DAT_600b7370 * (ulonglong)(local_c * 10) >> 0x26));
  }
  return;
}


