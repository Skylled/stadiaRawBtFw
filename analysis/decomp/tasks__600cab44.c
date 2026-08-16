// 600cab44  tasks__600cab44  size=232 bytes
// src: tasks.c
// --- callers ---
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d188 thunk_EXT_FUN_0000b2fe
//   6013d108 thunk_EXT_FUN_00007e0c
//   6013d140 thunk_EXT_FUN_0000b344


/* src: tasks.c */

undefined4
tasks__600cab44(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4,undefined4 *param_5)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  puVar8 = param_4;
  if (param_1 == 0) {
    FUN_601016a2(DAT_600cac34,0x13d6,DAT_600cac30,param_4,param_4);
  }
  thunk_EXT_FUN_00007e0c();
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = getBasePriority();
  }
  disableIRQinterrupts();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x50);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0xc4);
  }
  cVar1 = *(char *)(param_1 + 200);
  *(undefined1 *)(param_1 + 200) = 2;
  switch(param_3) {
  case 1:
    param_2 = *(uint *)(param_1 + 0xc4) | param_2;
    break;
  case 2:
    param_2 = *(int *)(param_1 + 0xc4) + 1;
    break;
  case 3:
    goto switchD_600cab9c_caseD_3;
  case 4:
    if (cVar1 == '\x02') {
      uVar3 = 0;
      goto LAB_600cabb6;
    }
    goto switchD_600cab9c_caseD_3;
  default:
    goto switchD_600cab9c_default;
  }
  *(uint *)(param_1 + 0xc4) = param_2;
switchD_600cab9c_default:
  if (cVar1 == '\x01') {
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_601016a2(DAT_600cac34,0x141d,DAT_600cac30,*(int *)(param_1 + 0x28),puVar8);
    }
    if (*DAT_600cac38 == 0) {
      iVar7 = param_1 + 4;
      thunk_EXT_FUN_0000b344(iVar7);
      uVar5 = *(uint *)(param_1 + 0x2c);
      *DAT_600cac3c = 1 << (uVar5 & 0xff) | *DAT_600cac3c;
      iVar4 = uVar5 * 0x14 + DAT_600cac40;
    }
    else {
      iVar7 = param_1 + 0x18;
      iVar4 = DAT_600cac48;
    }
    thunk_EXT_FUN_0000b2fe(iVar4,iVar7);
    if (*(uint *)(*DAT_600cac44 + 0x2c) < *(uint *)(param_1 + 0x2c)) {
      uVar3 = 1;
      if (param_5 == (undefined4 *)0x0) {
        *DAT_600cac4c = 1;
      }
      else {
        *param_5 = 1;
      }
      goto LAB_600cabb6;
    }
  }
  uVar3 = 1;
LAB_600cabb6:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar6);
  }
  return uVar3;
switchD_600cab9c_caseD_3:
  *(uint *)(param_1 + 0xc4) = param_2;
  goto switchD_600cab9c_default;
}


