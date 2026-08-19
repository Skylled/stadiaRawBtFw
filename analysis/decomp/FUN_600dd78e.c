// 600dd78e  FUN_600dd78e  size=60 bytes
// --- callers ---
// --- callees ---
//   6007d78c FUN_6007d78c


void FUN_600dd78e(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  
  puVar3 = param_1;
  piVar4 = param_2;
  for (uVar2 = 0; uVar2 < *param_1; uVar2 = uVar2 + 1) {
    iVar1 = uVar2 * 0xc;
    puVar3 = (uint *)((uint)puVar3 & 0xffffff00);
    FUN_6007d78c(iVar1 + param_1[1],*(undefined4 *)(param_1[1] + iVar1),
                 *(undefined4 *)(*param_2 + iVar1),*(undefined4 *)(*param_2 + iVar1 + 4),puVar3,
                 piVar4);
  }
  return;
}


