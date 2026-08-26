// 601014d4  FUN_601014d4  size=86 bytes
// --- callers ---
//   600ce1f8 FUN_600ce1f8
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   601014ca FUN_601014ca
//   6004cb28 FUN_6004cb28


bool FUN_601014d4(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  if (param_2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_6004cb28(param_2);
  }
  pcVar5 = (char *)FUN_601014ca(*param_1);
  pcVar2 = pcVar5;
  if (*pcVar5 == '\0') {
    bVar3 = iVar4 == 0;
  }
  else {
LAB_601014fc:
    do {
      pcVar7 = pcVar2;
      cVar1 = pcVar7[1];
      if (cVar1 != ' ') {
        pcVar2 = pcVar7 + 1;
        if (cVar1 != '\0') goto LAB_601014fc;
      }
      iVar6 = (int)(pcVar7 + 1) - (int)pcVar5;
      if ((iVar6 == iVar4) &&
         ((iVar4 == 0 ||
          (iVar6 = thunk_EXT_FUN_0000b554(pcVar5,param_2,iVar4,iVar6,param_4), iVar6 == 0)))) {
        return true;
      }
      pcVar5 = pcVar7 + 2;
      pcVar2 = pcVar5;
    } while (cVar1 != '\0');
    bVar3 = false;
  }
  return bVar3;
}


