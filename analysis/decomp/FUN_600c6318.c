// 600c6318  FUN_600c6318  size=100 bytes
// --- callers ---
//   600fe960 FUN_600fe960
//   600feaca FUN_600feaca
//   600fdf94 FUN_600fdf94
//   600fe05a FUN_600fe05a
//   600fea16 FUN_600fea16
// --- callees ---
//   60094d24 FUN_60094d24


void FUN_600c6318(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = DAT_600c637c;
  for (local_9 = 0; local_9 < 6; local_9 = local_9 + 1) {
    if (param_1 == *(int *)((local_9 + 0x25) * 0x20 + iVar1)) {
      *(undefined1 *)((uint)local_9 * 0x20 + iVar1 + 0x4ad) = param_2;
      FUN_60094d24((uint)local_9 * 0x20 + 0x490 + iVar1,0x1d0f,0);
    }
  }
  return;
}


