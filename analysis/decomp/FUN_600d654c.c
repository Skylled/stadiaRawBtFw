// 600d654c  FUN_600d654c  size=60 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600d6460 FUN_600d6460
//   60063dec FUN_60063dec
//   600d6028 FUN_600d6028


undefined4 * FUN_600d654c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600d6028(*(undefined4 *)(param_2 + 0x54),&stack0xffffffef,param_3,param_4,param_1,
                       CONCAT13((char)param_3,(int3)param_2));
  if (*(int *)(param_2 + 0x54) + 4 == iVar1) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  else {
    uVar2 = FUN_60063dec(*(int *)(param_2 + 0x54),&stack0xffffffef);
    FUN_600d6460(param_1,uVar2);
  }
  return param_1;
}


