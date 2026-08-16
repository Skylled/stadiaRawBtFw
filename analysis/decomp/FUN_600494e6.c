// 600494e6  FUN_600494e6  size=60 bytes
// --- callers ---
//   60042ee0 FUN_60042ee0
// --- callees ---


byte FUN_600494e6(int param_1,uint param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if ((uint)param_3[2] <= param_2) {
    uVar4 = ~(**(uint **)(*param_3 + 0x20) >> (*(uint *)(*param_3 + 0x18) & 0xff)) & 1;
    if (*(byte *)(param_3 + 1) != uVar4) {
      iVar3 = *(int *)(param_1 + 0x3f8);
      *(char *)(param_3 + 1) = (char)uVar4;
      param_3[2] = param_2 + iVar3;
    }
  }
  bVar1 = *(byte *)(param_3 + 1);
  bVar2 = *(byte *)param_3[4];
  if (bVar1 == 0) {
    bVar1 = *(byte *)param_3[3];
  }
  *(byte *)param_3[4] = bVar1;
  return bVar2 ^ bVar1;
}


