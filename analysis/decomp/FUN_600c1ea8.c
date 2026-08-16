// 600c1ea8  FUN_600c1ea8  size=114 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac
//   6009abb4 FUN_6009abb4


int FUN_600c1ea8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_28 [16];
  int local_18;
  undefined1 *local_14;
  
  local_18 = 0;
  local_18 = FUN_6006dbac(0x26,DAT_600c1f1c,0x205,0,param_2);
  if (local_18 != 0) {
    local_14 = (undefined1 *)(local_18 + 0x15);
    FUN_6009abb4(auStack_28);
    *local_14 = 8;
    for (iVar1 = 0; local_14 = local_14 + 1, iVar1 < 0x10; iVar1 = iVar1 + 1) {
      *local_14 = auStack_28[iVar1];
    }
    *(undefined2 *)(local_18 + 4) = 0xd;
    *(undefined2 *)(local_18 + 2) = 0x11;
  }
  return local_18;
}


