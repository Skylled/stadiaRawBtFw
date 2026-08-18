// 600d2b0e  FUN_600d2b0e  size=94 bytes
// --- callers ---
//   600d2bb0 FUN_600d2bb0
//   600d2b6c FUN_600d2b6c
// --- callees ---
//   600d2a6e FUN_600d2a6e


int FUN_600d2b0e(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint *puVar1;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar2;
  
  iVar4 = 0;
  while( true ) {
    puVar1 = param_2 + 1;
    do {
      puVar2 = puVar1 + 1;
      iVar4 = iVar4 + ((*puVar1 & 0xfffffff) >> 0x10);
      puVar1 = puVar2;
    } while (param_2 + 9 != puVar2);
    FUN_600d2a6e(*(undefined4 *)(param_1 + 8),param_2,*(undefined2 *)(param_2 + 0x11));
    for (puVar3 = param_2; puVar3 != param_2 + 0x18; puVar3 = puVar3 + 1) {
      *puVar3 = 0;
    }
    *param_2 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 **)(param_1 + 0x18) = param_2;
    *(char *)(param_1 + 0x47) = *(char *)(param_1 + 0x47) + '\x01';
    if (param_2 == param_3) break;
    param_2 = (undefined4 *)param_2[0x10];
  }
  return iVar4;
}


