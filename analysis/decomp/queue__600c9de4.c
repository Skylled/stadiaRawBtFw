// 600c9de4  queue__600c9de4  size=128 bytes
// src: queue.c
// --- callers ---
//   600587fc FUN_600587fc
//   6005bc74 FUN_6005bc74
//   60080b24 gatt_manager_task__60080b24
//   601007bc FUN_601007bc
//   6007f540 receiver__6007f540
//   600cac50 FUN_600cac50
//   60062e28 FUN_60062e28
//   601017fc FUN_601017fc
//   600650dc FUN_600650dc
//   600765a4 FUN_600765a4
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d3d0 thunk_EXT_FUN_000069a0


/* WARNING: Removing unreachable block (ram,0x600c9e24) */
/* src: queue.c */

int * queue__600c9de4(int param_1,int param_2,int *param_3,int *param_4,undefined1 param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_601016a2(DAT_600c9e68,0x132,DAT_600c9e64,param_4,0,param_2,param_3);
  }
  if (param_4 == (int *)0x0) {
    FUN_601016a2(DAT_600c9e68,0x136,DAT_600c9e64);
  }
  if (param_3 == (int *)0x0) {
    if (param_2 == 0) goto LAB_600c9e1a;
    uVar1 = 0x13b;
  }
  else {
    if (param_2 != 0) goto LAB_600c9e1a;
    uVar1 = 0x13a;
  }
  FUN_601016a2(DAT_600c9e68,uVar1,DAT_600c9e64);
LAB_600c9e1a:
  if (param_4 != (int *)0x0) {
    if (param_2 == 0) {
      param_3 = param_4;
    }
    *(undefined1 *)((int)param_4 + 0x46) = 1;
    *param_4 = (int)param_3;
    param_4[0xf] = param_1;
    param_4[0x10] = param_2;
    thunk_EXT_FUN_000069a0(param_4);
    *(undefined1 *)(param_4 + 0x13) = param_5;
  }
  return param_4;
}


