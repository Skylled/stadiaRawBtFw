// 600e080c  FUN_600e080c  size=22 bytes
// --- callers ---
// --- callees ---
//   6008d6b8 bcm__6008d6b8
//   600ea886 FUN_600ea886


void FUN_600e080c(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar1 = FUN_600ea886(*(undefined4 *)(param_2 + 8));
  bcm__6008d6b8(uVar2,uVar1);
  return;
}


