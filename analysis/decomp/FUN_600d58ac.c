// 600d58ac  FUN_600d58ac  size=226 bytes
// --- callers ---
// --- callees ---
//   6013d268 thunk_EXT_FUN_00006d2c
//   600d55e2 FUN_600d55e2


void FUN_600d58ac(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1c) = 0;
  do {
    iVar1 = thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0x2c4),param_1 + 0x318,0);
  } while (iVar1 == 1);
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x31c) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  do {
    iVar1 = thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0x374),param_1 + 0x3f0,0);
  } while (iVar1 == 1);
  *(undefined1 *)(param_1 + 0x3f0) = 0;
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x3fc) = 0;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x400) = 0;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x404) = 0;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x269) = 0;
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x268) = 0;
  *(undefined1 *)(param_1 + 0x35) = 0;
  *(undefined1 *)(param_1 + 0x36) = 0;
  *(undefined2 *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x99) = 0;
  *(undefined1 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined1 *)(param_1 + 0xfd) = 0;
  *(undefined1 *)(param_1 + 0xfe) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined2 *)(param_1 + 0x108) = 0;
  *(undefined1 *)(param_1 + 0x161) = 0;
  *(undefined1 *)(param_1 + 0x162) = 0;
  *(undefined1 *)(param_1 + 0x1b9) = 0;
  *(undefined1 *)(param_1 + 0x1ba) = 0;
  *(undefined1 *)(param_1 + 0x211) = 0;
  *(undefined1 *)(param_1 + 0x212) = 0;
  *(undefined1 *)(param_1 + 0x163) = 1;
  *(undefined1 *)(param_1 + 0x1bb) = 1;
  *(undefined1 *)(param_1 + 0x213) = 1;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  FUN_600d55e2(param_1);
  return;
}


