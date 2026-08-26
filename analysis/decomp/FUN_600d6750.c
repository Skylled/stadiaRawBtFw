// 600d6750  FUN_600d6750  size=152 bytes
// --- callers ---
//   60064438 usb_host_audio_topology__60064438
// --- callees ---
//   600d5f7e FUN_600d5f7e
//   600d6720 FUN_600d6720
//   6013d378 thunk_EXT_FUN_0000b532
//   60101d4a thunk_FUN_60101ccc
//   60101d4e FUN_60101d4e


int * FUN_600d6750(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2 + 4;
  iVar1 = 1;
  iVar4 = iVar5;
  iVar2 = *(int *)(param_2 + 8);
  while (iVar2 != 0) {
    iVar1 = FUN_600d6720(param_3,iVar2 + 0x10);
    iVar4 = iVar2;
    if (iVar1 == 0) {
      iVar2 = *(int *)(iVar2 + 0xc);
    }
    else {
      iVar2 = *(int *)(iVar2 + 8);
    }
  }
  iVar2 = iVar4;
  if (iVar1 != 0) {
    if (*(int *)(param_2 + 0xc) == iVar4) goto LAB_600d67de;
    iVar2 = thunk_FUN_60101ccc(iVar4);
  }
  iVar1 = FUN_600d6720(iVar2 + 0x10,param_3);
  if (iVar1 == 0) {
    *param_1 = iVar2;
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  }
LAB_600d67de:
  if (iVar5 == iVar4) {
    uVar3 = 1;
  }
  else {
    uVar3 = FUN_600d6720(param_3,iVar4 + 0x10);
  }
  iVar2 = thunk_EXT_FUN_0000b532(0x1c);
  FUN_600d5f7e(iVar2 + 0x10,param_3);
  FUN_60101d4e(uVar3,iVar2,iVar4,iVar5);
  iVar4 = *(int *)(param_2 + 0x14);
  *param_1 = iVar2;
  *(int *)(param_2 + 0x14) = iVar4 + 1;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}


