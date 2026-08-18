// 600cf1b2  FUN_600cf1b2  size=52 bytes
// --- callers ---
// --- callees ---


void FUN_600cf1b2(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  for (iVar2 = 0; iVar2 != param_3; iVar2 = iVar2 + 1) {
    bVar3 = (byte)*(undefined4 *)(param_1 + 0x1c);
    if ((int)(uVar1 << 0x14) < 0 || (uVar1 & 0x812) == 2) {
      bVar3 = bVar3 & 0x7f;
    }
    *(byte *)(param_2 + iVar2) = bVar3;
  }
  return;
}


