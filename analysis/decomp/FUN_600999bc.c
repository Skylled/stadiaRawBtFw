// 600999bc  FUN_600999bc  size=90 bytes
// --- callers ---
//   60098f88 FUN_60098f88
// --- callees ---
//   60098f34 FUN_60098f34
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600b2934 FUN_600b2934


void FUN_600999bc(undefined2 param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = FUN_60098f34(param_1);
  if (bVar1 < 4) {
    iVar2 = (uint)bVar1 * 0x14c + 0x110 + DAT_60099a18;
    *(undefined1 *)(iVar2 + 0x126) = 0;
    thunk_EXT_FUN_0000b5ba(iVar2 + 0x10e,0,0x18);
    FUN_600b2934(param_1);
  }
  return;
}


