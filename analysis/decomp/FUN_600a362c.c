// 600a362c  FUN_600a362c  size=174 bytes
// --- callers ---
//   600a02b4 FUN_600a02b4
// --- callees ---


void FUN_600a362c(void)

{
  byte bVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = (code *)0x0;
  if ((*(char *)(DAT_600a36dc + 0x6ed) != -0x80) &&
     ((*(byte *)((*(byte *)(DAT_600a36dc + 0x6ed) + 0xdb) * 8 + DAT_600a36dc + 8) & 2) != 0)) {
    local_18 = *(code **)((*(byte *)(DAT_600a36dc + 0x6ed) + 0xdb) * 8 + DAT_600a36dc + 4);
  }
  bVar1 = *(byte *)(DAT_600a36dc + 0x6ec);
  *(undefined1 *)(DAT_600a36dc + 0x6ec) = 4;
  for (local_14 = 0; local_14 < 1; local_14 = local_14 + 1) {
    *(undefined1 *)((local_14 + 0xdb) * 8 + DAT_600a36dc + 8) = 0;
  }
  if (local_18 != (code *)0x0) {
    if (bVar1 < 4) {
      (*local_18)((uint)bVar1 * 0x14c + DAT_600a36dc + 0x116,6,0xc,0);
    }
    else {
      (*local_18)(DAT_600a36e0,6,0xc,0);
    }
  }
  return;
}


