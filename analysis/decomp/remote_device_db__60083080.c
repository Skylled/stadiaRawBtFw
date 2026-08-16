// 60083080  remote_device_db__60083080  size=246 bytes
// src: remote_device_db.cc
// --- callers ---
// --- callees ---
//   600dfca0 FUN_600dfca0
//   601016f0 FUN_601016f0
//   6013d3c8 thunk_EXT_FUN_00001680
//   600d37ac FUN_600d37ac
//   6010165c FUN_6010165c
//   600dfc30 FUN_600dfc30
//   600cbb14 FUN_600cbb14
//   60074ec8 FUN_60074ec8
//   600da48a FUN_600da48a


/* src: remote_device_db.cc */

void remote_device_db__60083080(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  char local_c0 [4];
  int local_bc;
  int local_b8;
  undefined *local_b4;
  undefined4 local_b0;
  undefined1 *local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e [130];
  char local_1c;
  
  local_bc = *param_1;
  local_b8 = param_1[1];
  if (local_b8 != 0) {
    FUN_60074ec8();
  }
  if (local_bc == 0) {
    FUN_6010165c(0x28,PTR_s_remote_device_db_cc_6008317c,0x134,PTR_s_No_data_to_serialize_60083178);
    goto LAB_600830a6;
  }
  FUN_6010165c(0x14,PTR_s_remote_device_db_cc_6008317c,0x137,
               PTR_s_Writing_remote_device_database_t_60083180);
  iVar1 = local_bc;
  puVar3 = (undefined4 *)FUN_600dfca0();
  cVar2 = (**(code **)*puVar3)
                    (puVar3,0,(*(uint *)(puVar3[1] + 4) + 0x7ff) / *(uint *)(puVar3[1] + 4));
  if (cVar2 == '\0') {
    iVar6 = *(int *)(iVar1 + 0x800);
    uVar4 = FUN_600dfc30(iVar6,*(undefined4 *)(iVar1 + 0x804));
    *(undefined4 *)(iVar6 + 0x14) = uVar4;
    piVar5 = (int *)FUN_600dfca0();
    cVar2 = (**(code **)(*piVar5 + 8))(piVar5,0,iVar1,0x800);
    if (cVar2 != '\0') goto LAB_60083102;
  }
  else {
LAB_60083102:
    local_b4 = PTR_s_remote_device_db_cc_6008317c;
    local_b0 = 0x138;
    local_ac = local_9e;
    local_a8 = 0x80;
    uStack_a4 = 0;
    local_a0 = 0;
    local_9f = 0;
    local_9e[0] = 0;
    local_c0[0] = cVar2;
    local_1c = cVar2;
    uVar4 = FUN_600cbb14(local_c0);
    FUN_600d37ac(&local_ac,uVar4);
    FUN_600d37ac(&local_ac,PTR_LAB_6011c45c_1_60083184);
    FUN_600d37ac(&local_ac,PTR_s_Failed_to_save_BLE_database_to_f_60083188);
    FUN_601016f0(0x28,local_b4,local_b0,&local_ac);
  }
  local_b4 = (undefined *)0x0;
  *param_1 = 0;
  local_b0 = 0;
  FUN_600da48a(param_1 + 1,&local_b0);
  thunk_EXT_FUN_00001680(&local_b0);
LAB_600830a6:
  thunk_EXT_FUN_00001680(&local_b8);
  return;
}


