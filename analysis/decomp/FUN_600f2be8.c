// 600f2be8  FUN_600f2be8  size=60 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a7634 FUN_600a7634


void FUN_600f2be8(undefined1 *param_1)

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
  FUN_600a7634(auStack_18);
  return;
}


