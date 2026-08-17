// 600a16fc  FUN_600a16fc  size=192 bytes
// --- callers ---
//   600f2b6a FUN_600f2b6a
// --- callees ---


void FUN_600a16fc(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_38 [24];
  code *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  byte local_11;
  
  local_20 = *(code **)(DAT_600a17bc + 0x700);
  if (local_20 != (code *)0x0) {
    local_18 = (undefined1 *)(param_1 + 2);
    for (local_11 = 0; local_11 < *(byte *)(param_1 + 1); local_11 = local_11 + 1) {
      local_1c = local_18;
      puVar1 = auStack_38 + 0x15;
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        *puVar1 = *local_1c;
        puVar1 = puVar1 + -1;
        local_1c = local_1c + 1;
      }
      puVar1 = auStack_38 + 0xf;
      for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
        *puVar1 = *local_1c;
        puVar1 = puVar1 + -1;
        local_1c = local_1c + 1;
      }
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        *local_18 = auStack_38[iVar2 + 0x10];
        local_18 = local_18 + 1;
      }
      for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
        *local_18 = auStack_38[iVar2];
        local_18 = local_18 + 1;
      }
    }
    (*local_20)(param_1);
  }
  return;
}


