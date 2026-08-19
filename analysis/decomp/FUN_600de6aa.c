// 600de6aa  FUN_600de6aa  size=38 bytes
// --- callers ---
// --- callees ---


void FUN_600de6aa(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3 - 1;
  if (*(uint *)(param_1 + 0x30) < uVar1) {
    iVar2 = *(uint *)(param_1 + 0x30) + 1;
  }
  else {
    iVar2 = 0;
  }
  *(int *)(param_1 + 0x2c) = iVar2;
  if (uVar1 < iVar2 + 0x3fU) {
    *(uint *)(param_1 + 0x30) = uVar1;
  }
  else {
    *(uint *)(param_1 + 0x30) = iVar2 + 0x3fU;
  }
  return;
}


