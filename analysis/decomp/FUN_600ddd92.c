// 600ddd92  FUN_600ddd92  size=120 bytes
// --- callers ---
// --- callees ---
//   600de3de FUN_600de3de


void FUN_600ddd92(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0x9c);
  uVar1 = *(undefined4 *)(iVar4 + 0x1c);
  uVar2 = *(undefined4 *)(iVar4 + 0x20);
  uVar3 = *(undefined4 *)(iVar4 + 0x24);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar4 + 0x18);
  *(undefined4 *)(param_1 + 0xa4) = uVar1;
  *(undefined4 *)(param_1 + 0xa8) = uVar2;
  *(undefined4 *)(param_1 + 0xac) = uVar3;
  uVar1 = *(undefined4 *)(iVar4 + 0x2c);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(iVar4 + 0x28);
  *(undefined4 *)(param_1 + 0xb4) = uVar1;
  *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(param_1 + 0x1e0);
  *(undefined4 *)(param_1 + 0x1fc) = *(undefined4 *)(param_1 + 0x1e4);
  *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(param_1 + 0x1e8);
  uVar1 = *(undefined4 *)(iVar4 + 0x34);
  uVar2 = *(undefined4 *)(iVar4 + 0x38);
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(iVar4 + 0x30);
  *(undefined4 *)(param_1 + 0x1f0) = uVar1;
  *(undefined4 *)(param_1 + 500) = uVar2;
  uVar1 = *(undefined4 *)(iVar4 + 0x18);
  *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0x204);
  FUN_600de3de(param_1 + 8,uVar1,0);
  FUN_600de3de(param_1 + 0x44,*(undefined4 *)(*(int *)(param_1 + 4) + 0x30),0,param_4);
  return;
}


