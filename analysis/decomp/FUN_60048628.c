// 60048628  FUN_60048628  size=68 bytes
// --- callers ---
//   600473e4 queue__600473e4
//   600474a4 FUN_600474a4
// --- callees ---
//   6004c084 thunk_FUN_601016a2


void FUN_60048628(void)

{
  bool bVar1;
  undefined4 in_r3;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  if ((0xf < uVar2) && (*(byte *)(uVar2 + DAT_6004866c) < *DAT_60048670)) {
    thunk_FUN_601016a2(DAT_60048678,0x2e8,DAT_60048674);
  }
  if (*DAT_60048680 < (*DAT_6004867c & 0x700)) {
    thunk_FUN_601016a2(DAT_60048678,0x2f8,DAT_60048674,in_r3);
    return;
  }
  return;
}


