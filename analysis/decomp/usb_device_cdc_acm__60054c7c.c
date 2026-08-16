// 60054c7c  usb_device_cdc_acm__60054c7c  size=120 bytes
// src: usb_device_cdc_acm.c
// --- callers ---
//   600550e4 FUN_600550e4
// --- callees ---
//   600557e8 FUN_600557e8
//   6010165c FUN_6010165c
//   60055024 FUN_60055024


/* src: usb_device_cdc_acm.c */

int usb_device_cdc_acm__60054c7c(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_60054cf4;
  if (*DAT_60054cf4 == 0) {
    iVar2 = FUN_60055024(param_1,DAT_60054cf4,param_3,0,param_4);
    if (iVar2 == 0) {
      if (*piVar1 == 0) {
        iVar2 = 3;
      }
      else {
        *(undefined1 *)(piVar1 + 10) = 0;
        piVar1[1] = param_2;
        *(undefined1 *)((int)piVar1 + 0x2a) = 0xff;
        iVar3 = FUN_600557e8(piVar1 + 4);
        if (iVar3 != 0) {
          FUN_6010165c(0x28,DAT_60054cfc,0x256,DAT_60054cf8);
        }
        iVar3 = FUN_600557e8(DAT_60054d00);
        if (iVar3 != 0) {
          FUN_6010165c(0x28,DAT_60054cfc,0x25a,DAT_60054cf8);
        }
        iVar3 = FUN_600557e8(DAT_60054d04);
        if (iVar3 != 0) {
          FUN_6010165c(0x28,DAT_60054cfc,0x25e,DAT_60054cf8);
        }
        *param_3 = (int)piVar1;
      }
    }
  }
  else {
    iVar2 = 2;
  }
  return iVar2;
}


