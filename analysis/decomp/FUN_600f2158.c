// 600f2158  FUN_600f2158  size=98 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600b8ba4 FUN_600b8ba4
//   600a730c FUN_600a730c


void FUN_600f2158(int param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar1 = *(undefined1 *)(param_1 + 3);
  uVar2 = (ushort)(((uint)(ushort)((ushort)*(byte *)(param_1 + 2) * 0x100 +
                                  (ushort)*(byte *)(param_1 + 1)) << 0x14) >> 0x14);
  FUN_600b8ba4(uVar2,uVar1);
  FUN_600a730c(uVar2,uVar1);
  return;
}


