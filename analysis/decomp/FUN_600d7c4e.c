// 600d7c4e  FUN_600d7c4e  size=84 bytes
// --- callers ---
// --- callees ---


void FUN_600d7c4e(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_1 + 0x18);
  iVar6 = *(int *)(param_1 + 8);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (99 < iVar3) {
    iVar3 = 100;
  }
  iVar4 = *(int *)(param_1 + 0x14);
  iVar5 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x10);
  uVar1 = FUN_600653e0();
  FUN_600d8d5a(uVar1,(iVar3 * iVar6) / 100 & 0xff,(iVar3 * iVar5) / 100 & 0xff,
               (iVar3 * iVar2) / 100 & 0xff,(iVar3 * iVar4) / 100 & 0xff,param_2,param_3);
  return;
}


