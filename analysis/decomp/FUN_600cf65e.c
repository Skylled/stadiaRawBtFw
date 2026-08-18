// 600cf65e  FUN_600cf65e  size=158 bytes
// --- callers ---
//   600cf876 FUN_600cf876
// --- callees ---


void FUN_600cf65e(int param_1,int *param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_2 + 2);
  cVar2 = *(char *)((int)param_2 + 0x13);
  if (bVar1 == 0) {
    iVar6 = 2;
  }
  else {
    iVar6 = 1;
  }
  if (cVar2 == '\0') {
    uVar5 = *param_2 << 6;
  }
  else {
    uVar5 = iVar6 * param_2[1] * *param_2;
    *(uint *)(param_1 + 0x18) =
         (param_2[1] + -1) * 0x100 & 0x1f00U | *(uint *)(param_1 + 0x18) & 0xffffe0ff;
  }
  if (*(int *)(param_1 + 0x10) << 7 < 0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffff00;
    *(uint *)(param_1 + 0x10) = (param_4 / uVar5 >> 1) - 1 & 0xff | *(uint *)(param_1 + 0x10);
  }
  if (cVar2 == '\0') {
    uVar5 = 0x1f;
  }
  else {
    uVar5 = param_2[1] - 1;
  }
  uVar3 = uVar5 & 0x1f;
  uVar4 = uVar5 & 0x1f;
  if (*(char *)((int)param_2 + 0x12) != '\x01') {
    uVar5 = param_2[1] - 1;
  }
  *(uint *)(param_1 + 0x1c) = (uVar5 & 0x1f) << 8 | uVar3 << 0x18 | uVar4 << 0x10;
  *(uint *)(param_1 + 0x60) = (uint)bVar1;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfff0ffff;
  *(uint *)(param_1 + 0x14) =
       0x10000 << *(sbyte *)((int)param_2 + 0x11) & 0xf0000U | *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0xc) = (uint)*(byte *)(param_2 + 4);
  return;
}


