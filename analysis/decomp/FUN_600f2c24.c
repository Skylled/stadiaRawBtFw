// 600f2c24  FUN_600f2c24  size=108 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a74dc FUN_600a74dc


void FUN_600f2c24(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *local_2c;
  undefined1 auStack_28 [15];
  undefined1 local_19 [6];
  undefined1 local_13 [3];
  
  puVar1 = local_13;
  local_2c = param_1;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *puVar1 = *local_2c;
    puVar1 = puVar1 + -1;
    local_2c = local_2c + 1;
  }
  puVar1 = local_19;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *puVar1 = *local_2c;
    puVar1 = puVar1 + -1;
    local_2c = local_2c + 1;
  }
  local_13[2] = *local_2c;
  FUN_600a74dc(local_19 + 1,auStack_28,local_13[2]);
  return;
}


