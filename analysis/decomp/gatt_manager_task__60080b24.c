// 60080b24  gatt_manager_task__60080b24  size=108 bytes
// src: gatt_manager_task.cc
// --- callers ---
//   60080cdc gatt_manager_task__60080cdc
// --- callees ---
//   601016a2 FUN_601016a2
//   600c9de4 queue__600c9de4
//   601017fc FUN_601017fc


/* src: gatt_manager_task.cc */

undefined4 * gatt_manager_task__60080b24(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *param_1 = DAT_60080b90;
  param_1[0x15] = 0;
  FUN_601017fc();
  *param_1 = DAT_60080b94;
  param_1[0x4b] = param_1 + 0x4d;
  param_1[0x4c] = 0x800;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x84d) = 0;
  *(undefined1 *)((int)param_1 + 0x2135) = 0;
  uVar1 = queue__600c9de4(10,0x10,param_1 + 0x863,param_1 + 0x84e,0,param_2);
  param_1[0x862] = uVar1;
  param_1[0x17] = param_1 + 0x18;
  if (*DAT_60080b98 != 0) {
    FUN_601016a2(DAT_60080ba0,0x44,DAT_60080b9c);
  }
  return param_1;
}


