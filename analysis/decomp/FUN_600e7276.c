// 600e7276  FUN_600e7276  size=92 bytes
// --- callers ---
//   600e7450 FUN_600e7450
//   600e89f8 FUN_600e89f8
//   600e9bc2 FUN_600e9bc2
// --- callees ---


int FUN_600e7276(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = param_1 >> 0x10;
  iVar1 = -uVar4;
  if (-1 < iVar1) {
    uVar4 = param_1;
  }
  uVar6 = iVar1 >> 0x1f & 0x10;
  if (param_1 != 0) {
    uVar6 = uVar6 + 1;
  }
  iVar1 = -(uVar4 >> 8);
  uVar5 = uVar4 >> 8;
  if (-1 < iVar1) {
    uVar5 = uVar4;
  }
  iVar2 = -(uVar5 >> 4);
  uVar4 = uVar5 >> 4;
  if (-1 < iVar2) {
    uVar4 = uVar5;
  }
  uVar5 = uVar4 >> 2;
  iVar3 = -uVar5;
  if (-1 < iVar3) {
    uVar5 = uVar4;
  }
  return (uVar6 + (iVar1 >> 0x1f & 8U) + (iVar2 >> 0x1f & 4U) + (iVar3 >> 0x1f & 2U)) -
         ((int)-(uVar5 >> 1) >> 0x1f);
}


