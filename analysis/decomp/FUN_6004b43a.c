// 6004b43a  FUN_6004b43a  size=52 bytes
// --- callers ---
// --- callees ---
//   6004b422 FUN_6004b422
//   60046ed4 FUN_60046ed4


void FUN_6004b43a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_60046ed4();
  if (iVar1 != 0) {
    iVar2 = iVar1;
    do {
      iVar3 = iVar2 + 0x10;
      FUN_6004b422(iVar2);
      iVar2 = iVar3;
    } while (iVar3 != iVar1 + 0x100);
    func_0x6004b47a(*(undefined4 *)(iVar1 + 0x108));
    *(undefined4 *)(iVar1 + 0x108) = 0;
    *(undefined4 *)(iVar1 + 0x104) = 0;
    *(undefined4 *)(iVar1 + 0x100) = 0;
  }
  return;
}


