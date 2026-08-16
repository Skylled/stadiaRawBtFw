// 600c1cd4  FUN_600c1cd4  size=102 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c1cd4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x26,DAT_600c1d3c,0x181);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 3;
    local_14 = (undefined1 *)(iVar1 + 0x16);
    for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
      *local_14 = *(undefined1 *)(param_2 + iVar2 + 0x2d);
      local_14 = local_14 + 1;
    }
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 0x11;
  }
  return iVar1;
}


