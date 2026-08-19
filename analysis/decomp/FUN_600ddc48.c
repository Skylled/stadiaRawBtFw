// 600ddc48  FUN_600ddc48  size=88 bytes
// --- callers ---
//   600dd83c FUN_600dd83c
// --- callees ---
//   6007dfcc FUN_6007dfcc
//   600de44e FUN_600de44e
//   6007e514 FUN_6007e514
//   600de98e FUN_600de98e


int FUN_600ddc48(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_2;
  FUN_600de44e();
  uVar2 = *(undefined4 *)(param_2 + 0x3c);
  uVar3 = *(undefined4 *)(param_2 + 0x60);
  uVar1 = *(undefined4 *)(param_2 + 0x18);
  *(int *)(param_1 + 4) = param_2;
  FUN_6007dfcc(param_1 + 8,uVar1,uVar2,uVar3,1,iVar4);
  FUN_6007dfcc(param_1 + 0x44,*(undefined4 *)(*(int *)(param_1 + 4) + 0x30),
               *(undefined4 *)(*(int *)(param_1 + 4) + 0x54),*(undefined4 *)(param_2 + 0x60),0);
  FUN_6007e514(param_1 + 0x80,*(int *)(param_1 + 4) + 0x3c,
               *(undefined4 *)(*(int *)(param_1 + 4) + 0x60));
  FUN_600de98e(param_1 + 0x1e0,*(int *)(param_1 + 4) + 0x54,*(undefined4 *)(param_2 + 0x60));
  *(undefined4 *)(param_1 + 0x218) = 0;
  return param_1;
}


