// 600d8b3a  FUN_600d8b3a  size=50 bytes
// --- callers ---
//   60068f88 activation_sequence__60068f88
// --- callees ---
//   6006a448 FUN_6006a448


int FUN_600d8b3a(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1714);
  iVar3 = 0;
  iVar2 = param_1 + 0x230;
  while( true ) {
    if (iVar4 == iVar3) {
      return 0;
    }
    iVar1 = FUN_6006a448(iVar2,param_2);
    if (iVar1 != 0) break;
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x11c;
  }
  return iVar2;
}


