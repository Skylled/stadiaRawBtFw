// 6009a7c0  FUN_6009a7c0  size=54 bytes
// --- callers ---
//   600b31c4 FUN_600b31c4
// --- callees ---
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250


void FUN_6009a7c0(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_600d9250(DAT_6009a7fc);
    if (iVar1 == 0) break;
    FUN_6006ddd8(iVar1,DAT_6009a7f8,0xe30);
  }
  *(undefined1 *)(DAT_6009a800 + 0x1acc) = 0;
  return;
}


