// 6004bbfe  FUN_6004bbfe  size=42 bytes
// --- callers ---
//   60047548 FUN_60047548
// --- callees ---


void FUN_6004bbfe(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  iVar3 = param_1[0x10];
  if (iVar3 == 0) {
    return;
  }
  iVar1 = param_1[3];
  param_1[3] = iVar1 + iVar3;
  if ((uint)param_1[1] <= (uint)(iVar1 + iVar3)) {
    param_1[3] = *param_1;
  }
  puVar2 = (undefined1 *)param_1[3];
  puVar5 = (undefined1 *)(param_2 + -1);
  puVar4 = puVar2 + iVar3;
  for (; puVar2 != puVar4; puVar2 = puVar2 + 1) {
    puVar5 = puVar5 + 1;
    *puVar5 = *puVar2;
  }
  return;
}


