// 600eebd8  FUN_600eebd8  size=130 bytes
// --- callers ---
//   60094a3c FUN_60094a3c
// --- callees ---


undefined1 FUN_600eebd8(int param_1,short param_2,short param_3)

{
  int iVar1;
  undefined1 local_12;
  byte local_11;
  
  local_12 = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    local_12 = 1;
  }
  else {
    for (local_11 = 0; local_11 < *(byte *)(param_1 + 0x2e); local_11 = local_11 + 1) {
      iVar1 = (uint)local_11 * 0x1c + *(int *)(param_1 + 0x28);
      if ((param_2 == *(short *)(iVar1 + 0x14)) || (param_3 == *(short *)(iVar1 + 0x16))) {
        return 1;
      }
    }
  }
  return local_12;
}


