// 600d06d6  FUN_600d06d6  size=78 bytes
// --- callers ---
//   60054a54 usb_device_cdc_acm__60054a54
//   60054d08 usb_device_cdc_acm__60054d08
// --- callees ---
//   600d10f6 FUN_600d10f6


undefined4
FUN_600d06d6(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1[2] == 0) || (param_1[3] == 0)) {
    uVar2 = 1;
  }
  else {
    iVar5 = 0;
    uVar2 = 1;
    while( true ) {
      uVar3 = (uint)*(byte *)(param_1[2] + 4);
      if ((int)uVar3 <= iVar5) break;
      iVar4 = *(int *)(param_1[2] + 8);
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      uVar2 = FUN_600d10f6(*param_1,*(undefined1 *)(iVar4 + iVar1),uVar3,iVar4,param_4);
    }
    iVar5 = 0;
    while( true ) {
      uVar3 = (uint)*(byte *)(param_1[3] + 4);
      if ((int)uVar3 <= iVar5) break;
      iVar4 = *(int *)(param_1[3] + 8);
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      uVar2 = FUN_600d10f6(*param_1,*(undefined1 *)(iVar4 + iVar1),uVar3,iVar4,param_4);
    }
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return uVar2;
}


