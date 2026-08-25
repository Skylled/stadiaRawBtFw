// 600fab3e  FUN_600fab3e  size=84 bytes
// --- callers ---
//   600fb8c4 FUN_600fb8c4
//   600faec4 FUN_600faec4
// --- callees ---
//   600c1b74 FUN_600c1b74
//   600bffe8 FUN_600bffe8


void FUN_600fab3e(int param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  
  *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b2) & *(byte *)(param_1 + 0x1b4);
  bVar2 = *(byte *)(param_1 + 0x1b3) & *(byte *)(param_1 + 0x1b5);
  *(byte *)(param_1 + 0x1b5) = bVar2;
  iVar1 = FUN_600c1b74(2,param_1,bVar2,param_1,param_2);
  if (iVar1 != 0) {
    FUN_600bffe8(param_1,0);
  }
  return;
}


