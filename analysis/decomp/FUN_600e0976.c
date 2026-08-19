// 600e0976  FUN_600e0976  size=26 bytes
// --- callers ---
//   600ed3a0 FUN_600ed3a0
// --- callees ---


byte FUN_600e0976(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  for (iVar2 = 0; iVar2 != param_3; iVar2 = iVar2 + 1) {
    bVar1 = bVar1 | *(byte *)(param_1 + iVar2) ^ *(byte *)(param_2 + iVar2);
  }
  return bVar1;
}


