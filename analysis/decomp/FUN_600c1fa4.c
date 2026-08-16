// 600c1fa4  FUN_600c1fa4  size=102 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c1fa4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x26,DAT_600c200c,0x241);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 10;
    local_14 = (undefined1 *)(iVar1 + 0x16);
    for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
      *local_14 = *(undefined1 *)(param_2 + iVar2 + 0x1d8);
      local_14 = local_14 + 1;
    }
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 0x11;
  }
  return iVar1;
}


