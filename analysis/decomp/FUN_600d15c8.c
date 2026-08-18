// 600d15c8  FUN_600d15c8  size=28 bytes
// --- callers ---
//   600d201e FUN_600d201e
//   600d190a FUN_600d190a
//   600d1ea2 FUN_600d1ea2
//   60056d74 FUN_60056d74
//   600d6a6e FUN_600d6a6e
//   600567fc FUN_600567fc
// --- callees ---
//   6013d128 thunk_EXT_FUN_00007f58


void FUN_600d15c8(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)thunk_EXT_FUN_00007f58();
  if (puVar1 != (undefined1 *)0x0) {
    puVar2 = puVar1 + param_1;
    for (; puVar1 != puVar2; puVar1 = puVar1 + 1) {
      *puVar1 = 0;
    }
  }
  return;
}


