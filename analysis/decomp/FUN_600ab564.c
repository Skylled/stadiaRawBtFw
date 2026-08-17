// 600ab564  FUN_600ab564  size=180 bytes
// --- callers ---
//   600c6efc FUN_600c6efc
//   600ab9b8 FUN_600ab9b8
//   600ab318 FUN_600ab318
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600afb50 FUN_600afb50
//   600bd730 FUN_600bd730
//   600f672a FUN_600f672a


void FUN_600ab564(undefined2 param_1)

{
  byte bVar1;
  
  bVar1 = FUN_600afb50(param_1);
  if (((bVar1 != 0) && (bVar1 < 10)) &&
     (*(char *)((uint)bVar1 * 0x28 + DAT_600ab618 + 0xaa9) != '\0')) {
    if (*(int *)((uint)bVar1 * 0x28 + DAT_600ab618 + 0xa9c) != 0) {
      FUN_600bd730(*(undefined4 *)((uint)bVar1 * 0x28 + DAT_600ab618 + 0xa9c));
    }
    FUN_600f672a(DAT_600ab61c,(bVar1 + 0xfb) * 0x10 + DAT_600ab618);
    *(undefined1 *)((uint)bVar1 * 0x10 + DAT_600ab618 + 0xfbb) = 0;
    thunk_EXT_FUN_0000b5ba((uint)bVar1 * 0x28 + DAT_600ab618 + 0xa84,0,0x28);
  }
  return;
}


