// 6004bd70  FUN_6004bd70  size=30 bytes
// --- callers ---
// --- callees ---


int FUN_6004bd70(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  do {
    if (param_3 == iVar2) {
      return 0;
    }
    pbVar1 = (byte *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
    uVar3 = (uint)*(byte *)(param_2 + iVar2 + -1);
  } while (*pbVar1 == uVar3);
  return *pbVar1 - uVar3;
}


