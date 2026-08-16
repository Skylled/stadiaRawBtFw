// 600c1e18  FUN_600c1e18  size=138 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c1e18(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x20,DAT_600c1ea4,0x1e9);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 7;
    *(char *)(iVar1 + 0x16) = (char)*(undefined2 *)(param_2 + 0x1e8);
    *(char *)(iVar1 + 0x17) = (char)((ushort)*(undefined2 *)(param_2 + 0x1e8) >> 8);
    local_14 = (undefined1 *)(iVar1 + 0x18);
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      *local_14 = *(undefined1 *)(param_2 + iVar2 + 0x1ea);
      local_14 = local_14 + 1;
    }
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 0xb;
  }
  return iVar1;
}


