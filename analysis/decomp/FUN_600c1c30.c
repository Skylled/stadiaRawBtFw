// 600c1c30  FUN_600c1c30  size=160 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c1c30(undefined1 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x1c,DAT_600c1cd0,0x161);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = param_1;
    *(undefined1 *)(iVar1 + 0x16) = *(undefined1 *)(param_2 + 0x18e);
    *(undefined1 *)(iVar1 + 0x17) = *(undefined1 *)(param_2 + 400);
    *(undefined1 *)(iVar1 + 0x18) = *(undefined1 *)(param_2 + 0x192);
    *(undefined1 *)(iVar1 + 0x19) = *(undefined1 *)(param_2 + 0x1b1);
    *(undefined1 *)(iVar1 + 0x1a) = *(undefined1 *)(param_2 + 0x1b4);
    *(undefined1 *)(iVar1 + 0x1b) = *(undefined1 *)(param_2 + 0x1b5);
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 7;
  }
  return iVar1;
}


