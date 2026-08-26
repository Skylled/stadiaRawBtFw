// 600d76ca  FUN_600d76ca  size=72 bytes
// --- callers ---
// --- callees ---


int FUN_600d76ca(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 4);
  if (param_2 < uVar3) {
    param_2 = param_2 - uVar3 * (param_2 / uVar3);
    uVar3 = 0;
    puVar1 = *(undefined4 **)(param_1 + 0xf8);
    while ((uint)puVar1[1] <= param_2) {
      param_2 = param_2 - puVar1[1];
      uVar3 = (uVar3 + 1) % 9;
      puVar1 = *(undefined4 **)(param_1 + uVar3 * 4 + 0xf8);
    }
    iVar2 = (**(code **)*puVar1)();
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 8);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


