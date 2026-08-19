// 600db902  FUN_600db902  size=124 bytes
// --- callers ---
// --- callees ---
//   600db8e8 FUN_600db8e8
//   600db8b8 FUN_600db8b8


void FUN_600db902(int param_1,int param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  
  iVar3 = FUN_600db8b8();
  DataMemoryBarrier(0x1b);
  *(int *)(param_1 + 0x964) = iVar3;
  DataMemoryBarrier(0x1b);
  if ((param_3 == 0) || (param_2 == 0)) {
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x948) = 1;
    DataMemoryBarrier(0x1b);
    *(int *)(param_1 + 0x958) = iVar3;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x958);
    *(int *)(param_1 + 0x958) = iVar3;
    pbVar6 = (byte *)(param_1 + 0x949);
    *(int *)(param_1 + 0x94c) = param_2;
    *(int *)(param_1 + 0x950) = param_3;
    *(int *)(param_1 + 0x954) = iVar3 - iVar4;
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(pbVar6);
      bVar1 = *pbVar6;
      uVar5 = (uint)bVar1;
      bVar2 = (bool)hasExclusiveAccess(pbVar6);
    } while (!bVar2);
    *pbVar6 = 1;
    DataMemoryBarrier(0x1b);
    if (bVar1 != 0) {
      uVar5 = 0x19d8;
      pbVar6 = (byte *)(*(int *)(param_1 + 0x19d8) + 1);
    }
    if (bVar1 != 0) {
      *(byte **)(param_1 + uVar5) = pbVar6;
    }
  }
  FUN_600db8e8(param_1 + 4);
  return;
}


