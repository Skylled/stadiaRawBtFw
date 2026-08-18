// 600d26a4  FUN_600d26a4  size=70 bytes
// --- callers ---
// --- callees ---
//   600d16ae FUN_600d16ae
//   600d1692 FUN_600d1692
//   600d265a FUN_600d265a


undefined4 FUN_600d26a4(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else {
    FUN_600d1692(*(undefined4 *)(param_1 + 8));
    for (piVar2 = *(int **)(param_1 + 0x2d4);
        (piVar2 != (int *)0x0 &&
        ((*(byte *)((int)piVar2 + 0x43f) != param_2 || (*(byte *)(piVar2 + 0x110) != param_3))));
        piVar2 = (int *)*piVar2) {
    }
    FUN_600d16ae(*(undefined4 *)(param_1 + 8));
    if (piVar2 != (int *)0x0) {
      uVar1 = FUN_600d265a(param_1,piVar2);
      return uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


