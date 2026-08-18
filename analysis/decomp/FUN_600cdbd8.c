// 600cdbd8  FUN_600cdbd8  size=178 bytes
// --- callers ---
//   600ca1b4 tasks__600ca1b4
// --- callees ---
//   600d359a FUN_600d359a
//   601023e0 FUN_601023e0


void FUN_600cdbd8(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*DAT_600cdc8c != param_1) {
    if (*(int *)(param_1 + 0x24) != 0) {
      if (*(int *)(*(int *)(param_1 + 0x24) + 0xc) != 0) {
        iVar2 = 0;
        while( true ) {
          if (iVar2 == 0x80) break;
          piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + iVar2);
          while (piVar1 != (int *)0x0) {
            piVar1 = (int *)*piVar1;
            FUN_600d359a(param_1);
          }
          iVar2 = iVar2 + 4;
        }
        FUN_600d359a(param_1);
      }
      if (**(int **)(param_1 + 0x24) != 0) {
        FUN_600d359a(param_1);
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x58) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      FUN_600d359a(param_1);
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      (**(code **)(param_1 + 0x28))(param_1);
      if (*(int *)(param_1 + 0x48) != 0) {
        FUN_601023e0(param_1);
        return;
      }
    }
  }
  return;
}


