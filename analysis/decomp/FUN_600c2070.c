// 600c2070  FUN_600c2070  size=90 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c2070(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x17,DAT_600c20cc,0x277);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 0xb;
    *(undefined1 *)(iVar1 + 0x16) = *(undefined1 *)(param_2 + 0x192);
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 2;
  }
  return iVar1;
}


