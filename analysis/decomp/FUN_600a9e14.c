// 600a9e14  FUN_600a9e14  size=78 bytes
// --- callers ---
//   600a01c4 FUN_600a01c4
// --- callees ---
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8


void FUN_600a9e14(void)

{
  int iVar1;
  
  *(undefined2 *)(DAT_600a9e64 + 0xb8) = 0;
  while (iVar1 = FUN_600d9250(DAT_600a9e6c), iVar1 != 0) {
    FUN_6006ddd8(iVar1,DAT_600a9e68,0xbbf);
  }
  while (iVar1 = FUN_600d9250(DAT_600a9e70), iVar1 != 0) {
    FUN_6006ddd8(iVar1,DAT_600a9e68,0xbc3);
  }
  return;
}


