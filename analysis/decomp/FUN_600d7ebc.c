// 600d7ebc  FUN_600d7ebc  size=162 bytes
// --- callers ---
// --- callees ---
//   6013d1b0 thunk_EXT_FUN_00006668
//   600e02a8 FUN_600e02a8


undefined4 FUN_600d7ebc(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char local_44 [36];
  
  uVar7 = 0;
  while( true ) {
    if (param_3 <= uVar7) {
      return 0;
    }
    uVar8 = param_3 - uVar7;
    uVar5 = 0;
    if (0xf < uVar8) {
      uVar8 = 0x10;
    }
    do {
      bVar6 = *(byte *)(param_2 + uVar7 + uVar5);
      bVar1 = bVar6 >> 4;
      bVar6 = bVar6 & 0xf;
      if (bVar1 < 10) {
        cVar4 = bVar1 + 0x30;
      }
      else {
        cVar4 = bVar1 + 0x37;
      }
      local_44[uVar5 * 2] = cVar4;
      iVar2 = uVar5 * 2;
      uVar5 = uVar5 + 1;
      if (bVar6 < 10) {
        cVar4 = bVar6 + 0x30;
      }
      else {
        cVar4 = bVar6 + 0x37;
      }
      local_44[iVar2 + 1] = cVar4;
    } while (uVar8 != uVar5);
    iVar9 = uVar8 * 2;
    iVar2 = *(int *)(param_1 + 4);
    local_44[iVar9] = '\0';
    if ((iVar2 == 0) || (iVar2 = FUN_600e02a8(), iVar2 == 0)) {
      return 9;
    }
    uVar3 = FUN_600e02a8(*(undefined4 *)(param_1 + 4));
    iVar2 = thunk_EXT_FUN_00006668(uVar3,local_44,iVar9);
    if (iVar2 < 0) {
      return 0xd;
    }
    if (iVar9 != iVar2) break;
    uVar7 = uVar7 + uVar8;
  }
  return 0xf;
}


