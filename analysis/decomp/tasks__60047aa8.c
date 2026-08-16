// 60047aa8  tasks__60047aa8  size=194 bytes
// src: tasks.c
// --- callers ---
//   600488f4 heap_5_improved__600488f4
//   60047548 FUN_60047548
//   6004b8ce FUN_6004b8ce
//   60047678 queue__60047678
//   60047290 queue__60047290
//   60048774 heap_5_improved__60048774
//   60042c9c FUN_60042c9c
//   6004703c FUN_6004703c
//   6004bab0 FUN_6004bab0
//   60047b98 tasks__60047b98
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   6004c024 thunk_FUN_600ca0d8
//   60047974 tasks__60047974
//   6004bb60 FUN_6004bb60
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8
//   6004bb1a FUN_6004bb1a


/* src: tasks.c */

undefined4 tasks__60047aa8(void)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 in_r3;
  undefined4 uVar6;
  int iVar7;
  
  piVar1 = DAT_60047b6c;
  if (*DAT_60047b6c == 0) {
    thunk_FUN_601016a2(DAT_60047b74,0x877,DAT_60047b70,0,in_r3);
  }
  FUN_60048580();
  *piVar1 = *piVar1 + -1;
  iVar7 = DAT_60047b94;
  puVar3 = DAT_60047b80;
  piVar2 = DAT_60047b7c;
  if ((*piVar1 == 0) && (*DAT_60047b78 != 0)) {
    iVar4 = 0;
    while (*piVar2 != 0) {
      iVar4 = *(int *)(piVar2[3] + 0xc);
      FUN_6004bb60(iVar4 + 0x18);
      FUN_6004bb60(iVar4 + 4);
      uVar5 = *(uint *)(iVar4 + 0x2c);
      *puVar3 = 1 << (uVar5 & 0xff) | *puVar3;
      FUN_6004bb1a(uVar5 * 0x14 + iVar7,iVar4 + 4);
      if (*(uint *)(*DAT_60047b84 + 0x2c) <= *(uint *)(iVar4 + 0x2c)) {
        *DAT_60047b88 = 1;
      }
    }
    if (iVar4 != 0) {
      thunk_FUN_600ca0d8();
    }
    piVar2 = DAT_60047b8c;
    piVar1 = DAT_60047b88;
    iVar7 = *DAT_60047b8c;
    if (iVar7 != 0) {
      do {
        iVar4 = tasks__60047974();
        if (iVar4 != 0) {
          *piVar1 = 1;
        }
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *piVar2 = 0;
    }
    if (*DAT_60047b88 != 0) {
      *DAT_60047b90 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      uVar6 = 1;
      goto LAB_60047ace;
    }
  }
  uVar6 = 0;
LAB_60047ace:
  FUN_600485c8();
  return uVar6;
}


