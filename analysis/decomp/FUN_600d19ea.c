// 600d19ea  FUN_600d19ea  size=120 bytes
// --- callers ---
//   600d1a9c FUN_600d1a9c
//   60063e24 usb_host_audio_topology__60063e24
//   600d1c8c FUN_600d1c8c
// --- callees ---
//   600d18d2 FUN_600d18d2


undefined4 FUN_600d19ea(int param_1,uint param_2,int *param_3,short *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_20;
  int local_1c;
  int *piStack_18;
  
  *param_4 = 0;
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else if (param_3 == (int *)0x0) {
    uVar1 = 4;
  }
  else {
    local_1c = *(int *)(param_1 + 0x34);
    if (local_1c != 0) {
      iVar3 = 10;
      uStack_20 = CONCAT22(*(undefined2 *)(param_1 + 0x38),(short)param_1) & 0xffff00ff;
      piStack_18 = param_3;
      do {
        if ((uStack_20 >> 8 & 0xff) == param_2) {
          *param_3 = local_1c;
          *param_4 = uStack_20._2_2_;
          iVar3 = FUN_600d18d2(&local_1c,(int)&uStack_20 + 2,(int)&uStack_20 + 1);
          if (iVar3 == 0) {
            *param_4 = (short)local_1c - (short)*param_3;
            return 0;
          }
          return 0;
        }
        iVar2 = FUN_600d18d2(&local_1c,(int)&uStack_20 + 2,(int)&uStack_20 + 1);
      } while ((iVar2 == 0) && (iVar3 = iVar3 + -1, iVar3 != 0));
    }
    uVar1 = 1;
  }
  return uVar1;
}


