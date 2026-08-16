// 6009a8ec  FUN_6009a8ec  size=210 bytes
// --- callers ---
//   600fd210 FUN_600fd210
// --- callees ---
//   600b1640 FUN_600b1640
//   600a031c FUN_600a031c


undefined1 FUN_6009a8ec(char param_1)

{
  bool bVar1;
  undefined1 local_9;
  
  local_9 = 0;
  bVar1 = false;
  if (param_1 == '\0') {
    if ((*(byte *)(DAT_6009a9c0 + 0x81b) & 2) != 0) {
      FUN_600b1640(0,0);
      *(byte *)(DAT_6009a9c0 + 0x81b) = *(byte *)(DAT_6009a9c0 + 0x81b) & 0xfb;
      *(byte *)(DAT_6009a9c0 + 0x81b) = *(byte *)(DAT_6009a9c0 + 0x81b) & 0xfd;
      bVar1 = true;
    }
  }
  else if ((*(byte *)(DAT_6009a9c0 + 0x817) & 0x40) == 0) {
    local_9 = 10;
  }
  else if ((*(byte *)(DAT_6009a9c0 + 0x81b) & 2) == 0) {
    *(byte *)(DAT_6009a9c0 + 0x81b) = *(byte *)(DAT_6009a9c0 + 0x81b) | 2;
    *(byte *)(DAT_6009a9c0 + 0x81b) = *(byte *)(DAT_6009a9c0 + 0x81b) | 4;
    FUN_600b1640(1,1);
    bVar1 = true;
  }
  if (bVar1) {
    *(byte *)(DAT_6009a9c0 + 0x88e) = *(byte *)(DAT_6009a9c0 + 0x88e) | 0x10;
    FUN_600a031c(1);
  }
  return local_9;
}


