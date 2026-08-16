// 600c3a88  FUN_600c3a88  size=62 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c3a88(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(DAT_600c3ac8 + 0x138) != 0) {
    uVar1 = FUN_6006dbac(0x24,DAT_600c3acc,0x7c8);
    *(undefined4 *)(DAT_600c3ac8 + 0x138) = uVar1;
    thunk_EXT_FUN_0000b572(*(undefined4 *)(DAT_600c3ac8 + 0x138),param_1,0x24);
  }
  return;
}


