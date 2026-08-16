// 6008ac40  bcm__6008ac40  size=62 bytes
// src: bcm.c
// --- callers ---
//   6008cfd4 bcm__6008cfd4
// --- callees ---
//   600e092c FUN_600e092c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552


/* src: bcm.c */

int * bcm__6008ac40(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_600e092c(0x58);
  if (piVar1 == (int *)0x0) {
    FUN_600e0552(0xf,0,0x41,DAT_6008ac80,0x5a,param_2,param_3);
  }
  else {
    thunk_EXT_FUN_0000af90(piVar1,0,0x58);
    *piVar1 = (int)(piVar1 + 5);
    iVar2 = *param_1;
    piVar1[1] = iVar2;
    piVar1[2] = iVar2;
    piVar1[4] = 2;
  }
  return piVar1;
}


