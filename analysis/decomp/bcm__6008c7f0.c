// 6008c7f0  bcm__6008c7f0  size=64 bytes
// src: bcm.c
// --- callers ---
//   6008c834 bcm__6008c834
// --- callees ---
//   600e0552 FUN_600e0552


/* src: bcm.c */

int bcm__6008c7f0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if (*param_1 == 0) {
    uVar2 = 0x72;
    uVar4 = 0x217;
  }
  else {
    pcVar3 = *(code **)(*param_1 + 0x28);
    if (pcVar3 == (code *)0x0) {
      uVar2 = 0x68;
      uVar4 = 0x21c;
    }
    else {
      iVar1 = (*pcVar3)();
      if (iVar1 != -1) {
        return iVar1;
      }
      uVar2 = 0x69;
      uVar4 = 0x222;
    }
  }
  FUN_600e0552(0x1e,0,uVar2,DAT_6008c830,uVar4,param_2);
  return 0;
}


