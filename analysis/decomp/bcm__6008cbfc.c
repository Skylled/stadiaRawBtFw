// 6008cbfc  bcm__6008cbfc  size=126 bytes
// src: bcm.c
// --- callers ---
//   6008d7ac bcm__6008d7ac
// --- callees ---
//   600e721a FUN_600e721a
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e092c FUN_600e092c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552


/* src: bcm.c */

int * bcm__6008cbfc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_600e0552(0xf,0,0x79,DAT_6008cc7c,0x114,param_2,param_3);
  }
  else {
    if (*param_1 == 0) {
      uVar3 = 0x42;
      uVar4 = 0x119;
    }
    else {
      piVar1 = (int *)FUN_600e092c(0x158);
      if (piVar1 != (int *)0x0) {
        thunk_EXT_FUN_0000af90(piVar1,0,0x158);
        piVar1[0x43] = 1;
        *piVar1 = (int)param_1;
        FUN_600e721a(piVar1 + 2);
        iVar2 = (*(code *)*param_1)(piVar1);
        if (iVar2 == 0) {
          thunk_EXT_FUN_0000ac5e(piVar1);
          return (int *)0x0;
        }
        return piVar1;
      }
      uVar3 = 0x41;
      uVar4 = 0x11f;
    }
    FUN_600e0552(0xf,0,uVar3,DAT_6008cc7c,uVar4,param_2,param_3);
  }
  return (int *)0x0;
}


