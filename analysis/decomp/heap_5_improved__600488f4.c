// 600488f4  heap_5_improved__600488f4  size=136 bytes
// src: heap_5_improved.c
// --- callers ---
//   60047834 queue__60047834
// --- callees ---
//   600488d8 FUN_600488d8
//   60047958 FUN_60047958
//   60047aa8 tasks__60047aa8
//   60048684 FUN_60048684
//   6004c084 thunk_FUN_601016a2


/* src: heap_5_improved.c */

void heap_5_improved__600488f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = DAT_6004897c;
  if (param_1 != 0) {
    if (*(int *)(param_1 + -4) == -1) {
      piVar3 = *(int **)(param_1 + -8);
    }
    else {
      piVar3 = (int *)(param_1 + -8);
    }
    if ((piVar3[1] & *DAT_6004897c) == 0) {
      thunk_FUN_601016a2(DAT_60048984,0x1ec,DAT_60048980);
    }
    if (*piVar3 != 0) {
      thunk_FUN_601016a2(DAT_60048984,0x1ed,DAT_60048980);
    }
    if (((piVar3[1] & *puVar1) != 0) && (*piVar3 == 0)) {
      FUN_60047958();
      piVar3[1] = piVar3[1] & ~*puVar1;
      FUN_600488d8(piVar3);
      *DAT_60048988 = piVar3[1] + *DAT_60048988;
      iVar2 = FUN_60048684(piVar3,1);
      tasks__60047aa8();
      if (iVar2 == 0) {
        thunk_FUN_601016a2(DAT_60048984,0x204,DAT_60048980,param_4);
        return;
      }
    }
  }
  return;
}


