// 6009f4e4  FUN_6009f4e4  size=148 bytes
// --- callers ---
//   6009f5d0 FUN_6009f5d0
//   6009f60c FUN_6009f60c
// --- callees ---
//   6009c6d8 FUN_6009c6d8
//   6009c778 FUN_6009c778
//   6009e8fc FUN_6009e8fc
//   600f1592 FUN_600f1592


undefined4 FUN_6009f4e4(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  pbVar1 = DAT_6009f578;
  if (DAT_6009f578[0x19d] == 0) {
    iVar2 = FUN_6009c778();
    if (iVar2 == 1) {
      uVar3 = 0;
    }
    else {
      pbVar1[0x19d] = 0;
      if (pbVar1[0x16] == 1) {
        FUN_6009e8fc();
        pbVar1[0x19d] = pbVar1[0x19d] | 4;
      }
      if ((*pbVar1 & 0xf0) != 0) {
        FUN_600f1592();
        pbVar1[0x19d] = pbVar1[0x19d] | 2;
      }
      iVar2 = FUN_6009c6d8();
      if (iVar2 != 0) {
        pbVar1[0x19d] = pbVar1[0x19d] | 1;
      }
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


