// 600edb2a  FUN_600edb2a  size=68 bytes
// --- callers ---
//   600edc0e FUN_600edc0e
//   600edbf4 FUN_600edbf4
// --- callees ---


undefined4 * FUN_600edb2a(int param_1,uint *param_2,undefined4 param_3,code *param_4,code *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = (*param_4)(*(undefined4 *)(param_1 + 0x14),param_3);
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar1;
  }
  iVar2 = uVar1 - *(uint *)(param_1 + 8) * (uVar1 / *(uint *)(param_1 + 8));
  puVar4 = (undefined4 *)(*(int *)(param_1 + 4) + iVar2 * 4);
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 4) + iVar2 * 4);
  while ((puVar3 != (undefined4 *)0x0 &&
         (iVar2 = (*param_5)(*(undefined4 *)(param_1 + 0x10),*puVar3,param_3), iVar2 != 0))) {
    puVar4 = puVar3 + 1;
    puVar3 = (undefined4 *)puVar3[1];
  }
  return puVar4;
}


