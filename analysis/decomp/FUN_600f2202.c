// 600f2202  FUN_600f2202  size=96 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a30f0 FUN_600a30f0
//   600a59d0 FUN_600a59d0


void FUN_600f2202(undefined1 *param_1,short param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *local_1c;
  undefined1 auStack_18 [5];
  undefined1 local_13 [3];
  
  local_13[2] = *param_1;
  puVar1 = local_13;
  for (iVar2 = 0; local_1c = param_1 + 1, iVar2 < 6; iVar2 = iVar2 + 1) {
    *puVar1 = *local_1c;
    puVar1 = puVar1 + -1;
    param_1 = local_1c;
  }
  FUN_600a30f0(auStack_18,local_1c,param_2 + -7,local_13[2]);
  FUN_600a59d0(auStack_18,local_1c,local_13[2]);
  return;
}


