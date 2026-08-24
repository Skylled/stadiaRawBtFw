// 600f1e24  FUN_600f1e24  size=96 bytes
// --- callers ---
//   600f2cd8 FUN_600f2cd8
// --- callees ---
//   6009feb8 FUN_6009feb8
//   600a21e4 FUN_600a21e4


void FUN_600f1e24(undefined2 param_1,ushort param_2)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = FUN_6009feb8(param_1);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0xe) = ~((ushort)~(ushort)(((uint)param_2 << 0x11) >> 0x10) >> 1);
    puVar2 = (ushort *)FUN_600a21e4(iVar1 + 0x10);
    if (puVar2 != (ushort *)0x0) {
      *puVar2 = ~((ushort)~(ushort)(((uint)param_2 << 0x11) >> 0x10) >> 1);
    }
  }
  return;
}


