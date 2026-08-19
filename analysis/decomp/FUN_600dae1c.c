// 600dae1c  FUN_600dae1c  size=164 bytes
// --- callers ---
//   60076ba0 FUN_60076ba0
// --- callees ---
//   60101d22 FUN_60101d22
//   6013d310 thunk_EXT_FUN_0000b52a
//   60101e12 FUN_60101e12
//   600dadfe FUN_600dadfe


int FUN_600dae1c(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_1 + 4;
  iVar4 = *(int *)(param_1 + 8);
  iVar7 = iVar6;
  do {
    while( true ) {
      iVar1 = iVar7;
      iVar7 = iVar4;
      iVar5 = iVar1;
      if (iVar7 == 0) goto LAB_600dae72;
      iVar3 = *param_2;
      if (iVar3 <= *(int *)(iVar7 + 0x10)) break;
      param_3 = *(int *)(iVar7 + 0xc);
      iVar4 = param_3;
      iVar7 = iVar1;
    }
    param_3 = *(int *)(iVar7 + 8);
    iVar4 = param_3;
  } while (iVar3 < *(int *)(iVar7 + 0x10));
  iVar1 = iVar7;
  while (iVar2 = param_3, param_3 = 0, iVar4 = *(int *)(iVar7 + 0xc), iVar2 != 0) {
    if (*(int *)(iVar2 + 0x10) < iVar3) {
      param_3 = *(int *)(iVar2 + 0xc);
    }
    else {
      param_3 = *(int *)(iVar2 + 8);
      iVar1 = iVar2;
    }
  }
  while (iVar4 != 0) {
    param_3 = *(int *)(iVar4 + 0x10);
    if (iVar3 < param_3) {
      iVar4 = *(int *)(iVar4 + 8);
      iVar5 = iVar4;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xc);
    }
  }
LAB_600dae72:
  iVar7 = *(int *)(param_1 + 0x14);
  iVar4 = iVar1;
  if ((*(int *)(param_1 + 0xc) == iVar1) && (iVar4 = *(int *)(param_1 + 0xc), iVar6 == iVar5)) {
    FUN_600dadfe(param_1,*(int *)(param_1 + 8),param_3,iVar1,param_4);
    *(undefined4 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0xc) = iVar6;
    *(int *)(param_1 + 0x10) = iVar6;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  else {
    while (iVar5 != iVar4) {
      iVar1 = FUN_60101d22(iVar4);
      FUN_60101e12(iVar4,iVar6);
      thunk_EXT_FUN_0000b52a();
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      iVar4 = iVar1;
    }
  }
  return iVar7 - *(int *)(param_1 + 0x14);
}


