// 6005ee58  FUN_6005ee58  size=42 bytes
// --- callers ---
//   6005f07c FUN_6005f07c
// --- callees ---


void FUN_6005ee58(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_6005ee84;
  if ((char)param_1[4] != '\0') {
    iVar3 = param_1[1];
    DataSynchronizationBarrier(0xf);
    iVar2 = *param_1 + iVar3;
    for (; 0 < iVar3; iVar3 = iVar3 + -0x20) {
      *(int *)(iVar1 + 0x25c) = iVar2 - iVar3;
    }
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


