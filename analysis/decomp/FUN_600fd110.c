// 600fd110  FUN_600fd110  size=58 bytes
// --- callers ---
// --- callees ---
//   600c3f04 FUN_600c3f04
//   600a21e4 FUN_600a21e4


void FUN_600fd110(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600a21e4(param_1 + 8);
  if ((iVar1 != 0) && (*(char *)(param_1 + 0xe) != '\0')) {
    *(undefined1 *)(iVar1 + 0x14) = 1;
  }
  FUN_600c3f04(param_1 + 8);
  return;
}


