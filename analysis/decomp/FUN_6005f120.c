// 6005f120  FUN_6005f120  size=58 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   6005b1c0 application_state__6005b1c0
// --- callees ---
//   6005f110 FUN_6005f110


void FUN_6005f120(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = DAT_6005f160;
  switch(param_1) {
  case 1:
    uVar2 = 3;
    break;
  case 2:
    goto switchD_6005f128_caseD_2;
  case 3:
    uVar2 = 5;
    break;
  case 4:
    uVar2 = 1;
    break;
  case 5:
    iVar1 = *(int *)(DAT_6005f160 + 0x30);
    *(undefined4 *)(DAT_6005f160 + 0x30) = 0;
    if (iVar1 != 1) {
      return;
    }
    uVar2 = 2;
    break;
  default:
    return;
  }
  do {
    *(undefined4 *)(iVar3 + 0x30) = uVar2;
    FUN_6005f110();
switchD_6005f128_caseD_2:
    uVar2 = 4;
    iVar3 = DAT_6005f160;
  } while( true );
}


