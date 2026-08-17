// 60084bec  bio__60084bec  size=80 bytes
// src: bio.c
// --- callers ---
//   60067d14 gotham__60067d14
// --- callees ---
//   600e092c FUN_600e092c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e0552 FUN_600e0552


/* src: bio.c */

int * bio__60084bec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_600e092c(0x2c);
  if (piVar1 == (int *)0x0) {
    FUN_600e0552(0x11,0,0x41,DAT_60084c3c,0x4b,param_2,param_3);
  }
  else {
    thunk_EXT_FUN_0000b5ba(piVar1 + 1,0,0x28);
    *piVar1 = param_1;
    piVar1[2] = 1;
    piVar1[6] = 1;
    if ((*(code **)(param_1 + 0x1c) != (code *)0x0) &&
       (iVar2 = (**(code **)(param_1 + 0x1c))(piVar1), iVar2 == 0)) {
      thunk_EXT_FUN_0000ac5e(piVar1);
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}


