// 600c20d0  FUN_600c20d0  size=144 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac


int FUN_600c20d0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_5c [64];
  undefined1 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  
  local_18 = 0;
  local_1c = local_5c;
  thunk_EXT_FUN_0000b572(local_1c,param_2 + 0x10d,0x20);
  thunk_EXT_FUN_0000b572(local_1c + 0x20,param_2 + 0x12d,0x20);
  iVar1 = FUN_6006dbac(0x56,DAT_600c2160,0x29c);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 0xc;
    local_14 = (undefined1 *)(iVar1 + 0x16);
    for (iVar2 = 0; iVar2 < 0x40; iVar2 = iVar2 + 1) {
      *local_14 = local_1c[iVar2];
      local_14 = local_14 + 1;
    }
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 0x41;
  }
  return iVar1;
}


