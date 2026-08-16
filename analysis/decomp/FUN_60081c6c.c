// 60081c6c  FUN_60081c6c  size=74 bytes
// --- callers ---
//   60080ba4 FUN_60080ba4
// --- callees ---
//   60081ab4 gatt_server__60081ab4
//   6006a21c adapter__6006a21c
//   600696d0 adapter__600696d0


uint FUN_60081c6c(undefined1 *param_1)

{
  uint uVar1;
  
  uVar1 = gatt_server__60081ab4();
  if ((uVar1 & 0xff) == 0) {
    if ((*(char *)(DAT_60081cb8 + 0x1854) == '\x02') ||
       (uVar1 = adapter__6006a21c(DAT_60081cbc), (uVar1 & 0xff) == 0)) {
      uVar1 = adapter__600696d0(DAT_60081cbc,*DAT_60081cc0,DAT_60081cc0[1],DAT_60081cc0[2],
                                DAT_60081cc0[3],DAT_60081cc0[4]);
      if ((uVar1 & 0xff) == 0) {
        *param_1 = 1;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


