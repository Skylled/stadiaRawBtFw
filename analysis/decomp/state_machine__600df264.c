// 600df264  state_machine__600df264  size=604 bytes
// src: state_machine.cc
// --- callers ---
//   6008099c state_machine__6008099c
// --- callees ---
//   6010165c FUN_6010165c
//   600d37b8 FUN_600d37b8
//   60080c54 FUN_60080c54
//   600d37ac FUN_600d37ac
//   600d8942 thunk_FUN_600af1d8
//   600df30c FUN_600df30c
//   60080390 state_machine__60080390
//   6013d3c8 thunk_EXT_FUN_00001680
//   6005ae68 FUN_6005ae68
//   600df218 FUN_600df218
//   60080cdc gatt_manager_task__60080cdc
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600df1f0 FUN_600df1f0
//   60080424 adapter__60080424
//   60081234 advertiser__60081234
//   60051120 FUN_60051120
//   60080c90 FUN_60080c90
//   60080698 FUN_60080698
//   60080e58 FUN_60080e58


/* src: state_machine.cc */

undefined4 state_machine__600df264(int param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int **ppiVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined1 uStack_e4;
  char local_e3;
  undefined1 local_d8;
  char local_d7;
  undefined4 local_d4;
  undefined4 uStack_d0;
  int local_cc;
  int *local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_bc;
  int *local_b8;
  undefined1 auStack_b4 [156];
  
  if ((param_2 == 6) || (iVar6 = FUN_600df218(), iVar6 == param_2)) {
    return 0;
  }
  uVar3 = FUN_600df218();
  state_machine__60080390(&uStack_e4,uVar3);
  state_machine__60080390(&local_d8,param_2);
  uVar3 = FUN_60080e58();
  adapter__60080424(DAT_60080970,param_1);
  if (local_e3 != local_d7) {
    if (local_d7 == '\0') {
      advertiser__60081234(uVar3,uStack_d0,local_d4,local_d8);
      FUN_60080c54(&local_bc);
      local_c8 = local_b8;
      if (local_b8 == (int *)0x0) {
LAB_60080868:
        local_cc = 0;
      }
      else {
        piVar8 = local_b8 + 1;
        iVar6 = local_b8[1];
        do {
          if (iVar6 == 0) {
            local_c8 = (int *)0x0;
            break;
          }
          DataMemoryBarrier(0x1b);
          ExclusiveAccess(piVar8);
          iVar7 = *piVar8;
          bVar1 = false;
          if (iVar7 == iVar6) {
            bVar1 = (bool)hasExclusiveAccess(piVar8);
            if (bVar1) {
              *piVar8 = iVar6 + 1;
            }
            DataMemoryBarrier(0x1b);
          }
          iVar6 = iVar7;
        } while (!bVar1);
        if ((local_c8 == (int *)0x0) || (local_cc = local_bc, local_c8[1] == 0)) goto LAB_60080868;
      }
      if (local_b8 != (int *)0x0) {
        if (PTR_FUN_600ee062_1_60080988 == (undefined *)0x0) {
          iVar6 = local_b8[2];
          local_b8[2] = iVar6 + -1;
        }
        else {
          piVar8 = local_b8 + 2;
          DataMemoryBarrier(0x1b);
          do {
            ExclusiveAccess(piVar8);
            iVar6 = *piVar8;
            bVar1 = (bool)hasExclusiveAccess(piVar8);
          } while (!bVar1);
          *piVar8 = iVar6 + -1;
          DataMemoryBarrier(0x1b);
        }
        if (iVar6 == 1) {
          (**(code **)(*local_b8 + 0xc))();
        }
      }
      if (local_cc != 0) {
        FUN_6010165c(0x14,PTR_s_state_machine_cc_60080978,0x122,
                     PTR_s_Gatt_Manager_shutting_down_6008098c);
        puVar2 = DAT_60080990;
        DataMemoryBarrier(0x1b);
        *DAT_60080990 = 0;
        DataMemoryBarrier(0x1b);
        DataMemoryBarrier(0x1b);
        DataMemoryBarrier(0x1b);
        local_bc = CONCAT31(local_bc._1_3_,*puVar2);
        FUN_6005ae68(puVar2 + 4,&local_bc);
        uVar5 = FUN_60080c90(local_cc);
        if ((uVar5 & 0xff) != 0) {
          FUN_60051120(&local_bc,PTR_s_state_machine_cc_60080978,0x125,uVar5);
          FUN_600d37ac(auStack_b4,DAT_60080994);
          FUN_600d37b8(&local_bc);
        }
      }
      ppiVar4 = &local_c8;
    }
    else {
      gatt_manager_task__60080cdc(&local_bc);
      if (local_bc == 0) {
        FUN_6010165c(0x28,PTR_s_state_machine_cc_60080978,0x112,
                     PTR_s_Failed_to_start_OOBE_task_60080974);
        thunk_EXT_FUN_00001680(&local_b8);
        return 0;
      }
      FUN_6010165c(0x14,PTR_s_state_machine_cc_60080978,0x116,PTR_s_BLE_services_setup_6008097c);
      local_c4 = 0;
      local_cc = 1;
      local_c8 = (int *)0x0;
      FUN_600df30c(local_bc,1,0,0,local_c0);
      ppiVar4 = &local_b8;
    }
    thunk_EXT_FUN_00001680(ppiVar4);
  }
  advertiser__60081234(uVar3,uStack_d0,local_d4,local_d8);
  if (param_2 == 1) {
    uVar5 = FUN_600df1f0(*(undefined4 *)(DAT_60080980 + 4));
    if ((uVar5 & 0xff) != 0) {
      FUN_60051120(&local_bc,PTR_s_state_machine_cc_60080978,0x12e,uVar5);
      FUN_600d37ac(auStack_b4,PTR_s_Limited_discovery_timer_schedule_60080984);
      FUN_600d37b8(&local_bc);
    }
  }
  else {
    iVar6 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(DAT_60080980 + 4),3,0,0,10);
    if (iVar6 != 1) {
      FUN_60051120(&local_bc,PTR_s_state_machine_cc_60080978,0x131,4);
      FUN_600d37ac(auStack_b4,DAT_60080998);
      FUN_600d37b8(&local_bc);
    }
    if (param_2 == 5) {
      local_bc = 0;
      FUN_60080698(param_1 + 0x68,&local_bc);
      thunk_FUN_600af1d8(DAT_60080970);
      goto LAB_6008095c;
    }
  }
  iVar6 = FUN_600df218(param_1);
  if (iVar6 == 5) {
    local_bc = 1;
    FUN_60080698(param_1 + 0x68,&local_bc);
  }
LAB_6008095c:
  DataMemoryBarrier(0x1b);
  *(int *)(param_1 + 4) = param_2;
  DataMemoryBarrier(0x1b);
  return 1;
}


