// 60084c40  bio__60084c40  size=74 bytes
// src: bio.c
// --- callers ---
//   600861c0 pem_lib__600861c0
// --- callees ---
//   600e0552 FUN_600e0552


/* src: bio.c */

int bio__60084c40(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) ||
     (pcVar3 = *(code **)(*param_1 + 0x14), pcVar3 == (code *)0x0)) {
    uVar2 = 0x73;
    uVar4 = 0x91;
  }
  else {
    if (param_1[1] != 0) {
      if (param_3 < 1) {
        return 0;
      }
      iVar1 = (*pcVar3)();
      if (iVar1 < 1) {
        return iVar1;
      }
      param_1[9] = param_1[9] + iVar1;
      return iVar1;
    }
    uVar2 = 0x72;
    uVar4 = 0x95;
  }
  FUN_600e0552(0x11,0,uVar2,DAT_60084c8c,uVar4,param_2);
  return -2;
}


