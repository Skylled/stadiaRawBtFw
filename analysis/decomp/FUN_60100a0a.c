// 60100a0a  FUN_60100a0a  size=28 bytes
// --- callers ---
//   600caec8 FUN_600caec8
// --- callees ---


int FUN_60100a0a(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < uVar3) {
    iVar1 = (uVar3 - 1) - uVar2;
  }
  else {
    iVar1 = (*(int *)(param_1 + 8) + uVar3 + -1) - uVar2;
  }
  return iVar1;
}


