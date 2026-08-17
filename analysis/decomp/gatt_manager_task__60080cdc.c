// 60080cdc  gatt_manager_task__60080cdc  size=258 bytes
// src: gatt_manager_task.cc
// --- callers ---
//   600df264 state_machine__600df264
// --- callees ---
//   6013d3c8 thunk_EXT_FUN_00001680
//   6005c44c FUN_6005c44c
//   601016f0 FUN_601016f0
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60101b76 FUN_60101b76
//   60074ec8 FUN_60074ec8
//   6013d378 thunk_EXT_FUN_0000b532
//   60080b24 gatt_manager_task__60080b24
//   600cbb14 FUN_600cbb14
//   6010177a FUN_6010177a


/* src: gatt_manager_task.cc */

int * gatt_manager_task__60080cdc(int *param_1)

{
  int *piVar1;
  undefined *puVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  byte local_bc [4];
  undefined4 *local_b8;
  undefined4 *local_b4;
  undefined4 *local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 *puStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  thunk_EXT_FUN_0000b4c2(DAT_60080de0);
  piVar1 = DAT_60080de4;
  puVar7 = (undefined4 *)*DAT_60080de4;
  if (puVar7 == (undefined4 *)0x0) {
    local_b8 = puVar7;
    local_b4 = puVar7;
    iVar4 = thunk_EXT_FUN_0000b532(0x222c);
    gatt_manager_task__60080b24();
    local_b0 = puVar7;
    puVar5 = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
    puVar2 = PTR_PTR_60080de8;
    puVar5[4] = iVar4;
    *puVar5 = puVar2;
    puVar5[1] = 1;
    puVar5[2] = 1;
    local_b0 = local_b4;
    local_b8 = (undefined4 *)iVar4;
    local_b4 = puVar5;
    thunk_EXT_FUN_00001680(&local_b0);
    if (local_b8 == (undefined4 *)0x0) {
      *param_1 = 0;
      param_1[1] = 0;
    }
    else {
      bVar3 = FUN_6010177a(local_b8,PTR_s_gatt_mgr_task_60080dec,1);
      puVar5 = local_b4;
      if (bVar3 == 0) {
        *piVar1 = (int)local_b8;
        if (local_b4 != (undefined4 *)piVar1[1]) {
          if (local_b4 != (undefined4 *)0x0) {
            FUN_60074ec8(local_b4);
          }
          if (piVar1[1] != 0) {
            FUN_6005c44c();
          }
          piVar1[1] = (int)puVar5;
        }
        *param_1 = (int)local_b8;
        param_1[1] = (int)local_b4;
        local_b4 = (undefined4 *)0x0;
        local_b8 = (undefined4 *)0x0;
      }
      else {
        local_b0 = (undefined4 *)PTR_s_gatt_manager_task_cc_60080df0;
        local_9c = 0;
        local_ac = 0x36;
        local_a8 = local_9a;
        local_9b = 0;
        local_9a[0] = 0;
        local_a4 = 0x80;
        puStack_a0 = puVar7;
        FUN_60101b76(&local_a8,PTR_s_Failed_to_start_oobe_handler_tas_60080df4);
        local_bc[0] = bVar3;
        uVar6 = FUN_600cbb14(local_bc);
        FUN_60101b76(&local_a8,uVar6);
        FUN_601016f0(0x28,local_b0,local_ac,&local_a8);
        *param_1 = 0;
        param_1[1] = 0;
      }
    }
    thunk_EXT_FUN_00001680(&local_b4);
  }
  else {
    iVar4 = DAT_60080de4[1];
    *param_1 = (int)puVar7;
    param_1[1] = iVar4;
    if (iVar4 != 0) {
      FUN_60074ec8();
    }
  }
  thunk_EXT_FUN_00007d10(DAT_60080de0);
  return param_1;
}


