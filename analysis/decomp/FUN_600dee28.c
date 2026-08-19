// 600dee28  FUN_600dee28  size=152 bytes
// --- callers ---
//   6007f8e4 pattern_player__6007f8e4
//   6007f878 FUN_6007f878
// --- callees ---


void FUN_600dee28(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    piVar1 = *(int **)(param_1 + iVar3 * 0x10 + 0x9c);
    if (piVar1 != (int *)0x0) {
      *(int *)(param_1 + 0x94) = iVar3;
      if (*(int *)(param_1 + 0x11c) == 0) {
        iVar3 = param_1 + 0x98 + iVar3 * 0x10;
      }
      else {
        iVar3 = param_1 + 0x118;
      }
      if (*(int *)(iVar3 + 4) != param_2) {
        uVar2 = (**(code **)(*piVar1 + 0xc))();
        *(undefined4 *)(param_1 + 0x11c) = uVar2;
        *(undefined4 *)(param_1 + 0x128) =
             *(undefined4 *)(param_1 + *(int *)(param_1 + 0x94) * 0x10 + 0x9c);
      }
      if (*(int *)(param_1 + 0x11c) == 0) {
        iVar3 = param_1 + 0x98 + *(int *)(param_1 + 0x94) * 0x10;
      }
      else {
        iVar3 = param_1 + 0x118;
      }
      (**(code **)(**(int **)(iVar3 + 4) + 4))();
      if (*(int *)(param_1 + 0x11c) == 0) {
        param_1 = param_1 + 0x98 + *(int *)(param_1 + 0x94) * 0x10;
      }
      else {
        param_1 = param_1 + 0x118;
      }
      uVar2 = *(undefined4 *)(param_1 + 4);
      goto LAB_600dee86;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  *(undefined4 *)(param_1 + 0x94) = 7;
  uVar2 = 0;
LAB_600dee86:
  func_0x6007f758(uVar2);
  return;
}


