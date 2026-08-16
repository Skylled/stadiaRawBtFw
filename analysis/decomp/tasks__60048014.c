// 60048014  tasks__60048014  size=138 bytes
// src: tasks.c
// --- callers ---
//   6004bb98 FUN_6004bb98
// --- callees ---
//   6004bb1a FUN_6004bb1a
//   6004c084 thunk_FUN_601016a2
//   6004bb60 FUN_6004bb60


/* src: tasks.c */

undefined4 tasks__60048014(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    if (*DAT_600480a0 != param_1) {
      thunk_FUN_601016a2(DAT_600480a8,0x10cd,DAT_600480a4,*DAT_600480a0,param_4);
    }
    if (*(int *)(param_1 + 0x54) == 0) {
      thunk_FUN_601016a2(DAT_600480a8,0x10ce,DAT_600480a4,0,param_4);
    }
    iVar3 = *(int *)(param_1 + 0x54) + -1;
    *(int *)(param_1 + 0x54) = iVar3;
    iVar1 = DAT_600480ac;
    if ((*(int *)(param_1 + 0x2c) != *(int *)(param_1 + 0x50)) && (iVar3 == 0)) {
      iVar3 = FUN_6004bb60(param_1 + 4);
      puVar2 = DAT_600480b0;
      if ((iVar3 == 0) && (*(int *)(iVar1 + *(uint *)(param_1 + 0x2c) * 0x14) == 0)) {
        *DAT_600480b0 = *DAT_600480b0 & ~(1 << (*(uint *)(param_1 + 0x2c) & 0xff));
      }
      uVar4 = *(uint *)(param_1 + 0x50);
      *(uint *)(param_1 + 0x2c) = uVar4;
      *(uint *)(param_1 + 0x18) = 0x20 - uVar4;
      *puVar2 = 1 << (uVar4 & 0xff) | *puVar2;
      FUN_6004bb1a(uVar4 * 0x14 + iVar1,param_1 + 4);
      return 1;
    }
  }
  return 0;
}


