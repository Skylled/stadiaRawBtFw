// 600db730  FUN_600db730  size=208 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   600db714 FUN_600db714
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6007952c http_flash_writer__6007952c


uint FUN_600db730(int *param_1,int param_2,uint param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if ((char)param_1[0x42] == '\0') {
    uVar2 = (**(code **)(*(int *)*param_1 + 0x10))();
    uVar3 = param_1[9];
    uVar5 = *(int *)(*(int *)(*param_1 + 4) + 4) * param_1[2] - (param_1[4] + uVar3);
    if (param_3 <= uVar5) {
      uVar5 = param_3;
    }
    if (uVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      if (uVar3 < uVar2) {
        uVar4 = uVar2 - uVar3;
        if (uVar5 <= uVar2 - uVar3) {
          uVar4 = uVar5;
        }
        thunk_EXT_FUN_0000b572(uVar3 + (int)(param_1 + 5),param_2,uVar4,param_1 + 5,param_4);
        uVar5 = uVar5 - uVar4;
        FUN_600db714(param_1,param_1[9] + uVar4);
        param_2 = param_2 + uVar4;
      }
    }
    if (param_1[9] == uVar2) {
      cVar1 = http_flash_writer__6007952c(param_1,param_1 + 5,uVar2);
      if (cVar1 != '\0') {
        return uVar4;
      }
      FUN_600db714(param_1);
    }
    iVar7 = uVar5 - uVar2 * (uVar5 / uVar2);
    iVar6 = uVar5 - iVar7;
    if (iVar6 != 0) {
      cVar1 = http_flash_writer__6007952c(param_1,param_2,iVar6);
      if (cVar1 != '\0') {
        return uVar4;
      }
      uVar4 = uVar4 + iVar6;
      param_2 = param_2 + iVar6;
    }
    if (iVar7 != 0) {
      uVar4 = uVar4 + iVar7;
      thunk_EXT_FUN_0000b572(param_1 + 5,param_2,iVar7);
      FUN_600db714(param_1,iVar7);
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


