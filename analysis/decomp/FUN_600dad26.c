// 600dad26  FUN_600dad26  size=132 bytes
// --- callers ---
// --- callees ---
//   6013d268 thunk_EXT_FUN_00006d2c
//   600764fc input_task__600764fc


void FUN_600dad26(int param_1,undefined1 *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_24;
  int local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  local_20 = 0;
  local_24 = 5;
  while (iVar1 = thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0xec),&local_24,0), iVar1 == 1) {
    uVar3 = local_24 & 0xff;
    if (uVar3 == 2) {
      piVar2 = *(int **)(param_1 + 0x240);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0xc))(piVar2,0);
      }
      *(int *)(param_1 + 0x240) = local_20;
      if (local_20 == 0) {
        *param_2 = 0;
      }
      else {
        input_task__600764fc(param_1,local_1c);
        (**(code **)(**(int **)(param_1 + 0x240) + 0xc))(*(int **)(param_1 + 0x240),param_1 + 0x60);
        *param_2 = 1;
      }
    }
    else if (uVar3 == 3) {
      *(undefined1 *)(param_1 + 0x248) = 1;
    }
    else if (uVar3 == 4) {
      *(undefined1 *)(param_1 + 0x248) = 0;
    }
  }
  return;
}


