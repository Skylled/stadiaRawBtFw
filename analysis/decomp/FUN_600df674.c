// 600df674  FUN_600df674  size=152 bytes
// --- callers ---
//   60081ea4 FUN_60081ea4
//   600df674 FUN_600df674
// --- callees ---
//   600dfb00 FUN_600dfb00
//   600dfadc FUN_600dfadc
//   600df674 FUN_600df674


bool FUN_600df674(int param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined1 auStack_20 [4];
  undefined4 local_1c;
  undefined4 local_10;
  
  bVar5 = *(byte *)(param_1 + 4);
  bVar4 = bVar5 & 0x30;
  if ((bVar5 & 0x30) == 0) {
LAB_600df708:
    bVar1 = false;
  }
  else {
    iVar6 = *(int *)(param_1 + 9);
    if ((bVar4 == 0x20) || (bVar4 == 0x30)) {
      uVar2 = *(uint *)((int)param_2 + iVar6);
    }
    else {
      if ((bVar4 == 0x10) && (iVar6 != 0)) {
        return (bool)(*(byte *)((int)param_2 + iVar6) ^ 1);
      }
      if ((bVar5 & 0xc0) != 0) {
LAB_600df6ae:
        puVar3 = param_2;
        do {
          if (puVar3 == (uint *)(*(int *)(param_1 + 0xd) + (int)param_2)) {
            return true;
          }
          uVar2 = *puVar3;
          puVar3 = (uint *)((int)puVar3 + 1);
        } while ((byte)uVar2 == 0);
        goto LAB_600df708;
      }
      bVar5 = bVar5 & 0xf;
      if (bVar5 == 5) {
        uVar2 = *param_2;
      }
      else if (bVar5 == 6) {
        uVar2 = (uint)(byte)*param_2;
      }
      else {
        if (bVar5 != 9) {
          if (bVar5 == 7) {
            iVar6 = FUN_600dfadc(auStack_20,*(undefined4 *)(param_1 + 0x15));
            while( true ) {
              if (iVar6 == 0) {
                return true;
              }
              iVar6 = FUN_600df674(local_1c,local_10);
              if (iVar6 == 0) break;
              iVar6 = FUN_600dfb00(auStack_20);
            }
            return false;
          }
          goto LAB_600df6ae;
        }
        uVar2 = *(uint *)(param_1 + 0xd);
      }
    }
    bVar1 = uVar2 == 0;
  }
  return bVar1;
}


