// 600c1f20  FUN_600c1f20  size=128 bytes
// --- callers ---
// --- callees ---
//   600a1218 FUN_600a1218
//   6006dbac FUN_6006dbac


int FUN_600c1f20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_20 [8];
  int local_18;
  undefined1 *local_14;
  
  local_18 = 0;
  local_18 = FUN_6006dbac(0x1d,DAT_600c1fa0,0x224,0,param_2);
  if (local_18 != 0) {
    *(undefined1 *)(local_18 + 0x15) = 9;
    local_14 = (undefined1 *)(local_18 + 0x17);
    *(undefined1 *)(local_18 + 0x16) = 0;
    FUN_600a1218(auStack_20);
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      *local_14 = auStack_20[5 - iVar1];
      local_14 = local_14 + 1;
    }
    *(undefined2 *)(local_18 + 4) = 0xd;
    *(undefined2 *)(local_18 + 2) = 8;
  }
  return local_18;
}


