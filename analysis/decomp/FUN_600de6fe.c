// 600de6fe  FUN_600de6fe  size=104 bytes
// --- callers ---
//   600de4e0 FUN_600de4e0
// --- callees ---
//   600de6e8 FUN_600de6e8
//   6007e368 FUN_6007e368
//   6013d378 thunk_EXT_FUN_0000b532
//   60101fcc FUN_60101fcc


undefined1 * FUN_600de6fe(undefined1 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  *param_1 = *(undefined1 *)(param_2 + 0x75);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x70);
  iVar1 = *(int *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x10) = 0;
  uVar6 = iVar1 << 6;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (uVar6 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar2 = iVar1;
    if (0x3fffffff < uVar6) {
      iVar2 = FUN_60101fcc();
    }
    puVar3 = (undefined4 *)thunk_EXT_FUN_0000b532(iVar2 << 8);
  }
  *(undefined4 **)(param_1 + 8) = puVar3;
  *(undefined4 **)(param_1 + 0xc) = puVar3;
  *(undefined4 **)(param_1 + 0x10) = puVar3 + iVar1 * 0x40;
  puVar4 = puVar3;
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 **)(param_1 + 0xc) = puVar3 + iVar1 * 0x40;
  uVar5 = *(undefined4 *)(param_2 + 0x3c);
  param_1[0x1c] = 0;
  *(undefined4 *)(param_1 + 0x28) = uVar5;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_6007e368(param_1 + 0x34,param_2);
  FUN_600de6e8(param_1);
  return param_1;
}


