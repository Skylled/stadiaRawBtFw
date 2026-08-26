// 60100e08  FUN_60100e08  size=112 bytes
// --- callers ---
//   60100ed8 FUN_60100ed8
//   60100ffc FUN_60100ffc
//   60101198 FUN_60101198
// --- callees ---
//   60100b96 FUN_60100b96
//   60100b38 FUN_60100b38


int FUN_60100e08(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar1 = FUN_60100b96();
  if (param_2 <= uVar1) {
    uVar1 = 0xffffffff;
    puVar7 = (uint *)(param_1 + 0x1a);
    for (uVar5 = 0; uVar2 = FUN_60100b38(*param_1), uVar5 < uVar2; uVar5 = uVar5 + 1) {
      uVar6 = *puVar7;
      uVar2 = FUN_60100b96(param_1);
      if (((uVar2 != uVar6) || (uVar2 = uVar5, uVar1 != 0xffffffff)) &&
         (uVar2 = uVar1, param_2 <= uVar6)) {
        iVar4 = *(int *)(*(int *)(*param_1 + 4) + 4);
        return (iVar4 * uVar5 - uVar6) + iVar4;
      }
      uVar1 = uVar2;
      puVar7 = puVar7 + 1;
    }
    if (uVar1 != 0xffffffff) {
      iVar4 = *(int *)(*(int *)(*param_1 + 4) + 4);
      iVar3 = FUN_60100b96(param_1);
      return (iVar4 * uVar1 + iVar4) - iVar3;
    }
  }
  return -1;
}


