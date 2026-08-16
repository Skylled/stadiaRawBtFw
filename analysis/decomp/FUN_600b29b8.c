// 600b29b8  FUN_600b29b8  size=144 bytes
// --- callers ---
//   600f03e2 FUN_600f03e2
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


bool FUN_600b29b8(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xe,DAT_600b2a48,0x261);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 6;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x1c;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 3;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(undefined1 *)(iVar1 + 0xd) = param_2;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}


