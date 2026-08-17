// 60080bcc  gatt_manager_task__60080bcc  size=122 bytes
// src: gatt_manager_task.cc
// --- callers ---
// --- callees ---
//   60101832 FUN_60101832
//   60080ba4 FUN_60080ba4
//   6010165c FUN_6010165c
//   6013d268 thunk_EXT_FUN_00006d2c


/* src: gatt_manager_task.cc */

void gatt_manager_task__60080bcc(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uVar3;
  int local_30;
  undefined1 *puStack_2c;
  int local_28;
  
  *(undefined1 *)(param_1 + 0x2134) = 1;
  FUN_6010165c(0x14,PTR_s_gatt_manager_task_cc_60080c4c,0x4e,
               PTR_s_OOBE_task_runnable_started__60080c48);
  while (*(char *)(param_1 + 0x2134) != '\0') {
    thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0x2188),&local_30,0xffffffff);
    iVar2 = local_28;
    puVar1 = puStack_2c;
    if (local_30 == 0) {
      FUN_6010165c(0x28,PTR_s_gatt_manager_task_cc_60080c4c,0x59,
                   PTR_s_Received_uninitialized_OobeReque_60080c50);
      uVar3 = 0;
    }
    else if (local_30 == 1) {
      uVar3 = FUN_60080ba4(param_1);
    }
    else {
      uVar3 = 0;
    }
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = uVar3;
    }
    if (iVar2 != 0) {
      FUN_60101832(iVar2);
    }
  }
  return;
}


