// 60099c0c  FUN_60099c0c  size=134 bytes
// --- callers ---
//   60099adc FUN_60099adc
//   60099a1c FUN_60099a1c
//   60099bb8 FUN_60099bb8
//   600f7ca0 FUN_600f7ca0
//   60098f88 FUN_60098f88
// --- callees ---
//   600f0252 FUN_600f0252
//   60099f4c FUN_60099f4c


void FUN_60099c0c(undefined2 *param_1)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 0x97) == '\x01') {
    uVar1 = FUN_60099f4c(0xffff);
    param_1[1] = uVar1;
    if (*(short *)(DAT_60099c94 + 0x640) != 0) {
      FUN_600f0252(param_1 + 3,DAT_60099c98);
    }
  }
  *(undefined1 *)(param_1 + 0x95) = 1;
  if (*(int *)(DAT_60099c94 + 0x644) != 0) {
    (**(code **)(DAT_60099c94 + 0x644))
              (param_1 + 3,param_1 + 6,(int)param_1 + 0xf,param_1 + 0x87,1,*param_1,
               *(undefined1 *)(param_1 + 0x97));
  }
  return;
}


