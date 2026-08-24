// 600f2a7a  FUN_600f2a7a  size=102 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   60099dd0 FUN_60099dd0
//   600b9358 FUN_600b9358


void FUN_600f2a7a(undefined1 *param_1)

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
  local_13[1] = *local_1c;
  FUN_600b9358(auStack_18,local_13[1],local_13[2]);
  FUN_60099dd0(local_13[2],auStack_18,local_13[1]);
  return;
}


