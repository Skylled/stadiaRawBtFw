// 60080af8  gatt_manager_task__60080af8  size=30 bytes
// src: gatt_manager_task.cc
// --- callers ---
//   600df2ce FUN_600df2ce
// --- callees ---
//   600cc160 FUN_600cc160
//   6010165c FUN_6010165c


/* src: gatt_manager_task.cc */

undefined4 * gatt_manager_task__60080af8(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_60080b1c;
  *param_1 = DAT_60080b18;
  FUN_6010165c(0x14,uVar1,0x49,DAT_60080b20);
  FUN_600cc160(param_1);
  return param_1;
}


