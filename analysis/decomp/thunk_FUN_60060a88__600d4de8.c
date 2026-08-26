// 600d4de8  thunk_FUN_60060a88__600d4de8  size=4 bytes
// --- callers ---
// --- callees ---


uint thunk_FUN_60060a88__600d4de8(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_60060ad0;
  if ((*DAT_60060ad0 & 0x40) == 0) {
    uVar2 = FUN_600526a0(DAT_60060ad4);
    uVar2 = (uint)(((ulonglong)uVar2 / 6) / (ulonglong)((*puVar1 & 0x3f) + 1));
  }
  else {
    uVar2 = DAT_60060ae0;
    if (-1 < *(int *)(DAT_60060ad8 + 0x270) << 0x1b) {
      uVar2 = *DAT_60060adc;
    }
    uVar2 = uVar2 / ((*DAT_60060ad0 & 0x3f) + 1);
  }
  return uVar2;
}


