// 600ddcc4  FUN_600ddcc4  size=206 bytes
// --- callers ---
// --- callees ---
//   6007e598 FUN_6007e598
//   6007ded0 FUN_6007ded0
//   600de3de FUN_600de3de
//   600de9cc FUN_600de9cc


void FUN_600ddcc4(int param_1,char *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_2 + 4) != 0) {
    FUN_6007ded0(param_1 + 8);
    FUN_6007ded0(param_1 + 0x44);
    FUN_6007e598(param_1 + 0x80,param_2);
    FUN_600de9cc((undefined4 *)(param_1 + 0x1e0));
    iVar4 = *(int *)(param_1 + 4);
    uVar1 = *(undefined4 *)(iVar4 + 0x40);
    uVar2 = *(undefined4 *)(iVar4 + 0x44);
    uVar3 = *(undefined4 *)(iVar4 + 0x48);
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar4 + 0x3c);
    *(undefined4 *)(param_1 + 0xa4) = uVar1;
    *(undefined4 *)(param_1 + 0xa8) = uVar2;
    *(undefined4 *)(param_1 + 0xac) = uVar3;
    uVar1 = *(undefined4 *)(iVar4 + 0x50);
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(iVar4 + 0x4c);
    *(undefined4 *)(param_1 + 0xb4) = uVar1;
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0xa0);
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0xa4);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0xa8);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0xac);
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x88);
    *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0x90);
    *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0x94);
    *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_1 + 0x98);
    *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0x9c);
    uVar1 = *(undefined4 *)(iVar4 + 0x54);
    uVar2 = *(undefined4 *)(iVar4 + 0x58);
    uVar3 = *(undefined4 *)(iVar4 + 0x5c);
    *(undefined4 *)(param_1 + 0x1dc) = 0;
    *(undefined4 *)(param_1 + 0x1ec) = uVar1;
    *(undefined4 *)(param_1 + 0x1f0) = uVar2;
    *(undefined4 *)(param_1 + 500) = uVar3;
    *(undefined4 *)(param_1 + 0x1e0) = uVar1;
    *(undefined4 *)(param_1 + 0x1e4) = uVar2;
    *(undefined4 *)(param_1 + 0x1e8) = uVar3;
    *(undefined4 *)(param_1 + 0x1f8) = uVar1;
    *(undefined4 *)(param_1 + 0x1fc) = uVar2;
    *(undefined4 *)(param_1 + 0x200) = uVar3;
    uVar1 = *(undefined4 *)(iVar4 + 0x3c);
    *(undefined4 *)(param_1 + 0x214) = 0;
    FUN_600de3de(param_1 + 8,uVar1,1);
    FUN_600de3de(param_1 + 0x44,*(undefined4 *)(*(int *)(param_1 + 4) + 0x54),1);
  }
  if (*param_2 != '\0') {
    FUN_6007e598(param_1 + 0x80,param_2);
    return;
  }
  return;
}


