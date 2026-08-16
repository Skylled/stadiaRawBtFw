// 600a86d0  FUN_600a86d0  size=150 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   60058060 FUN_60058060
//   6006ddd8 FUN_6006ddd8
//   6006dbac FUN_6006dbac
//   600cdd2c FUN_600cdd2c


void FUN_600a86d0(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  ushort local_10;
  ushort local_e;
  undefined1 *local_c;
  
  local_10 = 0;
  iVar2 = FUN_6006dbac(*(short *)(param_2 + 2) * 3,DAT_600a8768,0x116);
  if (iVar2 == 0) {
    FUN_60058060(DAT_600a8774,DAT_600a8768);
  }
  else {
    local_e = 0;
    local_c = (undefined1 *)(param_2 + 8);
    while( true ) {
      if (*(ushort *)(param_2 + 2) <= local_e) break;
      sVar1 = FUN_600cdd2c(iVar2 + (uint)local_10,DAT_600a876c,*local_c);
      local_10 = local_10 + sVar1;
      local_e = local_e + 1;
      local_c = local_c + 1;
    }
    FUN_60058060(DAT_600a8770,iVar2);
    FUN_6006ddd8(iVar2,DAT_600a8768,0x120);
  }
  return;
}


