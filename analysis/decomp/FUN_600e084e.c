// 600e084e  FUN_600e084e  size=58 bytes
// --- callers ---
// --- callees ---
//   6008db08 bcm__6008db08
//   600ea88e FUN_600ea88e
//   600ea886 FUN_600ea886


undefined4 FUN_600e084e(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = FUN_600ea886(*(undefined4 *)(param_2 + 8));
  uVar2 = FUN_600ea88e(*(undefined4 *)(param_1 + 8));
  uVar3 = FUN_600ea88e(*(undefined4 *)(param_2 + 8));
  iVar4 = bcm__6008db08(uVar1,uVar2,uVar3,0);
  if (iVar4 == 0) {
    uVar1 = 1;
  }
  else if (iVar4 == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


