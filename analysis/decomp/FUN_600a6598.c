// 600a6598  FUN_600a6598  size=86 bytes
// --- callers ---
//   600f2e82 FUN_600f2e82
// --- callees ---


void FUN_600a6598(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *local_1c;
  undefined1 auStack_18 [5];
  undefined1 local_13 [3];
  
  if (*(int *)(DAT_600a65f0 + 0x1134) != 0) {
    puVar1 = local_13;
    local_1c = param_1;
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      *puVar1 = *local_1c;
      puVar1 = puVar1 + -1;
      local_1c = local_1c + 1;
    }
    local_13[1] = *local_1c;
    (**(code **)(DAT_600a65f0 + 0x1134))(5,auStack_18);
  }
  return;
}


