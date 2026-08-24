// 600ee01c  FUN_600ee01c  size=60 bytes
// --- callers ---
//   600ee062 FUN_600ee062
// --- callees ---
//   6013cff0 thunk_EXT_FUN_00008844
//   6013d0e0 thunk_EXT_FUN_0000728c
//   6013d2d0 thunk_EXT_FUN_0000713c


void FUN_600ee01c(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  thunk_EXT_FUN_0000713c();
  while (puVar1 = *(undefined4 **)(param_1 + 0x2c), puVar1 != (undefined4 *)0x0) {
    piVar3 = (int *)puVar1[4];
    *(undefined4 *)(param_1 + 0x2c) = *puVar1;
    if ((*(code **)puVar1[2] != (code *)0x0) && (puVar1[3] != 0)) {
      (**(code **)puVar1[2])();
    }
    piVar2 = (int *)piVar3[1];
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar3;
    }
    if (*piVar3 != 0) {
      *(int **)(*piVar3 + 4) = piVar2;
    }
    thunk_EXT_FUN_00008844(piVar3);
  }
  thunk_EXT_FUN_0000728c();
  return;
}


