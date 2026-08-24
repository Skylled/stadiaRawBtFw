// 600f2ba2  FUN_600f2ba2  size=70 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600f8bd4 FUN_600f8bd4
//   600a7870 FUN_600a7870


void FUN_600f2ba2(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *local_1c;
  undefined1 auStack_18 [5];
  undefined1 local_13 [3];
  
  puVar1 = local_13;
  local_1c = param_1;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *puVar1 = *local_1c;
    puVar1 = puVar1 + -1;
    local_1c = local_1c + 1;
  }
  FUN_600f8bd4(auStack_18);
  FUN_600a7870(auStack_18);
  return;
}


