// 600e75c8  FUN_600e75c8  size=22 bytes
// --- callers ---
//   600e75de FUN_600e75de
// --- callees ---
//   600e75c2 FUN_600e75c2


void FUN_600e75c8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (iVar1 = FUN_600e75c2(), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  return;
}


