// 600488d8  FUN_600488d8  size=22 bytes
// --- callers ---
//   600488f4 heap_5_improved__600488f4
// --- callees ---


void FUN_600488d8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = DAT_600488f0;
  iVar2 = *(int *)(param_1 + 4);
  for (puVar3 = (undefined4 *)(param_1 + 8); puVar3 < (undefined4 *)(param_1 + iVar2);
      puVar3 = puVar3 + 1) {
    *puVar3 = uVar1;
  }
  return;
}


